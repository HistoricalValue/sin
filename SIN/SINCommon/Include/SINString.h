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
		String const operator  *(unsigned int) const;

        bool operator==	(String const &) const;
        bool operator!=	(String const &) const;
        bool operator< 	(String const &) const;
		bool operator> 	(String const &) const;
		bool operator>=	(String const &) const;
		bool operator<=	(String const &) const;


		const char& operator[] ( size_t pos ) const;
		char&		operator[] ( size_t pos );
		
		size_t Length(void) const;
		String& Erase(size_t pos, size_t n);	// returns this
		String& DropLast(size_t n);				// returns this

        template <typename T> String &operator <<(T const &o)
            { *this += to_string(o); return *this; } 
        template <typename T> String const operator <<(T const &o) const
            { return *this + to_string(o); }

        char const *c_str(void) const;
    }; // class String

    /** "Default" provided string conversions for basic types */
    extern String const to_string(SIN::String const        &_val);
    extern String const to_string(char const *const        &_val);
    extern String const to_string(char const               &_val);
    extern String const to_string(unsigned char const      &_val);
    extern String const to_string(short int const          &_val);
    extern String const to_string(unsigned short int const &_val);
    extern String const to_string(int const                &_val);
    extern String const to_string(unsigned int const       &_val);
    extern String const to_string(long int const           &_val);
    extern String const to_string(unsigned long int const  &_val);
    extern String const to_string(float const              &_val);
    extern String const to_string(double const             &_val);
    extern String const to_string(void * const             &_val);

    /** Writing a String to an OutpuStream */
    extern OutputStream &operator <<(OutputStream &, String const &);
} // namespace SIN


#endif // __SIN_STRING_H__
