#include "SINParserManageBlock.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Block (ASTNode *_stmtd, ASTNode **_retblock){
	
		*_retblock = new ASTNode("BLock"); //Probably useless

		for(ASTNode *nxtStmt; _stmtd != NULL; _stmtd = nxtStmt){
			**_retblock << new ASTNode(*_stmtd);
			nxtStmt = static_cast<ASTNode*>(+(*_stmtd));
			delete _stmtd;
		}
	}

} // namespace SIN