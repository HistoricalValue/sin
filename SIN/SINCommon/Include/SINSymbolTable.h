#ifndef __SIN_SYMBOL_TABLE_H__
#define __SIN_SYMBOL_TABLE_H__

#include <vector>
#include "SINNamer.h"
#include "SINString.h"
#include "SINMemoryCell.h"
#include "SINVariableHolder.h"

namespace SIN {
	class SymbolTable {
	public:	
		typedef unsigned long				scope_id;
		typedef String						name_t;
		typedef InstanceProxy<MemoryCell>	elem_t;

		elem_t& 		Lookup(const name_t&); // in current and smaller scopes
		elem_t& 		Lookup(const scope_id&, const name_t&); // in given scope
		elem_t& 		LookupOnlyInCurrentScope(const name_t&); // in current scope
		elem_t& 		LookupByIndex(const unsigned int index); // in current scope
		elem_t& 		LookupByIndex(const scope_id&, const unsigned int index); // in given scope
		bool			LookupFailed(elem_t& previous_result) const; // previous lookup in any scope

		void			Insert(const name_t&, const elem_t&); // only in current scope
		void			Insert(const name_t&, const elem_t&, scope_id); // in given scope

		void			Remove(const name_t&); // searching from current to smaller, first found. DOES NOT DELETE IT
		void			Remove(const scope_id&, const name_t&); // only in given scope. DOES NOT DELETE IT

		void 			IncreaseScope(void);
		void 			DecreaseScope(void);
		const scope_id	CurrentScope(void) const;

		unsigned int	NumberOfSymbols(void) const; // current scope
		unsigned int	NumberOfSymbols(const scope_id&) const; // in given scope

		struct EntryHandler {
			virtual bool operator ()(const name_t&, const elem_t&) { return false; }
			virtual bool operator ()(const name_t&, const elem_t&) const { return false; }
		}; // struct EntryHandler
		
		EntryHandler&		for_each_symbol(      EntryHandler&) const; // in current scope
		const EntryHandler& for_each_symbol(const EntryHandler&) const; // in current scope
		EntryHandler&		for_each_symbol_in_scope(scope_id,       EntryHandler&) const; // in given scope
		const EntryHandler& for_each_symbol_in_scope(scope_id, const EntryHandler&) const; // in given scope


		SymbolTable(void);
		SymbolTable(const SymbolTable &);
		~SymbolTable();
	private:
		typedef std::vector<VariableHolder> Table;

		Table		table;
		scope_id	currScope;

	};

}	//namespace SIN

#endif //__SIN_SYMBOL_TABLE_H__
