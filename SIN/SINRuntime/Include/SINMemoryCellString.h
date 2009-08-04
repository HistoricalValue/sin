#ifndef __SIN_MEMORY_CELL_AST_H__STRING_H__
#define __SIN_MEMORY_CELL_AST_H__STRING_H__


#include "SINString.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellString: public MemoryCell {
	public:
		MemoryCellString(void)  : MemoryCell() {}
		MemoryCellString(const String & str) : MemoryCell(), value(str) {} 
		virtual ~MemoryCellString() { }


		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type (void);

		void					SetValue (const String & s);
		const String &			GetValue (void) const;


	private:
		String value;
	
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__STRING_H__