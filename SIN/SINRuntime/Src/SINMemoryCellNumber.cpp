#include "SINMemoryCellNumber.h"
#include "SINAlloc.h"


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
	
	const Number & MemoryCellNumber::GetValue (void) const	
		{ return value; }



}