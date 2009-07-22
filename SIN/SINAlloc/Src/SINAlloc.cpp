#include "SINAlloc.h"
#include <cstdlib>
#include <map>
#include "SINAssert.h"

#define SINALLOC_ALLOCATION_TYPE_VARIABLE	(1 << 0)
#define SINALLOC_ALLOCATION_TYPE_ARRAY		(1 << 1)

// Private API Macros
#define SINALLOC_ALLOCATE_SIZE(SIZE)		(malloc((SIZE)))
#define SINALLOC_ALLOCATE(NUM, TYPE)		(static_cast<TYPE *>(SINALLOC_ALLOCATE_SIZE(sizeof(TYPE) * (NUM))))
#define SINALLOC_DEALLOCATE(POINTER)		(free(POINTER))
#define SINALLOC_CURRENTLY_ALLOCATED		(totally_allocated - totally_freed)
#define SINALLOC_UPDATE_MAXIMUM_ALLOCATED	SINASSERT(totally_allocated > totally_freed); maximum_allocated = maximum_allocated > SINALLOC_CURRENTLY_ALLOCATED ? maximum_allocated : SINALLOC_CURRENTLY_ALLOCATED
#define SINALLOC_ALLOCATED(S)				totally_allocated += (S); SINALLOC_UPDATE_MAXIMUM_ALLOCATED
#define SINALLOC_DEALLOCATED(S)				totally_freed += (S)
#define SINALLOC_IS_VALID_CHUNK_AND_CACHE_RESULT(C,SAVETO)	\
											(SAVETO = chunks_map.find(C)) != chunks_map.end()

namespace SIN {
	namespace Alloc {
		// *********************** Implementation private ***************** //
		namespace {
			class MemoryAllocator {
			public:
				void* Allocate(size_t size);
				void  Deallocate(void* ptr);
			}; // class MemoryAllocator

			class MemoryChunkValidator {
			public:
				typedef unsigned long int memory_count_t;

				inline void* Allocate(size_t const& _size, String const& _file, unsigned int const& _line) {
					register void* memory = allocator.Allocate(_size);
					if (memory != 0x00) {
						chunks_map.insert(std::make_pair(memory, Alloc::Chunk(memory, _size, _file, _line)));
						SINALLOC_ALLOCATED(_size);
					}
					return memory;
				}
				inline void  Deallocate(register void* const _memory_chunk) {
					register chunks_map_t::iterator deletee;
					if (SINALLOC_IS_VALID_CHUNK_AND_CACHE_RESULT(_memory_chunk, deletee)) {
						SINALLOC_DEALLOCATED(deletee->second.Size());
						chunks_map.erase(deletee);
					}
					else
						SINASSERT(false);
				}

				inline bool  IsValid(void* const _memory_chunk) const
					{ return chunks_map.find(_memory_chunk) != chunks_map.end(); }

				inline memory_count_t const TotallyAllocated(void) const
					{ return totally_allocated; }
				inline memory_count_t const TotallyFreed(void) const
					{ return totally_freed; }
				inline memory_count_t const MaximunAllocated(void) const {
					SINASSERT(TotallyAllocated() >= TotallyFreed());
					return maximum_allocated;
				}
				inline memory_count_t const RemainingToBeFreed(void) const {
					SINASSERT(TotallyAllocated() >= TotallyFreed());
					return TotallyAllocated() - TotallyFreed();
				}
				inline bool const MemoryLeaking(void) const
					{ return RemainingToBeFreed() > 0; }

				typedef std::map<void*, Chunk> chunks_map_t;
				inline chunks_map_t const& UnfreedChunks(void) const
					{ return chunks_map; }

				MemoryChunkValidator(MemoryAllocator* _allocator):
				allocator(*_allocator),
				totally_allocated(0x00),
				totally_freed(0x00),
				maximum_allocated(0x00)
				{ }
			private:
				chunks_map_t chunks_map;

				MemoryAllocator& allocator;

				memory_count_t totally_allocated;
				memory_count_t totally_freed;
				memory_count_t maximum_allocated;
			}; // class MemoryChunkValidator

