#include "SINmain/WorldGreeter.h"
#include "SIN/VisitableTree.h"
#include "SINmain/Testers.h"

int main(int argc, char *argv[]) {
    SINMain::SIN_VisitableTree_Tester::GetInstance()();
    return SINmain::WorldGreeter().Greet();
}
