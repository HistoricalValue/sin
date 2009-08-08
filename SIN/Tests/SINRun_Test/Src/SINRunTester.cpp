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
#include "SINLibrary.h"
#include "SINLibraryFunction.h"
#include "SINLibraryFunctions.h"
#include "SINMemoryCellLibFunction.h"
#include "SINAlloc.h"

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

			static void __print_handler(SIN::String const& _msg) {
				SIN::LoggerManager::StreamLogger oot("STDOUT: ", SIN::Logging::Record::FINEST, SIN::STDOUT, SIN::Logging::RecordPrinter());
				oot.Notice(_msg);
			}



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

				VM::VirtualState vm;
				vm.SetPrintHandler(&__print_handler);

				Library::Library lib;

				Library::Functions::print			print;
				Library::Functions::println			println;
				Library::Functions::arguments		arguments;
				Library::Functions::totalarguments	totalarguments;
				Library::Functions::tostring		tostring;
				Library::Functions::strtonum		strtonum;
				Library::Functions::typeof			typeof;
				
				lib.InstallFunction(&print			);
				lib.InstallFunction(&println		);
				lib.InstallFunction(&arguments		);
				lib.InstallFunction(&totalarguments	);
				lib.InstallFunction(&tostring		);
				lib.InstallFunction(&strtonum		);
				lib.InstallFunction(&typeof			);

				// TODO remove the reference here and watch it burn 
				SymbolTable globalSymTable = static_cast<SinCodeASTNode*>(root)->getSymbolTable();
				globalSymTable.SetLocal("print",			SINEWCLASS(MemoryCellLibFunction, (&print)));
				globalSymTable.SetLocal("println",			SINEWCLASS(MemoryCellLibFunction, (&println)));
				globalSymTable.SetLocal("arguments",		SINEWCLASS(MemoryCellLibFunction, (&arguments)));
				globalSymTable.SetLocal("totalarguments",	SINEWCLASS(MemoryCellLibFunction, (&totalarguments)));
				globalSymTable.SetLocal("tostring",			SINEWCLASS(MemoryCellLibFunction, (&tostring)));
				globalSymTable.SetLocal("strtonum",			SINEWCLASS(MemoryCellLibFunction, (&strtonum)));
				globalSymTable.SetLocal("typeof",			SINEWCLASS(MemoryCellLibFunction, (&typeof)));

				TreeEvaluationVisitor eval(&lib, &vm);
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