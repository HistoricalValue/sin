#ifndef __SIN_MEMORY_CELL_AST_H__BOOL_H__
#define __SIN_MEMORY_CELL_AST_H__BOOL_H__


#include "SINTypes.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellBool : public MemoryCell {
		
	public:
		MemoryCellBool(void) : MemoryCell() {}
		MemoryCellBool(const Boolean & b) : MemoryCell(), value(b) {}
		~MemoryCellBool() {}

		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type(void);

		void					SetValue (const Boolean & b);
		const bool				GetValue (void) const;

	private:
		Boolean value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__BOOL_H__