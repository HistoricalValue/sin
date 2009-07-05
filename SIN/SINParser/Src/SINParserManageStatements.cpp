#include "SINParserManageStatements.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Statements(ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts){
	
		*_retstmts = new ASTNode("Statements");

		**_retstmts << _stmt << _stmts;
	}

	//---------------------------------------------------------------------

	void Manage_Statements_Empty(ASTNode **_retstmts){
	
		*_retstmts = new ASTNode("Empty Statements");
	}

} // namespace SIN