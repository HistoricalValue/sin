#include "SINParserTester.h"
#include "SINParserAPI.h"
#include "SINTest.h"
#include "SINLoggerManager.h"
#include "SINLogger.h"
#include "Common.h"
#include "SINTestingCommon.h"
#include "SINConstants.h"


#define SIN_TESTS_PARSER_RUN(NAME)               SINTESTS_RUNTEST(NAME)
#define SIN_TESTS_PARSER_TESTDEF(NAME,TESTCODE)  SINTESTS_TESTDEF(NAME,TESTCODE)
#define SIN_TESTS_PARSER_TESTRUN(NAME)           SINTESTS_CALLTEST(NAME)


#ifdef _MSC_VER
	#define FILE_PATH	".\\..\\..\\..\\Tests\\SINParser_Test\\Resource\\sin_grammar_test.sin"
#else
	#define FILE_PATH	"./../../../Tests/SINParser_Test/Resource/sin_grammar_test.sin"
#endif

namespace SIN {
	namespace Tests {
		namespace Parser {
			static InstanceProxy<SIN::Logger> logger;
			
			
			SIN_TESTS_PARSER_TESTDEF(ParserFileTest,
				ParserAPI test;
				TRY(test.ParseFile(FILE_PATH) == 0);
			)

			void test(void) { 
				logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser");
				SIN_TESTS_PARSER_TESTRUN(ParserFileTest);
			}
		}	//namespace Parser
	}		//namespace Tests
}			//namspace SIN