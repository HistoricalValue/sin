#ifndef __MHNMain__Testers_h__
#define __MHNMain__Testers_h__

#include "MHN/VisitableTree.h"
#include <iostream>

namespace MHNMain {
    class MHN_VisitableTree_Tester {
        void *data;
        std::ostream &out;
        static MHN_VisitableTree_Tester *const singleton_instance;
        MHN_VisitableTree_Tester(void *data, std::ostream &_out = std::cout);
        ~MHN_VisitableTree_Tester(void);
    public:
        static MHN_VisitableTree_Tester const &GetInstance(void);
        void operator()(void) const;
    }; // class MHN_VisitableTree_Tester
} // namespace MHNMain
#endif /* __MHNMain__Testers_h__ */