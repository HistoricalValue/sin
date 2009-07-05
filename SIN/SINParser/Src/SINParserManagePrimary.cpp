#include "SINParserManagePrimary.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINConstants.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Primary_LValue (ASTNode *_lvalue, ASTNode **_retprimary){

		*_retprimary = _lvalue;
	}

	//---------------------------------------------------------------------

	void Manage_Primary_Call (ASTNode *_call, ASTNode **_retprimary){

		*_retprimary = _call;
	}

	//---------------------------------------------------------------------

	void Manage_Primary_ObjectDefinition (ASTNode *_objectdef, ASTNode **_retprimary){
	
		*_retprimary = _objectdef;
	}

	//---------------------------------------------------------------------

	void Manage_Primary_FunctionDefinitionParentheses (ASTNode *_funcdef, ASTNode **_retprimary){
	
		*_retprimary = _funcdef;
	}

	//---------------------------------------------------------------------

	void Manage_Primary_Constant (ASTNode *_const, ASTNode **_retprimary){
	
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered primary : constant Rule");
		if(_retprimary == NULL)
			logger.Error("Const node is Nil");

		*_retprimary = _const;
	}

} // namespace SIN