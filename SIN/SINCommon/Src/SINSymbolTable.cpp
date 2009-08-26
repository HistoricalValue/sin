#include "SINSymbolTable.h"

#include "SINAssert.h"


#define ASSERT_CURRENT_SCOPE()					SINASSERT(currScope < table.size())
#define ASSERT_GIVEN_SCOPE()					SINASSERT(scope < table.size())

#define ASSERT_SCOPE(SCOPE)						SINASSERT(SCOPE < table.size())

#define CALL(SCOPE, FUNCTION_NAME, ARGUMENT)	if(true) {									\
													ASSERT_SCOPE(SCOPE);					\
													table[SCOPE].FUNCTION_NAME(ARGUMENT);	\
												}											\
												else

namespace SIN {


	//-----------------------------------------------------------------

	SymbolTable::SymbolTable(void) {
		table.reserve(20);	
		table.push_back(VariableHolder());
		currScope = 0;
	}


	SymbolTable::~SymbolTable() {}


	//-----------------------------------------------------------------
	// in current and smaller scopes
	SymbolTable::elem_t& SymbolTable::Lookup(const name_t& name) {
		SINASSERT(!"not implemented");
		ASSERT_CURRENT_SCOPE();
		return table[currScope].LookupArgument(name);
	}

	
	//-----------------------------------------------------------------
	// in given scope
	SymbolTable::elem_t& SymbolTable::Lookup(const scope_id& scope, const name_t& name) {
		//return CALL(scope, LookupArgument, name);
		ASSERT_GIVEN_SCOPE();
		return table[scope].LookupArgument(name);
	}
	

	//-----------------------------------------------------------------
	// in current scope
	SymbolTable::elem_t& SymbolTable::LookupOnlyInCurrentScope(const name_t& name) {
		ASSERT_CURRENT_SCOPE();
		return table[currScope].LookupArgument(name);
	}
	
	
	//-----------------------------------------------------------------
	// in current scope
	SymbolTable::elem_t& SymbolTable::LookupByIndex(const unsigned int index) {
		ASSERT_CURRENT_SCOPE();
		return table[currScope].Argument(index);
	}
	
	
	//-----------------------------------------------------------------
	// in given scope
	SymbolTable::elem_t& SymbolTable::LookupByIndex(const scope_id&, const unsigned int index) {
		SINASSERT(!"not implemented");
		return table[currScope].Argument(index);
	}


	//-----------------------------------------------------------------
	// only in current scope
	void SymbolTable::Insert(const name_t&, const SymbolTable::elem_t&) {
		SINASSERT(!"not implemented");
		ASSERT_CURRENT_SCOPE();
	}


	//-----------------------------------------------------------------

	void SymbolTable::IncreaseScope(void) {
		SINASSERT(!"not implemented");
	
	}
	
	
	//-----------------------------------------------------------------

	void SymbolTable::DecreaseScope(void) {
		SINASSERT(!"not implemented");
	}
	
	

	//-----------------------------------------------------------------

//	const scope_id SymbolTable::CurrentScope(void) const 
//		{ return currScope;	}


	
	//-----------------------------------------------------------------
	// current scope
	unsigned int SymbolTable::NumberOfSymbols(void) const {	
		ASSERT_CURRENT_SCOPE();
		return table[currScope].NumberOfArguments(); 
	}
	

	//-----------------------------------------------------------------
	// in given scope
	unsigned int SymbolTable::NumberOfSymbols(const scope_id& scope) const {
		ASSERT_GIVEN_SCOPE();
		return table[scope].NumberOfArguments();
	}

	


	#define FOR_EACH_SYMBOL()	return EntryHandler()
								/*ASSERT_CURRENT_SCOPE();							\
								return table[currScope].for_each_argument(eh)*/


	//-----------------------------------------------------------------
	// in current scope
	SymbolTable::EntryHandler& SymbolTable::for_each_symbol(SymbolTable::EntryHandler& eh) const 
		{ FOR_EACH_SYMBOL();	}
	

	//-----------------------------------------------------------------
	// in current scope
	const SymbolTable::EntryHandler& SymbolTable::for_each_symbol(const SymbolTable::EntryHandler& eh) const
		{ FOR_EACH_SYMBOL();	}

}