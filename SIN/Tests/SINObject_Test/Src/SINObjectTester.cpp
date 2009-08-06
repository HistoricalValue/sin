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


#include "SINAlloc.h"
#include "SINObject.h"
#include "SINASTNode.h"
#include "SINFunction.h"
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
				ASTNode	node("Testing");
				Types::Object *	obj1 = SINEW(Types::Object);
				Types::Object *	obj2 = SINEW(Types::Object);
				Types::Object *	obj3 = SINEW(Types::Object);
				


				MemoryCellObject *	object1_mc	= SINEW(MemoryCellObject);
				MemoryCellObject *	object2_mc	= SINEW(MemoryCellObject);
				MemoryCellObject *	object3_mc	= SINEW(MemoryCellObject);
				
				
				obj1->IncrementReferenceCounter();
				obj2->IncrementReferenceCounter();
				obj3->IncrementReferenceCounter();

				obj1->SetValue(SINEW(MemoryCellBool(true)));							// 0		: true
				obj1->SetValue("1", SINEWCLASS(MemoryCellNumber, (1.0)));				// 1		: 1
				obj1->SetValue("2", SINEWCLASS(MemoryCellNumber, (2.0)));				// 2		: 2
				obj1->SetValue(SINEWCLASS(MemoryCellNumber, (0.0)));					// 3		: 0
				obj1->SetValue("NUMBER", SINEWCLASS(MemoryCellNumber, (3.0)));			// NUMBER	: 0
				
				Types::Function function(&node);
				obj1->SetValue("function", SINEWCLASS(MemoryCellFunction, (&function)));	//function	: Tsting
				
				
				//Now we will try ti create a cycle inside the first object
				object1_mc->SetValue(obj1);
				object2_mc->SetValue(obj2);
				object3_mc->SetValue(obj3);

				obj1->SetValue(object2_mc);										// 4 : object(1){...}
				//obj2->SetValue(object3_mc);
				obj2->SetValue(object1_mc);				//uncomment this if you wont to create cycle
								
				FileOutputStream _fout("objectTestOutput.txt", FileOutputStream::Mode::Truncate());
				BufferedOutputStream fout(_fout);
				fout << obj1->ToString();

				fout << "\n\n --------------- Keys ---------------\n\n";
				Types::Object * obj_ptr =  obj1->ObjectKeys();
				fout <<	obj_ptr->ToString();


				fout << "\n\n --------------- clone keys ---------------\n\n";
				Types::Object * obj_ptr_clone =  obj_ptr->Clone();
				fout <<	obj_ptr_clone->ToString();
				
				obj_ptr->MarckedForDeletion();
				obj_ptr_clone->MarckedForDeletion();
				SINDELETE(obj_ptr);
				SINDELETE(obj_ptr_clone);
				SINDELETE(object1_mc);
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