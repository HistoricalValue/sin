#include "SINOutputStream.h"
#include <iostream>
#include "SINString.h"

#include <cstring>

namespace SIN {

    OutputStream::OutputStream(void) {
    }

    OutputStream::~OutputStream(void) {
    }

    OutputStream &operator <<(OutputStream &o, char const *       val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, char               val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, unsigned char      val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, short int          val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, unsigned short int val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, int                val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, unsigned int       val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, long int           val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, unsigned long int  val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, float              val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }
    OutputStream &operator <<(OutputStream &o, double             val) { String s; s << val; o.write(s.c_str(), strlen(s.c_str())); return o; }




    // ----------- STDOUT ----------- //
#define __STDOUT std::cout
    __ReadOnly__STDOUT::operator OutputStream &(void) const {
        static class : public OutputStream {
        public:
            virtual bool write(char const *_buf, size_t _len) {
                __STDOUT.write(_buf, _len);
                return __STDOUT ? true : false;
            }
        } _;
        return _;
    }
    __ReadOnly__STDOUT STDOUT;

    // ----------- VOIDOUT ----------- //
    __ReadOnly__VOIDOUT::operator OutputStream &(void) const {
        static class : public OutputStream {
        public:
            virtual bool write(char const *_buf, size_t _len) {
                return true;
            }
        } _;
        return _;
    }
    __ReadOnly__VOIDOUT VOIDOUT;

} // namespace SIN
