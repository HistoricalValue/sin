#include "SINMemoryCellFunction.h"


#include "SINAlloc.h"
#include "SINAssert.h"



namespace SIN {

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellFunction::Clone(void)
		{ return SINEW(MemoryCellFunction(value)); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellFunction::Type (void) 
		{ return MemoryCell::FUNCTION_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellFunction::ToString(void) const 
		{ return to_string(value); }


	//-----------------------------------------------------------------
	
	void MemoryCellFunction::SetValue (const Types::Function_t * function)	{ 
		SINASSERT(function);
		value = const_cast<Types::Function_t *>(function); 
	}


	//-----------------------------------------------------------------
	
	SIN::Types::Function_t * MemoryCellFunction::GetValue (void) { 
		SINASSERT(value);
		return value; 
	}


}