#include "BisonParseArguments.h"


#include "Common.h"
#include "SINLogger.h"
#include "SINConstants.h"
#include "SINLoggerManager.h"



#define SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME "SIN::BisonParseArguments"


namespace SIN {

	//-----------------------------------------------------------------

	BisonParseArguments::BisonParseArguments(void) : 
		hasError(false), root(static_cast<ASTNode *>(0))
	{
		Type<LoggerManager>::ref lm(*LoggerManager::SingletonGetInstance());
		lm.GetDefaultLoggerFactory()->DestroyLogger(lm.MakeStdoutLogger(SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME));
		logger_p = lm.GetLogger(SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME);
	}
	
	
	//-----------------------------------------------------------------

	BisonParseArguments::~BisonParseArguments() { errors.clear(); }

	
	//-----------------------------------------------------------------

	bool BisonParseArguments::HasError() const 
		{ return hasError; }


	//-----------------------------------------------------------------
	
	void BisonParseArguments::SetError(const String & error) {
		hasError = true;
		errors.push_back(error);
	}


	//-----------------------------------------------------------------
	
	void BisonParseArguments::WriteFine(const String & msg) 
		{ logger_p->Fine(msg);	}

	
	//-----------------------------------------------------------------
	
	void BisonParseArguments::SetRoot(ASTNode * node) 
		{ root = node; }


	//-----------------------------------------------------------------
	
	ASTNode * BisonParseArguments::GetRoot() const 
		{ return root; }


	//-----------------------------------------------------------------
	
	const BisonParseArguments::Errors &	BisonParseArguments::GetErros() const 
		{ return errors; }



}	//namespace SIN