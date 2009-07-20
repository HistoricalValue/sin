#ifndef __SIN_ASSIGN_AST_NODE_H__
#define __SIN_ASSIGN_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{
	
	class AssignASTNode : public ASTNode {

	public:

		AssignASTNode(void);
		AssignASTNode(String const &name);
		virtual ~AssignASTNode(void);

		virtual void Accept(ASTVisitor *) const;
	};

} // namespace SIN

#endif //__SIN_ASSIGN_AST_NODE_H__