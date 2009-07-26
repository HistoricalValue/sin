#include "SINASTNodes.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"
#include "SINAlloc.h"

//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_NODE_DEFS(NAME)									\
    NAME##ASTNode::NAME##ASTNode(void):	ASTNode() {}						\
	NAME##ASTNode::NAME##ASTNode(String const &_name): ASTNode(_name) {}	\
	NAME##ASTNode::~NAME##ASTNode(void) {}									\
	void NAME##ASTNode::Accept(ASTVisitor *_v) const {						\
        SINASSERT(_v);														\
        _v->Visit(*this);													\
    }																		\
	NAME##ASTNode *NAME##ASTNode::Clone(void) const {						\
		return SINEWCLASS(NAME##ASTNode, (*this));							\
	}

namespace SIN{

	SINASTNODE_DEFAULT_NODE_DEFS(SinCode		)
	SINASTNODE_DEFAULT_NODE_DEFS(Arguments		)
	SINASTNODE_DEFAULT_NODE_DEFS(Assign			)
	SINASTNODE_DEFAULT_NODE_DEFS(Block			)
	SINASTNODE_DEFAULT_NODE_DEFS(NormalCall		)
	SINASTNODE_DEFAULT_NODE_DEFS(MethodCall		)
	SINASTNODE_DEFAULT_NODE_DEFS(FuncdefCall	)
	SINASTNODE_DEFAULT_NODE_DEFS(Function		)
	SINASTNODE_DEFAULT_NODE_DEFS(LamdaFunction	)
	SINASTNODE_DEFAULT_NODE_DEFS(ID				)
	SINASTNODE_DEFAULT_NODE_DEFS(LocalID		)
	SINASTNODE_DEFAULT_NODE_DEFS(GlobalID		)
	SINASTNODE_DEFAULT_NODE_DEFS(If				)
	SINASTNODE_DEFAULT_NODE_DEFS(IfElse			)
	SINASTNODE_DEFAULT_NODE_DEFS(For			)
	SINASTNODE_DEFAULT_NODE_DEFS(While			)
	SINASTNODE_DEFAULT_NODE_DEFS(PreIncr		)
	SINASTNODE_DEFAULT_NODE_DEFS(PostIncr		)
	SINASTNODE_DEFAULT_NODE_DEFS(PreDecr		)
	SINASTNODE_DEFAULT_NODE_DEFS(PostDecr		)
	SINASTNODE_DEFAULT_NODE_DEFS(UnaryNot		)
	SINASTNODE_DEFAULT_NODE_DEFS(UnaryMin		)
	SINASTNODE_DEFAULT_NODE_DEFS(Continue		)
	SINASTNODE_DEFAULT_NODE_DEFS(Break			)
	SINASTNODE_DEFAULT_NODE_DEFS(Object			)
	SINASTNODE_DEFAULT_NODE_DEFS(EmptyObject	)
	SINASTNODE_DEFAULT_NODE_DEFS(UnindexedMember)
	SINASTNODE_DEFAULT_NODE_DEFS(IndexedMember	)
	SINASTNODE_DEFAULT_NODE_DEFS(ObjectMember	)
	SINASTNODE_DEFAULT_NODE_DEFS(ObjectIndex	)
	SINASTNODE_DEFAULT_NODE_DEFS(CallMember		)
	SINASTNODE_DEFAULT_NODE_DEFS(CallIndex		)
	SINASTNODE_DEFAULT_NODE_DEFS(Return			)
	SINASTNODE_DEFAULT_NODE_DEFS(Semicolon		)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaParse		)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaPreserve	)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaEvaluate	)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaUnparse	)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaParseString)

} // namespace SIN