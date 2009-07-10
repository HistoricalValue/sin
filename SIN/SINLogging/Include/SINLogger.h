#ifndef __SIN_LOGGER_H__
#define __SIN_LOGGER_H__

#include <string>
#include "SINRecord.h"
#include "Common.h"
#include "SINRecordPrinter.h"

namespace SIN {
    
    class Logger {
    protected:
        String name;
        Logger(String const &name, enum Logging::Record::Severity const &critical_severity);
        enum Logging::Record::Severity critical_severity;
        bool shouldLog(enum Logging::Record::Severity const &_this_severity) const;
        InstanceProxy<Logging::RecordPrinter> rp_p;
    public:
        void SetCriticalSeverity(enum Logging::Record::Severity const& new_severity);
		enum Logging::Record::Severity const& GetCriticalSeverity(void) const;

        void SetRecordPrinter(Logging::RecordPrinter *const &_rp);

        virtual void Message(Logging::Record const &record) = 0;

        void Finest   (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::FINEST   , _message)); }
        void Finer    (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::FINER    , _message)); }
        void Fine     (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::FINE     , _message)); }
        void Notice   (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::NOTICE   , _message)); }
        void Attention(String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::ATTENTION, _message)); }
        void Warning  (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::WARNING  , _message)); }
        void Serious  (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::SERIOUS  , _message)); }
        void Error    (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::ERROR    , _message)); }
        void Fatality (String const &_message) { Message(Logging::Record::CreateRecord(Logging::Record::FATALITY , _message)); }

    }; // class Logger

} // namespace SIN

#endif //__SIN_LOGGER_H__
