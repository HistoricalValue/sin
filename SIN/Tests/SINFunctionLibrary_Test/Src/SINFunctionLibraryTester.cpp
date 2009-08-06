#include "SINFunctionLibraryTester.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINTestingCommon.h"

namespace SIN {
    namespace Tests {
        namespace FunctionLibrary {
			InstanceProxy<Logger> logger;
			InstanceProxy<TestFactory> tf;

			class FunctionLibraryTest: public Test {
			public:
				FunctionLibraryTest(void): Test("FunctionLibraryTest" "Test") { }
			protected:
				virtual void TestLogic(void) {

				}
			}; // class FunctionLibraryTest

            void test(InstanceProxy<TestFactory> const& _tf) {
				tf = _tf;
				logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::FunctionLibrary");
				SINTESTS_RUNTEST(FunctionLibrary);
			}
        } // namespace Common
    } // namespace Tests
} // namespace SIN
