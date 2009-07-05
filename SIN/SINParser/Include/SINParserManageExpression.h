#ifndef __SIN_PARSER_MANAGE_EXPRESSION_H__
#define __SIN_PARSER_MANAGE_EXPRESSION_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Expression_AssignExpression				(ASTNode *_assignexpr, ASTNode **_retexpr);
	void Manage_Expression_ExpressionADDExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionMINExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionMULExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionDIVExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionMODExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionGTExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionGEExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionLTExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionLEExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionEQExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionNOTEQExpression	(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionANDExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionORExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_ExpressionNOTExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
	void Manage_Expression_MetaExpression				(ASTNode *_metaexpr, ASTNode **_retexpr);
	void Manage_Expression_Term							(ASTNode *_term, ASTNode **_retexpr);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_EXPRESSION_H__