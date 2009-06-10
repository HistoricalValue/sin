#include "MHNmain/Testers.h"
#include <cassert>

namespace MHNMain {
    // MHN_VisitorTree_Tester ////////////////////////////////
#define NUM_TESTS 3
    struct Data {
        typedef bool (*test_t)(Data *);
        test_t tests[NUM_TESTS];
    };
    bool test000(Data *d) {
        // Test 0
        return(MHN::VisitableTree().getParent() == 0x00);
    }
    bool test001(Data *d) {
        MHN::VisitableTree parent;
        // Test 1
        return(MHN::VisitableTree(&parent).getParent() == &parent);
    }
    bool test002(Data *d) {
        // Test 2
        MHN::VisitableTree().acceptVisitor(MHN::Visitor());
        return true;
    }
    // TODO add more tests
    struct Data Data = {
        // tests
        {test000, test001, test002}
    };
    ////////////////////////////////
    MHN_VisitableTree_Tester *const MHN_VisitableTree_Tester::
        singleton_instance = new MHN_VisitableTree_Tester(&Data);
    ////////////////////////////////
    MHN_VisitableTree_Tester::MHN_VisitableTree_Tester(
        void *_data, std::ostream &_out
    ):
    data(_data), out(_out)
    { }
    ////////////////////////////////
    void MHN_VisitableTree_Tester::operator ()(void) const {
        struct Data &data(*static_cast<struct Data *>(this->data));
        register size_t i;
        for (i = 0; i < NUM_TESTS; ++i)
            if (!data.tests[i](&data))
                break;
        if (i == NUM_TESTS)
            out << "MHN_VisitableTree_Tester: ALL OK!" << std::endl;
        else
            out << "MHN_VisitableTree_Tester: test " << i << " failed." <<
                    std::endl;
    }
    ////////////////////////////////
    MHN_VisitableTree_Tester const &MHN_VisitableTree_Tester::GetInstance(void) {
        return *singleton_instance;
    }
    ////////////////////////////////
    ////////////////////////////////
    ////////////////////////////////
    //MHN_VisitorTree_Tester  ////////////////////////////////
} // namespace MHNMain
