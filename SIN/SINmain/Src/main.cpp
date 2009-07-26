#include "SIN.h"
#include "Common.h"
#include "SINAssert.h"
#include "SINLogger.h"
#include "SINASTTester.h"
#include "SINTestFactory.h"
#include "SINParserTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"
#include "SINLoggerManager.h"
#include "SINTestCollection.h"
#include "SINSymbolTableTester.h"
#include "SINAllocTester.h"


//////// for quick tests and c++ questions ///////
// (please restore to original before commits)
#include "SINConstants.h"
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
#include "SINASTMITTreeVisualizerXMLProducerVisitor.h"
InstanceProxy<out_class> g_out;

static void quick_test(void) {
	SIN::LoggerManager::SingletonGetInstance()->MakeStdoutLogger("SIN::main::quick_test");
	out_class out(SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::main::quick_test"));
	g_out = out;
	// keep the above for convenience

	// Example of using "out" and "FOREACH"
//	std::list<int> lis; lis.push_back(9); lis.push_back(8); lis.push_back(7); lis.push_back(6);
//	FOREACH(lis)
//		out << *ITER(lis);
//	out << (SIN::string_cast("This is") << " horrible " << (4));
}
////////

class MainTestCollection: public SIN::Tests::TestCollection {
	SIN::Tests::TestFactory test_factory;
public:
	MainTestCollection(void): test_factory() { }
	MainTestCollection(SIN::Tests::TestFactory const& tf): test_factory(tf) { }
	virtual bool RunAll(void);
}; // class MainTestCollection



int main(int argc, char *argv[]) {
	SIN::Tests::TestFactory test_factory;

	// Early testing: LoggerManager taints the memory module.
	SIN::LoggerManager::StreamLogger alloc_logger("SIN::Tests::Alloc", SIN::Logging::Record::FINEST, SIN::STDOUT, SIN::Logging::RecordPrinter()); // TODO one day this will be removed, when tests work seriously
	SIN::Tests::Alloc::test(&test_factory, &alloc_logger); // TODO and one day this will be moved in along with the rest of the tests

    if (SIN::Initialise()) {
		MainTestCollection mtc(test_factory);
		mtc.RunAll();
        quick_test();
    }
	else
		SINASSERT(!"Initialisation failed");

	SIN::CleanUp();
	return 0;
}

///// MainTestCollection ////////////////////
bool MainTestCollection::RunAll(void) {
	SIN::Tests::AST::test(&test_factory);
	SIN::Tests::Common::test(&test_factory);
	SIN::Tests::Logging::test(&test_factory);
	SIN::Tests::Parser::test(&test_factory);
	SIN::Tests::ST::test(&test_factory);
	return true;
}
