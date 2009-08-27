#include "SINMemoryCellNil.h"
#include "SINAlloc.h"



namespace SIN {


	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellNil::Clone(void)  const
		{ return SINEW(MemoryCellNil()); }
	
	
	//-----------------------------------------------------------------
	MemoryCell::MemoryCellType MemoryCellNil::Type(void)  const
		{ return MemoryCell::NIL_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellNil::ToString(void) const
		{ return String("Nil"); }

	//-----------------------------------------------------------------

	bool MemoryCellNil::operator ==(MemoryCell const&) const {
		SINASSERT(!"Not implemented");
		return false;
	}
	
}
