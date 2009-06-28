#include "SINLoggerManager.h"
#include "SINAssert.h"

namespace SIN {
    ////////////
    LoggerManager::DefaultLoggerFactory::DefaultLoggerFactory(
        InstanceProxy<RecordPrinter> const * const &_rp):
    rp(*_rp)
    {
    }
    LoggerManager::DefaultLoggerFactory::~DefaultLoggerFactory(void) {
    }
    Logger *LoggerManager::DefaultLoggerFactory::MakeDefaultLogger(String const &_name) {
        return new StreamLogger(_name, Logging::Record::FINEST, STDOUT, &rp);
    }
    void LoggerManager::DefaultLoggerFactory::DestroyDefaultLogger(Logger *_logger) {
        delete _logger;
    }

    ////////////
    LoggerManager::StreamLogger::StreamLogger(
        String const &_name,
        enum Logging::Record::Severity const &_report_level,
        OutputStream &_out,
        InstanceProxy<RecordPrinter> const * const &_rp):
    Logger(_name, _report_level), out(_out), rp(*_rp)
    {
    }
    LoggerManager::StreamLogger::~StreamLogger(void) {
    }
    void LoggerManager::StreamLogger::Message(Record const &_record) {
        if (shouldLog(_record.Severity())) {
            out << name << ' ';
            rp->PrintRecord(_record);
        }
    }

    ////////////
    bool LoggerManager::singleton_created = false;
    bool LoggerManager::singleton_destroyed = false;
    LoggerManager *LoggerManager::me = 0x00;

    void LoggerManager::SingletonCreate(void) {
        SINASSERT(!singleton_created);
        SINASSERT(!singleton_destroyed);
        me = new LoggerManager;
        singleton_created = true;
    }

    bool LoggerManager::SingletonCreated(void) {
        SINASSERT(!singleton_destroyed);
        return singleton_created;
    }

    void LoggerManager::SingletonDestroy(void) {
        SINASSERT(singleton_created);
        SINASSERT(!singleton_destroyed);
        delete me;
        singleton_destroyed = true;
    }

    LoggerManager *LoggerManager::SingletonGetInstance(void) {
        SINASSERT(singleton_created);
        SINASSERT(!singleton_destroyed);
        return singleton_created && !singleton_destroyed ? me : 0x00;
    }

    ////////////////
    LoggerManager::DefaultLoggerFactory*
    LoggerManager::SetDefaultLoggerFactory(LoggerManager::DefaultLoggerFactory *_f) {
        register DefaultLoggerFactory *previous = dlf;
        dlf = _f;
        return previous;
    }
    RecordPrinter *LoggerManager::SetDefaultRecordPrinter(RecordPrinter *_rp) {
        register RecordPrinter *previous = dlf_rp;
        dlf_rp = _rp;
        return previous;
    }
    LoggerManager::DefaultLoggerFactory* LoggerManager::GetDefaultLoggerFactory(void) const {
        return dlf;
    }
    RecordPrinter *LoggerManager::GetDefaultRecordPrinter(void) const {
        return dlf_rp;
    }

    ////////////////
    LoggerManager::LoggerManager(void):
    loggers(),
    dlf_rp(&dlf_rp_inst),
    dlf(&dlf_inst),
    dlf_inst(&dlf_rp),
    dlf_rp_inst(STDOUT)
    {
    }

    LoggerManager::LoggerManager(LoggerManager const &_other):
    loggers(),
    dlf_rp(&dlf_rp_inst),
    dlf(&dlf_inst),
    dlf_inst(&dlf_rp),
    dlf_rp_inst(STDOUT)
    {
        SINASSERT(!"Copy constructor cannot be called for singletons");
    }

    LoggerManager::~LoggerManager(void) {
    }

    ////////////////
    Logger &LoggerManager::GetLogger(String const &_logger_name) {
        std::map<String, Logger*>::const_iterator result = loggers.end();
        if ((result = loggers.find(_logger_name)) == loggers.end()) {
            result = loggers.insert(std::make_pair(_logger_name, (*dlf)(_logger_name))).first;
        }
        return *result->second;
    }
    Logger *LoggerManager::SetLogger(String const &_logger_name, Logger *_logger_p) {
        register Logger *result = 0x00;
        std::map<String, Logger*>::iterator previous = loggers.end();
        if ((previous = loggers.find(_logger_name)) != loggers.end()) {
            SINASSERT(previous->first == _logger_name);
            result = previous->second;
        }
        loggers[_logger_name] = _logger_p;
        return result;
    }

    ////////////////
    Logger *LoggerManager::MakeStreamLogger(String const &_logger_name, OutputStream &_out) {
        return SetLogger(
            _logger_name,
            new StreamLogger(
                _logger_name,
                GetLogger(_logger_name).GetCriticalSeverity(),
                _out,
                &dlf_rp)
            );
    }
    ////////////////
    Logger *LoggerManager::MakeVoidLogger(String const &_logger_name) {
        return MakeStreamLogger(_logger_name, VOIDOUT);
    }
    Logger *LoggerManager::MakeStdoutLogger(String const &_logger_name) {
        return MakeStreamLogger(_logger_name, STDOUT);
    }

} // namespace SIN
