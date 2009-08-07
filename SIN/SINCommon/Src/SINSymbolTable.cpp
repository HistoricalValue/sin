#include "SINSymbolTable.h"


#include "SINAssert.h"
#include "SINAlloc.h"
#include "Common.h"
#include <map>
#include <vector>
#include <algorithm>

#define SIN_SYMBOLTABLE_LOOKUP(WHERE)												\
		names_t::iterator result = DATA->WHERE.find(_name);							\
		SINASSERT(static_cast<MemoryCell*>(DATA->not_found) == 0x00);				\
		return result != DATA->names.end() ? result->second : DATA->not_found;

namespace SIN {

	// *** Private API ***************** /
	namespace hsdfsd98sdfjk5t6ASFjadlfsdg0DFADfADf99999999AsdyuasdAASd7ad3 {
		typedef SymbolTable::name_t key_t;
		typedef SymbolTable::elem_t val_t;
		typedef std::map<key_t, val_t> names_t;
		typedef std::map<key_t, val_t> args_t;
		typedef std::vector<SymbolTable::Entry> args_ordered_t;
		struct Data {
			names_t names;
			args_t args;
			args_ordered_t args_ordered;
			val_t not_found;
		}; // struct Data

		typedef std::pair<names_t::iterator, bool> ins_pair_t;
		typedef std::pair<key_t const, val_t> entry_t;
	}
	using namespace hsdfsd98sdfjk5t6ASFjadlfsdg0DFADfADf99999999AsdyuasdAASd7ad3;

	SymbolTable::SymbolTable(void): data(SINEW(Data)), argument_namer("arg") { }
	SymbolTable::~SymbolTable(void) { SINDELETE(data); }

#define DATA static_cast<Data*>(data)
	void SymbolTable::AppendArgument(Type<name_t>::const_ref _name, Type<elem_t>::const_ref _elem) {
		ins_pair_t ins_r = DATA->args.insert(entry_t(_name, _elem));
		SINASSERT(ins_r.second /* node inserted == true */);
		DATA->args_ordered.push_back(Entry(ins_r.first->first, ins_r.first->second));
	}

	void SymbolTable::SetLocal(Type<name_t>::const_ref _name, Type<elem_t>::const_ref _elem) {
		DATA->names.insert(entry_t(_name, _elem));
	}

	SymbolTable::elem_t& SymbolTable::LookupLocal(Type<name_t>::const_ref _name) const {
		SIN_SYMBOLTABLE_LOOKUP(names);
	}

	SymbolTable::elem_t& SymbolTable::LookupArgument(name_t const& _name) const {
		SIN_SYMBOLTABLE_LOOKUP(args);
	}

	SymbolTable::elem_t& SymbolTable::Argument(size_t _index) const {
		Type<args_ordered_t>::ref args = DATA->args_ordered;
		return _index >= args.size() ? DATA->not_found : args.at(_index).value;
	}

	size_t SymbolTable::NumberOfArguments(void) const {
		return DATA->args_ordered.size();
	}

	SymbolTable::Callable& SymbolTable::for_each_argument(Callable& _f) const {
		args_ordered_t::const_iterator end = DATA->args_ordered.end();
		bool more = true;
		for (args_ordered_t::const_iterator ite = DATA->args_ordered.begin(); more && ite != end; ++ite)
			more = _f(*ite);
		return _f;
	}

	SymbolTable::Callable const& SymbolTable::for_each_argument(Callable const& _f) const {
		args_ordered_t::const_iterator end = DATA->args_ordered.end();
		bool more = true;
		for (args_ordered_t::const_iterator ite = DATA->args_ordered.begin(); more && ite != end; ++ite)
			more = _f(*ite);
		return _f;
	}
	 
}	//namepsace SIN
