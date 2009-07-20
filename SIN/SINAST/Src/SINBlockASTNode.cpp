#include "SINBlockASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

	//---------------------------------------------------
	
	BlockASTNode::BlockASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    BlockASTNode::BlockASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    BlockASTNode::~BlockASTNode(void) {}


	//---------------------------------------------------

    void BlockASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN