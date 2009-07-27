#include "SINParserTester.h"


#include "Common.h"
#include "SINTest.h"
#include "SINLogger.h"
#include "SINASTNode.h"
#include "SINConstants.h"
#include "SINBufferedOutputStream.h"
#include "SINFileOutputStream.h"
#include "SINParserAPI.h"
#include "SINTestingCommon.h"
#include "SINLoggerManager.h"
#include "SINASTTreeVisualisationVisitor.h"
#include "SINASTMITTreeVisualizerXMLProducerVisitor.h"

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
			
			namespace { static void __list_parsing_errors(ParserAPI const& _papi) {
				for (
					LexAndBisonParseArguments::Errors::const_iterator ite = _papi.GetErrors().begin(),
						end = _papi.GetErrors().end();
					ite != end;
					++ite
				)
					logger->Error(string_cast("Parsing error: line ") << ite->second <<
						": " << ite->first);
			}}
			
			SIN_TESTS_PARSER_TESTDEF(ParserFileTest,
				ParserAPI test;
				TRY(test.ParseFile(FILE_PATH) == 0);
				if (test.HasError()) {
					__list_parsing_errors(test);
					ASSERT(!test.HasError()); // certain failure here, to stop the test
				}
				ASTNode* root = test.GetAST();
				ASSERT(root != 0x00);
				
				FileOutputStream _fout("treeVisualisation.txt", FileOutputStream::Mode::Truncate());
				FileOutputStream _foutxml("treeVisualisation.xml", FileOutputStream::Mode::Truncate());
				BufferedOutputStream fout(_fout);
				BufferedOutputStream foutxml(_foutxml);
				ASTTreeVisualisationVisitor visitor(fout);
				ASTMITTreeVisualizerXMLProducerVisitor mitvis(foutxml);
				root->Accept(&visitor);
				root->Accept(&mitvis);
			)

			void test(InstanceProxy<TestFactory> const &tf) { 
				logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser");
				test_factory = tf;
				SIN_TESTS_PARSER_TESTRUN(ParserFileTest);
			}
		}	//namespace Parser
	}		//namespace Tests
}			//namspace SIN