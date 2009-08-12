#ifndef __SIN_MEMORY_CELL_NATIVE_RESOURCE_H__
#define __SIN_MEMORY_CELL_NATIVE_RESOURCE_H__

#include "SINMemoryCell.h"

namespace SIN {
	class MemoryCellNativeResource: public MemoryCell {
	public:
		typedef void* enclosed_t;

		virtual MemoryCell* Clone(void) const;
		virtual MemoryCellType Type(void) const;
		virtual String const ToString(void) const;

		MemoryCellNativeResource(enclosed_t const& data = 0x00);
		MemoryCellNativeResource(MemoryCellNativeResource const& = MemoryCellNativeResource(0x00));
		virtual ~MemoryCellNativeResource(void);

		void SetValue(enclosed_t const& value);
		enclosed_t const& GetValue(void) const;

	private:
		enclosed_t data;
	}; // class MemoryCellNativeResource
} // namespace SIN

#endif // __SIN_MEMORY_CELL_NATIVE_RESOURCE_H__
