#ifndef __SIN_MEMORY_CELL_AST_H__NIL_H__
#define __SIN_MEMORY_CELL_AST_H__NIL_H__


#include "SINTypes.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellNil : public MemoryCell {
		
	public:

		MemoryCellNil(void) : MemoryCell() {}
		~MemoryCellNil() {}

		virtual MemoryCell *	Clone(void) const;
		virtual MemoryCellType	Type(void) const;
		virtual const String	ToString(void) const;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__NIL_H__
