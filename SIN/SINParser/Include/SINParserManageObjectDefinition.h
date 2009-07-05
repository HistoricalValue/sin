#ifndef __SIN_PARSER_MANAGE_OBJECT_DEFINITION_H__
#define __SIN_PARSER_MANAGE_OBJECT_DEFINITION_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_ObjectDefinition_EmptyObject	(ASTNode **_retobjectdef);
	void Manage_ObjectDefinition_ObjectList		(ASTNode *_objectlist, ASTNode **_retobjectdef);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_OBJECT_DEFINITION_H__