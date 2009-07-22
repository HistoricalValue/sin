#ifndef __SIN_MEMORY_CELL_AST_H__FUNCTION_H__
#define __SIN_MEMORY_CELL_AST_H__FUNCTION_H__


#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellFunction : public MemoryCell {
	public:

		MemoryCellFunction(void) : MemoryCell() {}
		~MemoryCellFunction() {}

		virtual MemoryCellType Type (void) { return MemoryCell::FUNCTION_MCT; }
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__FUNCTION_H__