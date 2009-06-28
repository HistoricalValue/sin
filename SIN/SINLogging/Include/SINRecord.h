#ifndef __SIN_LOGGING_RECORD_H__
#define __SIN_LOGGING_RECORD_H__

#include <time.h>
#include "SINString.h"
#include "Common.h"
#include <new>
#include "SINOutputStream.h"

#define SIN_LOGGING_RECORD_NUMBER_OF_SEVERITIES 9
namespace SIN {
    namespace Logging {
        class Record : public ComparisonAware<Record> {
        public:
            enum Severity {FINEST, FINER, FINE, NOTICE, ATTENTION, WARNING, SERIOUS, ERROR, FATALITY};
        private:
            static time_t last_record_timestamp;
            static clock_t last_record_offset;

            const time_t timestamp; //time
            //const clock_t timestamp_offset; //clock in milliseconds
            const unsigned long int timestamp_offset;
            const String message;
            const enum Severity severity;

            static unsigned long int NextOffset(time_t _timestamp);
            // clock_t Record::NextOffset(time_t _timestamp) {
            Record(enum Severity, String const &msg, time_t timestamp);
        public:
            Record(Record const &);
            static Record CreateRecord(enum Severity sevirity, String const &message);
            SELF_ASSIGNMENT_OP(Record);

            time_t const &Timestamp(void) const;
            //clock_t Offset(void) const;
            unsigned long int Offset(void) const;
            String const &Message(void) const;
            enum Severity const &Severity(void) const;

            // ---
            bool operator ==(Record const &) const;
            bool operator  <(Record const &) const;
        }; // class Record

        extern String const string_cast(enum Record::Severity const &);
        extern OutputStream &operator <<(OutputStream &, enum Record::Severity const &);
        extern bool operator <(enum Record::Severity const &, enum Record::Severity const &);
    } // namespace Logging
} // namespace SIN

#endif //__SIN_LOGGING_RECORD_H__
