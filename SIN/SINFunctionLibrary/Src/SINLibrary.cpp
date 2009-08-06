#include "SINLibrary.h"

#include "SINAssert.h"
#include "SINAlloc.h"

namespace SIN {
	namespace Library {

		// *** Private API ************************************************/
		// ****************************************************************/

		Library::Library(VM_P_t const& _vm_p): functions(), f_imit(0x00), vm_p(_vm_p) { }
		Library::~Library(void) { }

		// returns a pair which contains true if this function has been replaced,
		// false otherwise. In the earlier case, the previous function's pointer
		// is in the returned pair.
		// The function is registered under its own name.
		std::pair<bool, Library::func_t> Library::InstallFunction(Function const* _f_p) {
			std::pair<fiter_t, bool> insertion = functions.insert(std::make_pair(_f_p->Name(), _f_p));
			func_t prev_f = 0x00;
			bool replaced;
			if ((replaced = (insertion.second == false))) { // no new element inserted
				prev_f = insertion.first->second;
				functions.erase(insertion.first);
				functions.insert(insertion.first, std::make_pair(_f_p->Name(), _f_p));
			}
			return std::make_pair(replaced, prev_f);
		}

		// returns true if there is a function installed with the given name
		bool Library::IsInstalled(name_t const& _name) const {
			return functions.find(_name) != functions.end();
		}
		
		// uninstalls the function with the given name and returns its pointer,
		// if a function with such a name was installed. Does nothing and returns
		// 0x00 otherwise.
		Library::func_t Library::Uninstall(name_t const& _name) {
			fiter_t deathee = functions.find(_name);
			func_t result = 0x00;
			if (deathee != functions.end()) {
				result = deathee->second;
				functions.erase(deathee);
			}
			return result;
		}

		// Invokes the function with the given name, passing the argument(s) and
		// returning the result of the function.
		// Invoking a function which is not insalled is an error.
		Library::f_ret_t Library::Invoke(name_t const& _name, SymbolTable const& _env) const {
			fciter_t fi = functions.find(_name);
			SINASSERT(fi != functions.end());
			return (*fi->second)(*vm_p, _env);
		}

	} // namespace Library
} // namespace SIN