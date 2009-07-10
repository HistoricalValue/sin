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

//////// for quick tests and c++ questions ///////
// (please restore to original before commits)
static void quick_test(void) {
	SIN::LoggerManager::SingletonGetInstance()->MakeStdoutLogger("SIN::main::quick_test");
	SIN::Logger &_out(SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::main::quick_test"));
	class __out {
		SIN::Logger& out;
	public:
		__out(SIN::Logger& _out): out(_out) { }
		__out& operator <<(SIN::String const& msg) {
			out.Notice(msg);
			return *this;
		}
	} out(_out);
	// keep the above for convenience. ex:
	// out << (SIN::String() << "This is" << " horrible " << (4));
	  std::list<int> lis; lis.push_back(9); lis.push_back(8); lis.push_back(7); lis.push_back(6);
  FOREACH(i, lis)
      out << (SIN::string_cast(*ITER(i, lis)));
  out << (SIN::String() << "This is" << " horrible " << (4));
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
