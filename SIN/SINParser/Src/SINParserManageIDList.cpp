#include "SINParserManageIDList.h"

namespace SIN{

	
	//---------------------------------------------------------------------

	void Manage_IDList (char *_id, ASTNode *_idlists, ASTNode **_retidlist){

		StringASTNode *id = new StringASTNode(_id);
		*_retidlist = new ASTNode("idlist");

		**_retidlist << id << _idlists;
	}
	
	//---------------------------------------------------------------------

	void Manage_IDList_Empty(ASTNode **_retidlist){
	
		*_retidlist = new ASTNode("EMpty idlist");
	}

} // namespace SIN