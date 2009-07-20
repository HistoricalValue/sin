#include "SINIDASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

    ///--------- IDASTNode ---------
	//---------------------------------------------------
	
	IDASTNode::IDASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    IDASTNode::IDASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    IDASTNode::~IDASTNode(void) {}


	//---------------------------------------------------

    void IDASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- LocalIDASTNode ---------
	//---------------------------------------------------
	
	LocalIDASTNode::LocalIDASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    LocalIDASTNode::LocalIDASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    LocalIDASTNode::~LocalIDASTNode(void) {}


	//---------------------------------------------------

    void LocalIDASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

	///--------- GlobalIDASTNode ---------
	//---------------------------------------------------
	
	GlobalIDASTNode::GlobalIDASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    GlobalIDASTNode::GlobalIDASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    GlobalIDASTNode::~GlobalIDASTNode(void) {}


	//---------------------------------------------------

    void GlobalIDASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN