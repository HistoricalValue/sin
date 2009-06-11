#ifndef __SINMain__Testers_h__
#define __SINMain__Testers_h__

#include "SIN/VisitableTree.h"
#include <iostream>

namespace SINMain {
    class SIN_VisitableTree_Tester {
        void *data;
        std::ostream &out;
        static SIN_VisitableTree_Tester *const singleton_instance;
        SIN_VisitableTree_Tester(void *data, std::ostream &_out = std::cout);
        ~SIN_VisitableTree_Tester(void);
    public:
        static SIN_VisitableTree_Tester const &GetInstance(void);
        void operator()(void) const;
    }; // class SIN_VisitableTree_Tester
} // namespace SINMain
#endif /* __SINMain__Testers_h__ */