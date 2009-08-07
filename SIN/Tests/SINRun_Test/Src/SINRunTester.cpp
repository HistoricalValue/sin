#include "SINRunTester.h"


#include "Common.h"
#include "SINTest.h"
#include "SINLogger.h"
#include "SINASTNode.h"
#include "SINConstants.h"
#include "SINParserAPI.h"
#include "SINTestingCommon.h"
#include "SINLoggerManager.h"
#include "SINFileOutputStream.h"
#include "SINBufferedOutputStream.h"
#include "SINTreeEvaluationVisitor.h"
#include "SINPreserveASTEvaluatorVisitor.h"
#include "SINASTMITTreeVisualizerXMLProducerVisitor.h"

#define SIN_TESTS_RUN_RUN(NAME)               SINTESTS_RUNTEST(NAME)
#define SIN_TESTS_RUN_TESTDEF(NAME,TESTCODE)  SINTESTS_TESTDEF(NAME,TESTCODE)
#define SIN_TESTS_RUN_TESTRUN(NAME)           SINTESTS_CALLTEST(NAME)


#ifdef _MSC_VER
	#define FILE_PATH	".\\..\\..\\..\\Tests\\SINRun_Test\\Resource\\sin_run_test.sin"
#else
	#define FILE_PATH	"./../../../Tests/SINRun_Test/Resource/sin_run_test.sin"
#endif


namespace SIN {
	namespace Tests {
		namespace Run {
			static InstanceProxy<SIN::Logger> logger;
			static InstanceProxy<TestFactory> test_factory;
			
			namespace { static void __list_parsing_errors(ParserAPI const& _papi) {
				for (
					LexAndBisonParseArguments::Errors::const_iterator ite = _papi.GetErrors().begin(),
						end = _papi.GetErrors().end();
					ite != end;
					++ite
				)
					logger->Error(to_string("Parsing error: line ") << ite->second <<
						": " << ite->first);
			}}


			//------------------------------------------------------------------
			class RunFileTest : public Test {                
			public:                                         
				RunFileTest(void): Test("RunFileTest") { }    
			protected:                                      
				virtual void TestLogic(void);
			};


			//------------------------------------------------------------------

			void RunFileTest::TestLogic(void) {
				ParserAPI test;
				TRY(test.ParseFile(FILE_PATH) == 0);
				if (test.HasError()) {
					__list_parsing_errors(test);
					ASSERT(!test.HasError()); // certain failure here, to stop the test
				}
				ASTNode* root = test.GetAST();
				ASSERT(root != 0x00);
				
				FileOutputStream _foutxml("RunTreeVisualisation.xml", FileOutputStream::Mode::Truncate());
				BufferedOutputStream foutxml(_foutxml);
				ASTMITTreeVisualizerXMLProducerVisitor mitvis(foutxml);
				root->Accept(&mitvis);
				
				TreeEvaluationVisitor eval;
				root->Accept(&eval);
			}


			//------------------------------------------------------------------
			static void test_RunFile(void){
				SINTESTS_RUNTEST(RunFile);
			}


			//------------------------------------------------------------------

			void test(InstanceProxy<TestFactory> const &tf) { 
				logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Run");
				test_factory = tf;
				SIN_TESTS_RUN_TESTRUN(RunFile);
				LoggerManager::SingletonGetInstance()->GetDefaultLoggerFactory()->DestroyLogger(logger);
			}
		}	//namespace Parser
	}		//namespace Tests
}			//namspace SIN