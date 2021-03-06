#ifndef __SIN_MEMORY_CELL_AST_H__AST_H__
#define __SIN_MEMORY_CELL_AST_H__AST_H__

#include "SINMemoryCell.h"
#include "SINTypes.h"
#include <list>

namespace SIN {

	class MemoryCellAST : public MemoryCell {
	public:
		MemoryCellAST(Types::Metacode_t const& node);
		MemoryCellAST(const MemoryCellAST&);
		~MemoryCellAST(void);


		virtual MemoryCell *		Clone(void) const;
		virtual enum MemoryCellType Type (void) const;
		virtual bool				ToBoolean(void) const;
		virtual const String		ToString(void) const;
		
		void						SetValue (Types::Metacode_t const&);
		Types::Metacode_t			GetValue (void) const;

	private:
		Types::Metacode_t value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__AST_H__
