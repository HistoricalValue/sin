#include "SINMemoryCellString.h"

#include "SINAlloc.h"


namespace SIN {

	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellString::Clone(void) 
		{ return SINEW(MemoryCellString(value)); }
	

	//-----------------------------------------------------------------	
	
	MemoryCell::MemoryCellType MemoryCellString::Type (void) 
		{ return MemoryCell::STRING_MCT; }
	

	//-----------------------------------------------------------------

	void MemoryCellString::SetValue (const String & s) 
		{ value = s; }

	
	//-----------------------------------------------------------------

	String & MemoryCellString::GetValue (void) 
		{ return value; }

}