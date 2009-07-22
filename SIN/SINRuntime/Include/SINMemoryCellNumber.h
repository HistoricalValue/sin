#ifndef __MEMORY_CELL_NUMBER_H__
#define __MEMORY_CELL_NUMBER_H__


#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellNumber : public MemoryCell {
	public:
		MemoryCellNumber(void) : MemoryCell() {}
		~MemoryCellNumber() {}
		
		virtual MemoryCellType Type (void) { return MemoryCell::NUMBER_MCT; }
	};
}

#endif	//__MEMORY_CELL_NUMBER_H__