#include "SINParserManageConstant.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINString.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Constant_Number (int _number, ASTNode **_retconst){
	
		*_retconst = new NumberASTNode(_number);
	}

	//---------------------------------------------------------------------

	void Manage_Constant_String (char *_string, ASTNode **_retconst){
	
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered const : string Rule. String ") + SIN::String(_string));

		*_retconst = new StringASTNode(_string);
	}

	//---------------------------------------------------------------------

	void Manage_Constant_Nil (ASTNode **_retconst){
	
		*_retconst = new NilASTNode();
	}

	//---------------------------------------------------------------------

	void Manage_Constant_True (ASTNode **_retconst){
	
		*_retconst = new TrueASTNode();
	}

	//---------------------------------------------------------------------

	void Manage_Constant_False (ASTNode **_retconst){

	*_retconst = new FalseASTNode();
	}

} // namespace SIN