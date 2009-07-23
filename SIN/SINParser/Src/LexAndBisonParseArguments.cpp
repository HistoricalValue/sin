#include "LexAndBisonParseArguments.h"

#include <algorithm>
#include <functional>



#include "Common.h"
#include "SINLogger.h"
#include "SINConstants.h"
#include "SINLoggerManager.h"



#define SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME "SIN::LexAndBisonParseArguments"


namespace SIN {


	//-----------------------------------------------------------------
	
	struct CleanListFunctor : public std::unary_function<ASTNode *, void> {
		void operator() (ASTNode * node) {
			delete node;
		}
	};



	//-----------------------------------------------------------------

	LexAndBisonParseArguments::LexAndBisonParseArguments(void) : 
		hasError(false), root(static_cast<ASTNode *>(0))
	{
		Type<LoggerManager>::ref lm(*LoggerManager::SingletonGetInstance());
		lm.GetDefaultLoggerFactory()->DestroyLogger(lm.MakeStdoutLogger(SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME));
		logger_p = lm.GetLogger(SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME);
	}
	
	
	//-----------------------------------------------------------------

	LexAndBisonParseArguments::~LexAndBisonParseArguments() 
		{ CleanErrosAndNodes(); }

	
	//-----------------------------------------------------------------

	bool LexAndBisonParseArguments::HasError() const 
		{ return hasError; }


	//-----------------------------------------------------------------
	void LexAndBisonParseArguments::SetError (const ErrorInfo & ei) {
		hasError = true;
		errors.push_back(ei);
	}

	//-----------------------------------------------------------------
	
	void LexAndBisonParseArguments::WriteFine(const String & msg) 
		{ logger_p->Fine(msg);	}

	
	//-----------------------------------------------------------------
	
	void LexAndBisonParseArguments::SetRoot(ASTNode * node) 
		{ root = node; }


	//-----------------------------------------------------------------
	
	ASTNode * LexAndBisonParseArguments::GetRoot() const 
		{ return root; }


	//-----------------------------------------------------------------
	
	const LexAndBisonParseArguments::Errors &	LexAndBisonParseArguments::GetErrors() const 
		{ return errors; }


	//-----------------------------------------------------------------
	
	void LexAndBisonParseArguments::CleanNodes (void) 
		{ std::for_each(nodesList.begin(), nodesList.end(), CleanListFunctor()); }

	
	//-----------------------------------------------------------------
	
	void LexAndBisonParseArguments::CleanErrors (void) 
		{ errors.clear(); }

	
	//-----------------------------------------------------------------
	
	void LexAndBisonParseArguments::CleanErrosAndNodes (void) {
		CleanNodes();
		CleanErrors();
	}

}	//namespace SIN