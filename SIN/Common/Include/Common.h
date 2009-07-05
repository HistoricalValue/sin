#ifndef __SIN_COMMON_H__
#define __SIN_COMMON_H__

#include <cassert>

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


#define READONLY(VAR,TYPE,VAL) extern class ___ReadOnly_##VAR##___ { public: operator TYPE(void) const { return VAL; } } VAR
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

template <typename _T>
class Type {
public:
	Type(void) { }
	Type(Type const &) { }
	~Type(void) { }
	typedef _T type;

	template <typename _FromType>
	static Type<_FromType> const MakeTypeFromObject(_FromType const &_dummy) {
		return Type<_FromType>();
	}

	template <typename _FromType> _T cast(_FromType &_obj) const {
		return static_cast<_T>(_obj);
	}

	template <typename _FromType> _T cast(_FromType const&_obj) const {
		return static_cast<_T>(_obj);
	}
}; // class Type<T>

#define FOREACH(ITERATOR_NAME,ITERATOR_TYPE,ITERABLE)	\
	for (												\
		ITERATOR_TYPE ITERATOR_NAME = ITERABLE.begin(); \
		ITERATOR_NAME != ITERABLE.end();				\
		++ITERATOR_NAME)

#endif //__SIN_COMMON_H__
