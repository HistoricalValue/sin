#ifndef __SIN_LIBRARY_STANDARD_LIBRARY_H__
#define __SIN_LIBRARY_STANDARD_LIBRARY_H__

#include "SINLibrary.h"

namespace SIN {
	namespace Library {
		// A utility class which is auto-initialised, having installed all the
		// standard library functions.
		class StandardLibrary: public Library {
		public:
			StandardLibrary(void);
			StandardLibrary(StandardLibrary const&);
			~StandardLibrary(void);
		private:
			Function* functions[8];
		}; // class StandardLibrary
	} // namespace Library
} // namespace SIN

#endif // __SIN_LIBRARY_STANDARD_LIBRARY_H__
