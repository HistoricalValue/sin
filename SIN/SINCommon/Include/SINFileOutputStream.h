#ifndef __SIN_FILEOUTPUTSTREAM_H__
#define __SIN_FILEOUTPUTSTREAM_H__

#include "SINOutputStream.h"
#include "SINString.h"
#include <fstream>

namespace SIN {
    // File output stream: writes stream to specified file
    class FileOutputStream : public OutputStream {
        String filepath;
		unsigned int mode;
		std::ofstream fout;
		bool file_open;

		bool openFile(void);
		bool closeFile(void);
		bool truncate(void) const;
    public:
        static CLASSREADONLY(Truncate,unsigned int, 1 << 1);
        FileOutputStream(String const &filepath, unsigned int mode);
        virtual ~FileOutputStream(void);
        virtual bool write(char const *buf, size_t len); // returns true on success
    }; // class FileOutputStream
} // namespace SIN

#endif //__SIN_FILEOUTPUTSTREAM_H__
