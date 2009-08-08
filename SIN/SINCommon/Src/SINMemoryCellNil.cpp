#include "SINMemoryCellNil.h"
#include "SINAlloc.h"



namespace SIN {


	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellNil::Clone(void) 
		{ return SINEW(MemoryCellNil()); }
	
	
	//-----------------------------------------------------------------
	MemoryCell::MemoryCellType MemoryCellNil::Type(void) 
		{ return MemoryCell::NIL_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellNil::ToString(void) const
		{ return String("Nil"); }

	
}
