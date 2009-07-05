#ifndef __SIN_PARSER_MANAGE_CALL_H__
#define __SIN_PARSER_MANAGE_CALL_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Call_CallCallSuffix						(ASTNode *_call, ASTNode *_callsuffix, ASTNode **_retcall);
	void Manage_Call_LValueCallSuffix					(ASTNode *_lvalue, ASTNode *_callsuffix, ASTNode **_retcall);
	void Manage_Call_FunctionDefinitionExpressionList	(ASTNode *_funcdef, ASTNode *_elist, ASTNode **_retcall);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_CALL_H__