#include "SIN.h"
#include "SINASTTester.h"
#include "SINParserTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"


int main(int argc, char *argv[]) {
    if (SIN::Initialise()) {
        SIN::Tests::AST::test();
        SIN::Tests::Common::test();
        SIN::Tests::Logging::test();
		SIN::Tests::Parser::test();
    }
    return 0;
}
