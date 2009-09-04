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

	void ShiftToMetaEvaluatorASTVisitor::Visit(MetaParseASTNode& _node)	{ 
		SINASSERT(_node.NumberOfChildren() == 1);

		//We  are going to copy all  the sub tree from this node and down.
		ASTCloneVisitor clone;
		_node.Accept(&clone);

		//conect the new sub tree to current tree.
		if(parent)
			*parent << clone.Root();
		
		if(!root)
			root = clone.Root();
		
		//splice my list with the list that contains the new nodes. 
		//We do this because we do not want to have memory leaks
		nodesList->splice(nodesList->end(), *clone.TakeNodesList());
		clone.DeleteList();
	}


	
	//-----------------------------------------------------------------

	void ShiftToMetaEvaluatorASTVisitor::Visit(MetaPreserveASTNode& _node)	{ 
		SINASSERT(_node.NumberOfChildren() == 1);

		//Evaluate the node.
		_node.Accept(&treeEvalVisitor);
		
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

		if(!root)
			root = cloneRoot;

		//splice my list with the list that contains the new nodes. 
		//We do this because we do not want to have memory leaks
		nodesList->splice(nodesList->end(), *clone.TakeNodesList());
		clone.DeleteList();
	}


} // namespace SIN
