#ifndef __SIN_PARSER_MANAGE_EXPRESSION_H__
#define __SIN_PARSER_MANAGE_EXPRESSION_H__

#include "SINTypes.h"
#include "SINASTNode.h"

namespace SIN{

	ASTNode *Manage_Expression_AssignExpression			(ASTNode *_p1);
	ASTNode *Manage_Expression_ExpressionADDExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionMINExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionMULExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionDIVExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionMODExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionGTExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionGEExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionLTExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionLEExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionEQExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionNOTEQExpression(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionANDExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionORExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_ExpressionNOTExpression	(ASTNode *_p1, ASTNode *_p2);
	ASTNode *Manage_Expression_Term						(ASTNode *_p1);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_EXPRESSION_H__