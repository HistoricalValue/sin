#include "SINParserManageObjectDefinition.h"
#include "SINLoggerManager.h"
#include "SINLogger.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_ObjectDefinition_EmptyObject (ASTNode **_retobjectdef){

		*_retobjectdef = new ASTNode("Empty object");
	}

	//---------------------------------------------------------------------

	void Manage_ObjectDefinition_ObjectList (ASTNode *_objectlist, ASTNode **_retobjectdef){
	
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered objectdef : [ objectlist ] Rule");

		*_retobjectdef = new ASTNode("Object");

		for(ASTNode *nxtObject; _objectlist != NULL; _objectlist = nxtObject){
			**_retobjectdef << new ASTNode(*_objectlist);
			nxtObject = static_cast<ASTNode*>(+(*_objectlist));
			delete _objectlist;
		}
	}

} // namespace SIN