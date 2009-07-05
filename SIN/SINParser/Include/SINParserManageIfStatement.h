#ifndef __SIN_PARSER_MANAGE_IF_STATEMENT_H__
#define __SIN_PARSER_MANAGE_IF_STATEMENT_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_IfStatement_If		(ASTNode *_expr, ASTNode *_stmt, ASTNode **_retifstmt);
	void Manage_IfStatement_IfElse	(ASTNode *_expr, ASTNode *_stmt1, ASTNode *_stmt2, ASTNode **_retifstmt);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_IF_STATEMENT_H__