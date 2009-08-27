#ifndef __LEX_AND_BISON_PARSER_ARGUMENTS_H__
#define __LEX_AND_BISON_PARSER_ARGUMENTS_H__


#include <list>

#include <utility>
#include "SINString.h"
#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"

namespace SIN {
		
		
	class LexAndBisonParseArguments {
	public:
		typedef std::list<ASTNode *>		NodesList;
		typedef std::pair<String, unsigned>	ErrorInfo;
		typedef std::list<ErrorInfo>		Errors;

		LexAndBisonParseArguments(const String & _fileName = "");
		~LexAndBisonParseArguments();



		struct ParsingFalgs {
			bool	onFunctionDef;

			ParsingFalgs() : onFunctionDef (false) {}
		} parsingFlags;



		struct ParsingCounters {
			int loops;

			ParsingCounters() : loops (0) {}
		} parsingCounters;



		bool	HasError () const;
		void	SetRoot (ASTNode *);
		void	SetError (const ErrorInfo &);
		void	WriteFine (const String &);
		void	AppendToNodeList (ASTNode *);
		bool	RemoveNodeFromList(ASTNode *);

		

		void	CleanNodes (void);
		void	CleanErrors (void);
		void	CleanErrosAndNodes (void);
		
		
		void			SetFileName(const String &);
		const String	GetFileName(void) const;
		
		ASTNode *		GetRoot (void) const;
		const Errors &	GetErrors (void) const;
		

	private:
		bool		hasError;
		Errors		errors;
		ASTNode *	root;
		NodesList	nodesList;
		String		fileName;
		
		InstanceProxy<Logger> logger_p;

	};
}	//namespace SIN


#endif //__LEX_AND_BISON_PARSER_ARGUMENTS_H__
