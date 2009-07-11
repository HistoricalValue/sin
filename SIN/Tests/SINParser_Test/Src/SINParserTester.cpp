#include "SINParserTester.h"


#include "Common.h"
#include "SINTest.h"
#include "SINLogger.h"
#include "SINASTNode.h"
#include "SINConstants.h"
#include "SINFileOutputStream.h"
#include "SINParserAPI.h"
#include "SINTestingCommon.h"
#include "SINLoggerManager.h"
#include "SINASTTreeVisualisationVisitor.h"


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
			static InstanceProxy<TestFactory> test_factory;
			
			
			SIN_TESTS_PARSER_TESTDEF(ParserFileTest,
				ParserAPI test;
				TRY(test.ParseFile(FILE_PATH) == 0);
				ASTNode * root = test.GetAST();
				FileOutputStream fout("treeVisualisation.txt", FileOutputStream::Truncate);
				ASTTreeVisualisationVisitor visitor(fout);
				root->Accept(&visitor);

			)

			void test(InstanceProxy<TestFactory> const &tf) { 
				logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser");
				test_factory = tf;
				SIN_TESTS_PARSER_TESTRUN(ParserFileTest);
			}
		}	//namespace Parser
	}		//namespace Tests
}			//namspace SIN