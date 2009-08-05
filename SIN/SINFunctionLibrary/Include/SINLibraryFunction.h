#ifndef __SIN_LIBRARY_FUNCTION_H__
#define __SIN_LIBRARY_FUNCTION_H__

#include "SINString.h"
#include "SINSymbolTable.h"
#include "SINMemoryCell.h"

namespace SIN {
	namespace Library {
		class Function {
		public:
			typedef MemoryCell* const return_type;

			inline Function(String const& _name): name(_name) { }
			inline virtual ~Function(void) { }

			String const& Name(void) const { return name; }

			// Invoke
			virtual return_type operator ()(SymbolTable const&) const = 0;
		protected:
			String const name;
		}; // class Function
	} // namespace Library
} // namespace SIN

#endif // __SIN_LIBRARY_FUNCTION_H__
