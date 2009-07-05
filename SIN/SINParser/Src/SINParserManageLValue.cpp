#include "SINParserManageLValue.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINString.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_LValue_ID (char *_ID, ASTNode **_retlvalue){

		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered lvalue : id Rule. ID = ") + SIN::String(_ID));

		*_retlvalue = new ASTNode(_ID);
	}

	//---------------------------------------------------------------------

	void Manage_LValue_LocalID (char *_localID, ASTNode **_retlvalue){
	
		*_retlvalue = new ASTNode(_localID);
	}

	//---------------------------------------------------------------------

	void Manage_LValue_GlobalID (char *_globalID, ASTNode **_retlvalue){
	
		*_retlvalue = new ASTNode(_globalID);
	}

	//---------------------------------------------------------------------

	void Manage_LValue_Member (ASTNode *_member, ASTNode **_retlvalue){
	
		*_retlvalue = _member;
	}

} // namespace SIN