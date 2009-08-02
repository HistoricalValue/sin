#include "SINAlloc.h"
#include <cstdlib>
#include <map>
#include "SINAssert.h"
#include <memory>
#include "Common.h"
#include <list>

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
#define SINALLOC_MAKE_A_DEFAULT_ALLOCATOR	Allocator<void>(P_singletons_p->allocator)

namespace SIN {
	namespace Alloc {
		// *********************** Implementation private ***************** //
		namespace {
			class MemoryChunkValidator {
			public:
				typedef unsigned long int memory_count_t;

				inline void* Allocate(size_t const& _size, char const* _file, unsigned int const& _line) {
					void* memory = allocator.Allocate(_size);
					if (memory != 0x00) {
						SINASSERT(!IsValid(memory) || !"Reallocating to memory address -- probably not SINDELETEd");
						chunks_map.insert(std::make_pair(memory, Alloc::Chunk(memory, _size, _file, _line)));
						cache.is_valid = false;
						SINALLOC_ALLOCATED(_size);
					}
					return memory;
				}
				inline void  Deallocate(void* const _memory_chunk, char const* const _file, unsigned int const _line) {
					ChunksMap::iterator deletee;
					if (SINALLOC_IS_VALID_CHUNK_AND_CACHE_RESULT(_memory_chunk, deletee)) {
						deallocations.push_back(std::pair<const Chunk, const Chunk>(deletee->second, Chunk(_memory_chunk, 0, _file, _line)));

						SINALLOC_DEALLOCATED(deletee->second.Size());
						chunks_map.erase(deletee);
						cache.is_valid = false;
					}
					else
						SINASSERT(false);
				}

				inline bool  IsValid(void* const _memory_chunk) const {
//					cache.is_valid = true;
					return
						//(
						//	cache.is_valid					&&
						//	cache.chunk == _memory_chunk	&&
						//	cache.is_valid_chunk
						//) ||
						//(
						//	(cache.is_valid = true)	&&
						//	(cache.is_valid_chunk = chunks_map.find(cache.chunk = _memory_chunk) != chunks_map.end())
						//);
						chunks_map.find(_memory_chunk) != chunks_map.end();
				}

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

				inline ChunksMap const& UnfreedChunks(void) const
					{ return chunks_map; }
				inline DeallocationsList const& Deallocations(void) const
					{ return deallocations; }

				MemoryChunkValidator(MemoryAllocator* _allocator):
				chunks_map(std::less<void*>(), Allocator<std::pair<void*, Chunk> >(_allocator)),
				allocator(*_allocator),
				totally_allocated(0),
				totally_freed(0),
				maximum_allocated(0),
				deallocations(Allocator<std::pair<Chunk, Chunk> >(_allocator))
				{ }
			private:
				ChunksMap chunks_map;

				MemoryAllocator& allocator;

				memory_count_t totally_allocated;
				memory_count_t totally_freed;
				memory_count_t maximum_allocated;

				DeallocationsList deallocations;

				struct Cache {
					volatile bool is_valid; // is the cache valid (or is it outdated?)
					volatile void* chunk; // last memory chunk validated
					volatile bool is_valid_chunk; // was last memory chunk validated valid
				}; volatile Cache cache;
			}; // class MemoryChunkValidator

			typedef unsigned char AllocationType;
			typedef std::pair<void*, AllocationType> AllocationTypeEntry;
			typedef Allocator<AllocationTypeEntry> AllocationsTypesMapAllocator;
			typedef std::map<void*, AllocationType, std::less<void*>, AllocationsTypesMapAllocator> AllocationsTypesMap;
			static struct Singletons {
				MemoryAllocator* allocator;
				MemoryChunkValidator* validator;
				AllocationsTypesMap* allocations_types;
				struct NextDeleteInfo {
					MemoryAllocator* allocator;
					String file;
					unsigned int line;
					NextDeleteInfo(MemoryAllocator* _allocator): allocator(_allocator), file(_allocator), line(0u) { }
					void Reset(void) { MemoryAllocator* _allocator = allocator; new(this) NextDeleteInfo(_allocator); }
				}* next_delete_info;
			}* P_singletons_p = 0x00; // struct Singletons
			static bool P_initialised = false;
		} // namespace 

