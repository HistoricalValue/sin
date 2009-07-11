#include "SIN.h"
#include "Common.h"
#include "SINASTTester.h"
#include "SINParserTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"
#include "SINLoggerManager.h"
#include "SINLogger.h"
#include "SINTestCollection.h"
#include "SINTestFactory.h"
#include "SINAssert.h"

//////// for quick tests and c++ questions ///////
// (please restore to original before commits)
class out_class {
	SIN::Logger& out;
public:
	out_class(SIN::Logger& _out): out(_out) { }
	template <typename _T>
	out_class& operator <<(_T const& something) {
		out.Notice(SIN::string_cast(something));
		return *this;
	}
};
// keep the above for convenience. ex:
// out << (SIN::String() << "This is" << " horrible " << (4));
static void quick_test(void) {
	SIN::LoggerManager::SingletonGetInstance()->MakeStdoutLogger("SIN::main::quick_test");
	out_class out(SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::main::quick_test"));
	// keep the above for convenience

	// Example of using "out" and "FOREACH"
	std::list<int> lis; lis.push_back(9); lis.push_back(8); lis.push_back(7); lis.push_back(6);
	FOREACH(lis)
		out << *ITER(lis);
	out << (SIN::string_cast("This is") << " horrible " << (4));
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
	else
		SINASSERT(!"Initialisation failed");

	SIN::CleanUp();
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
