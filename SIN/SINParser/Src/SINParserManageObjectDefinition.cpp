#include "SINParserManageObjectDefinition.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_ObjectDefinition_EmptyObject (ASTNode **_retobjectdef){

		*_retobjectdef = new ASTNode("Empty object");
	}

	//---------------------------------------------------------------------

	void Manage_ObjectDefinition_ObjectList (ASTNode *_objectlist, ASTNode **_retobjectdef){
	
		*_retobjectdef = new ASTNode("Object");

		**_retobjectdef << _objectlist;
	}

} // namespace SIN