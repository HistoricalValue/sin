#ifndef __SIN_FILEOUTPUTSTREAM_H__
#define __SIN_FILEOUTPUTSTREAM_H__

#include "SINOutputStream.h"
#include "SINString.h"
#include <fstream>
#include "SINAssert.h"

namespace SIN {
    // File output stream: writes stream to specified file
    class FileOutputStream : public OutputStream {
    public:
		typedef unsigned int mode_t;
		struct Mode {
			static inline mode_t Neutral (void) { return 0     ; }
			static inline mode_t Truncate(void) { return 1 << 1; }
			///
			static inline bool HasTruncate(Type<mode_t>::const_ref mode) { return Mode(mode).HasTruncate(); }
			///
			inline bool HasTruncate(void) const { return (mode & Truncate()) != 0; }
			///
			Mode(mode_t _mode): mode(_mode) {
				SINASSERT((mode & ~(Neutral() | Truncate())) == 0);
			}
		private:
			mode_t mode;
		};
		// Mode is a a bitwise-OR of Neutral and other modes
        FileOutputStream(String const &filepath, mode_t mode = Mode::Neutral());
        virtual ~FileOutputStream(void);
        virtual bool write(char const *buf, size_t len); // returns true on success

		bool DoesTruncate(void) const; // returns true if this truncates files on opening
	private:
		String filepath;
		Mode mode;
		std::ofstream fout;
		bool file_open;

		bool openFile(void);
		bool closeFile(void);
    }; // class FileOutputStream
} // namespace SIN

#endif //__SIN_FILEOUTPUTSTREAM_H__
