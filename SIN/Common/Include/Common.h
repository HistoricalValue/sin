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

namespace {
struct __ForeachAnyHolder {
private:
	bool assign;
public:
	__ForeachAnyHolder& Assign(void) { assign = true; return *this; }
	__ForeachAnyHolder& Read(void) { assign = false;  return *this; }
	template <typename _FromType> typename Type<_FromType>::ref operator =(_FromType const& _from) {
		static _FromType buf;
		if (assign)
			return buf = _from;
		else
			return buf;
	}
	template <typename _ToType> operator _ToType&(void) {
		register bool previous_assign = assign;
		register typename Type<_ToType>::ref result((*this).Read() = typename Type<_ToType>::type());
		assign = previous_assign;
		return result;
	}
	__ForeachAnyHolder(void): assign(true) { }
	template <typename _FromType> __ForeachAnyHolder(_FromType const& _from): assign(true)
		{ *this = _from; }
};
}
// WARNING (Terms of use)
// * Do not use for nested FOREACHes
// * ITERABLE.begin() will be called NUMEROUS times -- must be neutral
// --- Usage ----
// std::list<int> lis; lis.push_back(1); lis.push_back(20; lis.pushback(3);
// FOREACH(lis) std::cout << *ITER(lis) << std::endl;s
#define ITER(ITERABLE) Type<void*>::ForType(ITERABLE.begin()).CastRef(__h__)
#define FOREACH(ITERABLE) for (__ForeachAnyHolder __h__(ITERABLE.begin()); ITER(ITERABLE) != ITERABLE.end(); ++ITER(ITERABLE))

#endif //__SIN_COMMON_H__
