#ifndef __SIN_LOOP_AST_NODE_H__
#define __SIN_LOOP_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{

	class ForASTNode : public ASTNode {
		public:

		ForASTNode(void);
		ForASTNode(String const &name);
		virtual ~ForASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class ForASTNode

	class WhileASTNode : public ASTNode {
		public:

		WhileASTNode(void);
		WhileASTNode(String const &name);
		virtual ~WhileASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class WhileASTNode

} // namespace SIN

#endif //__SIN_LOOP_AST_NODE_H__