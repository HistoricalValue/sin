#ifndef __SIN_PARSER_MANAGE_WHILE_STATEMENT_H__
#define __SIN_PARSER_MANAGE_WHILE_STATEMENT_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_WhileStatement	(ASTNode *_expr, ASTNode *_stmt, ASTNode **_retwhilestmt);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_WHILE_STATEMENT_H__