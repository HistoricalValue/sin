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
#include "SINASTTreeVisualisationVisitor.h"
#include "SINASTMITTreeVisualizerXMLProducerVisitor.h"
#include "SINLibrary.h"
#include "SINLibraryFunction.h"
#include "SINLibraryFunctions.h"
#include "SINMemoryCellLibFunction.h"
#include "SINAlloc.h"
#include "SINShiftToMetaEvaluatorASTVisitor.h"
#include "SINShiftToMetaEvaluatorASTVisitor.h"


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
				//SIN::LoggerManager::StreamLogger oot("STDOUT: ", SIN::Logging::Record::FINEST, SIN::STDOUT, SIN::Logging::RecordPrinter());
				//oot.Notice(_msg);
				static_cast<OutputStream&>(STDOUT) << _msg;
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
				FileOutputStream _fouttxt("RunTreeVisualisation.txt", FileOutputStream::Mode::Truncate());
				FileOutputStream _metatxt("ShiftToMetaEvaluatorASTVisitor.txt", FileOutputStream::Mode::Truncate());

				BufferedOutputStream foutxml(_foutxml);
				BufferedOutputStream fouttxt(_fouttxt);
				BufferedOutputStream metatxt(_metatxt); 


				ASTTreeVisualisationVisitor				visitor(fouttxt);
				ASTTreeVisualisationVisitor				metaVisualVisitor(metatxt);
				ASTMITTreeVisualizerXMLProducerVisitor	mitvis(foutxml);
			
				
				ShiftToMetaEvaluatorASTVisitor metaVisitor;
				root->Accept(&metaVisitor);
				metaVisitor.Root()->Accept(&metaVisualVisitor);
				metaVisitor.DeleteAST();

				root->Accept(&visitor);
				root->Accept(&mitvis);
				foutxml.flush();
				fouttxt.flush();
				metatxt.flush();

				VM::VirtualState vs;
				vs.SetPrintHandler(&__print_handler);

				Library::Library lib;

				Library::Functions::print			print;
				Library::Functions::println			println;
				Library::Functions::arguments		arguments;
				Library::Functions::totalarguments	totalarguments;
				Library::Functions::tostring		tostring;
				Library::Functions::strtonum		strtonum;
				Library::Functions::typeof			typeof;
				Library::Functions::fileopen        fileopen;
				Library::Functions::fileread        fileread;
				
				lib.InstallFunction(&print			);
				lib.InstallFunction(&println		);
				lib.InstallFunction(&arguments		);
				lib.InstallFunction(&totalarguments	);
				lib.InstallFunction(&tostring		);
				lib.InstallFunction(&strtonum		);
				lib.InstallFunction(&typeof			);
				lib.InstallFunction(&fileopen       );
				lib.InstallFunction(&fileread       );

				// TODO remove the reference here and watch it burn 
				SymbolTable *globalSymTable = &vs.CurrentStable();
				globalSymTable->Insert("print",          SINEWCLASS(MemoryCellLibFunction, (&print)));
				globalSymTable->Insert("println",        SINEWCLASS(MemoryCellLibFunction, (&println)));
				globalSymTable->Insert("arguments",      SINEWCLASS(MemoryCellLibFunction, (&arguments)));
				globalSymTable->Insert("totalarguments", SINEWCLASS(MemoryCellLibFunction, (&totalarguments)));
				globalSymTable->Insert("tostring",       SINEWCLASS(MemoryCellLibFunction, (&tostring)));
				globalSymTable->Insert("strtonum",       SINEWCLASS(MemoryCellLibFunction, (&strtonum)));
				globalSymTable->Insert("typeof",         SINEWCLASS(MemoryCellLibFunction, (&typeof)));
				globalSymTable->Insert("fileopen",       SINEWCLASS(MemoryCellLibFunction, (&fileopen)));
				globalSymTable->Insert("fileread",       SINEWCLASS(MemoryCellLibFunction, (&fileread)));

				

				TreeEvaluationVisitor eval(&lib, &vs);
				root->Accept(&eval);

				ShiftToMetaEvaluatorASTVisitor shifter;
				root->Accept(&shifter);
				shifter.DeleteAST();

				test.DeleteAST();
				//ASTNode* metacode = shifter;
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
