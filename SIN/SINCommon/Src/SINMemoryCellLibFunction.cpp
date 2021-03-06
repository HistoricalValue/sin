#include "SINMemoryCellLibFunction.h"


#include "SINAlloc.h"
#include "SINAssert.h"



namespace SIN {

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellLibFunction::Clone(void) const
		{ return SINEW(MemoryCellLibFunction(value)); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellLibFunction::Type (void)  const
		{ return MemoryCell::LIB_FUNCTION_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellLibFunction::ToString(void) const 
		{ return to_string(value); }


	//-----------------------------------------------------------------
	
	void MemoryCellLibFunction::SetValue (const Types::LibraryFunction_t& function) { 
		SINASSERT(function);
		value = function; 
	}


	//-----------------------------------------------------------------
	
	SIN::Library::Function * MemoryCellLibFunction::GetValue (void) const { 
		SINASSERT(value);
		return value; 
	}

	//-----------------------------------------------------------------

	bool MemoryCellLibFunction::ToBoolean(void) const
		{ return true; }

}
