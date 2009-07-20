#include "SINCallASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

    ///--------- NormalCallASTNode ---------
	//---------------------------------------------------
	
	NormalCallASTNode::NormalCallASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    NormalCallASTNode::NormalCallASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    NormalCallASTNode::~NormalCallASTNode(void) {}


	//---------------------------------------------------

    void NormalCallASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- MethodCallASTNode ---------
	//---------------------------------------------------
	
	MethodCallASTNode::MethodCallASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    MethodCallASTNode::MethodCallASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    MethodCallASTNode::~MethodCallASTNode(void) {}


	//---------------------------------------------------

    void MethodCallASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

	///--------- FuncdefASTNode ---------
	//---------------------------------------------------
	
	FuncdefCallASTNode::FuncdefCallASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    FuncdefCallASTNode::FuncdefCallASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    FuncdefCallASTNode::~FuncdefCallASTNode(void) {}


	//---------------------------------------------------

    void FuncdefCallASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN