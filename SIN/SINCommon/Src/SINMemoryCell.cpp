#include "SINMemoryCell.h"

#include "SINAlloc.h"
#include "SINMemoryCellObject.h"

namespace SIN {
	void MemoryCell::Assign(MemoryCell*& _to, MemoryCell* _from) {
		SINDELETE(_to);

		_to = _from->Clone();
		if (_from->Type() == MemoryCell::OBJECT_MCT)
			static_cast<MemoryCellObject*>(_from)->GetValue()->IncrementReferenceCounter();
	}
} // namespace SIN 
