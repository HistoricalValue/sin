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

	BufferedOutputStream::BufferedOutputStream(OutputStream* _out_p):
	out_p(_out_p)
	{ }

	BufferedOutputStream::BufferedOutputStream(OutputStream& _out):
	out_p(&_out)
	{ }
	BufferedOutputStream::BufferedOutputStream(BufferedOutputStream const& _o):
	out_p(_o.out_p), buf(_o.buf)
	{ }

	BufferedOutputStream::~BufferedOutputStream(void) {
		flush();
	}

	bool BufferedOutputStream::write(char const *_buf, size_t _len) {
		bool result = true;
		if (buf.wouldOverflow(_len)) {
			if ((result = (out_p != 0x00))) {
				const size_t conjoined_buf_len = buf.length() + _len;
				char* conjoined_buf = SINEWARRAY(char, conjoined_buf_len);
				result = out_p->write(static_cast<char*>(
					memcpy(
						static_cast<char*>(Alloc::memcpy(conjoined_buf, buf.buf(), buf.length())) + buf.length(),
						_buf, _len
					)),
					conjoined_buf_len
				);
				buf.empty();
				SINDELETE(conjoined_buf);
			}
		}
		else {
			const size_t appended_bytes =  buf.append(_buf, _len);
			if (appended_bytes > _len)
				SINASSERT(!"Weird (append() appends more than indicated bytes)");
			else if (appended_bytes < _len)
				result = false; // something is weird -- overflowing check is done before
			/* else result = true */
		}

		return result;
	}

	void BufferedOutputStream::SetOut(OutputStream* _out_p) {
		out_p = _out_p;
	}
	OutputStream* BufferedOutputStream::GetOut(void) const {
		return out_p;
	}
	bool BufferedOutputStream::IsBuffer(void) const {
		return out_p == 0x00;
	}

	void BufferedOutputStream::flush(void) {
		out_p->write(buf.buf(), buf.length());
		buf.empty();
	}

	// private buffer manipulation
	BufferedOutputStream::Buf::Buf(void): buffer_length(0u)
	{ }
	BufferedOutputStream::Buf::Buf(Buf const& _o): buffer_length(_o.buffer_length) {
		::memcpy(buffer, _o.buffer, sizeof(buffer)/sizeof(buffer[0]));
	}
	BufferedOutputStream::Buf::~Buf(void) {
	}

	size_t BufferedOutputStream::Buf::append(char const* _buf, size_t _len) {
		const size_t free_len = SIN_BUFFEREDOUTPUTSTREAM_BUF_FREE_LENGTH;
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

	bool BufferedOutputStream::Buf::wouldOverflow(const size_t _len) const {
		return SIN_BUFFEREDOUTPUTSTREAM_BUF_WOULD_OVERFLOW(_len);
	}

} // namespace SIN
