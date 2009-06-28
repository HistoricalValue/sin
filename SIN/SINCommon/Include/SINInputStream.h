#ifndef __SIN_INPUTSTREAM_H__
#define __SIN_INPUTSTREAM_H__

#include "SINStream.h"

namespace SIN {

    class InputStream : public Stream {
    public:
        InputStream(void);
        virtual ~InputStream(void);
    }; // class InputStream

} // namespace SIN

#endif //__SIN_INPUTSTREAM_H__
