#include "SINTest.h"
#include <cstring>
#include <cstdio>
#include "SINNamer.h"

namespace SIN {
    namespace Tests {
        const char *Test::nextTestName(void) { // TODO fix static initialisation
            static Namer *namer = new Namer("Test:");
            return namer->Next();
        }

        Test::Test(String const &_name): name(_name), successful(true), 
        failure_message("No failure"), failed_condition("false"),
        failure_file("/dev/null"), failure_line(-1)
        {
        }

        Test::~Test(void) {
        }

        void Test::Run(void) {
            try {
                TestLogic();
            } catch(Test const *) {
            }
        }

        void Test::Fail(String const &message, String const &condition,
            String const &_file, unsigned long int _line
        ) {
            SetFailureFile(_file), SetFailureLine(_line), successful = false, failure_message = message,
                failed_condition = condition;
            throw this;
        }


        bool Test::Status(void) const {
            return successful;
        }

        String const &Test::Name(void) const {
            return name;
        }

        String const &Test::FailureMessage(void) const {
            return failure_message;
        }

        String const &Test::FailedCondition(void) const {
            return failed_condition;
        }

        String const &Test::GetFailureFile(void) const {
            return failure_file;
        }

        void Test::SetFailureFile(String const &_failure_file) {
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