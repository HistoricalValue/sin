#ifndef __SIN_MEMORY_CELL_AST_H__BOOL_H__
#define __SIN_MEMORY_CELL_AST_H__BOOL_H__


#include "SINTypes.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellBool : public MemoryCell {
		
	public:
		MemoryCellBool(void) : MemoryCell() {}
		MemoryCellBool(const Types::Boolean_t & b) : MemoryCell(), value(b) {}
		MemoryCellBool(const Types::Number_t& n) : MemoryCell(), value(n != 0 ? true : false) {}
		~MemoryCellBool() {}

		virtual MemoryCell *	Clone(void) const;
		virtual MemoryCellType	Type(void) const;
		virtual const String	ToString(void) const;

		void					SetValue (const Types::Boolean_t & b);
		Types::Boolean_t		GetValue (void) const;

	private:
		Types::Boolean_t value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__BOOL_H__
