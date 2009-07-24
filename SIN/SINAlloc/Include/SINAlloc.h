#ifndef __SIN_ALLOC_H__
#define __SIN_ALLOC_H__

#include "SINString.h"
#include <map>
#include "SINAssert.h"

namespace SIN { namespace Alloc {
	extern bool Initialise(void);
	inline bool Init(void) { return Initialise(); }
	extern void CleanUp(void);
	inline void Cleanup(void) { CleanUp(); }
	extern bool IsInitialised(void);
	
	extern size_t TotallyAllocated(void);
	extern size_t TotallyFreed(void);
	extern size_t MemoryLeaking(void);
	extern bool   MemoryLeak(void);
	extern size_t MaximumAllocated(void);

	extern bool IsArrayAllocated(void*);
	extern bool IsValid(void*);
	template <typename T> inline T* ValidateAndUse(T* _ptr) {
		register T* result = _ptr;
		if (!IsValid(_ptr)) {
			SINASSERT(false);
			result = 0x00;
		}
		return result;
	}


	class Chunk {
		String file; // file allocated in
		unsigned int line; // line in file
		void* memory; // memory chunk
		size_t size;
	public:
		inline Chunk(void* const& _chunk, size_t _size, String const& _file, unsigned int const& _line):
		file(_file), line(_line), memory(_chunk), size(_size)
		{ }
		inline String const File(void) const { return file; }
		inline unsigned int const Line(void) const { return line; }
		inline void* const Memory(void) const { return memory; }
		inline size_t const Size(void) const  { return size; }
	}; // class Pointer

	extern std::map<void*, Chunk> const UndeallocatedChunks(void);
	inline Chunk ChunkInformation(void* _ptr) { return UndeallocatedChunks().at(_ptr); }

	inline void* memcpy(register void* const _to, register const void* const _from, register size_t const _len) {
		if (_len <= ChunkInformation(_to).Size())
			std::memcpy(_to, _from, _len);
		else
			SINASSERT(false);
		return _to;
	}

	template <typename _T>
	inline _T* memcpy(register _T& _to, register _T const& _from)
		{ return static_cast<_T*>(memcpy(&_to, &_from, sizeof(_T))); }

} } // namespace Alloc / namespace SIN

////scalar, throwing new and it matching delete
//extern void* operator new (size_t size) throw (std::bad_alloc);
//extern void operator delete (void* ptr) throw();
////scalar, nothrow new and it matching delete
//extern void* operator new (std::size_t size,const std::nothrow_t&) throw ();
//extern void operator delete (void* ptr, const std::nothrow_t&) throw ();
////array throwing new and matching delete[]
//extern void* operator new  [](std::size_t size) throw (std::bad_alloc);
//extern void operator delete[](void* ptr) throw();
////array, nothrow new and matching delete[]
//extern void* operator new [](std::size_t size, const std::nothrow_t&) throw(); // array nothrow new
//extern void operator delete[](void* ptr, const std::nothrow_t&) throw(); // matching delete[]

// New/delete operators to be used
struct SINAllocationIndicator {};
extern void* operator new     (size_t size, SINAllocationIndicator const&, SIN::String const& file, unsigned int line) throw();
extern void* operator new[]   (size_t size, SINAllocationIndicator const&, SIN::String const& file, unsigned int line) throw();
extern void  operator delete  (void* ptr, SINAllocationIndicator const&, SIN::String const& file, unsigned int line) throw();
extern void  operator delete[](void* ptr, SINAllocationIndicator const&, SIN::String const& file, unsigned int line) throw();
#define SINEW(TYPE) new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE
#define SINEWCLASS(TYPE, ARGS) new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE ARGS
#define SINEWARRAY(TYPE, LENGTH) new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE[LENGTH]
#define SINDELETE(PTR) SIN::Alloc::IsArrayAllocated(PTR) ? operator delete[]((PTR), SINAllocationIndicator(), "", 0) : operator delete((PTR), SINAllocationIndicator(), "", 0)
#define SINPTR(PTR) SIN::Alloc::SafeDereferenceable(SIN::Alloc::ValidateAndUse((PTR)))
#define SINMEMCPY(TO, FROM) if (sizeof((FROM)) <= SIN::Alloc::ChunkInformation(TO).Size())
#endif // __SIN_ALLOC_H__
