#include "SINParserManageFunctionDefinition.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_FunctionDefinition_Function (char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef){
	
		*_retfuncdef = new ASTNode("Function");
		StringASTNode *id = new StringASTNode(_id);

		**_retfuncdef << id;	// To remove(No need to keep function names after we use unique IDs)
		for(ASTNode *nxtID; _idlist != NULL; _idlist = nxtID){
			**_retfuncdef << new ASTNode(*_idlist);
			nxtID = static_cast<ASTNode*>(+(*_idlist));
			delete _idlist;
		}
		**_retfuncdef << _block;
	}

	//---------------------------------------------------------------------

	void Manage_FunctionDefinition_LamdaFunction (ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef){
	
		*_retfuncdef = new ASTNode("Lamda Function");

		for(ASTNode *nxtID; _idlist != NULL; _idlist = nxtID){
			**_retfuncdef << new ASTNode(*_idlist);
			nxtID = static_cast<ASTNode*>(+(*_idlist));
			delete _idlist;
		}
		**_retfuncdef << _block;
	}

} // namespace SIN