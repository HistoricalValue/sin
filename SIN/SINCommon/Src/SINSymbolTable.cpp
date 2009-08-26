#include "SINSymbolTable.h"

#include <assert.h>


namespace SIN {
	SymbolTable::SymbolTable(void) {
		table.reserve(20);	
		table.push_back(VariableHolder());
		currScope = 0;
	}


	// in current and smaller scopes
	elem_t& SymbolTable::Lookup(const name_t&) {
	}

	
	// in given scope
	elem_t& SymbolTable::Lookup(const scope_id&, const name_t&) {
	}
	
	
	// in current scope
	elem_t& SymbolTable::LookupOnlyInCurrentScope(const name_t&) {
	
	}
	
	
	// in current scope
	elem_t& SymbolTable::LookupByIndex(const unsigned int index) {
		
	}
	
	
	// in given scope
	elem_t& SymbolTable::LookupByIndex(const scope_id&, const unsigned int index) {
	}


	// only in current scope
	void SymbolTable::Insert(const name_t&, const elem_t&) {
	}

	void SymbolTable::IncreaseScope(void);
	void SymbolTable::DecreaseScope(void);
	
	
	const scope_id SymbolTable::CurrentScope(void) const 
		{ return currScope;	}


	
	//-----------------------------------------------------------------
	// current scope
	unsigned int SymbolTable::NumberOfSymbols(void) const {	
		assert(currScope > table.size());
		return table[currScope].NumberOfArguments(); 
	}
	

	//-----------------------------------------------------------------
	// in given scope
	unsigned int SymbolTable::NumberOfSymbols(const scope_id& scope) const {
		assert(scope > table.size());
		return table[scope].NumberOfArguments();
	}

	
	//-----------------------------------------------------------------
	// in current scope
	EntryHandler& SymbolTable::for_each_symbol(EntryHandler& eh) const { 
		assert(currScope > table.size());
		return table[currScope].for_each_argument(eh);
	}
	
	const EntryHandler& SymbolTable::for_each_symbol(const EntryHandler&) const; // in current scope


}