#ifndef __SIN_PARSER_API_H__
#define __SIN_PARSER_API_H__

#include <string>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include "SINParser.h"


namespace SIN {

	class ParserAPI {
	public:
		ParserAPI(void);
		~ParserAPI();

		int ParseFile(const std::string &_fileName);
        int ParseText(const std::string &_input);
	}; // class ParserAPI

} // namespace SIN

#endif // __SIN_PARSER_API_H__
