#ifndef __SIN_OUTPUTSTREAM_H__
#define __SIN_OUTPUTSTREAM_H__

#include "SINStream.h"
#include <cstdlib>

namespace SIN {

    class OutputStream : public Stream {
    public:
        OutputStream(void);
        virtual ~OutputStream(void);

        virtual bool write(char const *buf, size_t len) = 0; // return true on success
    }; // class OutputStream

    extern OutputStream &operator <<(OutputStream &, char const *       );
    extern OutputStream &operator <<(OutputStream &, char               );
    extern OutputStream &operator <<(OutputStream &, unsigned char      );
    extern OutputStream &operator <<(OutputStream &, short int          );
    extern OutputStream &operator <<(OutputStream &, unsigned short int );
    extern OutputStream &operator <<(OutputStream &, int                );
    extern OutputStream &operator <<(OutputStream &, unsigned int       );
    extern OutputStream &operator <<(OutputStream &, long int           );
    extern OutputStream &operator <<(OutputStream &, unsigned long int  );
    extern OutputStream &operator <<(OutputStream &, float              );
    extern OutputStream &operator <<(OutputStream &, double             );

    // STDOUT read-only accessor
    extern class __ReadOnly__STDOUT {
    public:
        operator OutputStream &(void) const;
    } STDOUT;

    // Void output stream read-only accessor
    extern class __ReadOnly__VOIDOUT {
    public:
        operator OutputStream &(void) const;
    } VOIDOUT;

} // namespace SIN

#endif //__SIN_OUTPUTSTREAM_H__

