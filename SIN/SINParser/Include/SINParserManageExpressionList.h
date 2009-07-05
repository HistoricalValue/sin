#ifndef __SIN_PARSER_MANAGE_EXPRESSION_LIST_H__
#define __SIN_PARSER_MANAGE_EXPRESSION_LIST_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_ExpressionList		(ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist);
	void Manage_ExpressionList_Empty(ASTNode **_retelist);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_EXPRESSION_LIST_H__