#include "SINCommonTester.h"
#include "SINTest.h"
#include "SINConstants.h"
#include <cstring>
#include "SINOutputStream.h"
#include "SINTestingCommon.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "Common.h"

#define SINTESTSCOMMON_RUN(NAME)                SINTESTS_RUNTEST(NAME)
#define SINTESTSCOMMON_TESTDEF(NAME,TESTCODE)   SINTESTS_TESTDEF(NAME,TESTCODE)
#define SINTESTSCOMMON_TESTRUN(NAME)            SINTESTS_CALLTEST(NAME)

namespace SIN {
    namespace Tests {
        namespace Common {
            static InstanceProxy<Logger> logger;
			static InstanceProxy<TestFactory> test_factory;

            SINTESTSCOMMON_TESTDEF(Types,
                Number_t num;
                String_t str;
                Nil_t nil;
                Boolean_t bln;

                num = 12; ASSERT(num == 12); ASSERT(num + 1 == 13); ASSERT(num - 1 == 11);
                ASSERT(num++ == 12); ASSERT(num == 13); ASSERT(++num == 14); ASSERT(num == 14);
                ASSERT(num-- == 14); ASSERT(num == 13); ASSERT(--num == 12); ASSERT(num == 12);

                str = "18";
                ASSERT(str == str);
                ASSERT(str == String("18"));
                ASSERT(str == string_cast("18"));
                ASSERT(str == "18");
                ASSERT(str + "24" == "1824");
                ASSERT(str << "25" == "1825");
                ASSERT(str == "1825");
                ASSERT(strcmp(str.c_str(), "1825") == 0);
                ASSERT(strcmp(static_cast<String>(str).c_str(), str.c_str()) == 0);
                ASSERT(strcmp(String(str).c_str(), static_cast<std::string>(str.c_str()).c_str()) ==0);
                ASSERT(String(str) == "1825");
				String jon = "We live a beautiful life and then we die";
				ASSERT(jon.Erase(8,17) == "We live and then we die");
				ASSERT(jon.DropLast(7) + "..." == "We live and then...");

                ASSERT(nil == 0x00);

                bln = TRUE;
                ASSERT(bln == TRUE); ASSERT(!(bln == FALSE)); ASSERT(bln != FALSE); ASSERT(!bln == FALSE);
                bln = !bln;
                ASSERT(bln == FALSE); ASSERT(!(bln == TRUE)); ASSERT(bln != TRUE); ASSERT(!bln == TRUE);
            )

            void test(InstanceProxy<TestFactory> const &tf) {
                logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Common");
				test_factory = tf;
                SINTESTSCOMMON_TESTRUN(Types);
            }
        } // namespace Common
    } // namespace Tests
} // namespace SIN
