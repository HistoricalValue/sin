#include "SINMemoryCellNumber.h"
#include "SINAlloc.h"

using namespace SIN::Types;

namespace SIN {


	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellNumber::Clone(void) 
	{ return SINEW(MemoryCellNumber(value)); }


	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellNumber::Type (void) 
		{ return MemoryCell::NUMBER_MCT; }


	//-----------------------------------------------------------------

	void MemoryCellNumber::SetValue (const Number & num)	
		{ value = num; }
	

	//-----------------------------------------------------------------
	
	Number & MemoryCellNumber::GetValue (void) 	
		{ return value; }



}