#include "SIN.h"
#include "SINASTTester.h"
#include "SINParserTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"
#include "SINLoggerManager.h"
#include "SINLogger.h"


int main(int argc, char *argv[]) {
    if (SIN::Initialise()) {
        SIN::Tests::AST::test();
        SIN::Tests::Common::test();
        SIN::Tests::Logging::test();
		SIN::Tests::Parser::test();
		system("pause");
    }
    return 0;
}
