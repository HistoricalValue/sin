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
		


		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type (void);


		void					SetValue (const Number & num);
		const Number &			GetValue (void) const;

	private:
		Number value;
	};
}

#endif	//__MEMORY_CELL_NUMBER_H__