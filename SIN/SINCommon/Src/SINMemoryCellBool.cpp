#include "SINMemoryCellBool.h"

#include "SINAlloc.h"


namespace SIN {
	
	//-----------------------------------------------------------------

	MemoryCell * MemoryCellBool::Clone(void) {
		return SINEW(MemoryCellBool(value));
	}
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellBool::Type(void) 
		{ return MemoryCell::BOOL_MCT; }


	//-----------------------------------------------------------------

	void MemoryCellBool::SetValue (const Boolean & b)	
		{ value = b; }
	

	//-----------------------------------------------------------------

	const bool MemoryCellBool::GetValue (void) const	
		{ return value; }

}