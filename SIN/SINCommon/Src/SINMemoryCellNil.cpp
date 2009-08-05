#include "SINMemoryCellNil.h"
#include "SINAlloc.h"

using namespace SIN::Types;

namespace SIN {


	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellNil::Clone(void) 
		{ return SINEW(MemoryCellNil()); }
	
	
	//-----------------------------------------------------------------
	MemoryCell::MemoryCellType MemoryCellNil::Type(void) 
		{ return MemoryCell::NIL_MCT; }

	
}