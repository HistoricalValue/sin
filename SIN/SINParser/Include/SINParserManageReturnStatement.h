#ifndef __SIN_PARSER_MANAGE_RETURN_STATEMENT_H__
#define __SIN_PARSER_MANAGE_RETURN_STATEMENT_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_ReturnStatement_Return				(ASTNode **_retreturnstmt);
	void Manage_ReturnStatement_ReturnExpression	(ASTNode *_expr, ASTNode **_retreturnstmt);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_RETURN_STATEMENT_H__