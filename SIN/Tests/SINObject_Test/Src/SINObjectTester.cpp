#include "SINObjectTester.h"

#include <utility>

#include "SINTest.h"
#include "Common.h"
#include "SINLogger.h"
#include "SINConstants.h"
#include "SINOutputStream.h"
#include "SINTestingCommon.h"
#include "SINLoggerManager.h"
#include "SINFileOutputStream.h"
#include "SINBufferedOutputStream.h"



#include "SINObject.h"
#include "SINMemoryCellAST.h"
#include "SINMemoryCellBool.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellObject.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellFunction.h"



#define SIN_TESTS_OBJECT_RUN(NAME)               SINTESTS_RUNTEST(NAME)
#define SIN_TESTS_OBJECT_TESTDEF(NAME,TESTCODE)  SINTESTS_TESTDEF(NAME,TESTCODE)
#define SIN_TESTS_OBJECT_TESTRUN(NAME)           SINTESTS_CALLTEST(NAME)



namespace SIN {
	namespace Tests {
		namespace OBJ {
			static InstanceProxy<SIN::Logger> logger;
			static InstanceProxy<TestFactory> test_factory;
			
	

			//------------------------------------------------------------------
			class TestingSinObjectTest : public Test {                
			public:                                         
				TestingSinObjectTest(void): Test("TestingSinObject" "Test") { }    
			protected:                                      
				virtual void TestLogic(void);
			};


			//------------------------------------------------------------------

			void TestingSinObjectTest::TestLogic(void) {
				SinObject			obj1;
				SinObject			obj2;
				SinObject *			obj_ptr;
				MemoryCellBool		bool_mc(true);
				MemoryCellNumber	number_mc(0.0);
				MemoryCellNumber	number1_mc(1.0);
				MemoryCellNumber	number2_mc(2.0);
				MemoryCellNumber	number3_mc(3.0);
				MemoryCellObject	object_mc(obj2);
				MemoryCellObject	object2_mc(obj1);				//we want to create a self refrance

				obj1.SetValue(&bool_mc);							// 0	: true
				obj1.SetValue(std::make_pair("1", &number1_mc));	// 1	: 1
				obj1.SetValue(std::make_pair("2", &number2_mc));	// 2	: 2
				obj1.SetValue(std::make_pair("3", &bool_mc));		// 3	: 3
				obj1.SetValue(&number_mc);							// 4	: 0
				obj1.SetValue(&object_mc);							// 5	: Object
				obj1.SetValue(std::make_pair("BOOL", &bool_mc));	// BOOL	: true
				obj1.SetValue(std::make_pair("SELF", &object2_mc));	// SELF	: self
				obj1.SetValue(&object2_mc);							// 6	: self
				obj1.SetValue("hand", &number_mc);					// hand : 0

				


				FileOutputStream _fout("objectTestOutput.txt", FileOutputStream::Mode::Truncate());
				BufferedOutputStream fout(_fout);
				fout << obj1.ToString();

				fout << "\n\n --------------- Keys ---------------\n\n";
				obj_ptr =  obj1.ObjectKeys();
				fout <<	obj_ptr->ToString();

				SINDELETE(obj_ptr);
			}


			//------------------------------------------------------------------
			static void test_TestingSinObject(void){
				SIN_TESTS_OBJECT_RUN(TestingSinObject);
			}


			//------------------------------------------------------------------

			void test(InstanceProxy<TestFactory> const &tf) { 
				logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::OBJ");
				test_factory = tf;
				SIN_TESTS_OBJECT_TESTRUN(TestingSinObject);
			}
		}	//namespace OBJ
	}		//namespace Tests
}			//namspace SIN