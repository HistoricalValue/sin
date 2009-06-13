/*
 *	Virtual Class
 */

#ifndef __SIN_AST_TREE_VISITOR_H__
#define __SIN_AST_TREE_VISITOR_H__


#include "SINASTNode.h"

namespace SIN {
	class ASTTreeVisitor { 
	public :

		virtual void VisitConst (ConstASTNode *) = 0;


		virtual ~ASTTreeVisitor() {}
	};
}


#endif __SIN_AST_TREE_VISITOR_H__