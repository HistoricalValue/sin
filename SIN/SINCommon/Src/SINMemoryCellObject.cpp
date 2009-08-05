#include "SINMemoryCellObject.h"

#include "SINAlloc.h"
#include "SINAssert.h"

using namespace SIN::Types;

namespace SIN {

	//-----------------------------------------------------------------	

	MemoryCellObject::~MemoryCellObject()	{
		SINASSERT(value);
		value->DecrementReferenceCounter();
		if (value->IsUnreferenced()) {
			value->MarckedForDeletion();
			delete value;
			value = static_cast<SINObject *>(0);
		}
	}


	//-----------------------------------------------------------------	

	MemoryCell * MemoryCellObject::Clone(void)
		{ return SINEW(MemoryCellObject(value)); }


	//-----------------------------------------------------------------	

	MemoryCell::MemoryCellType MemoryCellObject::Type(void) 
		{ return MemoryCell::OBJECT_MCT; }


	//-----------------------------------------------------------------	

	void MemoryCellObject::SetValue (const SINObject * obj) { 
		SINASSERT(obj);	
		value = const_cast<SINObject *>(obj); 
	}
	

	//-----------------------------------------------------------------	

	SINObject * MemoryCellObject::GetValue (void){ 
		SINASSERT(value);	
		return value; 
	}


}