#include "SINFileOutputStream.h"

#include <fstream>
#include "SINAssert.h"
#include <new>

namespace SIN {

	FileOutputStream::FileOutputStream(String const& _filepath, mode_t _mode):
		filepath(_filepath),
		mode(_mode),
		fout(_filepath.c_str(), Mode(_mode).HasTruncate() ? std::ios_base::trunc : std::ios_base::out),
		file_open(false)
	{
		fout.close();
	}

	FileOutputStream::~FileOutputStream(void) {
		if (file_open) {
			SINASSERT(fout.is_open());
			fout.close();
		}
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
		SINASSERT(!fout.is_open());

		new (&fout) std::ofstream(filepath.c_str(), std::ios_base::app);

		return file_open = fout.good();
	}

	bool FileOutputStream::closeFile(void) {
		SINASSERT(file_open);
		SINASSERT(fout.is_open());

		fout.close();
		file_open = false;

		return fout.good();
	}

	bool FileOutputStream::DoesTruncate(void) const {
		return mode.HasTruncate();
	}

} // namespace SIN
