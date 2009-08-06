#ifndef __SIN_LIBRARY_LIBRARY_FUNCTIONS_H__
#define __SIN_LIBRARY_LIBRARY_FUNCTIONS_H__

#include "SINLibraryFunction.h"

namespace SIN {
	namespace Library {
		namespace Functions {
			// Print -----------------------------------------------------------
			class Print: public Function {
			public:
				inline Print(void): Function("print") { }
				inline virtual ~Print(void) { }
				virtual return_type operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const;
			}; // class Print
		} // namespace Functions
	} // namespace Library
} // namespace SIN

#endif // __SIN_LIBRARY_LIBRARY_FUNCTIONS_H__
