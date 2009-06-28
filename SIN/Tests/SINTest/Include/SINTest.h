#ifndef __SIN_TEST_H__
#define __SIN_TEST_H__

#include "SINString.h"

/** method-fail: must be run from inside a method of a Test */
#define FAIL(MSG,COND) Fail(MSG, #COND, __FILE__, __LINE__)
/** method-try: must be run from inside a method of a Test */
#define TRY(COND) do{ register bool cond=(COND); if (!cond) FAIL("Condition failed",COND); } while(false)
/** method-assert: must be run from inside a method of a Test */
#define ASSERT(COND) do{ register bool cond=(COND); if (!cond) FAIL("Assertion failed",COND); } while(false)

/** Simple test-definition: declares and defines a Test class which only implements TestLogic() */
#define TESTFOR(NAME, TESTCODE)                     \
    class NAME##Test : public Test {                \
    public:                                         \
        NAME##Test(void): Test(#NAME "Test") { }    \
    protected:                                      \
        virtual void TestLogic(void) { TESTCODE }   \
    };

namespace SIN {
    namespace Tests {

        class Test {
            String const name;
            bool successful;
            String failure_message;
            String failed_condition;
            String failure_file;
            unsigned long failure_line;

            static char const *nextTestName(void);
        protected:
            virtual void TestLogic(void) = 0;
        public:
            Test(String const &test_name = nextTestName());
            virtual ~Test(void);

            void Run(void);
            void Fail(String const &message = "", String const &condition = "",
                String const &_file = "", unsigned long int _line = 0x00ul);

            /** returns true if the test is successful (false if there are failures) */
            bool Status(void) const;
            String const &Name(void) const;
            String const &FailureMessage(void) const;
            String const &FailedCondition(void) const;

            String const &GetFailureFile(void) const;
            void SetFailureFile(String const&) ;
            unsigned long int  GetFailureLine(void) const;
            void  SetFailureLine(unsigned long int) ;
        }; // class Test

    } // namespace Tests
} // namespace SIN

#endif //__SIN_TEST_H__
