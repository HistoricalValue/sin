#include "SINTest.h"
#include <cstring>
#include <cstdio>

#define SINTESTS_DEFAULT_TEST_NAME_BASE "SIN::Tests::Test#"
#define ULONG_MAX_STR "4294967295"

namespace SIN {
    namespace Tests {
        unsigned long int Test::test_counter = 0x00ul;
        const char *Test::nextTestName(void) {
            static char next_name[] = SINTESTS_DEFAULT_TEST_NAME_BASE ULONG_MAX_STR;
            static const size_t base_offset = strlen(SINTESTS_DEFAULT_TEST_NAME_BASE);
            static const size_t max_num_len = strlen(ULONG_MAX_STR);
            sprintf(next_name + base_offset, "%0*lu", max_num_len, test_counter++);
            return next_name;
        }

        Test::Test(std::string const &_name): name(_name) {
        }

        Test::~Test(void) {
        }

        void Test::Run(void) {
            try {
                TestLogic();
            } catch(Test *) {
            }
        }

        void Test::Fail(std::string const &message, std::string const &condition,
            std::string const &_file, unsigned long int _line
        ) {
            SetFailureFile(_file), SetFailureLine(_line), successful = false, failure_message = message,
                failed_condition = condition;
            throw this;
        }


        bool Test::Status(void) const {
            return successful;
        }

        std::string const &Test::Name(void) const {
            return name;
        }

        std::string const &Test::FailureMessage(void) const {
            return failure_message;
        }

        std::string const &Test::FailedCondition(void) const {
            return failed_condition;
        }

        std::string const &Test::GetFailureFile(void) const {
            return failure_file;
        }

        void Test::SetFailureFile(std::string const &_failure_file) {
            failure_file = _failure_file;
        }

        unsigned long int  Test::GetFailureLine(void) const {
            return failure_line;
        }

        void  Test::SetFailureLine(unsigned long int _failure_line) {
            failure_line = _failure_line;
        }

    } // namespace Tests
} // namespace SIN