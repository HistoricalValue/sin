#include "BisonParseArguments.h"

#include <algorithm>
#include <functional>



#include "Common.h"
#include "SINLogger.h"
#include "SINConstants.h"
#include "SINLoggerManager.h"



#define SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME "SIN::BisonParseArguments"


namespace SIN {


	//-----------------------------------------------------------------
	
	struct CleanListFunctor : public std::unary_function<ASTNode *, void> {
		void operator() (ASTNode * node) {
			delete node;
		}
	};



	//-----------------------------------------------------------------

	BisonParseArguments::BisonParseArguments(void) : 
		hasError(false), root(static_cast<ASTNode *>(0))
	{
		Type<LoggerManager>::ref lm(*LoggerManager::SingletonGetInstance());
		lm.GetDefaultLoggerFactory()->DestroyLogger(lm.MakeStdoutLogger(SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME));
		logger_p = lm.GetLogger(SIN_BISON_PARSE_ARGUMENTS_LOGGER_NAME);
	}
	
	
	//-----------------------------------------------------------------

	BisonParseArguments::~BisonParseArguments() 
		{ CleanErrosAndNodes(); }

	
	//-----------------------------------------------------------------

	bool BisonParseArguments::HasError() const 
		{ return hasError; }


	//-----------------------------------------------------------------
	void BisonParseArguments::SetError (const ErrorInfo & ei) {
		hasError = true;
		errors.push_back(ei);
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


	//-----------------------------------------------------------------
	
	void BisonParseArguments::CleanNodes (void) 
		{ std::for_each(nodesList.begin(), nodesList.end(), CleanListFunctor()); }

	
	//-----------------------------------------------------------------
	
	void BisonParseArguments::CleanErrors (void) 
		{ errors.clear(); }

	
	//-----------------------------------------------------------------
	
	void BisonParseArguments::CleanErrosAndNodes (void) {
		CleanNodes();
		CleanErrors();
	}

}	//namespace SIN