#include "SINSymbolTable.h"

#include "SINAssert.h"


#define ASSERT_CURRENT_SCOPE()							SINASSERT(currScope < table.size()); SINASSERT(currScope >= 0)
#define ASSERT_GIVEN_SCOPE()							SINASSERT(scope < table.size())

#define ASSERT_SCOPE(SCOPE)								SINASSERT(SCOPE < table.size())

#define RETURN_VALUE(SCOPE, FUNCTION_NAME, ARGUMENT)	ASSERT_SCOPE(SCOPE);						\
														return table[SCOPE].FUNCTION_NAME(ARGUMENT)
												
namespace SIN {


	//-----------------------------------------------------------------

	SymbolTable::SymbolTable(void): table(1), currScope(0) {
		table.reserve(20);
	}


	SymbolTable::~SymbolTable() {}


	//-----------------------------------------------------------------
	// in current and smaller scopes
	SymbolTable::elem_t& SymbolTable::Lookup(const name_t& name) {
		ASSERT_CURRENT_SCOPE();
		
		elem_t* element_p = 0x00;
		for(scope_id scope = currScope; scope > 0; --scope)
			if(static_cast<MemoryCell*>(*(element_p = &Lookup(scope, name))) != static_cast<MemoryCell*>(0x00))
				return *element_p;

		// do once more for scope 0
		return Lookup(0, name);
	}

	
	//-----------------------------------------------------------------
	// in given scope
	SymbolTable::elem_t& SymbolTable::Lookup(const scope_id& scope, const name_t& name) 
		{	RETURN_VALUE(scope, LookupArgument, name);	}
	

	//-----------------------------------------------------------------
	// in current scope
	SymbolTable::elem_t& SymbolTable::LookupOnlyInCurrentScope(const name_t& name) 
		{	RETURN_VALUE(currScope, LookupArgument, name);	}


	//-----------------------------------------------------------------
	// in current scope
	SymbolTable::elem_t& SymbolTable::LookupByIndex(const unsigned int index) 
		{	RETURN_VALUE(currScope, Argument, index);	}
	
	
	//-----------------------------------------------------------------
	// in given scope
	SymbolTable::elem_t& SymbolTable::LookupByIndex(const scope_id& scope, const unsigned int index) 
		{	RETURN_VALUE(scope, Argument, index);	}


	//-----------------------------------------------------------------
	// only in current scope
	void SymbolTable::Insert(const name_t& name, const SymbolTable::elem_t& element) {
		ASSERT_CURRENT_SCOPE();
		table[currScope].AppendArgument(name, element);
	}


	//-----------------------------------------------------------------

	void SymbolTable::IncreaseScope(void) {
		SINASSERT(table.size() > 0);
		++currScope;
		table.push_back(VariableHolder());
		SINASSERT(currScope > 0);
	}
	
	
	//-----------------------------------------------------------------

	void SymbolTable::DecreaseScope(void) {
		SINASSERT(currScope > 0);
		--currScope;
		SINASSERT(table.size() > 1);
		table.pop_back();
		SINASSERT(table.size() > 0);
	}


	//-----------------------------------------------------------------

	const SymbolTable::scope_id SymbolTable::CurrentScope(void) const 
		{ return currScope;	}


	
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

	





	//-----------------------------------------------------------------

	struct CallableToEntryHolderAdaptor: public VariableHolder::Callable {
		typedef VariableHolder::Entry entry_t;
		typedef SymbolTable::EntryHandler handler_t;

		handler_t& entry_handler;
		handler_t const& const_entry_handler;
		explicit CallableToEntryHolderAdaptor(handler_t& eh): entry_handler(eh), const_entry_handler(*static_cast<handler_t*>(0x00)) { }
		explicit CallableToEntryHolderAdaptor(handler_t const& eh): entry_handler(*static_cast<handler_t*>(0x00)), const_entry_handler(eh) { }
		virtual ~CallableToEntryHolderAdaptor(void) { }

		virtual bool operator ()(entry_t const& _entry)
			{ return entry_handler(_entry.name, _entry.value); }
		virtual bool operator ()(entry_t const& _entry) const
			{ return const_entry_handler(_entry.name, _entry.value); }
	}; // struct CallableToEntryHolderAdaptor





#define FOR_EACH_SYMBOL()	ASSERT_CURRENT_SCOPE();													\
							table[currScope].for_each_argument(CallableToEntryHolderAdaptor(eh));	\
							return eh

	//-----------------------------------------------------------------
	// in current scope
	SymbolTable::EntryHandler& SymbolTable::for_each_symbol(SymbolTable::EntryHandler& eh) const {
		ASSERT_CURRENT_SCOPE();
		CallableToEntryHolderAdaptor cteha(eh);
		table[currScope].for_each_argument(cteha);
		return eh;
	}

	

	//-----------------------------------------------------------------
	// in current scope
	const SymbolTable::EntryHandler& SymbolTable::for_each_symbol(const SymbolTable::EntryHandler& eh) const {
		ASSERT_CURRENT_SCOPE();
		table[currScope].for_each_argument(CallableToEntryHolderAdaptor(eh));
		return eh;
	}

}