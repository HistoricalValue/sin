#ifndef __SIN_MEMORY_CELL_H__
#define __SIN_MEMORY_CELL_H__

#include "SINString.h"

namespace SIN {

	//-----------------------------------------------------------------------

	class MemoryCell {
	
	public:
		
		enum MemoryCellType {
			NIL_MCT		= 0,
			BOOL_MCT,
			STRING_MCT,
			NUMBER_MCT,
			AST_MCT,
			OBJECT_MCT,
			FUNCTION_MCT,
			LIB_FUNCTION_MCT,
			NATIVE_RESOURCE_MCT
		};


		virtual MemoryCell *	Clone(void) const = 0;
		virtual MemoryCellType	Type (void) const = 0;
		virtual const String	ToString(void) const = 0;
		
		MemoryCell(void) {}
		virtual ~MemoryCell() {}

		static void Assign(InstanceProxy<MemoryCell>& _to, InstanceProxy<MemoryCell> const& _from);
		static void Assign(MemoryCell*& to, MemoryCell* from);
	};

}	//namespace sin

#endif	//__SIN_MEMORY_CELL_H__
