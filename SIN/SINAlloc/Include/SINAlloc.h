#ifndef __SIN_ALLOC_H__
#define __SIN_ALLOC_H__

#include <map>
#include <string>
#include <cstring>
#include <list>
#include <set>
#include "SINAssert.h"
#include "SINAllocator.h"

#ifdef _MSC_VER // compiling with Microsoft Visual Studio
//disable the error: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
#pragma warning(disable:4290)
#endif // _MSC_VER

namespace SIN { namespace Alloc {
	extern bool Initialise(void);
	inline bool Init(void) { return Initialise(); }
	extern void CleanUp(void);
	inline void Cleanup(void) { CleanUp(); }
	extern bool IsInitialised(void);

// We only exist in _DEBUG
#ifdef _DEBUG
	typedef std::basic_string<char, std::char_traits<char>, Allocator<char> > String;

	extern size_t TotallyAllocated(void);
	extern size_t TotallyFreed(void);
	extern size_t MemoryLeaking(void);
	extern bool   MemoryLeak(void);
	extern size_t MaximumAllocated(void);

	extern bool IsArrayAllocated(void*);
	extern bool IsValid(void*); // TODO remove after refactoring
	extern bool IsValid_replacement(void const*); // TODO rename after refactoring

	extern Allocator<void> CreateADefaultAllocator(void); // TODO remove after refactoring (CreateUnmanagedAllocator)
	extern Allocator<void> CreateUnmanagedAllocator(void);

	class Chunk { // TODO remove after refactoring (Chunk_refactored)
		String file; // file allocated in
		unsigned int line; // line in file
		void* memory; // memory chunk
		size_t size;
	public:
		inline Chunk(void* const& _chunk, size_t _size, char const* const _file, unsigned int const& _line):
		file(_file, CreateADefaultAllocator()), line(_line), memory(_chunk), size(_size)
		{ }
		inline String const File(void) const { return file; }
		inline unsigned int const Line(void) const { return line; }
		inline void* const Memory(void) const { return memory; }
		inline size_t const Size(void) const  { return size; }
	}; // class Pointer
	typedef unsigned char AllocationType; // TODO remove after refactoring (AllocationType_refactored)
	enum AllocationType_refactored { VariableAllocationType, ArrayAllocationType }; // TODO rename after refactoring
	class Chunk_refactored {
	public:
		String file; // file allocated in
		unsigned int line; // line in file
		void* memory; // memory chunk
		size_t size;
		AllocationType_refactored allocation_type;
		Chunk_refactored(void* const&, size_t, char const* const, unsigned int const&, AllocationType_refactored const&);
		bool operator <(Chunk_refactored const& _other) const;
	}; // class Chunk

	typedef std::map<void*, Chunk, std::less<void*>, Allocator<std::pair<void*, Chunk> > > ChunksMap; // TODO remove after refactoring
	typedef std::set<Chunk_refactored, std::less<Chunk_refactored>, Allocator<Chunk_refactored> > ChunksSet;
	extern ChunksMap const UndeallocatedChunks(void); // TODO remove after refactoring
	extern ChunksSet const UndeallocatedChunks_repl(void); // TODO rename after refactoring
	extern Chunk const ChunkInformation(void* _ptr);

	typedef std::pair<const Chunk, const Chunk> DeallocationPair; // TODO remove after refactoring
	typedef std::list<DeallocationPair, Allocator<DeallocationPair> > DeallocationsList; // TODO remove after refactoring
	extern DeallocationsList DeallocatedChunks(void); // TODO remove after refactoring
	extern DeallocationsList DeallocatedChunksByMemory(void*); // TODO remove after refactoring
	extern DeallocationsList DeallocatedChunksByFileLine(char const*, unsigned int); // TODO remove after refactoring

	typedef std::pair<const Chunk_refactored, const Chunk_refactored> DeallocationPair_refactored; // TODO rename after refactoring
	typedef std::list<DeallocationPair_refactored, Allocator<DeallocationPair_refactored> > DeallocationsList_refactored; // TODO rename after refactoring
	extern DeallocationsList_refactored DeallocatedChunks_refactored(void); // TODO rename after refactoring
	extern DeallocationsList_refactored DeallocatedChunksByMemory_refactored(void*); // TODO rename after refactoring
	extern DeallocationsList_refactored DeallocatedChunksByFileLine_refactoreds(char const*, unsigned int); // TODO rename after refactoring

