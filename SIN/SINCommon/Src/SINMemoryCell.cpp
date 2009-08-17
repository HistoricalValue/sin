#include "SINMemoryCell.h"

#include "SINAlloc.h"
#include "SINMemoryCellObject.h"
#include "SINObject.h"

namespace SIN {
	void MemoryCell::Assign(InstanceProxy<MemoryCell>& _to, InstanceProxy<MemoryCell> const& _from) {
		MemoryCell* _to_p = _to;
		Assign(_to_p, _from);
		_to = _to_p;
	}

	void MemoryCell::Assign(MemoryCell*& _to, MemoryCell* _from) {
		if (_to != 0x00) {
			SINASSERT(_to->Type() != MemoryCell::FUNCTION_MCT);
			SINASSERT(_to->Type() != MemoryCell::LIB_FUNCTION_MCT);
			SINASSERT(_to->Type() != MemoryCell::NIL_MCT);
			SINDELETE(_to);
		}

		_to = _from->Clone();
		if (_from->Type() == MemoryCell::OBJECT_MCT)
			static_cast<MemoryCellObject*>(_from)->GetValue()->IncrementReferenceCounter();
	}
} // namespace SIN 
