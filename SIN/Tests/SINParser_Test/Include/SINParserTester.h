#ifndef __SIN_PARSER_TESTER_H__
#define __SIN_PARSER_TESTER_H__

#include "Common.h"
#include "SINTestFactory.h"

namespace SIN {
    namespace Tests {
        namespace Parser {
            extern void test(InstanceProxy<TestFactory> const &);
        }
    }
}
#endif //__SIN_PARSER_TESTER_H__
