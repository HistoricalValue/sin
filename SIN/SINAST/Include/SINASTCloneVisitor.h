#ifndef __SIN_AST_CLONE_VISITOR_H__
#define __SIN_AST_CLONE_VISITOR_H__

#include <list>

#include "SINASTNodes.h"
#include "SINASTVisitor.h"




namespace SIN {
	
	class ASTCloneVisitor: public ASTVisitor {
	public:
		typedef std::list<ASTNode *> NodesList;

		ASTCloneVisitor(void);
		ASTCloneVisitor(ASTCloneVisitor const&);
		~ASTCloneVisitor(void);

		SINASTVISITOR_VISIT_SIGNATURE(Number			);
		SINASTVISITOR_VISIT_SIGNATURE(String			);
		SINASTVISITOR_VISIT_SIGNATURE(Nil				);
		SINASTVISITOR_VISIT_SIGNATURE(True				);
		SINASTVISITOR_VISIT_SIGNATURE(False				);
		SINASTVISITOR_VISIT_SIGNATURE(Add				);
		SINASTVISITOR_VISIT_SIGNATURE(Sub				);
		SINASTVISITOR_VISIT_SIGNATURE(Mul				);
		SINASTVISITOR_VISIT_SIGNATURE(Div				);
		SINASTVISITOR_VISIT_SIGNATURE(Mod				);
		SINASTVISITOR_VISIT_SIGNATURE(Lt				);
		SINASTVISITOR_VISIT_SIGNATURE(Gt				);
		SINASTVISITOR_VISIT_SIGNATURE(Le				);
		SINASTVISITOR_VISIT_SIGNATURE(Ge				);
		SINASTVISITOR_VISIT_SIGNATURE(Eq				);
		SINASTVISITOR_VISIT_SIGNATURE(Ne				);
		SINASTVISITOR_VISIT_SIGNATURE(Or				);
		SINASTVISITOR_VISIT_SIGNATURE(And				);
		SINASTVISITOR_VISIT_SIGNATURE(Assign			);
		SINASTVISITOR_VISIT_SIGNATURE(NormalCall		);
		SINASTVISITOR_VISIT_SIGNATURE(MethodCall		);
		SINASTVISITOR_VISIT_SIGNATURE(FuncdefCall		);
		SINASTVISITOR_VISIT_SIGNATURE(ActualArguments	);
		SINASTVISITOR_VISIT_SIGNATURE(ExpressionList	);
		SINASTVISITOR_VISIT_SIGNATURE(Function			);
		SINASTVISITOR_VISIT_SIGNATURE(LamdaFunction		);
		SINASTVISITOR_VISIT_SIGNATURE(FormalArguments	);
		SINASTVISITOR_VISIT_SIGNATURE(ID				);
		SINASTVISITOR_VISIT_SIGNATURE(LocalID			);
		SINASTVISITOR_VISIT_SIGNATURE(GlobalID			);
		SINASTVISITOR_VISIT_SIGNATURE(If				);
		SINASTVISITOR_VISIT_SIGNATURE(IfElse			);
		SINASTVISITOR_VISIT_SIGNATURE(For				);
		SINASTVISITOR_VISIT_SIGNATURE(ForPreamble		);
		SINASTVISITOR_VISIT_SIGNATURE(ForAddendum		);
		SINASTVISITOR_VISIT_SIGNATURE(PreIncr			);
		SINASTVISITOR_VISIT_SIGNATURE(PostIncr			);
		SINASTVISITOR_VISIT_SIGNATURE(PreDecr			);
		SINASTVISITOR_VISIT_SIGNATURE(PostDecr			);
		SINASTVISITOR_VISIT_SIGNATURE(UnaryNot			);
		SINASTVISITOR_VISIT_SIGNATURE(UnaryMin			);
		SINASTVISITOR_VISIT_SIGNATURE(Continue			);
		SINASTVISITOR_VISIT_SIGNATURE(Break				);
		SINASTVISITOR_VISIT_SIGNATURE(Object			);
		SINASTVISITOR_VISIT_SIGNATURE(EmptyObject		);
		SINASTVISITOR_VISIT_SIGNATURE(UnindexedMember	);
		SINASTVISITOR_VISIT_SIGNATURE(ObjectMember		);
		SINASTVISITOR_VISIT_SIGNATURE(ObjectIndex		);
		SINASTVISITOR_VISIT_SIGNATURE(CallMember		);
		SINASTVISITOR_VISIT_SIGNATURE(CallIndex			);
		SINASTVISITOR_VISIT_SIGNATURE(ObjectKeys		);
		SINASTVISITOR_VISIT_SIGNATURE(ObjectSize		);
		SINASTVISITOR_VISIT_SIGNATURE(Return			);
		SINASTVISITOR_VISIT_SIGNATURE(Semicolon			);
		SINASTVISITOR_VISIT_SIGNATURE(MetaParse			);
		SINASTVISITOR_VISIT_SIGNATURE(MetaPreserve		);
		SINASTVISITOR_VISIT_SIGNATURE(MetaEvaluate		);
		SINASTVISITOR_VISIT_SIGNATURE(MetaUnparse		);
		SINASTVISITOR_VISIT_SIGNATURE(MetaParseString	);
		SINASTVISITOR_VISIT_SIGNATURE(SinCode			);
		SINASTVISITOR_VISIT_SIGNATURE(IndexedMember		);
		SINASTVISITOR_VISIT_SIGNATURE(While				);
		SINASTVISITOR_VISIT_SIGNATURE(Block				);
		SINASTVISITOR_VISIT_SIGNATURE(Not				);

		ASTNode *	Root(void) const ;
		void		DeleteAST(void);
		void		DeleteListAndAST(void);

		//------------->  WARNING	<----------------//
		//YOU MUST TAKE THIS LIST AND DELETE ALL THE ELEMENTS AND AFTER THAT YOU MUST DELETE AND THE LIST.
		//LexAndBisonParseArguments DOES NOT DO THIS AUTOMATCILALLY.
		//IF YOU DO NOT DO THAT, YOU ARE GOING TO HAVE MEMORY LEAKS
		ASTCloneVisitor::NodesList * TakeNodesList(void);
	private:
		ASTNode	*	parent;
		NodesList * nodesList;

	}; // class ASTCloneVisitor

	


} // namespace SIN

#endif // __SIN_AST_CLONE_VISITOR_H__
