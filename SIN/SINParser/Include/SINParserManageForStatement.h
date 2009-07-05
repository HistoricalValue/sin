#ifndef __SIN_PARSER_MANAGE_FOR_STATEMENT_H__
#define __SIN_PARSER_MANAGE_FOR_STATEMENT_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_ForStatement	(ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_FOR_STATEMENT_H__