		// *********************** Global functions *********************** //
		bool Initialise(void) {
			if (!P_initialised) {
				P_singletons_p = SINALLOC_ALLOCATE(1, struct Singletons);
				bool nobody_failed = (P_singletons_p != 0x00);
				if (nobody_failed)
					new(P_singletons_p) struct Singletons;
				if (nobody_failed) {
					nobody_failed = (P_singletons_p->allocator = SINALLOC_ALLOCATE(1, MemoryAllocator)) != 0x00;
					new(P_singletons_p->allocator) MemoryAllocator;
				}
				if (nobody_failed) {
					nobody_failed = (P_singletons_p->validator = SINALLOC_ALLOCATE(1, MemoryChunkValidator)) != 0x00;
					new(P_singletons_p->validator) MemoryChunkValidator(P_singletons_p->allocator);
				}
				if (nobody_failed) {
					nobody_failed = (P_singletons_p->allocations_types = SINALLOC_ALLOCATE(1, AllocationsTypesMap)) != 0x00;
					new(P_singletons_p->allocations_types) AllocationsTypesMap(std::less<void*>(), AllocationsTypesMapAllocator(P_singletons_p->allocator));
				}
				if (nobody_failed) {
					nobody_failed = (P_singletons_p->next_delete_info = SINALLOC_ALLOCATE(1, Singletons::NextDeleteInfo)) != 0x00;
					new(P_singletons_p->next_delete_info) struct Singletons::NextDeleteInfo(P_singletons_p->allocator);
				}
				P_initialised = nobody_failed;
			}
			else
				SINASSERT(false);
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
			return P_initialised ? P_singletons_p->validator->TotallyAllocated() : 0x00;
		}
				
		size_t TotallyFreed(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator->TotallyFreed() : 0x00;
		}

		size_t MemoryLeaking(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator->RemainingToBeFreed() : 0xffffffff;
		}

		bool   MemoryLeak(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator->MemoryLeaking() : true;
		}

		size_t MaximumAllocated(void) {
			SINASSERT(P_initialised);
			return P_initialised ? P_singletons_p->validator->MaximunAllocated() : 0x00;
		}

		bool IsArrayAllocated(void* _p) {
			SINASSERT(P_initialised);
			return P_singletons_p->allocations_types->find(SINPTR(_p))->second == SINALLOC_ALLOCATION_TYPE_ARRAY;
		}

		bool IsValid(void* const _p) {
			SINASSERT(P_initialised);
			return P_singletons_p->validator->IsValid(_p);
		}

		ChunksMap const UndeallocatedChunks(void) {
			if (P_initialised) {
//				ChunksMap result(std::less<void*>(), Allocator<std::pair<void*, Chunk> >(P_singletons_p->allocator));
//				MemoryChunkValidator::chunks_map_t const& chunks(P_singletons_p->validator->UnfreedChunks());
//				FOREACH(chunks)
//					result.insert(std::make_pair(ITER(chunks)->first, ITER(chunks)->second))
//				MemoryChunkValidator::chunks_map_t::const_iterator const end = chunks.end();
//				for (MemoryChunkValidator::chunks_map_t::const_iterator ite = chunks.begin(); ite != end; ++ite)
//					result.insert(std::make_pair(ite->first, ite->second));
//				return result;
				return P_singletons_p->validator->UnfreedChunks();
			}
			else
				SINASSERT(false);
			return ChunksMap();
		}

		Chunk const ChunkInformation(void* _ptr) {
			if (P_initialised) {
				ChunksMap::const_iterator result = P_singletons_p->validator->UnfreedChunks().find(_ptr);
				SINASSERT(result != P_singletons_p->validator->UnfreedChunks().end());
				return result->second;
			}
			else
				SINASSERT(false);
			return Chunk(0x00, 0x00, "", 0x00);
		}

		Allocator<void> CreateADefaultAllocator(void) {
			SINASSERT(P_initialised);
			return SINALLOC_MAKE_A_DEFAULT_ALLOCATOR;
		}

		template <typename _PredT>
		static DeallocationsList __DeallocationsListSelect(_PredT const& _pred) {
			SINASSERT(P_initialised);
			DeallocationsList result(CreateADefaultAllocator());
			DeallocationsList const& deallocs = P_singletons_p->validator->Deallocations();
			DeallocationsList::const_iterator const end = deallocs.end();
			DeallocationsList::const_iterator ite = deallocs.begin();
			for (; ite != end; ++ite)
				if (_pred(*ite))
					result.push_back(*ite);
			return result;
		}

