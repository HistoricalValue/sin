#ifndef __SIN_CALL_AST_NODE_H__
#define __SIN_CALL_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{

	class NormalCallASTNode : public ASTNode {
		public:

		NormalCallASTNode(void);
		NormalCallASTNode(String const &name);
		virtual ~NormalCallASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class NormalCallASTNode

	class MethodCallASTNode : public ASTNode {

	public:

		MethodCallASTNode(void);
		MethodCallASTNode(String const &name);
		virtual ~MethodCallASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class MethodCallASTNode

	class FuncdefCallASTNode : public ASTNode {

	public:

		FuncdefCallASTNode(void);
		FuncdefCallASTNode(String const &name);
		virtual ~FuncdefCallASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class FuncdefCallASTNode

} // namespace SIN

#endif //__SIN_CALL_AST_NODE_H__