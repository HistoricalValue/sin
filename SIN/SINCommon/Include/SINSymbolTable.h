#ifndef __SIN_SYMBOL_TABLE_H__
#define __SIN_SYMBOL_TABLE_H__

#include "SINString.h"
#include "SINMemoryCell.h"
#include "SINNamer.h"

namespace SIN {
	class SymbolTable {
	public:	
		typedef String name_t;
		typedef InstanceProxy<MemoryCell> elem_t;

		SymbolTable(void);
		~SymbolTable();

		void AppendArgument(Type<name_t>::const_ref, Type<elem_t>::const_ref);
		void AppendArgument(Type<elem_t>::const_ref _elem) { AppendArgument(argument_namer++, _elem); }
		void SetLocal(Type<name_t>::const_ref, Type<elem_t>::const_ref);


		// Return 0x00 if not found
		Type<elem_t>::ref LookupLocal(Type<name_t>::const_ref) const;
		Type<elem_t>::ref LookupArgument(Type<name_t>::const_ref) const;
		Type<elem_t>::ref Argument(size_t index) const;
		size_t NumberOfArguments(void) const;

	private:
		void* data;
		Namer argument_namer;
	};

}	//namespace SIN

#endif //__SIN_SYMBOL_TABLE_H__
