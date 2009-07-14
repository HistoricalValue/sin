#ifndef __SIN_COMMON_H__
#define __SIN_COMMON_H__

#include <cassert>
#include <cstring>

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

#define ULONG_MAX_STR "4294967295"
#define ULONG_MAX_STR_LEN 10

template <typename T> T const &min(T const &a, T const &b) {
    return a < b ? a : b;
}
template <typename T> T &min(T &a, T &b) {
    return a < b ? a : b;
}

template <typename T> T const &max(T const &a, T const &b) {
    return a > b ? a : b;
}
template <typename T> T &max(T &a, T &b) {
    return a > b ? a : b;
}


#define CLASSREADONLY(VAR,TYPE,VAL) class ___ReadOnly_##VAR##___ { public: operator TYPE(void) const { return VAL; } } VAR
#define CLASSREADONLYDEF(NS,VAR) class NS::___ReadOnly_##VAR##___ NS::VAR
#define READONLY(VAR,TYPE,VAL) extern CLASSREADONLY(VAR,TYPE,VAL)
#define READONLYDEF(VAR) class ___ReadOnly_##VAR##___ VAR

// Comparison operators for type T -- A subclass needs only to implement <(T) and ==(T)
template <typename T>
class ComparisonAware {
public:
    virtual ~ComparisonAware(void) { }
    virtual bool operator ==(T const &) const = 0;
    virtual bool operator  <(T const &) const = 0;
    bool operator <=(T const &other) const { return *this < other || *this == other; }
    bool operator !=(T const &other) const { return !(*this == other); }
    bool operator  >(T const &other) const { return !(*this <= other); }
    bool operator >=(T const &other) const { return *this > other || *this == other; }
}; // class ComparisonAware

#define ASSIGNMENT_OP(ME,FROM) ME const operator =(FROM const &_val) { return *new(this) ME(_val); }
#define SELF_ASSIGNMENT_OP(ME) ASSIGNMENT_OP(ME, ME)

template <typename T>
class InstanceProxy {
    T *p;
public:
    InstanceProxy(T *_p = 0x00): p(_p) { }
    void operator =(T *_p) { p = _p; }
    T &operator  *(void) const { assert(p != 0x00); return *p; }
    operator T *(void) const { return p; }

	template <typename _FromType>
	static InstanceProxy<_FromType> ProxyFor(_FromType &_obj) {
		return InstanceProxy<_FromType>(&_obj);
	}
    ///////////
    void operator =(T &_p) { (*this) = &_p; }
    T *operator ->(void) const { return &**this; }
	template <typename _FromType>
	static InstanceProxy<_FromType> ProxyFor(_FromType *_p)
		{ return ProxyFor(*_p); }
}; // class InstanceProxy<T>

template <typename T>
class ConstInstanceProxy {
    T const *p;
public:
    ConstInstanceProxy(T const*_p = 0x00): p(_p) { }
    void operator =(T const *_p) { p = _p; }
    T const &operator  *(void) const { assert(p != 0x00); return *p; }
    operator T const *(void) const { return p; }

	template <typename _FromType>
	static ConstInstanceProxy<_FromType> ProxyFor(_FromType const &_obj) {
		return ConstInstanceProxy<_FromType>(&_obj);
	}
    ///////////
    void operator =(T const &_p) { (*this) = &_p; }
    T const *operator ->(void) const { return &**this; }
	template <typename _FromType>
	static ConstInstanceProxy<_FromType> ProxyFor(_FromType const *_p)
		{ return ProxyFor(*_p); }
}; // class ConstInstanceProxy<T>

template <typename _Type>
_Type copy(_Type const &_o) { return _o; }

template <typename _Type>
struct Type {
	typedef _Type type;
	typedef type const const_type;
	typedef type& ref;
	typedef type const& const_ref;

	template <typename _FromType> static Type<_FromType> ForType(_FromType const& _) { return Type<_FromType>(); }

	template <typename _FromType> type Cast(_FromType const& _o) const { return _o; }
	template <typename _FromType> ref CastRef(_FromType& _o) const { return _o; }
	template <typename _FromType> const_ref CastConstRef(_FromType const& _o) { return _o; }
	template <typename _FromType> const_type CastConst(_FromType const& _o) { return _o; }
}; // class Type<T>

// A very very nasty AnyHolder
template <const unsigned int _Size>
class AnyHolder {
	char memory[_Size];
public:
	template <typename _FromType> AnyHolder(_FromType const& _holdee) {
		memcpy(memory, &_holdee, sizeof(memory));
	}
	template <typename _ToType> operator _ToType*(void) {
		assert(sizeof(_ToType) <= _Size);
		return static_cast<_ToType*>(static_cast<void*>(memory + 0));
	}

	/////////////////////////
	template <typename _ToType> operator _ToType&(void) {
		return *static_cast<_ToType*>(*this);
	}
};
// Foreach - works like a charm
// example:
//  std::list<int> lis; lis.push_back(9); lis.push_back(8); lis.push_back(7); lis.push_back(6);
//  FOREACH(lis)
//      out.Notice(SIN::string_cast(*ITER(lis)));
#define ITER(ITERABLE) (Type<void*>::ForType(ITERABLE.begin()).CastRef(ITERABLE__iterator))
#define FOREACH(ITERABLE)															\
	for (																			\
		AnyHolder<sizeof(ITERABLE.begin())> ITERABLE__iterator(ITERABLE.begin());	\
		ITER(ITERABLE) != ITERABLE.end()										;	\
		++ITER(ITERABLE)														)

// Native-array-type foreach-wrapper
template <typename T, const size_t N>
class ArrayIterableWrapper {
	typedef T(& ArrayType)[N];
	ArrayType arr;
public:
	ArrayIterableWrapper(ArrayType _arr): arr(_arr)
	{ }
	ArrayIterableWrapper(ArrayIterableWrapper<T,N> const& _other):
	arr(_other.arr)
	{ }
	~ArrayIterableWrapper(void) {
	}
	T* begin(void) const {
		return &arr[0];
	}
	T* end(void) const {
		return &arr[N];
	}
}; // ArrayIterableWrapper<T,N>

template <typename T, const size_t N>
class ConstArrayIterableWrapper {
public:
	typedef T const(& ArrayType)[N];
	ArrayType arr;
public:
	ConstArrayIterableWrapper(ArrayType _arr): arr(_arr)
	{ }
	ConstArrayIterableWrapper(ArrayIterableWrapper<T,N> const& _other):
	arr(_other.arr)
	{ }
	~ConstArrayIterableWrapper(void) {
	}
	T const* begin(void) const {
		return &arr[0];
	}
	T const* end(void) const {
		return &arr[N];
	}
}; // ConstArrayIterableWrapper<T,N>

template <typename T, const size_t N>
ConstArrayIterableWrapper<T, N> array_iterable(T const(& _arr)[N]) {
	return ConstArrayIterableWrapper<T, N>(_arr);
}

template <typename T, const size_t N>
ArrayIterableWrapper<T, N> array_iterable(T(& _arr)[N]) {
	return ArrayIterableWrapper<T, N>(_arr);
}


#endif //__SIN_COMMON_H__
