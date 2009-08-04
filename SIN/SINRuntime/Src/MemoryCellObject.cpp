#include "SINMemoryCellObject.h"

namespace SIN {

	MemoryCellObject::~MemoryCellObject()	{
		SINASSERT(obj);
		obj->DecrementReferenceCounter();
		if (obj->IsUnreferenced()) {
			delete obj;
			obj = static_cast<SINObject *>(0);
		}
	}



}