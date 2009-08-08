#include "SINMemoryCellNumber.h"
#include "SINAlloc.h"

//using namespace SIN::Types;

namespace SIN {


	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellNumber::Clone(void) 
	{ return SINEWCLASS(MemoryCellNumber, (value)); }


	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellNumber::Type (void) 
		{ return MemoryCell::NUMBER_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellNumber::ToString(void) const 
		{ return to_string(value); }


	//-----------------------------------------------------------------

	void MemoryCellNumber::SetValue (const Types::Number_t & num)	
		{ value = num; }
	

	//-----------------------------------------------------------------
	
	Types::Number_t MemoryCellNumber::GetValue (void) const
		{ return value; }



}
