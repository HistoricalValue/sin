#include "SINLibraryFunctions.h"
#include "SINLibrary.h"
#include "SINFileOutputStream.h"

#define SIN_LIBRARYFUNCTIONS_LIBFUNC(FNAME) FNAME::return_type FNAME::operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const

namespace SIN {
	namespace Library {
		namespace Functions {
			// print -----------------------------------------------------------
			namespace {
				struct ArgumentPrinter: public SymbolTable::Callable {
					virtual bool operator ()(SymbolTable::Entry const& _entry) const {
						vs.Print(_entry.value->ToString());
						return true;
					}
					ArgumentPrinter(VM::VirtualState& _vs): vs(_vs) { }
				private:
					VM::VirtualState& vs;
				};
			} // namespace
			SIN_LIBRARYFUNCTIONS_LIBFUNC(print) {
				_vs.CurrentFrame().stable.for_each_argument(ArgumentPrinter(_vs));
				_vs.ReturnValueNil();
			}
			// println ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(println) {
				MemoryCellString str("\n");
				_vs.CurrentFrame().stable.AppendArgument(&str);
				_lib.Invoke("print", _vs);
			}
			// tostring ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(tostring) {
				SymbolTable& st = _vs.CurrentFrame().stable;
				if (st.NumberOfArguments() > 0)
					_vs.ReturnValueString(st.Argument(0)->ToString());
				else
					_vs.AppendError("not enough arguments passed to tostring(obj)", "", 0u);
			}
			// strtonum ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(strtonum) {
				SymbolTable& st = _vs.CurrentFrame().stable;
				if (st.NumberOfArguments() > 0) {
					double const num = strtod(st.Argument(0)->ToString().c_str(), NULL);
					_vs.ReturnValueNumber(num);
				}
				else
					_vs.AppendError("not enough arguments passed to strtonum(str)", "", 0u);
			}
			// strsavetofile ----------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(strsavetofile) {
				SymbolTable& st = _vs.CurrentFrame().stable;
				if (st.NumberOfArguments() > 1) {
					FileOutputStream fout(st.Argument(0)->ToString());
					String const str(st.Argument(1)->ToString());
					char const* const c_str = str.c_str();
					size_t const len = strlen(c_str);
					fout.write(c_str, len);
					_vs.ReturnValueNumber(len);
				}
				else
					_vs.AppendError("not enough arguments passed to strsavetofile(file,str)", "", 0u);
			}
			// typeof -----------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_LIBFUNC(typeof) {
				SymbolTable& stable = _vs.CurrentFrame().stable;
				if (stable.NumberOfArguments() > 0) {
					char const* type_desc = 0x00;
					switch (stable.Argument(0)->Type()) {
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
							type_desc = "string";
							break;
						default:
							SINASSERT(!"Illegal program state");
							break;
					}
					_vs.ReturnValueString(type_desc);
				}
				else
					_vs.AppendError("not enough arguments passed to typeof(obj)", "", 0u);
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
				_vs.ReturnValueNumber(_vs.Down().CurrentFrame().stable.NumberOfArguments());
				_vs.Top();
			}
			// arguments --------------------------------------------------------
			namespace {
				struct ArgumentToTableCopier: public SymbolTable::Callable {
					ArgumentToTableCopier(Types::Object* _obj): obj(_obj) { }
					virtual bool operator ()(SymbolTable::Entry const& _entry) const {
						obj->SetValue(_entry.name, _entry.value->Clone());
						return true;
					}
				private:
					Types::Object* obj;
				}; // struct ArgumentToTableCopier
			} // namespace
			SIN_LIBRARYFUNCTIONS_LIBFUNC(arguments) {
				if (_vs.InCall()) {
					Types::Object* obj = SINEW(Types::Object);
					_vs.CurrentFrame().stable.for_each_argument(ArgumentToTableCopier(obj));
					_vs.ReturnValueObject(obj);
				}
				else
					_vs.AppendError("arguments() called not from within a function", "", 0u);
			}
			// objectcopy -------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_LIBFUNC(objectcopy);
		} // namespace Functions
	} // namespace Library
} // namespace SIN
