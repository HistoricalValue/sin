#ifndef __SIN_MEMORY_CELL_AST_H__BOOL_H__
#define __SIN_MEMORY_CELL_AST_H__BOOL_H__


#include "SINTypes.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellBool : public MemoryCell {
		
	public:
		MemoryCellBool(void) : MemoryCell() {}
		MemoryCellBool(const Types::Boolean_t & b) : MemoryCell(), value(b) {}
		~MemoryCellBool() {}

		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type(void);
		virtual const String	ToString(void) const;

		void					SetValue (const Types::Boolean_t & b);
		Types::Boolean_t &		GetValue (void);

	private:
		Types::Boolean_t value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__BOOL_H__