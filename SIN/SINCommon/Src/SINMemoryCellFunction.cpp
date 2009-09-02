#include "SINMemoryCellFunction.h"


#include "SINAlloc.h"
#include "SINAssert.h"



namespace SIN {

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellFunction::Clone(void) const
		{ return SINEW(MemoryCellFunction(value)); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellFunction::Type (void)  const
		{ return MemoryCell::FUNCTION_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellFunction::ToString(void) const 
		{ return to_string(value); }


	//-----------------------------------------------------------------
	
	void MemoryCellFunction::SetValue (const Types::Function_t& function)	{ 
		SINASSERT(function.GetASTNode());
		value = function; 
	}


	//-----------------------------------------------------------------
	
	SIN::Types::Function_t MemoryCellFunction::GetValue (void) const { 
		SINASSERT(value.GetASTNode());
		return value; 
	}

	//-----------------------------------------------------------------
	
	bool MemoryCellFunction::ToBoolean(void) const
		{ return true; }
}
