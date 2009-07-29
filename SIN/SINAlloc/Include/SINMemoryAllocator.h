#ifndef __SIN_MEMORY_ALLOCATOR_H__
#define __SIN_MEMORY_ALLOCATOR_H__

#include <cstdlib>

namespace SIN {
	namespace Alloc {
		
		// Default implementation uses malloc/free
		class MemoryAllocator {
		public:
			virtual void* Allocate(size_t _size)
				{ return malloc(_size); }
			virtual void  Deallocate(void* _ptr)
				{ free(_ptr); }

			MemoryAllocator(void) { }
			MemoryAllocator(MemoryAllocator const& _other) { }
			virtual ~MemoryAllocator(void) { }
		}; // class MemoryAllocator
	} // namespace Alloc
} // namespace SIN

#endif // __SIN_MEMORY_ALLOCATOR_H__
