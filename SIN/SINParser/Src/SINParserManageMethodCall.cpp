#include "SINParserManageMethodCall.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_MethodCall (char *_id, ASTNode *_elist, ASTNode **_retmethodcall){

		*_retmethodcall = new ASTNode("..method()");
		StringASTNode *id = new StringASTNode(_id);

		**_retmethodcall << id;
		for(ASTNode *nxtExpr; _elist != NULL; _elist = nxtExpr){
			**_retmethodcall << new ASTNode(*_elist);
			nxtExpr = static_cast<ASTNode*>(+(*_elist));
			delete _elist;
		}
	}

} // namespace SIN