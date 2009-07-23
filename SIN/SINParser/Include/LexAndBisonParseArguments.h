#ifndef __LEX_AND_BISON_PARSER_ARGUMENTS_H__
#define __LEX_AND_BISON_PARSER_ARGUMENTS_H__


#include <list>

#include <utility>
#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"

namespace SIN {
		
		
	class LexAndBisonParseArguments {
	public:
		typedef std::list<ASTNode *>		NodesList;
		typedef std::pair<String, unsigned>	ErrorInfo;
		typedef std::list<ErrorInfo>		Errors;

		LexAndBisonParseArguments(void);
		~LexAndBisonParseArguments();


		bool	HasError () const;
		void	SetRoot (ASTNode *);
		void	SetError (const ErrorInfo &);
		void	WriteFine (const String &);
		void	AppendToNodeList (ASTNode *);
		

		void	CleanNodes (void);
		void	CleanErrors (void);
		void	CleanErrosAndNodes (void);
		
		


		ASTNode *		GetRoot (void) const;
		const Errors &	GetErrors (void) const;
		

	private:
		bool		hasError;
		Errors		errors;
		ASTNode *	root;
		NodesList	nodesList;
		
		InstanceProxy<Logger> logger_p;

	};
}	//namespace SIN


#endif //__LEX_AND_BISON_PARSER_ARGUMENTS_H__