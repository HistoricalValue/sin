#include "SINLogger.h"

namespace SIN {
    using Logging::Record;

    Logger::Logger(String const &_name, enum Record::Severity const &_critical_severity):
    name(_name), critical_severity(_critical_severity)
    {
    }

    bool Logger::shouldLog(enum Logging::Record::Severity const &_this_severity) const {
        return _this_severity >= critical_severity;
    }

    void Logger::SetCriticalSeverity(enum Logging::Record::Severity const &new_severity) {
        critical_severity = new_severity;
    }

    enum Logging::Record::Severity const &Logger::GetCriticalSeverity(void) const {
        return critical_severity;
    }

    void Logger::SetRecordPrinter(Logging::RecordPrinter *const &_rp) {
        rp = _rp;
    }

} // namespcace SIN