	template <typename T> inline T* ValidateAndUse(T* _ptr) {
		T* result = _ptr;
		if (!IsValid(_ptr)) {
			// For debugging inspection
			DeallocationsList by_mem(DeallocatedChunksByMemory(_ptr));
			SINASSERT(false);
			result = 0x00;
		}
		return result;
	}

	inline void* memcpy(void* const _to, const void* const _from, size_t const _len) {
		if (_len <= ChunkInformation(_to).Size())
			std::memcpy(_to, _from, _len);
		else
			SINASSERT(false);
		return _to;
	}

	template <typename _T>
	inline _T* memcpy(_T& _to, _T const& _from)
		{ return static_cast<_T*>(memcpy(&_to, &_from, sizeof(_T))); }


	extern void SetNextDeleteFileLineInfo(char const*, unsigned int);
	extern void ResetNextDeleteFileLineInfo(void);
#else
	inline void* memcpy(void* const _to, void const* const _from, size_t const _len) {
		return std::memcpy(_to, _from, _len);
	}
#endif // _DEBUG
} } // namespace Alloc / namespace SIN

#ifdef _DEBUG
// New/delete operators to be used
struct SINAllocationIndicator {};
extern void* operator new     (size_t size, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
extern void* operator new[]   (size_t size, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
extern void  operator delete  (void* ptr, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
extern void  operator delete[](void* ptr, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
#define SINEW(TYPE) SIN::Alloc::ValidateAndUse(new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE)
#define SINEWCLASS(TYPE, ARGS) SIN::Alloc::ValidateAndUse(new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE ARGS)
#define SINEWARRAY(TYPE, LENGTH) SIN::Alloc::ValidateAndUse(new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE[LENGTH])
#define SINDELETE(PTR) do {													\
	SIN::Alloc::SetNextDeleteFileLineInfo(__FILE__, __LINE__);				\
	SINASSERT(!SIN::Alloc::IsArrayAllocated(PTR));							\
	delete((PTR));															\
	SIN::Alloc::ResetNextDeleteFileLineInfo();								\
	} while(false)
#define SINDELETEARRAY(PTR) do {											\
	SIN::Alloc::SetNextDeleteFileLineInfo(__FILE__, __LINE__);				\
	SINASSERT(SIN::Alloc::IsArrayAllocated(PTR));							\
	delete[]((PTR));														\
	SIN::Alloc::ResetNextDeleteFileLineInfo();								\
	} while(false)
#define SINPTR(PTR) SIN::Alloc::ValidateAndUse((PTR))
#else // No _DEBUG
#define SINEW(TYPE) new TYPE
#define SINEWCLASS(TYPE, ARGS) new TYPE ARGS
#define SINEWARRAY(TYPE, LENGTH) new TYPE [LENGTH]
#define SINDELETE(PTR) delete ((PTR))
#define SINDELETEARRAY(PTR) delete[] ((PTR))
#define SINPTR(PTR) ((PTR))
#endif


#ifdef _DEBUG
// replacing new/delete -- not to be used
//scalar, throwing new and it matching delete
extern void* operator new (std::size_t const size) throw (std::bad_alloc);
extern void operator delete (void* ptr) throw();
//scalar, nothrow new and it matching delete
extern void* operator new (std::size_t size, const std::nothrow_t&) throw ();
extern void operator delete (void* ptr, const std::nothrow_t&) throw ();
//array throwing new and matching delete[]
extern void* operator new  [](std::size_t size) throw (std::bad_alloc);
extern void operator delete[](void* ptr) throw();
//array, nothrow new and matching delete[]
extern void* operator new [](std::size_t size, const std::nothrow_t&) throw(); // array nothrow new
extern void operator delete[](void* ptr, const std::nothrow_t&) throw(); // matching delete[]
#endif // _DEBUG

#endif // __SIN_ALLOC_H__
