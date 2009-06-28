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

    ///////////
    void operator =(T &_p) { (*this) = &_p; }
    T *operator ->(void) const { return &**this; }
}; // class InstanceProxy<T>

template <typename T>
class ConstInstanceProxy {
    T const *p;
public:
    ConstInstanceProxy(T const*_p = 0x00): p(_p) { }
    void operator =(T const *_p) { p = _p; }
    T const &operator  *(void) const { assert(p != 0x00); return *p; }
    operator T const *(void) const { return p; }

    ///////////
    void operator =(T const &_p) { (*this) = &_p; }
    T const *operator ->(void) const { return &**this; }
}; // class ConstInstanceProxy<T>

#endif //__SIN_COMMON_H__
