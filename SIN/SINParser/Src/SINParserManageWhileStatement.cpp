#include "SINParserManageWhileStatement.h"

namespace SIN{

	
	//---------------------------------------------------------------------

	void Manage_WhileStatement (ASTNode *_expr, ASTNode *_stmt, ASTNode **_retwhilestmt){

		*_retwhilestmt = new ASTNode("while");

		**_retwhilestmt << _expr << _stmt;
	}

} // namespace SIN