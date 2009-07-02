#ifndef __SIN_PARSER_API_H__
#define __SIN_PARSER_API_H__

#include <string>
#include <stdio.h>
#include <assert.h>
#include <iostream>
//#include "SINParser.h"
#include "SINString.h"

namespace SIN {

	class ParserAPI {
	public:
		ParserAPI(void);
		~ParserAPI();

		int ParseFile(const String &_fileName);
        int ParseText(const char *_input);
	}; // class ParserAPI

} // namespace SIN

#endif // __SIN_PARSER_API_H__

