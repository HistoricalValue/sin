#ifndef __SIN_AST_NODE_H__
#define __SIN_AST_NODE_H__


#include "SINTreeNode.h"

class ASTTreeVisitor;	//forward declaration

namespace SIN {


	///--------------------------------------------
	class ASTNode : public TreeNode {
	public :
		
		//Constructor and destructor 
		ASTNode (void) : TreeNode {}
		virtual ~ASTNode() {}

		virtual void Accept(ASTTreeVisitor *) = 0;
		
	};


	
	///--------------------------------------------
	class ConstASTNode : public ASTNode {
	public:

		//Constructor and destructor 
		ConstASTNode (void) : TreeNode {}
		virtual ~ ConstASTNode() {};


		virtual void Accept(ASTTreeVisitor *);
		
	};



} // namespace SIN


#endif //__SIN_AST_NODE_H__