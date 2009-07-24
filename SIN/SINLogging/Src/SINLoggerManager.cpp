#include "SINLoggerManager.h"
#include "SINAssert.h"
#include "SINAlloc.h"

namespace SIN {
	///////////// DefaultLoggerFactory /////////////
	LoggerManager::DefaultLoggerFactory::DefaultLoggerFactory(
		InstanceProxy<RecordPrinter> const* _rp_prx_p,
		InstanceProxy<enum Record::Severity> const* _default_severity_prx_p):
	rp_p(*_rp_prx_p), default_severity_p(*_default_severity_prx_p)
	{ }
	LoggerManager::DefaultLoggerFactory::~DefaultLoggerFactory(void) {
	}

	///////////// DefaultDefaultLoggerFactory /////////////
	LoggerManager::DefaultDefaultLoggerFactory::DefaultDefaultLoggerFactory(
		InstanceProxy<RecordPrinter> const* _rp_p,
		InstanceProxy<enum Record::Severity> const* _default_severity_p):
	DefaultLoggerFactory(_rp_p, _default_severity_p)
	{
	}
	LoggerManager::DefaultDefaultLoggerFactory::~DefaultDefaultLoggerFactory(void) {
	}
	Logger *LoggerManager::DefaultDefaultLoggerFactory::MakeLogger(String const &_name) {
		return SINEWCLASS(StreamLogger, (_name, *default_severity_p, STDOUT, *rp_p));
	}
	void LoggerManager::DefaultDefaultLoggerFactory::DestroyLogger(Logger *_logger) {
		SINDELETE(_logger);
	}

	///////////// StreamLogger /////////////
	LoggerManager::StreamLogger::StreamLogger(
		String const &_name,
		enum Logging::Record::Severity const &_report_level,
		OutputStream &_out,
		RecordPrinter const &_rp):
	Logger(_name, _report_level), out(_out), rp(_rp)
	{
	}
	LoggerManager::StreamLogger::~StreamLogger(void) {
	}
	void LoggerManager::StreamLogger::Message(Record const &_record) {
		if (shouldLog(_record.Severity())) {
			out << name << ' ';
			rp.PrintRecord(_record);
		}
	}

	//////////// LoggerManager Singleton /////////////
	bool LoggerManager::singleton_created = false;
	LoggerManager *LoggerManager::me = 0x00;

	void LoggerManager::SingletonCreate(void) {
		SINASSERT(!singleton_created);
		me = SINEW(LoggerManager);
		singleton_created = true;
	}

	bool LoggerManager::SingletonCreated(void) {
		return singleton_created;
	}

	void LoggerManager::SingletonDestroy(void) {
		SINASSERT(singleton_created);
		SINDELETE(me);
		singleton_created = false;
	}

	LoggerManager *LoggerManager::SingletonGetInstance(void) {
		SINASSERT(singleton_created);
		return singleton_created ? me : 0x00;
	}

	//////////////// LoggerManager Set/Get Defaults /////////////
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
	enum Record::Severity LoggerManager::GetDefaultSeverity(void) const {
		return default_severity_instance;
	}

	//////////////// LoggerManager Instantiation /////////////
	LoggerManager::LoggerManager(void):
	loggers(),
	dlf_rp(&dlf_rp_inst),
	dlf(&dlf_inst),
	default_severity(&default_severity_instance),
	dlf_inst(&dlf_rp, &default_severity),
	dlf_rp_inst(STDOUT),
	default_severity_instance(Record::FINEST)
	{
	}

	LoggerManager::LoggerManager(LoggerManager const &_other):
	loggers(),
	dlf_rp(&dlf_rp_inst),
	dlf(&dlf_inst),
	default_severity(&default_severity_instance),
	dlf_inst(&dlf_rp, &default_severity),
	dlf_rp_inst(STDOUT),
	default_severity_instance(Record::FINEST)
	{
		SINASSERT(!"Copy constructor cannot be called for singletons");
	}

	LoggerManager::~LoggerManager(void) {
	}

	//////////////// LoggerManager Get/Set Loggers /////////////
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

	//////////////// LoggerManager MakeStreamLogger (Make lvl 1) /////////////
	Logger *LoggerManager::MakeStreamLogger(String const &_logger_name, OutputStream &_out) {
		return SetLogger(
			_logger_name,
			SINEWCLASS(StreamLogger, (
				_logger_name,
				GetLogger(_logger_name).GetCriticalSeverity(), // TODO get critical severity properyl
				_out,
				*dlf_rp) )
			);
	}
	//////////////// LoggerManager (Make lvl 2) /////////////
	Logger *LoggerManager::MakeVoidLogger(String const &_logger_name) {
		return SetLogger(
			_logger_name,
			SINEWCLASS(StreamLogger, (
				_logger_name,
				GetLogger(_logger_name).GetCriticalSeverity(), // TODO get critical severity properly
				VOIDOUT,
				Logging::RecordPrinter(VOIDOUT)) )
			);
	}
	Logger *LoggerManager::MakeStdoutLogger(String const &_logger_name) {
		return MakeStreamLogger(_logger_name, STDOUT);
	}

} // namespace SIN
