#include "SINParserAPI.h"
#include <cassert>

// TODO those should be somewhere?
//extern int PrepareForFile(const char * filePath);
//extern int yyparse(void);

namespace SIN {
    ////////////////////////////////
    ParserAPI::ParserAPI(void) {
    }
    ////////////////////////////////
    ParserAPI::~ParserAPI(void) {
    }
    ////////////////////////////////
    int ParserAPI::ParseFile(String const &_filepath) {
        return 0;
            //PrepareForFile(_filepath.c_str()) == 0 &&
           // yyparse() == 0
            //? 0 : 1;
    }
    ////////////////////////////////
    int ParserAPI::ParseText(char const *_input) {
        assert(!"Not implemented yet");
        throw String("Not implemented yet");
        return 1;
    }
    ////////////////////////////////
} // namespace SIN
