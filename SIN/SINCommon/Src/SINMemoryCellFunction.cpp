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
	
	void MemoryCellFunction::SetValue (const ASTNode *functionNode)	{ 
		SINASSERT(functionNode);
		value = const_cast<ASTNode *>(functionNode); 
	}


	//-----------------------------------------------------------------
	
	ASTNode * MemoryCellFunction::GetValue (void) { 
		SINASSERT(value);
		return value; 
	}


}