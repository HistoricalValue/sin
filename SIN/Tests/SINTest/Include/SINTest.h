#ifndef __SIN_TEST_H__
#define __SIN_TEST_H__

#include <string>

/** method-assert: must be run from inside a method of a Test */
#define ASSERT(COND) do{register bool cond=(COND); Assert(cond, #COND, __FILE__, __LINE__);}while(false)
/** method-fail: must be run from inside a method of a Test */
#define FAIL(MSG,COND) SetFailureFile(__FILE__); SetFailureLine(__LINE__); Fail(MSG, #COND);
/** method-try: must be run from inside a method of a Test */
#define TRY(COND) do{register bool cond=(COND); if (!cond) { FAIL("Condition failed",COND); }}while(false)

/** Simple test-definition: declares and defines a Test class which only implements TestLogic() */
#define TESTFOR(NAME, TESTCODE)                     \
    class NAME##Test : public Test {                \
    public:                                         \
        NAME##Test(void): Test(#NAME "Test") { }    \
        void TestLogic(void) { TESTCODE }           \
    };

namespace SIN {
    namespace Tests {

        class Test {
            std::string const name;
            bool successful;
            std::string failure_message;
            std::string failed_condition;
            std::string failure_file;
            unsigned long failure_line;

            static unsigned long int test_counter;
            static char const *nextTestName(void);
        protected:
            virtual void TestLogic(void) = 0;
        public:
            Test(std::string const &test_name = nextTestName());
            virtual ~Test(void);

            void Assert(
                bool cond,
                std::string const &cond_str,
                std::string const &file,
                unsigned int line);
            void Run(void);
            void Fail(std::string const &message = "", std::string const &condition = "");

            /** returns true if the test is successful (false if there are failures) */
            bool Status(void) const;
            std::string const &Name(void) const;
            std::string const &FailureMessage(void) const;
            std::string const &FailedCondition(void) const;

            std::string const &GetFailureFile(void) const;
            void SetFailureFile(std::string const&) ;
            unsigned long int  GetFailureLine(void) const;
            void  SetFailureLine(unsigned long int) ;
        }; // class Test

    } // namespace Tests
} // namespace SIN

#endif //__SIN_TEST_H__
