#include "SINParserManageFunctionDefinition.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_FunctionDefinition_Function (char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef){
	
		*_retfuncdef = new ASTNode("Function");
		StringASTNode *id = new StringASTNode(_id);

		**_retfuncdef << id << _idlist << _block;
	}

	//---------------------------------------------------------------------

	void Manage_FunctionDefinition_LamdaFunction (ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef){
	
		*_retfuncdef = new ASTNode("Lamda Function");

		**_retfuncdef << _idlist << _block;
	}

} // namespace SIN