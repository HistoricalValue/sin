#ifndef __SIN_MEMORY_CELL_AST_H__STRING_H__
#define __SIN_MEMORY_CELL_AST_H__STRING_H__


#include "SINString.h"
#include "SINMemoryCell.h"
#include "SINTypes.h"


namespace SIN {

	class MemoryCellString: public MemoryCell {
	public:
		MemoryCellString(void)  : MemoryCell() {}
		MemoryCellString(const Types::String_t & str) : MemoryCell(), value(str) {} 
		virtual ~MemoryCellString() { }


		virtual MemoryCell *	Clone(void) const;
		virtual MemoryCellType	Type (void) const;
		virtual bool			ToBoolean(void) const;
		virtual const String	ToString(void) const;

		void					SetValue (const Types::String_t & s);
		Types::String_t const	GetValue (void) const;


	private:
		Types::String_t value;
	
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__STRING_H__
