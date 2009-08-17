#ifndef __SIN_MEMORY_CELL_NATIVE_RESOURCE_H__
#define __SIN_MEMORY_CELL_NATIVE_RESOURCE_H__

#include "SINMemoryCell.h"

namespace SIN {
	class MemoryCellNativeResource: public MemoryCell {
	public:
		virtual MemoryCell* Clone(void) const = 0;
		virtual MemoryCellType Type(void) const;
		virtual String const ToString(void) const = 0;

		MemoryCellNativeResource(void);
		virtual ~MemoryCellNativeResource(void);
	private:
		// Unusable
		inline MemoryCellNativeResource(MemoryCellNativeResource const&);
	}; // class MemoryCellNativeResource
} // namespace SIN

#endif // __SIN_MEMORY_CELL_NATIVE_RESOURCE_H__
