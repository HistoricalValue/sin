#include "SINUnaryASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

    ///--------- PreIncrASTNode ---------
	//---------------------------------------------------
	
	PreIncrASTNode::PreIncrASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    PreIncrASTNode::PreIncrASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    PreIncrASTNode::~PreIncrASTNode(void) {}


	//---------------------------------------------------

    void PreIncrASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- PostIncrASTNode ---------
	//---------------------------------------------------
	
	PostIncrASTNode::PostIncrASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    PostIncrASTNode::PostIncrASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    PostIncrASTNode::~PostIncrASTNode(void) {}


	//---------------------------------------------------

    void PostIncrASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- PreDecrASTNode ---------
	//---------------------------------------------------
	
	PreDecrASTNode::PreDecrASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    PreDecrASTNode::PreDecrASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    PreDecrASTNode::~PreDecrASTNode(void) {}


	//---------------------------------------------------

    void PreDecrASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- PostDecrASTNode ---------
	//---------------------------------------------------
	
	PostDecrASTNode::PostDecrASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    PostDecrASTNode::PostDecrASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    PostDecrASTNode::~PostDecrASTNode(void) {}


	//---------------------------------------------------

    void PostDecrASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- UnaryNotASTNode ---------
	//---------------------------------------------------
	
	UnaryNotASTNode::UnaryNotASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    UnaryNotASTNode::UnaryNotASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    UnaryNotASTNode::~UnaryNotASTNode(void) {}


	//---------------------------------------------------

    void UnaryNotASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- UnaryMinASTNode ---------
	//---------------------------------------------------
	
	UnaryMinASTNode::UnaryMinASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    UnaryMinASTNode::UnaryMinASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    UnaryMinASTNode::~UnaryMinASTNode(void) {}


	//---------------------------------------------------

    void UnaryMinASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN