#include "SINRecordPrinter.h"
#include "SINConstants.h"
#include "SINAssert.h"

namespace SIN {
    namespace Logging {
        RecordPrinter::RecordPrinter(OutputStream &_out): out(_out) {
        }

        RecordPrinter::~RecordPrinter(void) {
        }

        void RecordPrinter::PrintRecord(Record const &_record) {
            static char buf[1024];
            out                                             <<
                '['                                         ;
            register size_t timestamp_len = strftime(
                    buf,
                    sizeof(buf),
                    "%Y-%m-%d %H:%M:%S ",
                    localtime(&_record.Timestamp()));
            SINASSERT(timestamp_len > 0u);
            out                                             <<
                (timestamp_len > 0u ? buf : " ??? ")        <<
                _record.Severity()                          <<
                "] "                                        <<
                _record.Message()                           <<
                ENDL;
        }
    } // namespace Logging
} // namespace SIN
