#include "SINLibraryFunctions.h"
#include "SINLibrary.h"
#include "SINFileOutputStream.h"

#define SIN_LIBRARYFUNCTIONS_LIBFUNC(FNAME) FNAME::return_type FNAME::operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const

namespace SIN {
	namespace Library {
		namespace Functions {
			// print -----------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(print) {
				size_t const num_args = _st.NumberOfArguments();
				for (size_t i = 0; i < num_args; i++)
					_vm.Print(_st.Argument(i)->ToString());
				_vm.ReturnValueNil();
			}
			// println ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(println) {
				MemoryCellString str("\n");
				_st.AppendArgument(&str);
				_lib.Invoke("print", _st);
			}
			// tostring ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(tostring) {
				if (_st.NumberOfArguments() > 0)
					_vm.ReturnValueString(_st.Argument(0)->ToString());
				else
					_vm.AppendError("not enough arguments passed to tostring(obj)", "", 0u);
			}
			// strtonum ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(strtonum) {
				if (_st.NumberOfArguments() > 0) {
					double const num = strtod(_st.Argument(0)->ToString().c_str(), NULL);
					_vm.ReturnValueNumber(num);
				}
				else
					_vm.AppendError("not enough arguments passed to strtonum(str)", "", 0u);
			}
			// strsavetofile ----------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(strsavetofile) {
				if (_st.NumberOfArguments() > 1) {
					FileOutputStream fout(_st.Argument(0)->ToString());
					String const str(_st.Argument(1)->ToString());
					char const* const c_str = str.c_str();
					size_t const len = strlen(c_str);
					fout.write(c_str, len);
					_vm.ReturnValueNumber(len);
				}
				else
					_vm.AppendError("not enough arguments passed to strsavetofile(file,str)", "", 0u);
			}
			// typeof -----------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(typeof) {
				VM::VirtualState::Frame& frame = _vm.CurrentFrame();
				SymbolTable& stable = frame.st;
				if (stable.NumberOfArguments() > 0) {
					char const* type_desc = 0x00;
					switch (_vm.CurrentFrame().st.Argument(0)->Type()) {
						case MemoryCell::AST_MCT:
							type_desc = "metacode";
							break;
						case MemoryCell::BOOL_MCT:
							type_desc = "boolean";
							break;
						case MemoryCell::FUNCTION_MCT:
							type_desc = "function";
							break;
						case MemoryCell::LIB_FUNCTION_MCT:
							type_desc = "library function";
							break;
						case MemoryCell::NIL_MCT:
							type_desc = "nil";
							break;
						case MemoryCell::NUMBER_MCT:
							type_desc = "number";
							break;
						case MemoryCell::OBJECT_MCT:
							type_desc = "object";
							break;
						case MemoryCell::STRING_MCT:
							break;
						default:
							SINASSERT(!"Illegal program state");
							break;
					}
					_vm.ReturnValueString(type_desc);
				}
				else
					_vm.AppendError("not enough arguments passed to typeof(obj)", "", 0u);
			}
			// input ------------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(input);
			// openfile ---------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(openfile);
			// closefile --------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(closefile);
			// writefile --------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(writefile);
			// totalarguments ---------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(totalarguments) {
				_vm.ReturnValueNumber(_vm.Down().CurrentFrame().st.NumberOfArguments());
				_vm.Top();
			}
			// arguments --------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(arguments) {
				if (_vm.InCall()) {
					// TODO continue here
				}
				else
					_vm.AppendError("arguments() called not from within a function", "", 0u);
			}
			// objectcopy -------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(objectcopy);
		} // namespace Functions
	} // namespace Library
} // namespace SIN
