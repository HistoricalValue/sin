#ifndef __MEMORY_CELL_NUMBER_H__
#define __MEMORY_CELL_NUMBER_H__


#include "SINTypes.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellNumber : public MemoryCell {
	public:
		MemoryCellNumber(void) : MemoryCell() {}
		MemoryCellNumber(const Types::Number_t & num) : MemoryCell(), value(num) {}
		~MemoryCellNumber() {}
		


		virtual MemoryCell *	Clone(void) const;
		virtual MemoryCellType	Type (void) const;
		virtual bool			ToBoolean(void) const;
		virtual const String	ToString(void) const;


		void					SetValue (const Types::Number_t & num);
		Types::Number_t			GetValue (void) const;

	private:
		Types::Number_t value;
	};
}

#endif	//__MEMORY_CELL_NUMBER_H__
