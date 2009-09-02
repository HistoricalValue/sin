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
		virtual bool			ToBoolean(void) const;
		virtual const String	ToString(void) const;
		
		
		void					SetValue (const Types::Nil_t & num);
		Types::Nil_t			GetValue (void) const;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__NIL_H__
