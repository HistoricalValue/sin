#include "SINMemoryCellLibFunction.h"


#include "SINAlloc.h"
#include "SINAssert.h"



namespace SIN {

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellLibFunction::Clone(void)
		{ return SINEW(MemoryCellLibFunction(value)); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellLibFunction::Type (void) 
		{ return MemoryCell::LIB_FUNCTION_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellLibFunction::ToString(void) const 
		{ return to_string(value); }


	//-----------------------------------------------------------------
	
	void MemoryCellLibFunction::SetValue (const Library::Function * function)	{ 
		SINASSERT(function);
		value = const_cast<Library::Function *>(function); 
	}


	//-----------------------------------------------------------------
	
	SIN::Library::Function * MemoryCellLibFunction::GetValue (void) { 
		SINASSERT(value);
		return value; 
	}


}