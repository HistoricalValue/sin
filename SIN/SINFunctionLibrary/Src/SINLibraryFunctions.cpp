#include "SINLibraryFunctions.h"

namespace SIN {
	namespace Library {
		namespace Functions {
			// Print -----------------------------------------------------------
			Print::return_type Print::operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const {
				size_t const num_args = _st.NumberOfArguments();
				for (size_t i = 0; i < num_args; i++)
					_vm.Print(_st.Argument(i)->ToString());
			}
		} // namespace Functions
	} // namespace Library
} // namespace SIN
