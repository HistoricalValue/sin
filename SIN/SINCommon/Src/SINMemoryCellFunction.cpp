#include "SINMemoryCellFunction.h"


#include "SINAlloc.h"
#include "SINAssert.h"

using namespace SIN::Types;

namespace SIN {

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellFunction::Clone(void)
		{ return SINEW(MemoryCellFunction(value)); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellFunction::Type (void) 
		{ return MemoryCell::FUNCTION_MCT; }


	//-----------------------------------------------------------------
	
	void MemoryCellFunction::SetValue (const Types::Function * function)	{ 
		SINASSERT(function);
		value = const_cast<Types::Function *>(function); 
	}


	//-----------------------------------------------------------------
	
	SIN::Types::Function * MemoryCellFunction::GetValue (void) { 
		SINASSERT(value);
		return value; 
	}


}