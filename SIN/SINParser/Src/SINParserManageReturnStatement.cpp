#include "SINParserManageReturnStatement.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_ReturnStatement_Return (ASTNode **_retreturnstmt){
	
		*_retreturnstmt = new ASTNode("return");
	}

	//---------------------------------------------------------------------

	void Manage_ReturnStatement_ReturnExpression (ASTNode *_expr, ASTNode **_retreturnstmt){
	
		*_retreturnstmt = new ASTNode("return expr");

		**_retreturnstmt << _expr;
	}
} // namespace SIN