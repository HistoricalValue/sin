#include "SINMemoryCellNativeResource.h"

#include "SINAlloc.h"

namespace SIN {

	MemoryCellNativeResource::MemoryCellNativeResource(void* const& _data): data(_data) { }
	MemoryCellNativeResource::MemoryCellNativeResource(MemoryCellNativeResource const& _other):
	data(_other.data) { }
	MemoryCellNativeResource::~MemoryCellNativeResource(void) { }

	MemoryCell* MemoryCellNativeResource::Clone(void) const {
		return SINEWCLASS(MemoryCellNativeResource, (*this));
	}

	enum MemoryCell::MemoryCellType MemoryCellNativeResource::Type(void) const {
		return NATIVE_RESOURCE_MCT;
	}

	void MemoryCellNativeResource::SetValue(enclosed_t const& _data) {
		data = _data;
	}

	MemoryCellNativeResource::enclosed_t const& MemoryCellNativeResource::GetValue(void) const {
		return data;
	}
} // namespace SIN
