#include "MHNMain/Testers.h"
#include <cassert>

namespace MHNMain {
    // MHN_VisitorTree_Tester ////////////////////////////////
    void MHN_VisitableTree_Tester::operator ()(void) const {
        MHN::VisitableTree parent;
        // Test 1
        assert(parent.getParent() == 0x00);
        // Test 2
        assert(MHN::VisitableTree(&parent).getParent() == &parent);
        // Test 3
        MHN::VisitableTree().acceptVisitor(MHN::Visitor());
        // TODO add more tests
    }
    ////////////////////////////////
    ////////////////////////////////
    ////////////////////////////////
    ////////////////////////////////
    //MHN_VisitorTree_Tester  ////////////////////////////////
} // namespace MHNMain
