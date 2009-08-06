#include "SINLibraryFunctions.h"
#include "SINLibrary.h"

#define SIN_LIBRARYFUNCTIONS_LIBFUNC(FNAME) FNAME::return_type FNAME::operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const

namespace SIN {
	namespace Library {
		namespace Functions {
			// print -----------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(print) {
				size_t const num_args = _st.NumberOfArguments();
				for (size_t i = 0; i < num_args; i++)
					_vm.Print(_st.Argument(i)->ToString());
			}
			// println ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(println) {
				MemoryCellString str("\n");
				_st.AppendArgument(&str);
				_lib.Invoke("print", _st);
			}
			// tostring ---------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(tostring) {
			//}
			// strtonum ---------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(strtonum);
			// strsavetofile ----------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(strsavetofile);
			// typeof -----------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(typeof);
			// input ------------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(input);
			// openfile ---------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(openfile);
			// closefile --------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(closefile);
			// writefile --------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(writefile);
			// totalarguments ---------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(totalarguments);
			// arguments --------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(arguments);
			// objectcopy -------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(objectcopy);
		} // namespace Functions
	} // namespace Library
} // namespace SIN
