#ifndef __SIN_PARSER_MANAGE_PRIMARY_H__
#define __SIN_PARSER_MANAGE_PRIMARY_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Primary_LValue							(ASTNode *_lvalue, ASTNode **_retprimary);
	void Manage_Primary_Call							(ASTNode *_call, ASTNode **_retprimary);
	void Manage_Primary_ObjectDefinition				(ASTNode *_objectdef, ASTNode **_retprimary);
	void Manage_Primary_FunctionDefinitionParentheses	(ASTNode *_funcdef, ASTNode **_retprimary);
	void Manage_Primary_Constant						(ASTNode *_const, ASTNode **_retprimary);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_ASSIGN_EXPRESSION_H__