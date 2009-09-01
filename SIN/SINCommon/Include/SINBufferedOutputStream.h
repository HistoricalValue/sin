#ifndef __SIN_BUFFEREDOUTPUTSTREAM_H__
#define __SIN_BUFFEREDOUTPUTSTREAM_H__

#include "SINOutputStream.h"
#include "Common.h"

#define SIN_BUFFERED_OUTPUT_STREAM_BUFFER_LENGTH ((1 << 10) << 7) // 256KiB

namespace SIN {

	// Buffers up to SIN_BUFFERED_OUTPUT_STREAM_BUFFER_LENGTH bytes before 
	// writing them to the underlying stream.
	// If the underlying stream's pointer is NULL and this buffer is full,
	// then subsequent writes will fail until an underlying output stream is
	// set. This way, the BufferedOutputStream can be used as a buffer.
	class BufferedOutputStream : public OutputStream {
		OutputStream* out_p;
		struct Buf {
			char* buf(void);
			size_t length(void) const;
			size_t freeLength(void) const;
			bool wouldOverflow(size_t appended_length) const;

			void empty(void);
			size_t append(char const* buf, size_t len); // returns the number of bytes appended

			Buf(void);
			Buf(Buf const&);
			~Buf(void);
		private:
			char buffer[SIN_BUFFERED_OUTPUT_STREAM_BUFFER_LENGTH];
			size_t buffer_length;
		} buf;
    public:
		BufferedOutputStream(OutputStream* underlying_output_stream_p = 0x00);
		BufferedOutputStream(OutputStream& underlying_output_stream);
		BufferedOutputStream(BufferedOutputStream const&);
		virtual ~BufferedOutputStream(void);
		void SetOut(OutputStream* out);
		OutputStream* GetOut(void) const;
		bool IsBuffer(void) const; 

		virtual bool write(char const *buf, size_t len); // return true on success
		virtual void flush(void);
    }; // class OutputStream

} // namespace SIN

#endif // __SIN_BUFFEREDOUTPUTSTREAM_H__
