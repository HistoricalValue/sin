#ifndef __SIN_LIBRARY_FUNCTION_H__
#define __SIN_LIBRARY_FUNCTION_H__

#include "SINString.h"
#include "SINSymbolTable.h"
#include "SINMemoryCell.h"
#include "SINVirtualState.h"

#define SIN_FUNCTIONLIBRARY_FUNC_ARGS VM::VirtualState& _vs, SIN::Library::Library& _lib

namespace SIN {
	namespace Library {
		class Library;

		class Function {
		public:
			typedef void const return_type;

			inline Function(String const& _name): name(_name) { }
			inline virtual ~Function(void) { }

			String const& Name(void) const { return name; }

			bool operator== (const SIN::Library::Function & libFunck) const { return name == libFunck.Name(); }
			bool operator!= (const SIN::Library::Function & libFunck) const { return name != libFunck.Name();  }

			// Invoke
			virtual return_type operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const = 0;
		protected:
			String const name;
		}; // class Function
	} // namespace Library
} // namespace SIN

#endif // __SIN_LIBRARY_FUNCTION_H__