		namespace DeallocationsListFilters {
			struct MemEq {
				void* const mem;
				MemEq(void* const _mem = 0x00): mem(_mem) { }
				bool operator ()(DeallocationPair const& _p) const
					{ return _p.first.Memory() == mem; }
			}; // struct MemEq
			struct FileLineEq {
				String const file;
				unsigned int const line;
				FileLineEq(char const* const _file, unsigned int const _line): file(_file), line(_line) { }
				bool operator ()(DeallocationPair const& _p) const
					{ return _p.first.File() == file && _p.first.Line() == line; }
			}; // struct FileLineEq
		} // namespace DeallocationsListFilters
		DeallocationsList DeallocatedChunksByMemory(void* const _mem)
			{ return __DeallocationsListSelect(DeallocationsListFilters::MemEq(_mem)); }
		DeallocationsList DeallocatedChunksByFileLine(char const* const _file, unsigned int const _line)
			{ return __DeallocationsListSelect(DeallocationsListFilters::FileLineEq(_file, _line)); }
		DeallocationsList DeallocatedChunks(void)
			{ return P_singletons_p->validator->Deallocations(); }


		void SetNextDeleteFileLineInfo(char const* const _file, unsigned int const _line) {
			SINASSERT(P_initialised);
			P_singletons_p->next_delete_info->file = _file;
			P_singletons_p->next_delete_info->line = _line;
		}
	} // namespace Alloc
} // namespace SIN

// ************************** New/Delete Operators ************************** //
namespace {
inline static void* __SINAlloc_new(size_t const _size, SIN::Alloc::AllocationType const& _allocation_type, char const* _file, unsigned int const _line) throw () {
	void* result = 0x00;
	if (SIN::Alloc::P_initialised) {
		result = SIN::Alloc::P_singletons_p->validator->Allocate(_size, _file, _line);
		if (result != 0x00)
			SIN::Alloc::P_singletons_p->allocations_types->insert(
				std::make_pair(result, _allocation_type));
	}
	else
		SINASSERT(false);
	return result;
}
inline static void __SINAlloc_delete(void* const _ptr, SIN::Alloc::AllocationType const& _allocation_type) {
	if (SIN::Alloc::P_initialised) {
		SINASSERT(SIN::Alloc::P_singletons_p->validator->IsValid(_ptr));
		SIN::Alloc::P_singletons_p->validator->Deallocate(_ptr, SIN::Alloc::P_singletons_p->next_delete_info->file.c_str(), SIN::Alloc::P_singletons_p->next_delete_info->line);
		SIN::Alloc::P_singletons_p->next_delete_info->Reset();
		SIN::Alloc::P_singletons_p->allocations_types->erase(_ptr);
	}
	else
		SINASSERT(false);
}
} // namespace
void* operator new(size_t const _size, SINAllocationIndicator const&, char const* const _file, unsigned int const _line) throw() {
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_VARIABLE, _file, _line);
}
void* operator new[](size_t const _size, SINAllocationIndicator const&, char const* const _file, unsigned int const _line) throw() {
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_ARRAY, _file, _line);
}
void operator delete(void* const _ptr, SINAllocationIndicator const&, char const* const, unsigned int const) throw() {
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_VARIABLE);
}
void operator delete[](void* const _ptr, SINAllocationIndicator const&, char const* const, unsigned int const) throw() {
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_ARRAY);
}


// Default C++ new/delete operators
//scalar, throwing new and it matching delete
void* operator new (std::size_t const _size) throw (std::bad_alloc) {
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_VARIABLE, "", 0);
}
void operator delete (void* const _ptr) throw() {
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_ARRAY);
}
//scalar, nothrow new and it matching delete
void* operator new (std::size_t const _size, const std::nothrow_t&) throw () {
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_VARIABLE, "", 0);
}
void operator delete (void* const _ptr, const std::nothrow_t&) throw () {
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_ARRAY);
}
//array throwing new and matching delete[]
void* operator new  [](std::size_t const _size) throw (std::bad_alloc) {
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_ARRAY, "", 0);
}
void operator delete[](void* const _ptr) throw() {
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_ARRAY);
}
//array, nothrow new and matching delete[]
void* operator new [](std::size_t const _size, const std::nothrow_t&) throw() { // array nothrow new
	return __SINAlloc_new(_size, SINALLOC_ALLOCATION_TYPE_ARRAY, "", 0);
}
void operator delete[](void* const _ptr, const std::nothrow_t&) throw() { // matching delete[]
	__SINAlloc_delete(_ptr, SINALLOC_ALLOCATION_TYPE_ARRAY);
}
