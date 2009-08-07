#ifndef __SIN_MEMORY_CELL_LIB_FUNCTION_H__
#define __SIN_MEMORY_CELL_LIB_FUNCTION_H__


#include "SINLibraryFunction.h"

namespace SIN {

	class MemoryCellLibFunction : public MemoryCell {
	public:

		MemoryCellLibFunction(void) : MemoryCell() {}
		MemoryCellLibFunction(Library::Function * function) : MemoryCell(), value(function) {}
		~MemoryCellLibFunction() {}

		virtual MemoryCell *		Clone(void);
		virtual MemoryCellType		Type (void);
		virtual const String		ToString(void) const;

		void						SetValue (const Library::Function * function);
		SIN::Library::Function *	GetValue (void);

	private:

		Library::Function * value;
	};
}



#endif //__SIN_MEMORY_CELL_LIB_FUNCTION_H__