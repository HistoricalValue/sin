#include "SIN.h"
#include "SINASTTester.h"
#include "SINParserTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"
#include "SINLoggerManager.h"
#include "SINLogger.h"
#include "SINTestCollection.h"
#include "SINTestFactory.h"

//////// for quick tests and c++ questions ///////
// (please restore to original before commits)
#include "SINASTTreeVisualisationVisitor.h"
static void quick_test(void) {
	
}
////////

class MainTestCollection: public SIN::Tests::TestCollection {
	SIN::Tests::TestFactory test_factory;
public:
	MainTestCollection(void);
	virtual bool RunAll(void);
}; // class MainTestCollection

int main(int argc, char *argv[]) {
    if (SIN::Initialise()) {
		MainTestCollection mtc;
		mtc.RunAll();
        quick_test();
    }
    return 0;
}

///// MainTestCollection ////////////////////
MainTestCollection::MainTestCollection(void): test_factory() {
}

bool MainTestCollection::RunAll(void) {
	SIN::Tests::AST::test(&test_factory);
	SIN::Tests::Common::test(&test_factory);
	SIN::Tests::Logging::test(&test_factory);
	SIN::Tests::Parser::test(&test_factory);
	return true;
}