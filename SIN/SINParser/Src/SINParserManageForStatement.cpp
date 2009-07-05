#include "SINParserManageForStatement.h"

namespace SIN{

	
	//---------------------------------------------------------------------
	void Manage_ForStatement (ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt){

		*_retforstmt = new ASTNode("for");

		**_retforstmt << _elist1 << _expr << _elist2 << _stmt;
	}

} // namespace SIN