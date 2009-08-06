#ifndef __SIN_PRESERVE_AST_EVALUATION_VISITOR_H__
#define __SIN_PRESERVE_AST_EVALUATION_VISITOR_H__

#include <stack>

#include "SINASTVisitor.h"
#include "SINTreeEvaluationVisitor.h"

/*
#ifdef _MSC_VER // compiling with Microsoft Visual Studio
//disable the error: not enough actual parameters for macro 'SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE'
#pragma warning(disable:4003)
#endif // _MSC_VER
*/


#define PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(NODENAME)		SINASTVISITOR_VISIT_SIGNATURE(NODENAME)


namespace SIN{

	//class TreeEvaluationVisitor;	//forword 



	class PreserveASTEvaluatorVisitor : public ASTVisitor {
	public:

		//constructor and destructor
		PreserveASTEvaluatorVisitor (TreeEvaluationVisitor & visitor) : treeEvalVisitor(visitor){}
		virtual ~PreserveASTEvaluatorVisitor (void);



		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(					) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Number			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(String			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Nil				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(True				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(False				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Add				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Sub				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Mul				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Div				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Mod				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Lt				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Gt				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Le				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Ge				) ;	
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Eq				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Ne				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Or				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(And				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(For				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(While				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(If				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(IfElse			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Return			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Semicolon			) ;	
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Break				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Continue			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Block				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Assign			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(NormalCall		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(MethodCall		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(FuncdefCall		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(ActualArguments	) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(ExpressionList	) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Function			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(LamdaFunction		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(FormalArguments	) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(ID				) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(LocalID			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(GlobalID			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(PreIncr			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(PostIncr			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(PreDecr			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(PostDecr			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(UnaryNot			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(UnaryMin			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(Object			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(EmptyObject		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(UnindexedMember	) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(IndexedMember		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(ObjectMember		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(ObjectIndex		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(CallMember		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(CallIndex			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(MetaParse			) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(MetaPreserve		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(MetaEvaluate		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(MetaUnparse		) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(MetaParseString	) ;
		PRESERVE_AST_EVALUATION_VISITOR_SIGNATURE(SinCode			) ;

	private:
		TreeEvaluationVisitor & treeEvalVisitor;
	
	};

} // /namespace SIN


#endif	//__SIN_PRESERVE_AST_EVALUATION_VISITOR_H__