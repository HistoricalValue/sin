#ifndef __BISON_PARSER_ARGUMENTS_H__
#define __BISON_PARSER_ARGUMENTS_H__


#include <list>

#include <utility>
#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"

namespace SIN {
		
		
	class BisonParseArguments {
	public:
		typedef std::list<ASTNode *>		NodesList;
		typedef std::pair<String, unsigned>	ErrorInfo;
		typedef std::list<ErrorInfo>		Errors;

		BisonParseArguments(void);
		~BisonParseArguments();


		bool	HasError () const;
		void	SetRoot (ASTNode *);
		void	SetError (const ErrorInfo &);
		void	WriteFine (const String &);
		void	AppendToNodeList (ASTNode *);
		

		void	CleanNodes (void);
		void	CleanErrors (void);
		void	CleanErrosAndNodes (void);
		
		


		ASTNode *		GetRoot (void) const;
		const Errors &	GetErros (void) const;
		

	private:
		bool		hasError;
		Errors		errors;
		ASTNode *	root;
		NodesList	nodesList;
		
		InstanceProxy<Logger> logger_p;

	};
}	//namespace SIN


#endif //__BISON_PARSER_ARGUMENTS_H__