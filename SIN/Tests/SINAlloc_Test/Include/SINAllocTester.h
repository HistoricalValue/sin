#ifndef __SIN_ALLOC_TESTER_H__
#define __SIN_ALLOC_TESTER_H__

#include "SINTestFactory.h"
#include "SINLogger.h"

namespace SIN {
    namespace Tests {
        namespace Alloc {
			extern void test(InstanceProxy<TestFactory> const&, InstanceProxy<Logger> const&);
        }
    }
}
#endif // __SIN_ALLOC_TESTER_H__
