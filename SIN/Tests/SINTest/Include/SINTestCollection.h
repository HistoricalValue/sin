#ifndef __SIN_TESTCOLLECTION_H__
#define __SIN_TESTCOLLECTION_H__

#include <list>
#include "SINTest.h"

namespace SIN {
	namespace Tests {
		class TestCollection {
		protected:
			// API for subclasses: iterable
			std::list<Test *> tests;
			typedef std::list<Test *>::const_iterator iterator;
		public:
			TestCollection(void);
			virtual ~TestCollection(void);

			// return this
			TestCollection& AddTest(Test* const&);
			TestCollection& operator <<(Test* const& _test)
				{ return AddTest(_test); }

			// returns true if all tests succeeded
			virtual bool RunAll(void);
		}; // class TestCollection
	} // namespace Tests
} // namespace SIN

#endif // __SIN_TESTCOLLECTION_H__
