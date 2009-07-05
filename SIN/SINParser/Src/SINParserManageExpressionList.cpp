#include "SINParserManageExpressionList.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_ExpressionList (ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist){
	
		*_retelist = new ASTNode("elist");

		**_retelist << _expr << _elists;
	}

	//---------------------------------------------------------------------

	void Manage_ExpressionList_Empty(ASTNode **_retelist){
	
		*_retelist = new ASTNode("Empty expression list");
	}

} // namespace SIN