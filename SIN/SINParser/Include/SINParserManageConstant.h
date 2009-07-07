#ifndef __SIN_PARSER_MANAGE_CONSTANT_H__
#define __SIN_PARSER_MANAGE_CONSTANT_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Constant_Number	(double _number, ASTNode **_retconst);
	void Manage_Constant_String	(char *_string, ASTNode **_retconst);
	void Manage_Constant_Nil	(ASTNode **_retconst);
	void Manage_Constant_True	(ASTNode **_retconst);
	void Manage_Constant_False	(ASTNode **_retconst);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_CONSTANT_H__