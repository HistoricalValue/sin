#include "SINMemoryCellString.h"

#include "SINAlloc.h"


namespace SIN {

	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellString::Clone(void)  const
		{ return SINEW(MemoryCellString(value)); }
	

	//-----------------------------------------------------------------	
	
	MemoryCell::MemoryCellType MemoryCellString::Type (void)  const
		{ return MemoryCell::STRING_MCT; }


	const String MemoryCellString::ToString(void) const
		{ return value; }
	

	//-----------------------------------------------------------------

	void MemoryCellString::SetValue (const String & s) 
		{ value = s; }

	
	//-----------------------------------------------------------------

	Types::String_t const MemoryCellString::GetValue (void) const
		{ return value; }

	//-----------------------------------------------------------------

	bool MemoryCellString::ToBoolean(void) const
		{ return value == "" ? false : true; }

}
