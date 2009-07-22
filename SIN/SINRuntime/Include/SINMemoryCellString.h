#ifndef __SIN_MEMORY_CELL_AST_H__STRING_H__
#define __SIN_MEMORY_CELL_AST_H__STRING_H__


#include "SINString.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellString: public MemoryCell {
	public:
		MemoryCellString(void)  : MemoryCell() {}
		MemoryCellString(const String & str) : MemoryCell(), value(str) {} 
		~MemoryCellString();


		virtual MemoryCellType Type (void) { return MemoryCell::STRING_MCT; }


		void			SetValur (const String & s) { value = s; }
		const String &	GetValue (void) const		{ return value; }


	private:
		String value;
	
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__STRING_H__