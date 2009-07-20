#include "SINArgumentsASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

	//---------------------------------------------------
	
	ArgumentsASTNode::ArgumentsASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    ArgumentsASTNode::ArgumentsASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    ArgumentsASTNode::~ArgumentsASTNode(void) {}


	//---------------------------------------------------

    void ArgumentsASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }

} // namespace SIN