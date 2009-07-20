#include "SINLoopASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

    ///--------- ForASTNode ---------
	//---------------------------------------------------
	
	ForASTNode::ForASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    ForASTNode::ForASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    ForASTNode::~ForASTNode(void) {}


	//---------------------------------------------------

    void ForASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- WhileASTNode ---------
	//---------------------------------------------------
	
	WhileASTNode::WhileASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    WhileASTNode::WhileASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    WhileASTNode::~WhileASTNode(void) {}


	//---------------------------------------------------

    void WhileASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN