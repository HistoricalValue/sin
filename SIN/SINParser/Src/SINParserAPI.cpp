#include "SINParserAPI.h"
#include <cassert>

	#include "Common.h"
	#include "SINLogger.h"
	#include "SINConstants.h"
	#include "SINLoggerManager.h"
#include "SINAssert.h"
#include "SINASTNode.h"

#include "SINParserBison.h"


// TODO those should be somewhere?
extern int PrepareForFile(const char * filePath);
extern int yyparse(bool, SIN::Logger & logger, SIN::ASTNode **);


namespace SIN {
    //--------------------------------------------------------

	ParserAPI::ParserAPI(void) : hasError(false){
    }



    //--------------------------------------------------------

    ParserAPI::~ParserAPI(void) {
    }
    

	
	//--------------------------------------------------------

    int ParserAPI::ParseFile(String const &_filepath) {
		SIN::Logger * logger = &SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::ParserAPI->Parser");
        if (PrepareForFile(_filepath.c_str()) == 0 && yyparse(hasError, *logger, &root) == 0)
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
		return hasError ? static_cast<ASTNode *>(0): root;
	}


    ////////////////////////////////
} // namespace SIN
