#ifndef __SIN_IF_AST_NODE_H__
#define __SIN_IF_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{

	class IfASTNode : public ASTNode {
		public:

		IfASTNode(void);
		IfASTNode(String const &name);
		virtual ~IfASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class IfASTNode

	class IfElseASTNode : public ASTNode {
		public:

		IfElseASTNode(void);
		IfElseASTNode(String const &name);
		virtual ~IfElseASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class IfElseASTNode

} // namespace SIN

#endif //__SIN_IF_AST_NODE_H__