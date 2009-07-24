#ifndef __SIN_AST_NODES_H__
#define __SIN_AST_NODES_H__

#include "SINASTNode.h"
#include "SINSymbolTable.h"

namespace SIN{

	#define SINASTNODE_NODE_DECL(NAME)				\
	class NAME##ASTNode : public ASTNode {			\
    public:											\
        NAME##ASTNode(void);						\
        NAME##ASTNode(String const &name);			\
        ~NAME##ASTNode(void);						\
        virtual void Accept(ASTVisitor *) const;	\
		virtual NAME##ASTNode *Clone(void) const;	\
    }

	class BlockASTNode : public ASTNode {

	public:

		BlockASTNode(void);
		BlockASTNode(String const &name);
		 ~BlockASTNode(void);

		void Accept(ASTVisitor *) const;

		SymbolTable getSymbolTable(void) { return symTable; }
		void setSymbolTable(SymbolTable _symTable){ symTable = _symTable; }

		BlockASTNode *Clone(void) const;

	private:
		SymbolTable symTable;
	};

	SINASTNODE_NODE_DECL(Arguments		);
	SINASTNODE_NODE_DECL(Assign			);
	SINASTNODE_NODE_DECL(NormalCall		);
	SINASTNODE_NODE_DECL(MethodCall		);
	SINASTNODE_NODE_DECL(FuncdefCall	);
	SINASTNODE_NODE_DECL(Function		);
	SINASTNODE_NODE_DECL(LamdaFunction	);
	SINASTNODE_NODE_DECL(ID				);
	SINASTNODE_NODE_DECL(LocalID		);
	SINASTNODE_NODE_DECL(GlobalID		);
	SINASTNODE_NODE_DECL(If				);
	SINASTNODE_NODE_DECL(IfElse			);
	SINASTNODE_NODE_DECL(For			);
	SINASTNODE_NODE_DECL(While			);
	SINASTNODE_NODE_DECL(PreIncr		);
	SINASTNODE_NODE_DECL(PostIncr		);
	SINASTNODE_NODE_DECL(PreDecr		);
	SINASTNODE_NODE_DECL(PostDecr		);
	SINASTNODE_NODE_DECL(UnaryNot		);
	SINASTNODE_NODE_DECL(UnaryMin		);
	SINASTNODE_NODE_DECL(Continue		);
	SINASTNODE_NODE_DECL(Break			);
	SINASTNODE_NODE_DECL(Object			);
	SINASTNODE_NODE_DECL(EmptyObject	);
	SINASTNODE_NODE_DECL(UnindexedMember);
	SINASTNODE_NODE_DECL(IndexedMember	);
	SINASTNODE_NODE_DECL(ObjectMember	);
	SINASTNODE_NODE_DECL(ObjectIndex	);
	SINASTNODE_NODE_DECL(CallMember		);
	SINASTNODE_NODE_DECL(CallIndex		);
	SINASTNODE_NODE_DECL(Return			);
	SINASTNODE_NODE_DECL(Semicolon		);
	SINASTNODE_NODE_DECL(MetaParse		);
	SINASTNODE_NODE_DECL(MetaPreserve	);
	SINASTNODE_NODE_DECL(MetaEvaluate	);
	SINASTNODE_NODE_DECL(MetaUnparse	);
	SINASTNODE_NODE_DECL(MetaParseString);


} // namespace SIN

#endif //__SIN_AST_NODES_H__