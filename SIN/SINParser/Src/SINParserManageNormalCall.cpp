#include "SINParserManageNormalCall.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_NormalCall (ASTNode *_elist, ASTNode **_retnormalcall){

		*_retnormalcall = new ASTNode("()");

		for(ASTNode *nxtExpr; _elist != NULL; _elist = nxtExpr){
			**_retnormalcall << new ASTNode(*_elist);
			nxtExpr = static_cast<ASTNode*>(+(*_elist));
			delete _elist;
		}
	}

} // namespace SIN