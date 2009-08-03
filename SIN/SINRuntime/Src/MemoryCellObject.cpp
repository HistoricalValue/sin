#include "SINMemoryCellObject.h"


namespace SIN {
	MemoryCellObject::~MemoryCellObject()	{
		obj->DecrementReferenceCounter();
		if (obj->IsUnreferenced())
			delete obj;
	}
}