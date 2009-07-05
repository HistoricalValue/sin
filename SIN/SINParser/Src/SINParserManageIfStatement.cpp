#include "SINParserManageIfStatement.h"

namespace SIN{

	
	//---------------------------------------------------------------------

	void Manage_IfStatement_If (ASTNode *_expr, ASTNode *_stmt, ASTNode **_retifstmt){

		*_retifstmt = new ASTNode("if");

		**_retifstmt << _expr << _stmt;
	}
	
	//---------------------------------------------------------------------

	void Manage_IfStatement_IfElse	(ASTNode *_expr, ASTNode *_stmt1, ASTNode *_stmt2, ASTNode **_retifstmt){

		*_retifstmt = new ASTNode("if else");

		**_retifstmt << _expr << _stmt1 << _stmt2;
	}

} // namespace SIN