#ifndef __SIN_COMMON_TESTER_H__
#define __SIN_COMMON_TESTER_H__

#include "SINTestFactory.h"

namespace SIN {
    namespace Tests {
        namespace Common {
            extern void test(InstanceProxy<TestFactory> const &);
        } // namespace Common
    } // namespace Tests
} // namespace SIN

#endif //__SIN_COMMON_TESTER_H__
