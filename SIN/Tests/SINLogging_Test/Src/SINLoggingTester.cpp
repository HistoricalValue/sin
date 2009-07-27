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
#include "SINAlloc.h"

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
				for (unsigned int i = 0; i < r.size(); ++i) {
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

			class IndicatorLogger: public Logger {
				String& ind;
			public:
				IndicatorLogger(String& _ind, String const& _name = "IndicatorLogger"):
				Logger(_name, Record::WARNING),
				ind(_ind)
				{ }
				void Message(Record const& _r) {
					if (shouldLog(_r.Severity()))
						ind << _r.Message();
				}
				void operator =(String &_ind) { ind = _ind; }
			};
			class IndicatorLoggerFactory: public LoggerManager::DefaultLoggerFactory {
				RecordPrinter rp;
				enum Record::Severity default_severity;
				InstanceProxy<RecordPrinter> rp_p;
				InstanceProxy<enum Record::Severity> default_severity_p;
				String& ind;
				Namer namer;
			public:
				IndicatorLoggerFactory(String& _ind):
				DefaultLoggerFactory(&rp_p, &default_severity_p),
				rp(VOIDOUT), default_severity(Record::WARNING),
				rp_p(&rp), default_severity_p(&default_severity),
				ind(_ind), namer("IndicatorLogger:")
				{ }

				Logger* MakeLogger(Type<String>::const_ref _name = "") {
					return SINEWCLASS(IndicatorLogger, (ind, _name == "" ? namer++ : _name));
				}
				void DestroyLogger(Logger* _logger) {
					SINDELETE(_logger);
				}
			};
			SINTESTS_TESTDEF(LoggerManager,
//			static void f(void) {
				if (!LoggerManager::SingletonCreated())
					LoggerManager::SingletonCreate();
				ASSERT(LoggerManager::SingletonCreated());
				Type<LoggerManager>::ref lm(*LoggerManager::SingletonGetInstance());
				//// Level 1: Test defaults
				enum Record::Severity default_severity = lm.GetDefaultSeverity();
				Logger *victim1 = lm.MakeVoidLogger("Maria");
				if (victim1 != 0x00) {
					ASSERT(victim1->GetCriticalSeverity() == default_severity);
					lm.GetDefaultLoggerFactory()->DestroyLogger(victim1);
				}
				String indicator("I'm empty, like a caramel\n");
				IndicatorLoggerFactory logger_factory(indicator);
				LoggerManager::DefaultLoggerFactory* prev_lf =
					lm.SetDefaultLoggerFactory(&logger_factory);
				ASSERT(lm.GetDefaultLoggerFactory() == &logger_factory);
				// The following statement creates a VoidLogger for the
				// logger named Eyanthia. The logger returned, though, is the
				// "previous" logger, which did not exist until now, and
				// therefore, will have been created with the DefaultLoggerFactory.
				// So, it should present the behaviour we expect because of
				// setting our own DefaultLoggerFactory.
				victim1 = lm.MakeVoidLogger("Eyanthia");
				ASSERT(victim1 != 0x00);
				String indicator_original(indicator);
				String msg1("\n\n +++++++ This should not be there ++++++ \n\n");
				String msg2("This will appear, it is a warning\n");
				String msg3("This will appear too, it's an error\n");
				victim1->Attention(msg1);
				ASSERT(indicator == indicator_original);
				victim1->Warning(msg2);
				ASSERT(indicator == indicator_original + msg2);
				victim1->Error(msg3);
				ASSERT(indicator == indicator_original + msg2 + msg3);
				logger_factory.DestroyLogger(victim1);
				lm.SetDefaultLoggerFactory(prev_lf);
				ASSERT(lm.GetDefaultLoggerFactory() == prev_lf);
				// Failing assertiong, to make sure assertions work.
				// To make correct, just add ! before the condition.
				ASSERT(!(indicator == indicator_original + msg1 + msg2 + msg3));
			)
//			}

			void test(InstanceProxy<TestFactory> const &tf) {
				logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Logging");
				test_factory = tf;
				SINTESTS_CALLTEST(Record);
				SINTESTS_CALLTEST(LoggerManager);
			}
		} // namespace Logging
	} // namespace Tests
} // namespace SIN
