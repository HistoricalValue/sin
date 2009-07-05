#ifndef __SIN_PARSER_MANAGE_LVALUE_H__
#define __SIN_PARSER_MANAGE_LVALUE_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_LValue_ID		(char *_ID, ASTNode **_retlvalue);
	void Manage_LValue_LocalID	(char *_localID, ASTNode **_retlvalue);
	void Manage_LValue_GlobalID	(char *_globalID, ASTNode **_retlvalue);
	void Manage_LValue_Member	(ASTNode *_member, ASTNode **_retlvalue);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_LVALUE_H__