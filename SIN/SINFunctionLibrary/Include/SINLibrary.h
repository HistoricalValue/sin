#ifndef __SIN_LIBRARY_LIBRARY_H__
#define __SIN_LIBRARY_LIBRARY_H__

#include <utility>
#include "SINFunction.h"
#include "SINSymbolTable.h"
#include "SINMemoryCell.h"

namespace SIN {
	namespace Library {
		class Library {
		public:
			typedef String name_t;
			typedef Function const* func_t;
			typedef Function::return_type const f_ret_t;

			// returns a pair which contains true if this function has been replaced,
			// false otherwise. In the earlier case, the previous function's pointer
			// is in the returned pair.
			// The function is registered under its own name.
			std::pair<bool, func_t> InstallFunction(Function const* f_p);

			// returns true if there is a function installed with the given name
			bool IsInstalled(name_t const& name) const;

			// uninstalls the function with the given name and returns its pointer,
			// if a function with such a name was installed. Does nothing and returns
			// 0x00 otherwise.
			func_t Uninstall(name_t const& name);


			// Invokes the function with the given name, passing the argument(s) and
			// returning the result of the function.
			// Invoking a function which is not insalled is an error.
			f_ret_t Invoke(name_t const& name, SymbolTable const& env) const;

			Library(void);
			~Library(void);
		private:
			typedef std::map<String, func_t> functions_map_t;
			typedef functions_map_t::iterator fiter_t;
			typedef functions_map_t::const_iterator fciter_t;
			typedef functions_map_t::value_type entry_t;
			functions_map_t functions;

			func_t f_imit;
		}; // class Library
	} // namespace Library
} // namespace SIN

#endif // __SIN_LIBRARY_LIBRARY_H__
