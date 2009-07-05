#ifndef __SIN_PARSER_MANAGE_STATEMENTS_H__
#define __SIN_PARSER_MANAGE_STATEMENTS_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Statements		(ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts);
	void Manage_Statements_Empty(ASTNode **_retstmts);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_STATEMENTS_H__