#include "SINString.h"

#include <cstring>
#include <sstream>

#define SINSTRING_STRING_CAST_DEF(ARGCLASS)         \
    String const string_cast(ARGCLASS const &_val) {\
        return to_string(_val);                     \
    }

namespace SIN {

    //// Privates of shame
    template <typename T> static String to_string(T const &o) {
        std::ostringstream imp;
        imp << o;
        return imp.str();
    }
    //// -----------------

    String::String(void) {
    }

    String::String(std::string const &_core): core(_core) {
    }

    String::String(String const &_other): core(_other.core) {
    }

    String::String(char const *_str): core(_str) {
    }

    String const String::operator +(String const &_other) const {
        return String(core + _other.core);
    }

    String const String::operator =(String const &_other) {
        return *new (this) String(_other);
    }

    bool String::operator ==(String const &_other) const {
        return core == _other.core;
    }

    bool String::operator <(String const &_other) const {
        return core < _other.core;
    }

	size_t String::Length(void) const {
		return core.length();
	}

	String& String::Erase(size_t pos, size_t n) {
		core.erase(pos, n);
		return *this;
	}

	String& String::DropLast(size_t n) {
		return Erase(Length() - n, n);
	}

    char const *String::c_str(void) const {
        return core.c_str();
    }


    String const string_cast(String const &_val) {
        return _val;
    }
    SINSTRING_STRING_CAST_DEF(char const *       )
    SINSTRING_STRING_CAST_DEF(char               )
    SINSTRING_STRING_CAST_DEF(unsigned char      )
    SINSTRING_STRING_CAST_DEF(short int          )
    SINSTRING_STRING_CAST_DEF(unsigned short int )
    SINSTRING_STRING_CAST_DEF(int                )
    SINSTRING_STRING_CAST_DEF(unsigned int       )
    SINSTRING_STRING_CAST_DEF(long int           )
    SINSTRING_STRING_CAST_DEF(unsigned long int  )
    SINSTRING_STRING_CAST_DEF(float              )
    SINSTRING_STRING_CAST_DEF(double             )
	SINSTRING_STRING_CAST_DEF(void *             )

    // --- OutputStream << String
    OutputStream &operator <<(OutputStream &o, String const &s) {
        return o << s.c_str();
    }

} // namespace SIN
