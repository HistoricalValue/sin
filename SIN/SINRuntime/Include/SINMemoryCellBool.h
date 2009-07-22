#ifndef __SIN_MEMORY_CELL_AST_H__BOOL_H__
#define __SIN_MEMORY_CELL_AST_H__BOOL_H__


//#include "SIN"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellBool : public MemoryCell {
		
	public:
		MemoryCellBool(void) : MemoryCell() {}
		MemoryCellBool(const bool b) : MemoryCell(), value(b) {}
		~MemoryCellBool() {}

		virtual MemoryCellType Type(void) { return MemoryCell::OBJECT_MCT; }

		void		SetType (const bool b)	{ value = b; }
		const bool	GetType (void) const	{ return value; }
	private:
		bool value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__BOOL_H__