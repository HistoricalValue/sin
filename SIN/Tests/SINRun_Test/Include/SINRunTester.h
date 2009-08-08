#ifndef __SIN_RUN_TESTER_H__
#define __SIN_RUN_TESTER_H__

#include "Common.h"
#include "SINTestFactory.h"

namespace SIN {
    namespace Tests {
        namespace Run {
            extern void test(InstanceProxy<TestFactory> const &);
        }
    }
}
#endif //__SIN_RUN_TESTER_H__
