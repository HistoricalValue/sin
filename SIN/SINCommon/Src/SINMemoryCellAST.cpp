#include "SINMemoryCellAST.h"

#include "SINAlloc.h"
#include "SINAssert.h"



namespace SIN {

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellAST::Clone(void) const
		{ return SINEW(MemoryCellAST); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellAST::Type (void)  const
		{ return MemoryCell::AST_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellAST::ToString(void) const
		{ return to_string(value); }
		


	//-----------------------------------------------------------------

	void MemoryCellAST::SetValue (const Types::Metacode_t& node) { 
		SINASSERT(node);
		value = node; 
	}


	//-----------------------------------------------------------------

	Types::Metacode_t MemoryCellAST::GetValue (void) const { 
		SINASSERT(value);
		return value; 
	}
	
	//-----------------------------------------------------------------

	bool MemoryCellAST::ToBoolean(void) const
		{ return true; }
}
