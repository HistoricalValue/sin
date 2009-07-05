#ifndef __SIN_PARSER_MANAGE_TERM_H__
#define __SIN_PARSER_MANAGE_TERM_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Term_ExpressionParentheses	(ASTNode *_expr, ASTNode **_retterm);
	void Manage_Term_MINExpression			(ASTNode *_expr, ASTNode **_retterm);
	void Manage_Term_NOTExpression			(ASTNode *_expr, ASTNode **_retterm);
	void Manage_Term_INCRLValue				(ASTNode *_lvalue, ASTNode **_retterm);
	void Manage_Term_LValueINCR				(ASTNode *_lvalue, ASTNode **_retterm);
	void Manage_Term_DECRLValue				(ASTNode *_lvalue, ASTNode **_retterm);
	void Manage_Term_LValueDECR				(ASTNode *_lvalue, ASTNode **_retterm);
	void Manage_Term_Primary				(ASTNode *_primary, ASTNode **_retterm);

} // namespace SIN

#endif //__SIN_PARSER_Manage_Term_H__