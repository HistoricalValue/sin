#include "SINParserManageObjectList.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_ObjectList_ExpressionObjectLists (ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists){
	
		*_retobjectlists = new ASTNode("Unindexed Object");

		**_retobjectlists << _expr;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	}

	//---------------------------------------------------------------------

	void Manage_ObjectList_ExpressionExpressionObjectLists (ASTNode *_expr1, ASTNode *_expr2, ASTNode *_objectlists, ASTNode **_retobjectlists){
	
		*_retobjectlists = new ASTNode("Indexed Object");

		**_retobjectlists << _expr1 << _expr2;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	}

	//---------------------------------------------------------------------

	void Manage_ObjectList_Empty (ASTNode **_retobjectlists){
	
		*_retobjectlists = NULL;
	}

} // namespace SIN