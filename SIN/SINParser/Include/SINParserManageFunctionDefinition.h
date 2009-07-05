#ifndef __SIN_PARSER_MANAGE_FUNCTION_DEFINITION_H__
#define __SIN_PARSER_MANAGE_FUNCTION_DEFINITION_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_FunctionDefinition_Function			(char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef);
	void Manage_FunctionDefinition_LamdaFunction	(ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_FUNCTION_DEFINITION_H__