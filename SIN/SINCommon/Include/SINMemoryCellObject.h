#ifndef __MEMORY_CELL_OBJECT_H__
#define __MEMORY_CELL_OBJECT_H__


#include "SINObject.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellObject : public MemoryCell {
		
	public:
		MemoryCellObject(void) : MemoryCell() {}
		MemoryCellObject(Types::SINObject * obj) : MemoryCell(),  value(obj){}
		~MemoryCellObject();


		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type(void);
	
		void					SetValue (const Types::SINObject *);
		Types::SINObject *		GetValue (void);

	private:
		Types::SINObject * value;
	};
}

#endif	//__MEMORY_CELL_OBJECT_H__