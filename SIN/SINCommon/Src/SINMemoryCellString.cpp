#include "SINMemoryCellString.h"

#include "SINAlloc.h"


namespace SIN {

	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellString::Clone(void) 
		{ return SINEW(MemoryCellString(value)); }
	

	//-----------------------------------------------------------------	
	
	MemoryCell::MemoryCellType MemoryCellString::Type (void) 
		{ return MemoryCell::STRING_MCT; }


	const String MemoryCellString::ToString(void) const
		{ return value; }
	

	//-----------------------------------------------------------------

	void MemoryCellString::SetValue (const String & s) 
		{ value = s; }

	
	//-----------------------------------------------------------------

	Types::String_t const MemoryCellString::GetValue (void) const
		{ return value; }

}
