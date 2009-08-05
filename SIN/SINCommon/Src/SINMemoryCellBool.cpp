#include "SINMemoryCellBool.h"

#include "SINAlloc.h"


using namespace SIN::Types;

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

	Boolean & MemoryCellBool::GetValue (void) 	
		{ return value; }

}