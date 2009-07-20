#ifndef __SIN_ID_AST_NODE_H__
#define __SIN_ID_AST_NODE_H__

#include "SINASTNode.h"

namespace SIN{
	
	class IDASTNode : public ASTNode {

	public:

		IDASTNode(void);
		IDASTNode(String const &name);
		virtual ~IDASTNode(void);

		virtual void Accept(ASTVisitor *) const;
	}; // class IDASTNode

	class LocalIDASTNode : public ASTNode {

	public:

		LocalIDASTNode(void);
		LocalIDASTNode(String const &name);
		virtual ~LocalIDASTNode(void);

		virtual void Accept(ASTVisitor *) const;
	}; // class LocalIDASTNode

	class GlobalIDASTNode : public ASTNode {

	public:

		GlobalIDASTNode(void);
		GlobalIDASTNode(String const &name);
		virtual ~GlobalIDASTNode(void);

		virtual void Accept(ASTVisitor *) const;
	}; // class GlobalIDASTNode

} // namespace SIN

#endif //__SIN_ID_AST_NODE_H__