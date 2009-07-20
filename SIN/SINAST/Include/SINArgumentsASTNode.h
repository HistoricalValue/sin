#ifndef __SIN_ARGUMENTS_AST_NODE_H__
#define __SIN_ARGUMENTS_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{

	class ArgumentsASTNode : public ASTNode {
		public:

		ArgumentsASTNode(void);
		ArgumentsASTNode(String const &name);
		virtual ~ArgumentsASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class ArgumentsASTNode

} // namespace SIN

#endif //__SIN_ARGUMENTS_AST_NODE_H__