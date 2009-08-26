#ifndef __SIN_SYMBOL_TABLE_H__
#define __SIN_SYMBOL_TABLE_H__

#include "SINNamer.h"
#include "SINString.h"
#include "SINMemoryCell.h"


namespace SIN {
	class SymbolTable {
	public:	
		typedef unsigned long				scope_id;
		typedef String						name_t;
		typedef InstanceProxy<MemoryCell>	elem_t;

		elem_t& Lookup(const name_t&);
		elem_t& Lookup(const scope_id&, const name_t&);
		elem_t& LookupOnlyInCurrentScope(const name_t&);
		elem_t& LookupByIndex(unsigned int index);

		void Insert(const name_t&, const elem_t&);

		void IncreaseScope(void);
		void DecreaseScope(void);
		const scope_id CurrentScope(void) const;

		unsigned int NumberOfSymbols(void) const; // current scope

		struct EntryHandler {
			virtual bool operator ()(const name_t&, const elem_t&) { return false; }
			virtual bool operator ()(const name_t&, const elem_t&) const { return false; }
		}; // struct EntryHandler
		      EntryHandler& for_each_symbol(      EntryHandler&) const; // in current scope
		const EntryHandler& for_each_symbol(const EntryHandler&) const; // in current scope
	};

}	//namespace SIN

#endif //__SIN_SYMBOL_TABLE_H__
