#ifndef __SIN_PARSER_MANAGE_MEMBER_H__
#define __SIN_PARSER_MANAGE_MEMBER_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Member_LValueID			(ASTNode *_lvalue, char *_id, ASTNode **_retmember);
	void Manage_Member_LValueExpression	(ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retmember);
	void Manage_Member_CallID			(ASTNode *_call, char *_id, ASTNode **_retmember);
	void Manage_Member_CallExpression	(ASTNode *_call, ASTNode *_expr, ASTNode **_retmember);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_MEMBER_H__