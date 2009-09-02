#include "SINASTTreeCtrlVisitor.h"

#include <stdio.h>
#include <iostream>

#include "Common.h"
#include "SINLogger.h"
#include "SINAssert.h"
#include "SINTreeNode.h"
#include "SINConstants.h"
#include "SINLoggerManager.h"

#define SIN_ASTTreeCtrlVisitor_LoggerName "SIN::ASTTreeCtrlVisitor"

#define SIN_ASTTreeCtrlVisitor_IdentationSequence "    "

#define SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(NODENAME)		\
	void ASTTreeCtrlVisitor::Visit(NODENAME##ASTNode & _node) {		\
		Visit(static_cast<ASTNode &>(_node));						\
	}

namespace SIN {

	ASTTreeCtrlVisitor::ASTTreeCtrlVisitor(OutputStream& _out):
		ASTTreeVisualisationVisitor(_out)
	{}

	ASTTreeCtrlVisitor::~ASTTreeCtrlVisitor(void) {
	}

	void ASTTreeCtrlVisitor::Visit(ASTNode &node) {
		if (node.Name() == "AST")
			out			<< 
			"(RootId:"	<< 
			node.ID();
		
		else
			out				<< 
			"(id:"			<< 
			node.ID()		<< 
			", parentId: "	<<  
			static_cast<ASTNode *>(node.GetParent())->ID();

		out << ", line: " << node.AssociatedFileLine() << ", expression:\"" << node.Name() << "\"" << ")" << SIN::ENDL;
	}

	//-----------------------------------------------------------------
	
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Number	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(String	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Nil	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(True	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(False	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Add	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Sub	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Mul	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Div	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Mod	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Lt	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Gt	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Le	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Ge	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Eq	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Ne	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Or	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Not)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(And)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(For		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ForPreamble)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ForAddendum)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(While		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(If			)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(IfElse		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Return		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Semicolon	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Break		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Continue	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Block		)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Assign	)


	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(NormalCall		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(MethodCall		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(FuncdefCall	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ActualArguments)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ExpressionList	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Function		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(LamdaFunction	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(FormalArguments)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ID			)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(LocalID	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(GlobalID	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(PreIncr	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(PostIncr	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(PreDecr	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(PostDecr	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(UnaryNot	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(UnaryMin	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(Object			)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(EmptyObject	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(UnindexedMember)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(IndexedMember	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ObjectMember	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ObjectIndex	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(CallMember	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(CallIndex	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ObjectKeys	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(ObjectSize	)

	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(MetaParse			)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(MetaPreserve		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(MetaEvaluate		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(MetaUnparse		)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(MetaParseString	)
	SIN_AST_TREE_CTRL_DEFAULT_VISIT_DEFINITION(SinCode			)

	

} // namespace SIN
