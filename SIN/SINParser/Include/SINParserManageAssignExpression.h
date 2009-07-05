#ifndef __SIN_PARSER_MANAGE_ASSIGN_EXPRESSION_H__
#define __SIN_PARSER_MANAGE_ASSIGN_EXPRESSION_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_AssignExpression	(ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retassignexpr);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_ASSIGN_EXPRESSION_H__