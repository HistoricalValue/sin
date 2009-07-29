/*
 *	Virtual Class
 */

#ifndef __SIN_SIN_AST_VISITOR_H__
#define __SIN_SIN_AST_VISITOR_H__


#include "SINASTNode.h"
#include "SINASTNodes.h"
#include "SINASTCommon.h"

//disable the error: not enough actual parameters for macro 'SINASTVISITOR_VISIT_SIGNATURE'
#pragma warning(disable:4003)


#define SINASTVISITOR_VISIT_SIGNATURE(NODENAME) virtual void Visit(NODENAME##ASTNode const&)


namespace SIN {
	class ASTVisitor { 
	public :
		virtual ~ASTVisitor() {}


		SINASTVISITOR_VISIT_SIGNATURE(					) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Number			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(String			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Nil				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(True				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(False				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Add				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Sub				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Mul				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Div				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Mod				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Lt				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Gt				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Le				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Ge				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Eq				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Ne				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Or				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Not				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(And				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Arguments			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Assign			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(NormalCall		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(MethodCall		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(FuncdefCall		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Function			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(LamdaFunction		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(ID				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(LocalID			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(GlobalID			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(If				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(IfElse			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(For				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(PreIncr			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(PostIncr			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(PreDecr			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(PostDecr			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(UnaryNot			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(UnaryMin			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Continue			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Break				) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Object			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(EmptyObject		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(UnindexedMember	) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(ObjectMember		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(ObjectIndex		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(CallMember		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(CallIndex			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Return			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(Semicolon			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(MetaParse			) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(MetaPreserve		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(MetaEvaluate		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(MetaUnparse		) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(MetaParseString	) = 0;
		SINASTVISITOR_VISIT_SIGNATURE(SinCode			) = 0;
	};
}


#endif //__SIN_AST_VISITOR_H__
