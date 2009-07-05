#include "SINParserManageNormalCall.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_NormalCall (ASTNode *_elist, ASTNode **_retnormalcall){

		*_retnormalcall = new ASTNode("()");

		**_retnormalcall << _elist;
	}

} // namespace SIN