#include "SINFunctionASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{
	
	///--------- FunctionASTNode ---------
	//---------------------------------------------------
	
	FunctionASTNode::FunctionASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    FunctionASTNode::FunctionASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    FunctionASTNode::~FunctionASTNode(void) {}


	//---------------------------------------------------

    void FunctionASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

    ///--------- LamdaFunctionASTNode ---------
	//---------------------------------------------------
	
	LamdaFunctionASTNode::LamdaFunctionASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    LamdaFunctionASTNode::LamdaFunctionASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    LamdaFunctionASTNode::~LamdaFunctionASTNode(void) {}


	//---------------------------------------------------

    void LamdaFunctionASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN