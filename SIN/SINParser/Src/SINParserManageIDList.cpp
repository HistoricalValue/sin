#include "SINParserManageIDList.h"

namespace SIN{

	
	//---------------------------------------------------------------------

	void Manage_IDList (char *_id, ASTNode *_idlists, ASTNode **_retidlist){

		*_retidlist = new StringASTNode(_id);

		if(_idlists != NULL)
			(*_retidlist)->SetRightSibling(_idlists);
	}
	
	//---------------------------------------------------------------------

	void Manage_IDList_Empty(ASTNode **_retidlist){
	
		*_retidlist = NULL;
	}

} // namespace SIN