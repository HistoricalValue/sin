#include "SINmain/Testers.h"
#include <cassert>

namespace SINMain {
    // SIN_VisitorTree_Tester ////////////////////////////////
#define NUM_TESTS 4
    struct Data {
        typedef bool (*test_t)(Data *);
        test_t tests[NUM_TESTS];
    };
    bool test000(Data *d) {
        // Test 0
        return(SIN::VisitableTree().getParent() == 0x00);
    }
    bool test001(Data *d) {
        SIN::VisitableTree parent;
        // Test 1
        return(SIN::VisitableTree(&parent).getParent() == &parent);
    }
    bool test002(Data *d) {
        // Test 2
        SIN::VisitableTree().acceptVisitor(SIN::Visitor());
        return true;
    }
    bool test003(Data *d) {
        // Test 3
        SIN::VisitableTree parent, kid0(&parent), kid1(&parent), kid2(&parent);
        parent << &kid0 << &kid1 << &kid2;
        return
            &parent[0]              ==  &kid0   &&
            &parent[1]              ==  &kid1   &&
            &parent[2]              ==  &kid2   &&
            parent.numberOfKids()   ==  3
        ;
    }
    // TODO add more tests
    struct Data Data = {
        // tests
        {test000, test001, test002, test003}
    };
    ////////////////////////////////
    SIN_VisitableTree_Tester *const SIN_VisitableTree_Tester::
        singleton_instance = new SIN_VisitableTree_Tester(&Data);
    ////////////////////////////////
    SIN_VisitableTree_Tester::SIN_VisitableTree_Tester(
        void *_data, std::ostream &_out
    ):
    data(_data), out(_out)
    { }
    ////////////////////////////////
    void SIN_VisitableTree_Tester::operator ()(void) const {
        struct Data &data(*static_cast<struct Data *>(this->data));
        register size_t i;
        for (i = 0; i < NUM_TESTS; ++i)
            if (!data.tests[i](&data))
                break;
        if (i == NUM_TESTS)
            out << "SIN_VisitableTree_Tester: ALL OK!" << std::endl;
        else
            out << "SIN_VisitableTree_Tester: test " << i << " failed." <<
                    std::endl;
    }
    ////////////////////////////////
    SIN_VisitableTree_Tester const &SIN_VisitableTree_Tester::GetInstance(void) {
        return *singleton_instance;
    }
    ////////////////////////////////
    ////////////////////////////////
    ////////////////////////////////
    //SIN_VisitorTree_Tester  ////////////////////////////////
} // namespace SINMain
