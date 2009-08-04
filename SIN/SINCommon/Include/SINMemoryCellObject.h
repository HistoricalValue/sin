#ifndef __MEMORY_CELL_OBJECT_H__
#define __MEMORY_CELL_OBJECT_H__


#include "SINObject.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellObject : public MemoryCell {
		
	public:
		MemoryCellObject(void) : MemoryCell() {}
		MemoryCellObject(SINObject * obj) : MemoryCell(),  value(obj){}
		~MemoryCellObject();


		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type(void);
	
		void					SetValue (const SINObject *);
		const SINObject *		GetValue (void) const;

	private:
		SINObject * value;
	};
}

#endif	//__MEMORY_CELL_OBJECT_H__