#include "SINMemoryCellNil.h"
#include "SINAlloc.h"



namespace SIN {


	//-----------------------------------------------------------------
	
	MemoryCell * MemoryCellNil::Clone(void)  const
		{ return SINEW(MemoryCellNil()); }
	
	
	//-----------------------------------------------------------------
	MemoryCell::MemoryCellType MemoryCellNil::Type(void)  const
		{ return MemoryCell::NIL_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellNil::ToString(void) const
		{ return String("Nil"); }

	//-----------------------------------------------------------------


	void MemoryCellNil::SetValue(const Types::Nil_t & num) 
		{}

	//-----------------------------------------------------------------

	Types::Nil_t MemoryCellNil::GetValue(void) const
		{	return Types::Nil_t();	}

	//-----------------------------------------------------------------
	
}
