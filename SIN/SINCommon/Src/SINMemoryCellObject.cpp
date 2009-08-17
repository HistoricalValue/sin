#include "SINMemoryCellObject.h"

#include "SINAlloc.h"
#include "SINAssert.h"
#include "SINObject.h"

namespace SIN {

	//-----------------------------------------------------------------	

	MemoryCellObject::~MemoryCellObject()	{
		if (value != 0x00) {
			value->DecrementReferenceCounter();
			if (value->IsUnreferenced()) {
				value->MarkForDeletion();
				SINDELETE(value);
				value = static_cast<Types::Object *>(0);
			}
		}
	}


	//-----------------------------------------------------------------	

	MemoryCell * MemoryCellObject::Clone(void) const
		{ return SINEWCLASS(MemoryCellObject, (value)); }


	//-----------------------------------------------------------------	

	MemoryCell::MemoryCellType MemoryCellObject::Type(void)  const
		{ return MemoryCell::OBJECT_MCT; }


	//-----------------------------------------------------------------	
	const String MemoryCellObject::ToString(void) const
	{ return value != 0x00 ? value->ToString() : ""; }


	//-----------------------------------------------------------------	

	void MemoryCellObject::SetValue (const Types::Object_t& obj) { 
		value = obj; 
	}
	

	//-----------------------------------------------------------------	

	Types::Object_t MemoryCellObject::GetValue (void) const { 
		SINASSERT(value);	
		return value; 
	}


}
