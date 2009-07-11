#ifndef __SIN_PARSER_API_H__
#define __SIN_PARSER_API_H__

#include <string>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include "SINString.h"
#include "SINASTNode.h"

namespace SIN {

	class ParserAPI {
	public:
		ParserAPI(void);
		~ParserAPI();

		// return !=0 on error
		int		ParseFile(const String &_fileName);
        int		ParseText(const char *_input);
		bool	HasError(void) const { return hasError; }
		void	DeleteAST(void); //delete the fucking AST
		
		// If Parse* returned no error, this returns the produced AST
		ASTNode *GetAST(void) const;

		

	private:
		bool		hasError;	
		ASTNode *	root;

		
	}; // class ParserAPI

} // namespace SIN

#endif // __SIN_PARSER_API_H__

