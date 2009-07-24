#include "SINBufferedOutputStream.h"
#include "SINAssert.h"
#include "SINAlloc.h"

#define SIN_BUFFEREDOUTPUTSTREAM_BUF_USED_LENGTH			(buffer_length)
#define SIN_BUFFEREDOUTPUTSTREAM_BUF_FREE_LENGTH			(SIN_BUFFERED_OUTPUT_STREAM_BUFFER_LENGTH - SIN_BUFFEREDOUTPUTSTREAM_BUF_USED_LENGTH)
#define SIN_BUFFEREDOUTPUTSTREAM_BUF_WOULD_OVERFLOW(LEN)	((LEN) > SIN_BUFFEREDOUTPUTSTREAM_BUF_FREE_LENGTH)
#define SIN_BUFFEREDOUTPUTSTREAM_BUF_INCREASE_USED_LENGTH(A)	buffer_length += (A)
#define SIN_BUFFEREDOUTPUTSTREAM_BUF_DECREASE_USED_LENGTH(A)	SIN_BUFFEREDOUTPUTSTREAM_BUF_INCREASE_USED_LENGTH(-(A))
#define SIN_BUFFEREDOUTPUTSTREAM_BUF_IS_EMPTY	(SIN_BUFFEREDOUTPUTSTREAM_BUF_USED_LENGTH == 0u)
#define SIN_BUFFEREDOUTPUTSTREAM_BUF_MAKE_EMPTY	(buffer_length = 0)

namespace SIN {

	BufferedOutputStream::BufferedOutputStream(OutputStream& _out):
	out(_out)
	{ }

	BufferedOutputStream::~BufferedOutputStream(void) {
		flush();
	}

	bool BufferedOutputStream::write(char const *_buf, size_t _len) {
		register bool result = true;
		if (buf.wouldOverflow(_len)) {
			const size_t conjoined_buf_len = buf.length() + _len;
			char* conjoined_buf = SINEWARRAY(char, conjoined_buf_len);
			result = out.write(static_cast<char*>(
				memcpy(
					Alloc::memcpy(conjoined_buf, buf.buf(), buf.length()) + buf.length(),
					_buf, _len
				)),
				conjoined_buf_len
			);
			buf.empty();
			SINDELETE(conjoined_buf);
		}
		else {
			const register size_t appended_bytes =  buf.append(_buf, _len);
			if (appended_bytes > _len)
				SINASSERT(!"Weird (append() appends more than indicated bytes)");
			else if (appended_bytes < _len)
				result = false; // something is weird -- overflowing check is done before
			/* else result = true */
		}

		return result;
	}

	void BufferedOutputStream::flush(void) {
		out.write(buf.buf(), buf.length());
		buf.empty();
	}

	// private buffer manipulation
	BufferedOutputStream::Buf::Buf(void): buffer_length(0u)
	{ }
	BufferedOutputStream::Buf::~Buf(void) {
	}

	size_t BufferedOutputStream::Buf::append(char const* _buf, register size_t _len) {
		register const size_t free_len = SIN_BUFFEREDOUTPUTSTREAM_BUF_FREE_LENGTH;
		if (SIN_BUFFEREDOUTPUTSTREAM_BUF_WOULD_OVERFLOW(_len))
			_len = free_len;
		memcpy(buffer + SIN_BUFFEREDOUTPUTSTREAM_BUF_USED_LENGTH, _buf, _len);
		SIN_BUFFEREDOUTPUTSTREAM_BUF_INCREASE_USED_LENGTH(_len);
		return _len;
	}

	void BufferedOutputStream::Buf::empty(void) {
		SIN_BUFFEREDOUTPUTSTREAM_BUF_MAKE_EMPTY;
	}

	char *BufferedOutputStream::Buf::buf(void) {
		return buffer;
	}

	size_t BufferedOutputStream::Buf::length(void) const {
		return SIN_BUFFEREDOUTPUTSTREAM_BUF_USED_LENGTH;
	}

	bool BufferedOutputStream::Buf::wouldOverflow(register const size_t _len) const {
		return SIN_BUFFEREDOUTPUTSTREAM_BUF_WOULD_OVERFLOW(_len);
	}

} // namespace SIN
