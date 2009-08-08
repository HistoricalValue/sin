#include "SINMemoryCellObject.h"

#include "SINAlloc.h"
#include "SINAssert.h"

//using namespace SIN::Types;

namespace SIN {

	//-----------------------------------------------------------------	

	MemoryCellObject::~MemoryCellObject()	{
		if (value != 0x00) {
			value->DecrementReferenceCounter();
			if (value->IsUnreferenced()) {
				value->MarckedForDeletion();
				delete value;
				value = static_cast<Types::Object *>(0);
			}
		}
	}


	//-----------------------------------------------------------------	

	MemoryCell * MemoryCellObject::Clone(void)
		{ return SINEW(MemoryCellObject(value)); }


	//-----------------------------------------------------------------	

	MemoryCell::MemoryCellType MemoryCellObject::Type(void) 
		{ return MemoryCell::OBJECT_MCT; }


	//-----------------------------------------------------------------	
	const String MemoryCellObject::ToString(void) const
	{ return value != 0x00 ? value->ToString() : ""; }


	//-----------------------------------------------------------------	

	void MemoryCellObject::SetValue (Types::Object * obj) { 
		value = obj; 
	}
	

	//-----------------------------------------------------------------	

	Types::Object * MemoryCellObject::GetValue (void){ 
		SINASSERT(value);	
		return value; 
	}


}