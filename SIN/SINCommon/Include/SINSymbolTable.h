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



		Type<elem_t>::ref Lookup(Type<name_t>::const_ref) const;
		Type<elem_t>::ref Lookup(const scope_id, Type<name_t>::const_ref) const;

		

		void Insert(Type<name_t>::const_ref, Type<elem_t>::const_ref);


		void IncreaseScope(void);
		void DecreaseScope(void);
	};

}	//namespace SIN

#endif //__SIN_SYMBOL_TABLE_H__
