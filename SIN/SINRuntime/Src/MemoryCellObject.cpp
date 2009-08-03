#include "SINMemoryCellObject.h"

#define ZERO	static_cast<SINObject *>(0)

namespace SIN {
	MemoryCellObject::~MemoryCellObject()	{
		if (obj != ZERO && !obj->IsUnreferenced()) {	//An eixame kuklo eidi miwsame ton kai diagrfoume to upolipo
			obj->DecrementReferenceCounter();
			if (obj->IsUnreferenced()) {
				delete obj;
				obj = ZERO;
			}
		}
	}
}