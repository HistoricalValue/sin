#ifndef __SIN_AST_TREE_CTRL_VISITOR_H__
#define __SIN_AST_TREE_CTRL_VISITOR_H__

#include "Common.h"
#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"
#include "SINASTVisitor.h"
#include "SINOutputStream.h"
#include "SINASTTreeVisualisationVisitor.h"

#ifdef _MSC_VER // compiling with Microsoft Visual Studio
//disable the error: not enough actual parameters for macro 'SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE'
#pragma warning(disable:4003)
#endif // _MSC_VER

#define SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(NODENAME) virtual void Visit(NODENAME##ASTNode &)

namespace SIN {
	class ASTTreeCtrlVisitor: public ASTTreeVisualisationVisitor {
	public:
		ASTTreeCtrlVisitor(OutputStream& out);
		virtual ~ASTTreeCtrlVisitor(void);
		

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(	);
		//////////////////////////////////////////////////
		//Const value nodes
		//virtual void	Visit (IdASTNode const &		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Number	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(String	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Nil		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(True		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(False	);
		
		
		//////////////////////////////////////////////////
		//arithmetic operators nodes
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Add	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Sub	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Mul	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Div	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Mod	);
		//virtual void	Visit (IncrASTNode const &	);
		//virtual void	Visit (DecrASTNode const &	);
		

		//////////////////////////////////////////////////
		//compare nodes
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Lt);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Gt);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Le);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Ge);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Eq);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Ne);


		//////////////////////////////////////////////////
		//logic nodes
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Or	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Not	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(And	);

		//////////////////////////////////////////////////
		//stmt nodes
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(For			);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(ForPreamble	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(ForAddendum	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(While		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(If			);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(IfElse		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Return		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Semicolon	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Break		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Continue		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Block		);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Assign	);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(NormalCall		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(MethodCall		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(FuncdefCall		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(ActualArguments	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(ExpressionList	);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Function			);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(LamdaFunction	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(FormalArguments	);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(ID		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(LocalID	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(GlobalID	);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(PreIncr	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(PostIncr	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(PreDecr	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(PostDecr	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(UnaryNot	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(UnaryMin	);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(Object			);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(EmptyObject		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(UnindexedMember	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(IndexedMember	);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(ObjectMember	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(ObjectIndex	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(CallMember	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(CallIndex	);

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(MetaParse		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(MetaPreserve		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(MetaEvaluate		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(MetaUnparse		);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(MetaParseString	);
		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(SinCode			);
	}; // class ASTTreeCtrlVisitor


} // namespace SIN




#endif // __SIN_AST_TREE_CTRL_VISITOR_H__
