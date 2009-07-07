#include "SINParserManageForStatement.h"

namespace SIN{

	
	//---------------------------------------------------------------------
	void Manage_ForStatement (ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt){

		*_retforstmt = new ASTNode("for");

		for(ASTNode *nxtExpr; _elist1 != NULL; _elist1 = nxtExpr){
			**_retforstmt << new ASTNode(*_elist1);
			nxtExpr = static_cast<ASTNode*>(+(*_elist1));
			delete _elist1;
		}
		**_retforstmt << _expr;
		for(ASTNode *nxtExpr; _elist2 != NULL; _elist2 = nxtExpr){
			**_retforstmt << new ASTNode(*_elist2);
			nxtExpr = static_cast<ASTNode*>(+(*_elist2));
			delete _elist2;
		}
		**_retforstmt << _stmt;
	}

} // namespace SIN