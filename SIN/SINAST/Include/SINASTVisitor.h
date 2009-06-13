/*
 *	Virtual Class
 */

#ifndef __SIN_SIN_AST_VISITOR_H__
#define __SIN_SIN_AST_VISITOR_H__


#include "SINASTNode.h"

namespace SIN {
	class SINASTVisitor { 
	public :

		virtual void VisitLeaf (LeafASTNode *) = 0;
		virtual ~SINASTVisitor() {}
	};
}


#endif __SIN_SIN_AST_VISITOR_H__