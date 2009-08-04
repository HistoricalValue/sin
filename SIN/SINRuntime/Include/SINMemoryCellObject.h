#ifndef __MEMORY_CELL_OBJECT_H__
#define __MEMORY_CELL_OBJECT_H__


#include "SINObject.h"
#include "SINAssert.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellObject : public MemoryCell {
		
	public:
		MemoryCellObject(void) : MemoryCell() {}
		MemoryCellObject(SINObject * _obj) : MemoryCell(),  obj(_obj){}
		~MemoryCellObject();


		virtual MemoryCellType Type(void) { return MemoryCell::OBJECT_MCT; }
	
		void				SetValue (SINObject * _obj)		{ SINASSERT(_obj);	obj = _obj; }
		const SINObject *	GetValue (void) const			{ SINASSERT(obj);	return obj; }

	private:
		SINObject * obj;
	};
}

#endif	//__MEMORY_CELL_OBJECT_H__