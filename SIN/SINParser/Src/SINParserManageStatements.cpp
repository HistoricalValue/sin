#include "SINParserManageStatements.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Statements(ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts){
	
		*_retstmts = _stmt;

		if(_stmts != NULL)
			(*_retstmts)->SetRightSibling(_stmts);
	}

	//---------------------------------------------------------------------

	void Manage_Statements_Empty(ASTNode **_retstmts){
	
		*_retstmts = NULL;
	}

} // namespace SIN