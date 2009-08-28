
#include "SINSymbolTable.h"


#include "SINAssert.h"
#include "SINAlloc.h"
#include "Common.h"
#include <map>
#include <deque>
#include <algorithm>

#define SIN_SYMBOLTABLE_LOOKUP(WHERE)												\
		names_t::iterator result = data->WHERE.find(_name);							\
		SINASSERT(static_cast<MemoryCell*>(data->not_found) == 0x00);				\
		return result != data->WHERE.end() ? result->second : data->not_found;

namespace SIN {

	/// *** Private API ***************** /
	//namespace hsdfsd98sdfjk5t6ASFjadlfsdg0DFADfADf99999999AsdyuasdAASd7ad3 {
	namespace {
		typedef VariableHolder::name_t key_t;
		typedef VariableHolder::elem_t val_t;
		//typedef std::map<key_t, val_t> names_t;
		//typedef std::map<key_t, val_t> args_t;
		//typedef std::deque<VariableHolder::Entry> args_ordered_t;
		// Debugging
		
		//-----------------------------------------------------------------
		struct names_t: public std::map<key_t, val_t> {
			names_t(void){ }
			~names_t(void) { }
		};


		//-----------------------------------------------------------------

		struct args_t: public std::map<key_t, val_t> {
			args_t(void) { }
			~args_t(void) { }
		};
		
		
		//-----------------------------------------------------------------

		struct args_ordered_t: public std::deque<VariableHolder::Entry> {
			args_ordered_t(void) { }
			~args_ordered_t(void) { }
		};
		
		
		typedef names_t::const_iterator			nciter_t;
		typedef args_t::const_iterator			aciter_t;
		typedef args_ordered_t::const_iterator	oaciter_t;

		typedef std::pair<key_t const, val_t>		entry_t;
		typedef std::pair<names_t::iterator, bool>	ins_pair_t;
		
	}
	//using namespace hsdfsd98sdfjk5t6ASFjadlfsdg0DFADfADf99999999AsdyuasdAASd7ad3;
	
	
	///-----------------	struct Data		------------------------------------------------
	struct VariableHolder::Data {
		names_t			names;
		args_t			args;
		args_ordered_t	args_ordered;
		val_t			not_found;
		
		Data(void) { }
		~Data(void) { }
	private:
		explicit Data(Data const&) { SINASSERT(!"Not yet"); }
	}; // struct Data

	#define DATA static_cast<Data*>(data)


	
	//-----------------------------------------------------------------
	
	VariableHolder::VariableHolder(void): data(SINEW(Data)), argument_namer("arg") { }
	

	//-----------------------------------------------------------------

	VariableHolder::VariableHolder(VariableHolder const& _other): data(SINEW(Data)), argument_namer(_other.argument_namer) {
		names_t	const &			names				= static_cast<Data*>(_other.data)->names;
		args_t	const &			args				= static_cast<Data*>(_other.data)->args;
		args_ordered_t const &	args_ordered		= static_cast<Data*>(_other.data)->args_ordered;
		nciter_t const			names_end			= names.end();
		aciter_t const			args_end			= args.end();
		oaciter_t const			args_ordered_end	= args_ordered.end();
		
		// copy variables
		for (nciter_t ite = names.begin(); ite != names_end; ++ite) {
			MemoryCell* assigned = 0x00;
			MemoryCell::Assign(assigned, ite->second);
			SetLocal(ite->first, assigned);
		}
		// copy args
		for (aciter_t ite = args.begin(); ite != args_end; ++ite) {
			MemoryCell* assigned = 0x00;
			MemoryCell::Assign(assigned, ite->second);
			AppendArgument(ite->first, assigned);
		}
	}
	
	
	//-----------------------------------------------------------------

	VariableHolder::~VariableHolder(void) {
		// Clear memcells
		nciter_t const names_end	= DATA->names.end();
		aciter_t const args_end		= DATA->args.end();
		
		for (nciter_t ite = DATA->names.begin(); ite != names_end; ++ite)
			SINDELETE(ite->second);

		for (aciter_t ite = DATA->args.begin(); ite != args_end; ++ite)
			SINDELETE(ite->second);
		
		SINDELETE(DATA);
	}


	//-----------------------------------------------------------------

	void VariableHolder::AppendArgument(Type<name_t>::const_ref _name, Type<elem_t>::const_ref _elem) {
		ins_pair_t ins_r = DATA->args.insert(entry_t(_name, _elem));
		SINASSERT(ins_r.second /* node inserted == true */);
		DATA->args_ordered.push_back(Entry(ins_r.first->first, ins_r.first->second));
	}


	//-----------------------------------------------------------------

	void VariableHolder::SetLocal(Type<name_t>::const_ref _name, Type<elem_t>::const_ref _elem) 
		{	DATA->names.insert(entry_t(_name, _elem));	}


	//-----------------------------------------------------------------

	VariableHolder::elem_t& VariableHolder::LookupLocal(Type<name_t>::const_ref _name) const 
		{	SIN_SYMBOLTABLE_LOOKUP(names);	}


	//-----------------------------------------------------------------

	VariableHolder::elem_t& VariableHolder::LookupArgument(name_t const& _name) const 
		{	SIN_SYMBOLTABLE_LOOKUP(args);	}


	//-----------------------------------------------------------------

	VariableHolder::elem_t& VariableHolder::Argument(size_t _index) const {
		Type<args_ordered_t>::ref args = DATA->args_ordered;
		return _index >= args.size() ? DATA->not_found : args.at(_index).value;
	}


	//-----------------------------------------------------------------
	
	size_t VariableHolder::NumberOfArguments(void) const 
		{	return DATA->args_ordered.size();	}

	//-----------------------------------------------------------------

	bool VariableHolder::LookupFailed(InstanceProxy<MemoryCell>& _previous_result) const {
		return &_previous_result == &data->not_found;
	}

	//-----------------------------------------------------------------

	VariableHolder::Callable& VariableHolder::for_each_argument(Callable& _f) const {
		args_ordered_t::const_iterator end = DATA->args_ordered.end();
		bool more = true;
		for (args_ordered_t::const_iterator ite = DATA->args_ordered.begin(); more && ite != end; ++ite)
			more = _f(*ite);
		return _f;
	}



	//-----------------------------------------------------------------

	VariableHolder::Callable const& VariableHolder::for_each_argument(Callable const& _f) const {
		args_ordered_t::const_iterator end = DATA->args_ordered.end();
		bool more = true;
		for (args_ordered_t::const_iterator ite = DATA->args_ordered.begin(); more && ite != end; ++ite)
			more = _f(*ite);
		return _f;
	}
	 
}	//namepsace SIN
