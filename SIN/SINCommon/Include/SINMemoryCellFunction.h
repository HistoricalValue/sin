#ifndef __SIN_MEMORY_CELL_FUNCTION_H__
#define __SIN_MEMORY_CELL_FUNCTION_H__


#include "SINFunction.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellFunction : public MemoryCell {
	public:

		MemoryCellFunction(void) : MemoryCell() {}
		MemoryCellFunction(Types::Function_t * function) : MemoryCell(), value(function) {}
		~MemoryCellFunction() {}

		virtual MemoryCell *		Clone(void);
		virtual MemoryCellType		Type (void);
		virtual const String		ToString(void) const;

		void						SetValue (const Types::Function_t * function);
		SIN::Types::Function_t *	GetValue (void);

	private:

		Types::Function * value;
	};
}

#endif	//__SIN_MEMORY_CELL_FUNCTION_H__