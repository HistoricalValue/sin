#include "SINMemoryCell.h"

#include "SINAlloc.h"
#include "SINMemoryCellObject.h"
#include "SINObject.h"

namespace SIN {
	namespace {

		//-----------------------------------------------------------------

		void assign(MemoryCell*& _to, MemoryCell* const _from, bool _w_del, bool _w_clone) {
			typedef MemoryCell* const memcell_const;
			if (memcell_const(_to) == _from)
				; // do nothing
			else {
				if (_to != 0x00) {
					SINASSERT(_to->Type() != MemoryCell::FUNCTION_MCT);
					SINASSERT(_to->Type() != MemoryCell::LIB_FUNCTION_MCT);
					if (_w_del)
						SINDELETE(_to);
				}

				_to = _w_clone? _from->Clone() : _from;
				if (_from->Type() == MemoryCell::OBJECT_MCT)
					static_cast<MemoryCellObject*>(_from)->GetValue()->IncrementReferenceCounter();
			}
		}

	} // namespace


	//-----------------------------------------------------------------

	void MemoryCell::Assign(InstanceProxy<MemoryCell>& _to, InstanceProxy<MemoryCell> const& _from) {
		MemoryCell* to_p = _to;
		assign(to_p, _from, true, true);
		_to = to_p;
	}


	//-----------------------------------------------------------------

	void MemoryCell::Assign(MemoryCell*& _to, MemoryCell* _from) 
		{	assign(_to, _from, true, true);	}
	
	
	//-----------------------------------------------------------------

	void MemoryCell::UnobtrusiveAssign(InstanceProxy<MemoryCell>& _to, InstanceProxy<MemoryCell> const& _from) {
		MemoryCell* to_p = _to;
		assign(to_p, _from, false, true);
		_to = to_p;
	}

	
	//-----------------------------------------------------------------

	void MemoryCell::UnobtrusiveAssign(MemoryCell*& _to, MemoryCell* _from) 
		{	assign(_to, _from, false, true);	}
	
	
	//-----------------------------------------------------------------

	void MemoryCell::SimpleAssign(InstanceProxy<MemoryCell>& _to, InstanceProxy<MemoryCell> const& _from) {
		MemoryCell* to_p = _to;
		assign(to_p, _from, false, false);
		_to = to_p;
	}
	
	
	//-----------------------------------------------------------------

	void MemoryCell::SimpleAssign(MemoryCell*& _to, MemoryCell* _from) 
		{	assign(_to, _from, false, false);	}
} // namespace SIN 
