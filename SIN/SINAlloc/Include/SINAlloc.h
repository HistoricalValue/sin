#ifndef __SIN_ALLOC_H__
#define __SIN_ALLOC_H__

#include <map>
#include "SINAssert.h"
#include <string>
#include <cstring>

//disable the error: C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
#pragma warning(disable:4290)

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
		T* result = _ptr;
		if (!IsValid(_ptr)) {
			SINASSERT(false);
			result = 0x00;
		}
		return result;
	}


	// Pure virtual/abstract
	class MemoryAllocator {
	public:
		virtual void* Allocate(size_t size) = 0;
		virtual void  Deallocate(void* ptr) = 0;
		virtual ~MemoryAllocator(void) { }
	}; // class MemoryAllocator

	template <typename _T>
	// Implementing the std::allocator interface, using malloc instead of new
	struct DefaultAllocator {
		typedef _T			value_type;
		typedef _T*			pointer;
		typedef _T&			reference;
		typedef _T const*	const_pointer;
		typedef _T const&	const_reference;
		typedef size_t		size_type;
		typedef	ptrdiff_t	difference_type;

		DefaultAllocator(MemoryAllocator* _allocator = 0x00) throw (): allocator(_allocator) { }
		template <typename _FromType> DefaultAllocator(const DefaultAllocator<_FromType>& _other) throw (): allocator(_other.allocator) { }
		~DefaultAllocator(void) throw () { }

		pointer			address(reference		_o) const { return &_o; }
		const_pointer	address(const_reference	_o) const { return &_o; }

		pointer			allocate(size_type _size, void* const _hint = 0x00)
						{ return static_cast<pointer>(allocator->Allocate(sizeof(value_type) * _size)); }
		void			construct(pointer _ptr, const_reference _copy_val)
						{ new(_ptr) _T(_copy_val); }
		void			deallocate(pointer _ptr, size_type _num_of_els)
						{ allocator->Deallocate(_ptr); }
		void			destroy(pointer _ptr)
						{ _ptr->~_T(); }

		size_type		max_size(void) const throw ()
						{ return std::allocator<_T>().max_size(); }

		bool			operator ==(DefaultAllocator<_T> const& _other) const
						{ return allocator == _other.allocator && allocator != 0x00; }

		template<class _Other>
		struct rebind {	// convert an allocator<_T> to an allocator <_Other>
			typedef DefaultAllocator<_Other> other; };

		MemoryAllocator* allocator;
	}; // struct DefaultAllocator<T>

	template <> struct DefaultAllocator<void> {
		typedef void		_T;
		typedef _T			value_type;
		typedef _T*			pointer;
		typedef _T const*	const_pointer;
		typedef size_t		size_type;
		typedef	ptrdiff_t	difference_type;

		DefaultAllocator(void) throw () { }
		template <typename _FromType> DefaultAllocator(const DefaultAllocator<_FromType>&) throw () { }
		~DefaultAllocator(void) throw () { }

		template<class _Other> struct rebind {	// convert an allocator<void> to an allocator <_Other>
			typedef DefaultAllocator<_Other> other; };

		bool	operator ==(DefaultAllocator<void> const& _other) const { return true; }
	}; // struct DefaultAllocator<void>

	extern DefaultAllocator<void*> CreateADefaultAllocator(void);

	class Chunk {
		typedef std::basic_string<char, std::char_traits<char>, DefaultAllocator<char> > string;
		string file; // file allocated in
		unsigned int line; // line in file
		void* memory; // memory chunk
		size_t size;
	public:
		inline Chunk(void* const& _chunk, size_t _size, char const* const _file, unsigned int const& _line):
		file(_file, CreateADefaultAllocator()), line(_line), memory(_chunk), size(_size)
		{ }
		inline string const File(void) const { return file; }
		inline unsigned int const Line(void) const { return line; }
		inline void* const Memory(void) const { return memory; }
		inline size_t const Size(void) const  { return size; }
	}; // class Pointer

	typedef std::map<void*, Chunk, std::less<void*>, DefaultAllocator<std::pair<void*, Chunk> > > ChunksMap;
	extern ChunksMap const UndeallocatedChunks(void);
	inline Chunk ChunkInformation(void* _ptr) { return UndeallocatedChunks().find(_ptr)->second; }

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

} } // namespace Alloc / namespace SIN

// New/delete operators to be used
struct SINAllocationIndicator {};
extern void* operator new     (size_t size, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
extern void* operator new[]   (size_t size, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
extern void  operator delete  (void* ptr, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
extern void  operator delete[](void* ptr, SINAllocationIndicator const&, char const* file, unsigned int line) throw();
#define SINEW(TYPE) SIN::Alloc::ValidateAndUse(new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE)
#define SINEWCLASS(TYPE, ARGS) SIN::Alloc::ValidateAndUse(new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE ARGS)
#define SINEWARRAY(TYPE, LENGTH) SIN::Alloc::ValidateAndUse(new(SINAllocationIndicator(), __FILE__, __LINE__) TYPE[LENGTH])
#define SINDELETE(PTR) SIN::Alloc::IsArrayAllocated(PTR) ? delete[]((PTR)) : delete((PTR))
#define SINPTR(PTR) SIN::Alloc::ValidateAndUse((PTR))
#define SINMEMCPY(TO, FROM) if (sizeof((FROM)) <= SIN::Alloc::ChunkInformation(TO).Size())




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


#endif // __SIN_ALLOC_H__
