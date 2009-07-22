#ifndef __MEMORY_CELL_NUMBER_H__
#define __MEMORY_CELL_NUMBER_H__


#include "SINTypes.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellNumber : public MemoryCell {
	public:
		MemoryCellNumber(void) : MemoryCell() {}
		MemoryCellNumber(const Number & num) : MemoryCell(), value(num) {}
		~MemoryCellNumber() {}
		
		virtual MemoryCellType Type (void) { return MemoryCell::NUMBER_MCT; }


		void			SetValue (const Number & num)	{ value = num; }
		const Number &	GetValue (void) const			{ return value; }

	private:
		Number value;
	};
}

#endif	//__MEMORY_CELL_NUMBER_H__