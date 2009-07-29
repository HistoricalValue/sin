#include "SINParserAPI.h"
#include <cassert>

#include "Common.h"
#include "SINLogger.h"
#include "SINAssert.h"
#include "SINASTNode.h"
#include "SINConstants.h"
#include "SINParserBison.h"
#include "SINLoggerManager.h"







// TODO those should be somewhere?
extern int PrepareForFile(const char * filePath);
extern int yyparse(SIN::LexAndBisonParseArguments &);


namespace SIN {
    //--------------------------------------------------------

	ParserAPI::ParserAPI(void) {
    }



    //--------------------------------------------------------

    ParserAPI::~ParserAPI(void) {
    }
    

	
	//--------------------------------------------------------

    int ParserAPI::ParseFile(String const &_filepath) {
        if (PrepareForFile(_filepath.c_str()) == 0 && yyparse(fabpa) == 0)
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
		ASTNode * root = fabpa.GetRoot();
		SINASSERT(root);
		return fabpa.HasError() ? static_cast<ASTNode *>(0): root;
	}


	const LexAndBisonParseArguments::Errors & ParserAPI::GetErrors(void) const 
		{ return fabpa.GetErrors(); }


	void ParserAPI::DeleteAST(void) 
		{ fabpa.CleanNodes(); }

    ////////////////////////////////
} // namespace SIN
