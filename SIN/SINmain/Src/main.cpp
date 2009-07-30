#include "SINLogger.h"
#include "SINTestCollection.h"
#include "SINTestFactory.h"
#include "SINAllocTester.h"
#include "SIN.h"
#include "SINAssert.h"
#include "SINASTTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"
#include "SINParserTester.h"
#include "SINSymbolTableTester.h"
#include "SINLoggerManager.h"

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
static InstanceProxy<out_class> g_out;

void quick_test(void) {
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
	SIN::Tests::Alloc::Status alloc_test_status;
	void emulateAllocTest(void) const;
public:
	MainTestCollection(SIN::Tests::Alloc::Status const& _alloc_test_status): test_factory(), alloc_test_status(_alloc_test_status) { }
	MainTestCollection(SIN::Tests::TestFactory const& tf, SIN::Tests::Alloc::Status const& _alloc_test_status): test_factory(tf), alloc_test_status(_alloc_test_status) { }
	virtual bool RunAll(void);
}; // class MainTestCollection



int main(int argc, char *argv[]) {
	// Early testing: LoggerManager taints the memory module.
	SIN::Tests::Alloc::Status s;
	SIN::Tests::Alloc::test(s); // TODO and one day this will be moved in along with the rest of the tests

	if (SIN::Initialise()) {
		MainTestCollection mtc(s);
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
	emulateAllocTest();
	SIN::Tests::AST::test(&test_factory);
	SIN::Tests::Common::test(&test_factory);
	SIN::Tests::Logging::test(&test_factory);
	SIN::Tests::Parser::test(&test_factory);
	SIN::Tests::ST::test(&test_factory);
	return true;
}

void MainTestCollection::emulateAllocTest(void) const {
	SIN::Logger& logga(SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Alloc"));
	logga.Notice(alloc_test_status.failed ? SIN::string_cast("FAIL'D at line ") << alloc_test_status.at_line : "OK");
}