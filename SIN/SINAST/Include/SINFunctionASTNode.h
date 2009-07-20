#ifndef __SIN_FUNCTION_AST_NODE_H__
#define __SIN_FUNCTION_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{
	
	class FunctionASTNode : public ASTNode {

	public:

		FunctionASTNode(void);
		FunctionASTNode(String const &name);
		virtual ~FunctionASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class FunctionASTNode

	class LamdaFunctionASTNode : public ASTNode {

	public:

		LamdaFunctionASTNode(void);
		LamdaFunctionASTNode(String const &name);
		virtual ~LamdaFunctionASTNode(void);

		virtual void Accept(ASTVisitor *) const;

	}; // class LamdaFunctionASTNode

} // namespace SIN

#endif //__SIN_BLOCK_AST_NODE_H__