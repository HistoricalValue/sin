#include "SINFileOutputStream.h"

#include <fstream>
#include "SINAssert.h"

namespace SIN {

	CLASSREADONLYDEF(FileOutputStream, Truncate);

	FileOutputStream::FileOutputStream(String const& _filepath, unsigned int _mode):
	filepath(_filepath), mode(_mode), fout(), file_open(false)
	{ }

	FileOutputStream::~FileOutputStream(void) {
	}

	bool FileOutputStream::write(char const* buf, size_t len) {
		return
			openFile()					&&
			fout.write(buf, len).good()	&&
			closeFile()					&&
			true;
	}

	/// private utilities
	bool FileOutputStream::openFile(void) {
		SINASSERT(!file_open);

		std::ios_base::open_mode mode = std::ios_base::out;
		if (truncate())
			mode |= std::ios_base::trunc;
		new (&fout) std::ofstream(filepath.c_str(), mode);
		file_open = true;

		return fout.good();
	}

	bool FileOutputStream::closeFile(void) {
		SINASSERT(file_open);

		fout.close();
		file_open = false;

		return fout.good();
	}

	bool FileOutputStream::truncate(void) const {
		return mode & Truncate;
	}
} // namespace SIN
