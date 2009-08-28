#ifndef __SIN_ALLOCATOR_H__
#define __SIN_ALLOCATOR_H__

// We only exist in _DEBUG
#ifdef _DEBUG
#include "SINMemoryAllocator.h"

namespace SIN {
	namespace Alloc {
		template <typename _T>
		// Implementing the std::allocator interface, using SIN::MemoryAllocator instead of new/delete
		struct Allocator {
			typedef _T			value_type;
			typedef _T*			pointer;
			typedef _T&			reference;
			typedef _T const*	const_pointer;
			typedef _T const&	const_reference;
			typedef size_t		size_type;
			typedef	ptrdiff_t	difference_type;

			Allocator(MemoryAllocator* _allocator = 0x00) throw (): allocator(_allocator) { }
			template <typename _FromType> Allocator(const Allocator<_FromType>& _other) throw (): allocator(_other.allocator) { }
			~Allocator(void) throw () { }

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

			bool			operator ==(Allocator<_T> const& _other) const
							{ return allocator == _other.allocator && allocator != 0x00; }

			template<class _Other> struct rebind {	// convert an Allocator<_T> to an Allocator <_Other>
				typedef Allocator<_Other> other;
			}; // struct rebind

			MemoryAllocator* allocator;
		}; // struct Allocator<T>

		template <> struct Allocator<void> {
			typedef void		_T;
			typedef _T			value_type;
			typedef _T*			pointer;
			typedef _T const*	const_pointer;
			typedef size_t		size_type;
			typedef	ptrdiff_t	difference_type;

			Allocator(MemoryAllocator* _allocator = 0x00) throw (): allocator(_allocator) { }
			template <typename _FromType> Allocator(const Allocator<_FromType>& _other) throw (): allocator(_other.allocator) { }
			~Allocator(void) throw () { }

			template<class _Other> struct rebind {	// convert an Allocator<void> to an Allocator <_Other>
				typedef Allocator<_Other> other;
			}; // struct rebind<_Other>


			bool	operator ==(Allocator<_T> const& _other) const
					{ return allocator == _other.allocator && allocator != 0x00; }


			MemoryAllocator* allocator;
		}; // struct Allocator<void>
	} // namespace Alloc
} // namespace SIN

#endif // _DEBUG
#endif // __SIN_ALLOCATOR_H__
