#include "SINSymbolTableTester.h"


#include "Common.h"
#include "SINTest.h"
#include "SINLogger.h"
#include "SINASTNode.h"
#include "SINConstants.h"
#include "SINSymbolTable.h"
#include "SINTestingCommon.h"
#include "SINLoggerManager.h"
#include "SINFileOutputStream.h"
#include "SINASTTreeVisualisationVisitor.h"


#define SIN_TESTS_SYMBOL_TABLE_RUN(NAME)               SINTESTS_RUNTEST(NAME)
#define SIN_TESTS_SYMBOL_TABLE_TESTDEF(NAME,TESTCODE)  SINTESTS_TESTDEF(NAME,TESTCODE)
#define SIN_TESTS_SYMBOL_TABLE_TESTRUN(NAME)           SINTESTS_CALLTEST(NAME)



namespace SIN {
	namespace Tests {
		namespace ST {
			static InstanceProxy<SIN::Logger> logger;
			static InstanceProxy<TestFactory> test_factory;
			
			
			SIN_TESTS_SYMBOL_TABLE_TESTDEF(SymbolTableTest,
				SymbolTable st;

			)

			void test(InstanceProxy<TestFactory> const &tf) { 
				logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::ST");
				test_factory = tf;
				SIN_TESTS_SYMBOL_TABLE_TESTRUN(SymbolTableTest);
			}
		}	//namespace ST
	}		//namespace Tests
}			//namspace SIN