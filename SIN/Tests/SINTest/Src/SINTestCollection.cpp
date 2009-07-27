#include "SINTestCollection.h"

namespace SIN {
	namespace Tests {
		/////////////////// Test Collection /////////////////
		TestCollection::TestCollection(void): tests() {
		}

		TestCollection::~TestCollection(void) {
		}

		TestCollection& TestCollection::AddTest(Test* const& _test) {
			tests.push_back(_test);
			return *this;
		}

		bool TestCollection::RunAll(void) {
			bool somebody_failed = false;
			for (iterator ite = tests.begin(); ite != tests.end(); ++ite) {
				(*ite)->Run();
				somebody_failed = somebody_failed || (*ite)->Status();
			}
			return somebody_failed;
		}
	} // namespace Tests
} // namespace SIN
