#ifndef __SIN_BUFFEREDOUTPUTSTREAM_H__
#define __SIN_BUFFEREDOUTPUTSTREAM_H__

#include "SINOutputStream.h"
#include "Common.h"

#define SIN_BUFFERED_OUTPUT_STREAM_BUFFER_LENGTH ((1 << 10) << 8) // 256KiB

namespace SIN {

	class BufferedOutputStream : public OutputStream {
		OutputStream& out;
		struct Buf {
			char* buf(void);
			size_t length(void) const;
			size_t freeLength(void) const;
			bool wouldOverflow(size_t appended_length) const;

			void empty(void);
			size_t append(char const* buf, size_t len); // returns the number of bytes appended

			Buf(void);
			~Buf(void);
		private:
			char buffer[SIN_BUFFERED_OUTPUT_STREAM_BUFFER_LENGTH];
			size_t buffer_length;
		} buf;
    public:
		BufferedOutputStream(OutputStream& underlying_output_stream);
		virtual ~BufferedOutputStream(void);

		virtual bool write(char const *buf, size_t len); // return true on success
		virtual void flush(void);
    }; // class OutputStream

} // namespace SIN

#endif // __SIN_BUFFEREDOUTPUTSTREAM_H__
