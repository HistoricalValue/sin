#include "SINShiftToMetaEvaluatorASTVisitor.h"


#include <algorithm>
#include <functional>

#include "SINAlloc.h"
#include "SINAssert.h"
#include "SINMemoryCellAST.h"




namespace SIN {




	//-----------------------------------------------------------------

	ShiftToMetaEvaluatorASTVisitor::ShiftToMetaEvaluatorASTVisitor(TreeEvaluationVisitor & visitor):
		treeEvalVisitor(visitor)
	{ }

	//-----------------------------------------------------------------

	ShiftToMetaEvaluatorASTVisitor::ShiftToMetaEvaluatorASTVisitor(ShiftToMetaEvaluatorASTVisitor const& _o):
		treeEvalVisitor(_o.treeEvalVisitor)	
	{ parent = _o.parent;}

	//-----------------------------------------------------------------

	ShiftToMetaEvaluatorASTVisitor::~ShiftToMetaEvaluatorASTVisitor(void) { }

	
	//-----------------------------------------------------------------

	void ShiftToMetaEvaluatorASTVisitor::Visit(MetaPreserveASTNode& _node)	{ 
		SINASSERT(_node.NumberOfChildren() == 1);

		//Evaluate the node children.
		static_cast<ASTNode &>(*_node.begin()).Accept(&treeEvalVisitor);
		
		//Check if the return value of the evaluator is AST.
		MemoryCell * astmc = treeEvalVisitor.Memory();
		SINASSERT(astmc && astmc->Type() == MemoryCell::AST_MCT);	//run time error?
		
		//Copy the evaluator AST
		ASTCloneVisitor clone;
		static_cast<MemoryCellAST *>(astmc)->GetValue()->Accept(&clone);

		ASTNode * cloneRoot = clone.Root();
		SINASSERT(cloneRoot != 0x00);
		
		//Conect the Clone visitor root to my tree.
		if (parent)
			*parent << cloneRoot;
		//parent = root;	//look the assert for more info
		SINASSERT(!"Edw mipos prepi na brw pou einai h oura nou root ? ");

		//splice my list with the list that contains the new nodes. 
		//We do this because we do not want to have memory leaks
		nodesList->splice(nodesList->end(), *clone.TakeNodesList());
		clone.DeleteList();
	}


} // namespace SIN
