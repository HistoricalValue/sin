#ifndef __SIN_MEMORY_CELL_AST_H__FUNCTION_H__
#define __SIN_MEMORY_CELL_AST_H__FUNCTION_H__


#include "SINFunction.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellFunction : public MemoryCell {
	public:

		MemoryCellFunction(void) : MemoryCell() {}
		MemoryCellFunction(Types::Function * function) : MemoryCell(), value(function) {}
		~MemoryCellFunction() {}

		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type (void);

		void					SetValue (const Types::Function * function);
		SIN::Types::Function *	GetValue (void);

	private:

		Types::Function * value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__FUNCTION_H__