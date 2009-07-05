#ifndef __SIN_PARSER_MANAGE_ID_LIST_H__
#define __SIN_PARSER_MANAGE_ID_LIST_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_IDList		(char *_id, ASTNode *_idlists, ASTNode **_retidlist);
	void Manage_IDList_Empty(ASTNode **_retidlist);

} // namespace SIN

#endif //__SIN_PARSER_MANAGE_ID_LIST_H__