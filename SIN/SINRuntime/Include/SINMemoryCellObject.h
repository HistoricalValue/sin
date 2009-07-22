#ifndef __MEMORY_CELL_OBJECT_H__
#define __MEMORY_CELL_OBJECT_H__


#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellObject : public MemoryCell {
		
	public:
		MemoryCellObject(void) : MemoryCell() {}
		~MemoryCellObject()	{}


		virtual MemoryCellType GetType(void) { return MemoryCell::OBJECT_MCT; }
	};
}

#endif	//__MEMORY_CELL_OBJECT_H__