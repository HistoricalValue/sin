#include "SINMemoryCellNativeResource.h"

#include "SINAlloc.h"
#include "SINAssert.h"

namespace SIN {

	MemoryCellNativeResource::MemoryCellNativeResource(void) { }
	MemoryCellNativeResource::MemoryCellNativeResource(MemoryCellNativeResource const& _other) {
		SINASSERT(!"Not allowed");
	}
	MemoryCellNativeResource::~MemoryCellNativeResource(void) { }


	enum MemoryCell::MemoryCellType MemoryCellNativeResource::Type(void) const {
		return NATIVE_RESOURCE_MCT;
	}
} // namespace SIN
