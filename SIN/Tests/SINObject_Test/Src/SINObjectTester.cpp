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
				SinObject	obj1;
				SinObject	obj2;
				SinObject * obj_ptr;
				MemoryCellBool		bool_mc;
				MemoryCellNumber	number_mc;
				MemoryCellObject	object_mc;
				MemoryCellObject	object2_mc;

				bool_mc.SetValue(true);
				number_mc.SetValue(13);
				object_mc.SetValue(obj2);

				obj1.SetValue(&bool_mc);
				obj1.SetValue(&number_mc);
				obj1.SetValue(&object_mc);
				obj1.SetValue(std::make_pair("BOOL", &bool_mc));

				object2_mc.SetValue(obj1);
				obj1.SetValue(std::make_pair("SELF", &object2_mc));
				obj1.SetValue(&object2_mc);


				obj1.SetValue("hand", &number_mc);

				
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