#include "SINASTTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"
#include "SIN.h"

int main(int argc, char *argv[]) {
    if (SIN::Initialise()) {
        SIN::Tests::AST::test();
        SIN::Tests::Common::test();
        SIN::Tests::Logging::test();
    }
    return 0;
}
