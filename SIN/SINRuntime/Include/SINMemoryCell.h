#ifndef __SIN_MEMORY_CELL_H__
#define __SIN_MEMORY_CELL_H__

namespace SIN {

	//-----------------------------------------------------------------------

	class MemoryCell {
	
	public:
		
		enum MemoryCellType {
			NIL_MCT		= 0,
			BOOL_MCT,
			STRING_MCT,
			NUMBER_MCT,
			AST_MCT,
			OBJECT_MCT,
			FUNCTION_MCT
		};


		virtual MemoryCellType Type (void) = 0;

		MemoryCell(void) {}
		virtual ~MemoryCell() {}
	};

}	//namespace sin

#endif	//__SIN_MEMORY_CELL_H__
