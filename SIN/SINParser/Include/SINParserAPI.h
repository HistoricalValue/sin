#ifndef __SIN_PARSER_API_H__
#define __SIN_PARSER_API_H__

#include <string>
#include <stdio.h>
#include <assert.h>
#include <iostream>


#include "SINParser.h"
extern int PrepareForFile(const char * filePath);
extern int yyparse();


namespace SIN {

	class ParserAPI {
	public:
		ParserAPI (void) {}
		~ParserAPI () {}

		int ParseFile (const std::string & fileName) {
			PrepareForFile(fileName.c_str());
			return yyparse();
		}

		//int ParseString ()
		
	private:

	}; // class ParserAPI

} // namespace SIN

#endif // __SIN_PARSER_API_H__

