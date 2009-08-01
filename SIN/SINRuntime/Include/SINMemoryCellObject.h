#ifndef __MEMORY_CELL_OBJECT_H__
#define __MEMORY_CELL_OBJECT_H__


#include "SINObject.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellObject : public MemoryCell {
		
	public:
		MemoryCellObject(void) : MemoryCell() {}
		~MemoryCellObject()	{}


		virtual MemoryCellType Type(void) { return MemoryCell::OBJECT_MCT; }
	
		void				SetValue (const SinObject & s)	{ value = s; }
		const SinObject &	GetValue (void) const			{ return value; }

	private:
		SinObject value;
	};
}

#endif	//__MEMORY_CELL_OBJECT_H__