#ifndef __SIN_PARSER_MANAGE_CALL_SUFFIX_H__
#define __SIN_PARSER_MANAGE_CALL_SUFFIX_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_CallSuffix_NormalCall	(ASTNode *_normalcall, ASTNode **_retcallsuffix);
	void Manage_CallSuffix_MethodCall	(ASTNode *_methodcall, ASTNode **_retcallsuffix);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_CALL_SUFFIX_H__