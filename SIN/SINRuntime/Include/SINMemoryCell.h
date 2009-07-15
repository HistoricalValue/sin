#ifndef __SIN_MEMORY_CELL_H__
#define __SIN_MEMORY_CELL_H__


namespace SIN {
	class MemoryCell {
	public:
		enum MemoryCellType {
			string,
			number,
			nil,
			AST,
			sin_object,
			function
		};

		virtual enum MemoryCellType GetType(void) = 0;

		MemoryCell(void);
		~MemoryCell();
	};

}	//namespace sin

#endif	//__SIN_MEMORY_CELL_H__