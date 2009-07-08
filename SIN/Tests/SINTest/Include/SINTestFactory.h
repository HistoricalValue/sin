#ifndef __SIN_TESTFACTORY_H__
#define __SIN_TESTFACTORY_H__

#include "SINTest.h"
#include "SINNamer.h"

namespace SIN {
	namespace Tests {
		class TestFactory {
			Namer namer;
			char const *nextTestName(void);
		public:
			TestFactory(void);
			virtual ~TestFactory(void);

			String const NextTestName(void);
		}; // class TestFactory
	} // namespace Tests
} // namespace SIN

#endif // __SIN_TESTFACTORY_H__
