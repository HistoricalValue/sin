/*
 *	Virtual Class
 */

#ifndef __SIN_SIN_AST_VISITOR_H__
#define __SIN_SIN_AST_VISITOR_H__


#include "SINASTNode.h"
#include "SINASTCommon.h"

namespace SIN {
	class SINASTVisitor { 
	public :

		virtual void VisitAdd (AddASTNode *) = 0;
		virtual void VisitSub (SubASTNode *) = 0;
		virtual void VisitMul (MulASTNode *) = 0;
		virtual void VisitDiv (DivASTNode *) = 0;

		virtual ~SINASTVisitor() {}
	};
}


#endif __SIN_SIN_AST_VISITOR_H__