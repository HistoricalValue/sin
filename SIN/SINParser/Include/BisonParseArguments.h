#ifndef __BISON_PARSER_ARGUMENTS_H__
#define __BISON_PARSER_ARGUMENTS_H__


#include <list>

#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"

namespace SIN {
		
		
	class BisonParseArguments {
	public:
		typedef std::list<String> Errors;
		
		BisonParseArguments(void);
		~BisonParseArguments();

		bool	HasError () const;
		void	SetError (const String &);
		void	WriteFine (const String &);

		
		void	SetRoot (ASTNode *);


		ASTNode *		GetRoot (void) const;
		const Errors &	GetErros (void) const;
		

	private:
		bool		hasError;
		Errors		errors;
		ASTNode *	root;

		InstanceProxy<Logger> logger_p;

	};
}	//namespace SIN


#endif //__BISON_PARSER_ARGUMENTS_H__