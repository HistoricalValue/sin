#ifndef __SIN_PARSER_MANAGE_OBJECT_LIST_H__
#define __SIN_PARSER_MANAGE_OBJECT_LIST_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_ObjectList_ExpressionObjectLists			(ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists);
	void Manage_ObjectList_ExpressionExpressionObjectLists	(ASTNode *_expr1, ASTNode *_expr2, ASTNode *_objectlists, ASTNode **_retobjectlists);
	void Manage_ObjectList_Empty							(ASTNode **_retobjectlists);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_OBJECT_LIST_H__