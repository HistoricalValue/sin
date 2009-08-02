#ifndef __SIN__TESTINGCOMMONS_H__
#define __SIN__TESTINGCOMMONS_H__

#include "SINConstants.h"
#include "SINTest.h"
#include <ctime>

namespace SIN {

#define SINTESTS_RUNTEST(NAME)                                                                      \
    NAME##Test __test_##NAME;                                                                       \
    __test_##NAME.Run();                                                                            \
    String test_result_str;                                                                         \
    test_result_str << __test_##NAME.Name() << ":  ";                                               \
    if (__test_##NAME.Status())                                                                     \
        test_result_str << "ok";                                                                    \
    else                                                                                            \
        test_result_str << "FAIL'D:" <<                                                             \
        __test_##NAME.GetFailureFile() << ':' << __test_##NAME.GetFailureLine() <<                  \
        ": " << __test_##NAME.FailureMessage() << " [" << __test_##NAME.FailedCondition()           \
        << "]";																						\
    logger->Notice(test_result_str);

#define SINTESTS_TESTDEF(NAME,TESTCODE) \
    static void test_##NAME(void) { TESTFOR(NAME, TESTCODE); SINTESTS_RUNTEST(NAME); }
#define SINTESTS_CALLTEST(NAME)   \
    test_##NAME();

#define TIME(CALL) do {	\
	clock_t start, end;	\
	start = clock();	\
	CALL;				\
	end = clock();		\
	logger->Fine(string_cast(#CALL) << " took " << (static_cast<double>(end - start) / CLOCKS_PER_SEC) << "sec");	\
	} while(false);

} // namespace SIN

#endif //__SIN__TESTINGCOMMONS_H__
