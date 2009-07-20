#include "SINAssignASTNode.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"

namespace SIN{

	//---------------------------------------------------
	
	AssignASTNode::AssignASTNode(void):	ASTNode() {}


	//---------------------------------------------------

    AssignASTNode::AssignASTNode(String const &_name): ASTNode(_name) {}


	//---------------------------------------------------

    AssignASTNode::~AssignASTNode(void) {}


	//---------------------------------------------------

    void AssignASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }
	
} // namespace SIN