#ifndef __MEMORY_CELL_OBJECT_H__
#define __MEMORY_CELL_OBJECT_H__

#include "SINMemoryCell.h"
#include "SINTypes.h"


namespace SIN {

	class MemoryCellObject : public MemoryCell {
		
	public:
		MemoryCellObject(void) : MemoryCell() {}
		MemoryCellObject(const Types::Object_t& obj) : MemoryCell(),  value(obj){}
		~MemoryCellObject();


		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type(void);
		virtual const String	ToString(void) const;
	
		void					SetValue (const Types::Object_t& );
		Types::Object_t			GetValue (void) const;

	private:
		Types::Object_t value;
	};
}

#endif	//__MEMORY_CELL_OBJECT_H__