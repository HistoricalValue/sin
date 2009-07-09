#include "SINParserAPI.h"
#include <cassert>


#include "SINAssert.h"
#include "SINASTNode.h"

#include "SINParserBison.h"


// TODO those should be somewhere?
extern int PrepareForFile(const char * filePath);
extern int yyparse(void);
extern SIN::ASTNode * root;

namespace SIN {
    //--------------------------------------------------------

    ParserAPI::ParserAPI(void) {
    }



    //--------------------------------------------------------

    ParserAPI::~ParserAPI(void) {
    }
    

	
	//--------------------------------------------------------

    int ParserAPI::ParseFile(String const &_filepath) {
        if (PrepareForFile(_filepath.c_str()) == 0 && yyparse() == 0)
			return 0;
		return -1;
    }
    
	
	
	//--------------------------------------------------------
    
	int ParserAPI::ParseText(char const *_input) {
        assert(!"Not implemented yet");
        throw String("Not implemented yet");
        return 1;
    }


	// If Parse* returned no error, this returns the produced AST
	ASTNode * ParserAPI::GetAST(void) const {
		SINASSERT(root);
		return root;
	}


    ////////////////////////////////
} // namespace SIN
