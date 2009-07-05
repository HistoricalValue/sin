#include "SINParserManageMethodCall.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_MethodCall (char *_id, ASTNode *_elist, ASTNode **_retmethodcall){

		*_retmethodcall = new ASTNode("..method()");
		StringASTNode *id = new StringASTNode(_id);

		**_retmethodcall << id << _elist;
	}

} // namespace SIN