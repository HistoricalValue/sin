#include "SINParserManageSinCode.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_SinCode	(ASTNode *_stmts, ASTNode **_retsincode){
	
		*_retsincode = new ASTNode("AST");

		for(ASTNode *nxtStmt; _stmts != NULL; _stmts = nxtStmt){
			**_retsincode << new ASTNode(*_stmts);
			nxtStmt = static_cast<ASTNode*>(+(*_stmts));
			delete _stmts;
		}
	}

} // namespace SIN