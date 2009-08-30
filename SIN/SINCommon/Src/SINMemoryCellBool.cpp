#include "SINMemoryCellBool.h"

#include "SINAlloc.h"

//using namespace SIN::Types;

namespace SIN {
	
	//-----------------------------------------------------------------

	MemoryCell * MemoryCellBool::Clone(void) const {
		return SINEW(MemoryCellBool(value));
	}
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellBool::Type(void)  const
		{ return MemoryCell::BOOL_MCT; }


	//-----------------------------------------------------------------
	
	const String MemoryCellBool::ToString(void) const
		{ return to_string(value); }

	//-----------------------------------------------------------------

	void MemoryCellBool::SetValue (const Types::Boolean_t & b)	
		{ value = b; }
	

	//-----------------------------------------------------------------

	Types::Boolean_t MemoryCellBool::GetValue(void) const
		{ return value; }

	//-----------------------------------------------------------------

}
