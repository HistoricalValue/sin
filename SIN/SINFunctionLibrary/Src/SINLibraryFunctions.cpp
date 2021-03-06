#include "SINLibraryFunctions.h"
#include "SINLibrary.h"
#include "SINFileOutputStream.h"
#include "SINAlloc.h"
#include "SINFileOutputStream.h"
#include "SINBufferedOutputStream.h"
#include <new>
#include <sstream>

#define SIN_LIBRARYFUNCTIONS_LIBFUNC(FNAME) FNAME::return_type FNAME::operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const
#define SIN_LIBRARYFUNCTIONS_DEFAULTS(FNAME) void FNAME::Initialise(void) { } void FNAME::CleanUp(void) { }
#define SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(FNAME) SIN_LIBRARYFUNCTIONS_DEFAULTS(FNAME) SIN_LIBRARYFUNCTIONS_LIBFUNC(FNAME)

namespace SIN {
	namespace Library {
		namespace Functions {
			// print -----------------------------------------------------------
			namespace {
				struct ArgumentPrinter: public SymbolTable::EntryHandler {
					virtual bool operator ()(SymbolTable::name_t const& _name, SymbolTable::elem_t const& _value) const {
						vs.Print(_value->ToString());
						return true;
					}
					ArgumentPrinter(VM::VirtualState& _vs): vs(_vs) { }
				private:
					VM::VirtualState& vs;
				};
			} // namespace
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(print) {
				_vs.CurrentStable().for_each_symbol(ArgumentPrinter(_vs));
				_vs.ReturnValueNil();
			}
			// println ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(println) {
				_vs.CurrentStable().for_each_symbol(ArgumentPrinter(_vs));
				MemoryCellString newline_inst("\n");
				InstanceProxy<MemoryCell> newline(&newline_inst);
				(ArgumentPrinter(_vs))("newline", newline);
				_vs.ReturnValueNil();
			}
			// tostring ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(tostring) {
				SymbolTable& st = _vs.CurrentStable();
				if (st.NumberOfSymbols() > 0)
					_vs.ReturnValueString(st.LookupByIndex(0)->ToString());
				else
					_vs.AppendError("not enough arguments passed to tostring(obj)", "", 0u);
			}
			// strtonum ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(strtonum) {
				SymbolTable& st = _vs.CurrentStable();
				if (st.NumberOfSymbols() > 0) {
					double const num = strtod(st.LookupByIndex(0)->ToString().c_str(), NULL);
					_vs.ReturnValueNumber(num);
				}
				else
					_vs.AppendError("not enough arguments passed to strtonum(str)", "", 0u);
			}
			// strsavetofile ----------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(strsavetofile) {
				SymbolTable& st = _vs.CurrentStable();
				if (st.NumberOfSymbols() > 1) {
					FileOutputStream fout(st.LookupByIndex(0)->ToString());
					String const str(st.LookupByIndex(1)->ToString());
					char const* const c_str = str.c_str();
					size_t const len = strlen(c_str);
					fout.write(c_str, len);
					_vs.ReturnValueNumber(len);
				}
				else
					_vs.AppendError("not enough arguments passed to strsavetofile(file,str)", "", 0u);
			}
			// typeof -----------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(typeof) {
				SymbolTable& stable = _vs.CurrentStable();
				if (stable.NumberOfSymbols() > 0) {
					char const* type_desc = 0x00;
					switch (stable.LookupByIndex(0)->Type()) {
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
						case MemoryCell::NATIVE_RESOURCE_MCT:
							type_desc = "native resource";
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
			//SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(input);
			// fileopen ---------------------------------------------------------
			namespace {
				struct file {
					String const path;
					BufferedOutputStream buf;
					file(String const& _path): path(_path) { }
					file(file const& _o): path(_o.path), buf(_o.buf) { }
				};
				struct filememcell: public MemoryCellNativeResource {
					struct file file;
					filememcell(String const& _path): file(_path) { }
					filememcell(filememcell const& _o): file(_o.file) { }
					filememcell* Clone(void) const { return SINEWCLASS(filememcell, (*this)); }
					String const ToString(void) const { return file.path; }
					bool ToBoolean(void) const { return true; }
					id_t ID(void) const { return &id; }
					static void id(void) { }
					virtual bool operator ==(MemoryCell const&) const { SINASSERT(!"Not implemented"); return false; }
				}; // struct filememcell
			} // namespace
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(fileopen) {
				SymbolTable& stable = _vs.CurrentStable();
				if (stable.NumberOfSymbols() > 0) {
					Types::Object& obj_inst = *SINEW(Types::Object);
					MemoryCell* const arg0 = stable.LookupByIndex(0);
					obj_inst.SetValue("file", SINEWCLASS(filememcell, (arg0->ToString())));
					_vs.ReturnValueObject(&obj_inst);
				}
				else {
					_vs.AppendError("not enough arguments passed to fileopen(filepath)", "", 0u);
					_vs.ReturnValueNil();
				}
			}
			// fileclose --------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(fileclose);
			// filewrite --------------------------------------------------------
			//SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(filewrite);
			// fileread ---------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(fileread) {
				SymbolTable& stable = _vs.CurrentStable();
				if (stable.NumberOfSymbols() > 0) {
					MemoryCell* const arg0 = stable.LookupByIndex(0);
					if (arg0->Type() == MemoryCell::OBJECT_MCT) {
						Types::Object_t const obj = static_cast<MemoryCellObject*>(arg0)->GetValue();
						filememcell* const fres = &static_cast<filememcell&>(*obj->GetValue("file"));
						if (fres != 0x00) {
							std::ifstream fin(fres->file.path.c_str());
							if (fin) {
								std::ostringstream imp;
								fin.get(*imp.rdbuf(), '\0');
								_vs.ReturnValueString(imp.str());
							}
							else {
								_vs.AppendError(to_string("error while reading from file ") << fres->file.path, "", 0U);
								_vs.ReturnValueNil();
							}
						}
						else {
							_vs.AppendError("no \"file\" element in file resource passed to fileread()", "", 0u);
							_vs.ReturnValueNil();
						}
					}
					else {
						_vs.AppendError("invalid argument in fileread(file)", "", 0u);
						_vs.ReturnValueNil();
					}
				}
				else {
					_vs.AppendError("not enough arguments passed to fileread(file)", "", 0u);
					_vs.ReturnValueNil();
				}
			}
			// totalarguments ---------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(totalarguments) {
				if (_vs.InCall()) {
					size_t const num_args = _vs.Down().CurrentStable().NumberOfSymbols(0);
					_vs.Top();
					_vs.ReturnValueNumber(num_args);
				}
				else
					_vs.AppendError("arguments() called not from within a function", "", 0u);
			}
			// arguments --------------------------------------------------------
			namespace {
				struct ArgumentToTableCopier: public SymbolTable::EntryHandler {
					ArgumentToTableCopier(Types::Object* _obj): obj(_obj) { }
					virtual bool operator ()(SymbolTable::name_t const& _name, SymbolTable::elem_t const& _value) const {
						obj->SetValue(_name, _value->Clone());
						if (_value->Type() == MemoryCell::OBJECT_MCT)
							static_cast<MemoryCellObject&>(*_value).GetValue()->IncrementReferenceCounter();
						return true;
					}
				private:
					Types::Object* obj;
				}; // struct ArgumentToTableCopier
			} // namespace
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(arguments) {
				if (_vs.InCall()) {
					Types::Object_t obj_inst_p = SINEW(Types::Object);
					_vs.Down().CurrentStable().for_each_symbol_in_scope(0, ArgumentToTableCopier(obj_inst_p));
					_vs.Top();
					_vs.ReturnValueObject(obj_inst_p);
				}
				else
					_vs.AppendError("arguments() called not from within a function", "", 0u);
			}
			// objectcopy -------------------------------------------------------
			SIN_LIBRARYFUNCTIONS_DEFAULTS_AND_LIBFUNC(objectcopy) {
				SymbolTable& stable = _vs.CurrentStable();
				if (stable.NumberOfSymbols() > 0) {
					MemoryCell* obj = stable.LookupByIndex(0);
					if (obj->Type() == MemoryCell::OBJECT_MCT) {
						_vs.ReturnValueObject(static_cast<MemoryCellObject*>(obj)->GetValue()->Clone());
					}
					else
						_vs.AppendError("argument passed to objectcopy() is not an object", "", 0u);
				}
				else
					_vs.AppendError("not enough arguments passed to objectcopy()", "", 0u);
			}
			// -------------------------------------------------------------------
			// Utility classes
			// -------------------------------------------------------------------
		} // namespace Functions
	} // namespace Library
} // namespace SIN
