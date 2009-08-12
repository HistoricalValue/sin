#ifndef __SIN_MEMORY_CELL_AST_H__AST_H__
#define __SIN_MEMORY_CELL_AST_H__AST_H__

#include "SINMemoryCell.h"
#include "SINTypes.h"

namespace SIN {

	class MemoryCellAST : public MemoryCell {
	public:
		MemoryCellAST(void) : MemoryCell() {}
		MemoryCellAST(Types::Metacode_t const& node) : MemoryCell(), value(node) {}
		
		~MemoryCellAST() {}


		virtual MemoryCell *		Clone(void) const;
		virtual enum MemoryCellType Type (void) const;
		virtual const String		ToString(void) const;

		
		void						SetValue (Types::Metacode_t const&);
		Types::Metacode_t			GetValue (void) const;



	private:
		Types::Metacode_t value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__AST_H__
