#include "SINParserManageExpressionList.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_ExpressionList (ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist){
	
		*_retelist = _expr;

		if(_elists != NULL)
			(*_retelist)->SetRightSibling(_elists);
	}

	//---------------------------------------------------------------------

	void Manage_ExpressionList_Empty(ASTNode **_retelist){
	
		*_retelist = NULL;
	}

} // namespace SIN