			typedef unsigned char AllocationType;
			typedef std::map<void*, AllocationType> AllocationsTypesMap;
			static struct Singletons {
				MemoryAllocator allocator;
				MemoryChunkValidator validator;
				AllocationsTypesMap allocations_types;
				inline Singletons(void):validator(&allocator) { }
			}* P_singletons_p = 0x00; // struct Singletons
			static bool P_initialised = false;
		} // namespace 

		// *********************** Global functions *********************** //
		bool Initialise(void) {
			P_singletons_p = SINALLOC_ALLOCATE(1, struct Singletons);
			if ((P_initialised = (P_singletons_p != 0x00)))
				new(P_singletons_p) struct Singletons;
			return P_initialised;
		}

		void CleanUp(void) {
			if (P_initialised) {
				SINALLOC_DEALLOCATE(P_singletons_p);
				P_initialised = false;
			}
			else
				SINASSERT(false);
		}

		bool IsInitialised(void) {
			return P_initialised;
		}

		size_t TotallyAllocated(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator.TotallyAllocated() : 0x00;
		}
				
		size_t TotallyFreed(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator.TotallyFreed() : 0x00;
		}

		size_t MemoryLeaking(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator.RemainingToBeFreed() : 0xffffffff;
		}

		bool   MemoryLeak(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator.MemoryLeaking() : true;
		}

		size_t MaximumAllocated(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator.MaximunAllocated() : 0x00;
		}

		bool IsArrayAllocated(void* _p) {
			SINASSERT(P_initialised);
			return P_singletons_p->allocations_types[_p] == SINALLOC_ALLOCATION_TYPE_ARRAY;
		}

		bool IsValid(register void* const _p) {
			SINASSERT(P_initialised);
			return P_singletons_p->validator.IsValid(_p);
		}

		std::map<void*, Chunk> const UndeallocatedChunks(void) {
			std::map<void*, Chunk> result;
			if (P_initialised)
				result = P_singletons_p->validator.UnfreedChunks();
			else
				SINASSERT(false);
			return result;
		}

		// *********************** Memory Allocator *********************** //
		void* MemoryAllocator::Allocate(register size_t const _size) {
			return SINALLOC_ALLOCATE_SIZE(_size);
		}
		void  Deallocate(register void* const _ptr) {
			SINALLOC_DEALLOCATE(_ptr);
		}
	} // namespace Alloc
} // namespace SIN 

// ************************** New/Delete Operators ************************** //
namespace {
inline static void* __SINAlloc_new(register size_t const _size, register SIN::Alloc::AllocationType const& _allocation_type, register SIN::String const& _file, register unsigned int const _line) throw () {
	register void* result = 0x00;
	if (SIN::Alloc::P_initialised) {
		result = SIN::Alloc::P_singletons_p->validator.Allocate(_size, _file, _line);
		if (result != 0x00)
			SIN::Alloc::P_singletons_p->allocations_types.insert(
				std::make_pair(result, _allocation_type));
	}
	else
		SINASSERT(false);
	return result;
}
inline static void __SINAlloc_delete(register void* const _ptr, register SIN::Alloc::AllocationType const& _allocation_type) {
	if (SIN::Alloc::P_initialised) {
		SINASSERT(SIN::Alloc::P_singletons_p->validator.IsValid(_ptr));
		SIN::Alloc::P_singletons_p->validator.Deallocate(_ptr);
		SIN::Alloc::P_singletons_p->allocations_types.erase(_ptr);
	}
	else
		SINASSERT(false);
}
} // namespace
void* operator new(register size_t const _size, register SINAllocationIndicator const&, register SIN::String const& _file, register unsigned int const _line) throw() {
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_VARIABLE, _file, _line);
}
void* operator new[](register size_t const _size, register SINAllocationIndicator const&, register SIN::String const& _file, register unsigned int const _line) throw() {
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_ARRAY, _file, _line);
}
void operator delete(register void* const _ptr, SINAllocationIndicator const&, SIN::String const&, register unsigned int const) throw() {
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_VARIABLE);
}
void operator delete[](register void* const _ptr, SINAllocationIndicator const&, SIN::String const&, register unsigned int const) throw() {
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_ARRAY);
}
