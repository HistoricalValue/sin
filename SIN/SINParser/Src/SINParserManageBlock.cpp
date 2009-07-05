#include "SINParserManageBlock.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Block (ASTNode *_stmtd, ASTNode **_retblock){
	
		*_retblock = new ASTNode("BLock"); //Probably useless

		**_retblock << _stmtd;
	}

} // namespace SIN