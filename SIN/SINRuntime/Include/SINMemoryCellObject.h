#ifndef __MEMORY_CELL_OBJECT_H__
#define __MEMORY_CELL_OBJECT_H__


#include "SINObject.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellObject : public MemoryCell {
		
	public:
		MemoryCellObject(void) : MemoryCell() {}
		MemoryCellObject(const SINObject & obj) : MemoryCell(),  value(obj){}
		~MemoryCellObject()	{}


		virtual MemoryCellType Type(void) { return MemoryCell::OBJECT_MCT; }
	
		void				SetValue (const SINObject & s)	{ value = s; }
		const SINObject &	GetValue (void) const			{ return value; }

	private:
		SINObject value;
	};
}

#endif	//__MEMORY_CELL_OBJECT_H__