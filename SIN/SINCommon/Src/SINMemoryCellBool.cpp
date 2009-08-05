#include "SINMemoryCellBool.h"

#include "SINAlloc.h"


//using namespace SIN::Types;

namespace SIN {
	
	//-----------------------------------------------------------------

	MemoryCell * MemoryCellBool::Clone(void) {
		return SINEW(MemoryCellBool(value));
	}
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellBool::Type(void) 
		{ return MemoryCell::BOOL_MCT; }


	//-----------------------------------------------------------------

	void MemoryCellBool::SetValue (const Types::Boolean_t & b)	
		{ value = b; }
	

	//-----------------------------------------------------------------

	Types::Boolean_t & MemoryCellBool::GetValue (void) 	
		{ return value; }

}