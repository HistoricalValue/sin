#ifndef __SIN_FILEOUTPUTSTREAM_H__
#define __SIN_FILEOUTPUTSTREAM_H__

#include "SINOutputStream.h"
#include "SINString.h"

namespace SIN {
    // File output stream: writes stream to specified file
    class FileOutputStream : public OutputStream {
        String filepath;
    public:
        READONLY(Truncate,unsigned int, 1 << 1);
        FileOutputStream(String const &filepath, unsigned int mode);
        virtual ~FileOutputStream(void);
        virtual bool write(char const *buf, size_t len); // returns true on success
    }; // class FileOutputStream
} // namespace SIN

#endif //__SIN_FILEOUTPUTSTREAM_H__
