#include "SINMemoryCell.h"

#include "SINAlloc.h"
#include "SINMemoryCellObject.h"
#include "SINObject.h"

namespace SIN {
	void MemoryCell::Assign(MemoryCell*& _to, MemoryCell* _from) {
		if (_to != 0x00)
			SINDELETE(_to);

		_to = _from->Clone();
		if (_from->Type() == MemoryCell::OBJECT_MCT)
			static_cast<MemoryCellObject*>(_from)->GetValue()->IncrementReferenceCounter();
	}
} // namespace SIN 
