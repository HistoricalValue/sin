#ifndef __SP_SIN_PARSER_API_H__
#define __SP_SIN_PARSER_API_H__

#include <string>
#include <stdio.h>
#include <assert.h>
#include <iostream>


#include "SinParser.hpp"
extern int PrepareForFile(const char * filePath);
extern int yyparse();


namespace SP {	//SinParser

	class SinParserAPI {
	public:
		SinParserAPI (void) {}
		~SinParserAPI () {}

		int ParseFile (const std::string & fileName) {
			PrepareForFile(fileName.c_str());
			return yyparse();
		}

		//int ParseString ()
		
	private:



	};
}	//end of namespace SP

#endif //__SP_SIN_PARSER_API_H__