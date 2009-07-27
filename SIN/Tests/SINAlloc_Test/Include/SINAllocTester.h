#ifndef __SIN_ALLOC_TESTER_H__
#define __SIN_ALLOC_TESTER_H__



namespace SIN {
	namespace Tests {
		namespace Alloc {
			struct Status {
				bool failed;
				unsigned int at_line;
				Status(bool _failed = false, unsigned int _at_line = 0u):
					failed(_failed), at_line(_at_line) { }
				Status(Status const& _other):
					failed(_other.failed), at_line(_other.at_line) { }
			};
			extern void test(Status& status_result);
		}
	}
}
#endif // __SIN_ALLOC_TESTER_H__
