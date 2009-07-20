#include "SINIfASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

    ///--------- IfASTNode ---------
	//---------------------------------------------------
	
	IfASTNode::IfASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    IfASTNode::IfASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    IfASTNode::~IfASTNode(void) {}


	//---------------------------------------------------

    void IfASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- IfElseASTNode ---------
	//---------------------------------------------------
	
	IfElseASTNode::IfElseASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    IfElseASTNode::IfElseASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    IfElseASTNode::~IfElseASTNode(void) {}


	//---------------------------------------------------

    void IfElseASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN