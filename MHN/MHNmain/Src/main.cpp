#include "MHNmain/WorldGreeter.h"
#include "MHN/VisitableTree.h"
#include "MHNMain/Testers.h"

int main(int argc, char *argv[]) {
    MHNMain::MHN_VisitableTree_Tester()();
    return MHNmain::WorldGreeter().Greet();
}
