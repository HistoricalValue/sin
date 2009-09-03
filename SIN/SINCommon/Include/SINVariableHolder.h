#ifndef __SIN_VARIABLE_HOLDER_H__
#define __SIN_VARIABLE_HOLDER_H__

#include "SINString.h"
#include "SINMemoryCell.h"
#include "SINNamer.h"

namespace SIN {
	class VariableHolder {
	public:	
		typedef String name_t;
		typedef InstanceProxy<MemoryCell> elem_t;

		struct Entry {
			name_t const& name;
			elem_t& value;
			Entry(name_t const& _name, elem_t& _value): name(_name), value(_value) { }
			Entry(Entry const& _o): name(_o.name), value(_o.value) { }
			~Entry(void) { }
			void operator =(Entry const& _o) { new(this) Entry(_o); }
			bool operator ==(Entry const& _o) const { return name == _o.name; }
		};

		VariableHolder(void);
		VariableHolder(VariableHolder const&);
		~VariableHolder();
		void operator =(VariableHolder const& _other) { new(this) VariableHolder(_other); }

		void AppendArgument(Type<name_t>::const_ref, Type<elem_t>::const_ref);
		void AppendArgument(Type<elem_t>::const_ref _elem) { AppendArgument(argument_namer++, _elem); }
		void RemoveArgument(Type<name_t>::const_ref);
		void SetLocal(Type<name_t>::const_ref, Type<elem_t>::const_ref);


		// If not found, calling LookupFailed(result_of_this_call) returns true
		Type<elem_t>::ref LookupLocal(Type<name_t>::const_ref) const;
		Type<elem_t>::ref LookupArgument(Type<name_t>::const_ref) const;
		Type<elem_t>::ref Argument(size_t index) const;
		size_t NumberOfArguments(void) const;
		bool LookupFailed(Type<elem_t>::ref) const;


		struct Callable { // returns false to stop iterating
			virtual bool operator ()(Entry const&) { return false; }
			virtual bool operator ()(Entry const&) const { return false; }
		};
		
		Callable& for_each_argument(Callable&) const;
		Callable const& for_each_argument(Callable const&) const;

	private:
		struct Data;
		Data* data;
		Namer argument_namer;
	};

}	//namespace SIN

#endif //__SIN_VARIABLE_HOLDER_H__
