#ifndef __SIN_UNARY_AST_NODE_H__
#define __SIN_UNARY_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{

	class PreIncrASTNode : public ASTNode {
		public:

		PreIncrASTNode(void);
		PreIncrASTNode(String const &name);
		virtual ~PreIncrASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class PreIncrASTNode

	class PostIncrASTNode : public ASTNode {
		public:

		PostIncrASTNode(void);
		PostIncrASTNode(String const &name);
		virtual ~PostIncrASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class PostIncrASTNode

	class PreDecrASTNode : public ASTNode {
		public:

		PreDecrASTNode(void);
		PreDecrASTNode(String const &name);
		virtual ~PreDecrASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class PreDecrASTNode

	class PostDecrASTNode : public ASTNode {
		public:

		PostDecrASTNode(void);
		PostDecrASTNode(String const &name);
		virtual ~PostDecrASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class PostDecrASTNode

	class UnaryNotASTNode : public ASTNode {
		public:

		UnaryNotASTNode(void);
		UnaryNotASTNode(String const &name);
		virtual ~UnaryNotASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class UnaryNotASTNode

	class UnaryMinASTNode : public ASTNode {
		public:

		UnaryMinASTNode(void);
		UnaryMinASTNode(String const &name);
		virtual ~UnaryMinASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class UnaryMinASTNode

} // namespace SIN

#endif //__SIN_UNARY_AST_NODE_H__