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
			bool stmtError;

			ParsingFalgs() : stmtError(true) {}
		} parsingFlags;



		struct ParsingCounters {
			int loops;
			int functions;
			int nextLamdaFunctionId;

			ParsingCounters() : loops(0), functions(0), nextLamdaFunctionId(0) {}
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
		void	DeleteNodesListAndNodes(void);
		
		
		void			SetFileName(const String &);
		const String	GetFileName(void) const;
		
		ASTNode *		GetRoot (void) const;
		const Errors &	GetErrors (void) const;
		
		//------------->  WARNING	<----------------//
		//YOU MUST TAKE THIS LIST AND DELETE ALL THE ELEMENTS AND AFTER THAT YOU MUST DELETE AND THE LIST.
		//LexAndBisonParseArguments DOES NOT DO THIS AUTOMATCILALLY.
		//IF YOU DO NOT DO THAT, YOU ARE GOING TO HAVE MEMORY LEAKS
		NodesList *		TakeNodesList(void);
		
		
	private:
		bool		hasError;
		Errors		errors;
		ASTNode *	root;
		NodesList *	nodesList;
		String		fileName;
		
		InstanceProxy<Logger> logger_p;

	};
}	//namespace SIN


#endif //__LEX_AND_BISON_PARSER_ARGUMENTS_H__
