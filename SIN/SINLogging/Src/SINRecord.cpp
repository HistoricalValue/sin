#include "SINRecord.h"
#include "SINAssert.h"

namespace SIN {
namespace Logging {

    Record::Record(enum Severity _severity, String const &_message, time_t _timestamp):
    timestamp(_timestamp), timestamp_offset(NextOffset(_timestamp)), message(_message), severity(_severity)
    {
    }

    Record::Record(Record const &_other):
    timestamp(_other.timestamp), timestamp_offset(_other.timestamp_offset), message(_other.message),
    severity(_other.severity)
    {
    }

    /** Getting time in milliseconds is platform depended. So currently
      * the offset is simply a serial number. */
    unsigned long int Record::NextOffset(time_t _timestamp) {
    // clock_t Record::NextOffset(time_t _timestamp) {
        static time_t last_timestamp = 0;
        //static clock_t last_timesamp_offset = clock();
        //clock_t result;
        static unsigned long int last_offset;
        unsigned long int result;
        if (_timestamp > last_timestamp) {
            last_timestamp = _timestamp;
            //result = last_timestamp_offset = 0;
            result = last_offset = 0;
        }
        else if (_timestamp == last_timestamp) {
            //clock_t new_offset = clock();
            //if (new_offset >= last_timestamp_offset)
            //    result = new_offset - last_timestamp_offset;
            //else {
            //  // TODO : do the maths in here
            //}
            //last_timesamp_offset = new_offset;
            result = ++last_offset;
        }
        else
            SINASSERT(!"_timestamp < last_timestamp");

        return result;
    }

    Record Record::CreateRecord(enum Severity _severity, String const &_message) {
        return Record(_severity, static_cast<String const &>(_message), time(NULL));
    }

    time_t const &Record::Timestamp(void) const {
        return timestamp;
    }

    // clock_t Record::Offset(void) const {
    unsigned long int Record::Offset(void) const {
        return timestamp_offset;
    }

    String const &Record::Message(void) const {
        return message;
    }
    
    enum Record::Severity const &Record::Severity(void) const {
        return severity;
    }

    bool Record::operator ==(Record const &_other) const {
        return
            Timestamp() == _other.Timestamp() &&
            Offset() == _other.Offset();
    }

    bool Record::operator <(Record const &_other) const {
        return
            Timestamp() < _other.Timestamp() ||
            (Timestamp() == _other.Timestamp() && Offset() < _other.Offset())
        ;
    }

#define OP_APPEND_TO_STRING_SEVERITY_CASE(SEV) case Record::SEV: result = #SEV; break
    String const to_string(enum Record::Severity const &sev) {
        char const *result = 0x00;
        switch (sev) {
            OP_APPEND_TO_STRING_SEVERITY_CASE(FINEST);
            OP_APPEND_TO_STRING_SEVERITY_CASE(FINER);
            OP_APPEND_TO_STRING_SEVERITY_CASE(FINE);
            OP_APPEND_TO_STRING_SEVERITY_CASE(NOTICE);
            OP_APPEND_TO_STRING_SEVERITY_CASE(ATTENTION);
            OP_APPEND_TO_STRING_SEVERITY_CASE(WARNING);
            OP_APPEND_TO_STRING_SEVERITY_CASE(SERIOUS);
            OP_APPEND_TO_STRING_SEVERITY_CASE(ERROR);
            OP_APPEND_TO_STRING_SEVERITY_CASE(FATALITY);
            default: SINASSERT(!"Illegal program state");
        }
        return result;
    }

    OutputStream &operator <<(OutputStream &_o, enum Record::Severity const &_sev) {
        return _o << to_string(_sev);
    }

} // namespace Logging
} // namespace SIN
