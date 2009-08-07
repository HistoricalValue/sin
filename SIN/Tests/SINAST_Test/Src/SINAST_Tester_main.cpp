#include "SINASTTester.h"
#include "Common.h"
#include "SINLogger.h"
#include "SINTestFactory.h"
#include "SINLoggerManager.h"
#include "SINTestingCommon.h"

namespace SIN {
    namespace Tests {
        namespace AST {
			static InstanceProxy<Logger> logger;
			static InstanceProxy<TestFactory> test_factory;

			extern void test_StrictTreeNode(void);
			extern void test_AST(InstanceProxy<TestFactory> const &tf);

            void test(InstanceProxy<TestFactory> const &tf) {
                logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::AST");
				test_factory = tf;
				SINTESTS_CALLTEST(StrictTreeNode);
				LoggerManager::SingletonGetInstance()->GetDefaultLoggerFactory()->DestroyLogger(logger);
			}
		}
	}
}
