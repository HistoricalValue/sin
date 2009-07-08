#include "SINLoggingTester.h"
#include <iostream>
#include "SINTest.h"
#include "SINRecord.h"
#include <vector>
#include "SINOutputStream.h"
#include "SINString.h"
#include "SINConstants.h"
#include "SINTestingCommon.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "Common.h"

namespace SIN {
    namespace Tests {
        namespace Logging {
            static InstanceProxy<Logger> logger;
			static InstanceProxy<TestFactory> test_factory;
            using SIN::Logging::Record;

            SINTESTS_TESTDEF(Record,
                Record r00(Record::CreateRecord(Record::FINEST, "This is FINEST"));
                Record r01(Record::CreateRecord(Record::FINER, "This is FINER"));
                Record r02(Record::CreateRecord(Record::FINE, "This is FINE"));
                Record r03(Record::CreateRecord(Record::NOTICE, "This is NOTICE"));
                Record r04(Record::CreateRecord(Record::ATTENTION, "This is ATTENTION"));
                Record r05(Record::CreateRecord(Record::WARNING, "This is WARNING"));
                Record r06(Record::CreateRecord(Record::SERIOUS, "This is SERIOUS"));
                Record r07(Record::CreateRecord(Record::ERROR, "This is ERROR"));
                Record r08(Record::CreateRecord(Record::FATALITY, "This is FATALITY"));
                //Record r09(Record::CreateRecord(Record::NOTHING, "This is NOTHING"));
                std::vector<Record> r(SIN_LOGGING_RECORD_NUMBER_OF_SEVERITIES, r00);
                r[ 0] = r00; r[ 1] = r01; r[ 2] = r02; r[ 3] = r03; r[ 4] = r04;
                r[ 5] = r05; r[ 6] = r06; r[ 7] = r07; r[ 8] = r08;
                for (register unsigned int i = 0; i < r.size(); ++i) {
                    if (i < r.size() - 1 && !(r[i] < r[i + 1]))
                        Fail(String("r[") << i << "] >= r[" << (i + 1) <<
                                "]", "r[i] < r[i + 1]", __FILE__, __LINE__);
                    else if(!(r[i] == r[i]))
                        Fail(String("r[") << i << "] does not equal itself",
                            "r[i] == r[i]", __FILE__, __LINE__);
                    else if (r[i] != r[i])
                        Fail(String("r[") << i << "] does not equal itself",
                        "!(r[i] != r[i])", __FILE__, __LINE__);
                    if (!(r[i].Message() == String("This is ") << r[i].Severity()))
                        Fail(String("r[") << i << "].Message(){\"" << r[i].Message()
                                << "\"} != \"" << String("This is ") << r[i].Severity() << '"',
                                "r[i].Message() == String(\"This is \") << r[i].Severity()",
                                __FILE__, __LINE__);
                }
            )

            void test(InstanceProxy<TestFactory> const &tf) {
                logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Logging");
				test_factory = tf;
                SINTESTS_CALLTEST(Record);
            }
        } // namespace Logging
    } // namespace Tests
} // namespace SIN
