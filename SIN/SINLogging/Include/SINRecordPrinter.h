#ifndef __SIN_LOGGING_RECORDPRINTER_H__
#define __SIN_LOGGING_RECORDPRINTER_H__

#include <iostream>
#include "SINRecord.h"
#include "SINOutputStream.h"

namespace SIN {
	namespace Logging {
		class RecordPrinter {
		protected:
			OutputStream &out;
		public:
			RecordPrinter(OutputStream &_out = STDOUT);
			virtual ~RecordPrinter(void);

			virtual void PrintRecord(Record const &);
		}; // class RecordPrinter
	} // namespace Logging
} // namespace SIN

#endif //__SIN_LOGGING_RECORDPRINTER_H__
