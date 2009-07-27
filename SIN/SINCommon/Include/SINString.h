#ifndef __SIN_STRING_H__
#define __SIN_STRING_H__

#include <string>
#include "Common.h"
#include "SINOutputStream.h"

namespace SIN {
    
	class String: public ComparisonAware<String> {
        std::string core;
    public:
        String(void);
        String(String const &);
        String(std::string const &);
        String(char const *);

        String const operator  +(String const &) const;
        String const operator  =(String const &);
        String const operator +=(String const &o)
            { return *this = *this + o; }

        bool operator ==(String const &) const;
        bool operator  <(String const &) const;

		size_t Length(void) const;
		String& Erase(size_t pos, size_t n);	// returns this
		String& DropLast(size_t n);				// returns this

        template <typename T> String &operator <<(T const &o)
            { *this += string_cast(o); return *this; } 
        template <typename T> String const operator <<(T const &o) const
            { return *this + string_cast(o); }

        char const *c_str(void) const;
    }; // class String

    /** "Default" provided string conversions for basic types */
    extern String const string_cast(SIN::String const        &_val);
    extern String const string_cast(char const *const        &_val);
    extern String const string_cast(char const               &_val);
    extern String const string_cast(unsigned char const      &_val);
    extern String const string_cast(short int const          &_val);
    extern String const string_cast(unsigned short int const &_val);
    extern String const string_cast(int const                &_val);
    extern String const string_cast(unsigned int const       &_val);
    extern String const string_cast(long int const           &_val);
    extern String const string_cast(unsigned long int const  &_val);
    extern String const string_cast(float const              &_val);
    extern String const string_cast(double const             &_val);
    extern String const string_cast(void * const             &_val);

    /** Writing a String to an OutpuStream */
    extern OutputStream &operator <<(OutputStream &, String const &);
} // namespace SIN


#endif // __SIN_STRING_H__
