#ifndef __SIN_MEMORY_CELL_LIB_FUNCTION_H__
#define __SIN_MEMORY_CELL_LIB_FUNCTION_H__

#include "SINTypes.h"
#include "SINMemoryCell.h"

namespace SIN {

	class MemoryCellLibFunction : public MemoryCell {
	public:

		MemoryCellLibFunction(void) : MemoryCell() {}
		MemoryCellLibFunction(Types::LibraryFunction_t function) : MemoryCell(), value(function) {}
		~MemoryCellLibFunction() {}

		virtual MemoryCell *		Clone(void) const;
		virtual MemoryCellType		Type (void) const;
		virtual const String		ToString(void) const;

		void						SetValue (const Types::LibraryFunction_t& function);
		Types::LibraryFunction_t	GetValue (void) const;

	private:

		Types::LibraryFunction_t value;
	};
}



#endif //__SIN_MEMORY_CELL_LIB_FUNCTION_H__
