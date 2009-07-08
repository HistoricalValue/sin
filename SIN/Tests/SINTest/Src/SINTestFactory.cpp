#include "SINTestFactory.h"

namespace SIN {
	namespace Tests {
		///////////////////// Test Factory //////////////////////////
		TestFactory::TestFactory(void): namer("Test:") {
		}

		TestFactory::~TestFactory(void) {
		}

		const char *TestFactory::nextTestName(void) {
			return namer++;
		}

		String const TestFactory::NextTestName(void) {
			return nextTestName();
		}
	} // namespace Tests
} // namespace SIN
