#ifndef __SIN_LOGGERMANAGER_H__
#define __SIN_LOGGERMANAGER_H__

#include <map>
#include "SINString.h"
#include "SINLogger.h"
#include "SINRecordPrinter.h"
#include "Common.h"

namespace SIN {
    using Logging::RecordPrinter;
    using Logging::Record;

    class LoggerManager {
    public:
        class DefaultLoggerFactory {
            InstanceProxy<RecordPrinter> const &rp;
        public:
            DefaultLoggerFactory(InstanceProxy<RecordPrinter> const * const &rp);
            virtual ~DefaultLoggerFactory(void);
            virtual Logger *MakeDefaultLogger(String const &name);
            virtual void    DestroyDefaultLogger(Logger *logger);
            Logger *operator ()(String const &_name) { return MakeDefaultLogger(_name); }
        }; // class DefaultLoggerFactory
        class StreamLogger : public Logger {
            OutputStream &out;
            RecordPrinter rp;
        public:
            StreamLogger(String const &name, enum Record::Severity const &report_level, OutputStream &out, RecordPrinter const &rp);
            virtual ~StreamLogger(void);
            virtual void Message(Record const &rec);
        }; // clss StreamLogger
    protected:
        std::map<String, Logger*> loggers;
        InstanceProxy<RecordPrinter> dlf_rp;
        InstanceProxy<DefaultLoggerFactory> dlf;
    private:
        DefaultLoggerFactory dlf_inst;
        RecordPrinter dlf_rp_inst;
        ///////////
        static bool singleton_created, singleton_destroyed;
        static LoggerManager *me;
        ///////////
        LoggerManager(void);
        LoggerManager(LoggerManager const &);
        ~LoggerManager(void);
    public:
        static void SingletonCreate(void);
        static void SingletonDestroy(void);
        static bool SingletonCreated(void);
        static LoggerManager *SingletonGetInstance(void);

        ///////////
        // return previous
        DefaultLoggerFactory *SetDefaultLoggerFactory(DefaultLoggerFactory *factory);
        RecordPrinter *SetDefaultRecordPrinter(RecordPrinter *rp);
        // return current
        DefaultLoggerFactory *GetDefaultLoggerFactory(void) const;
        RecordPrinter *GetDefaultRecordPrinter(void) const;

        ///////////
        // Gets an existing logger or creates one for the given name
        // (using DefaultLoggerFactory)
        Logger &GetLogger(String const &logger_name);
        // Pointers returned by this method should be fed to the
        // DefaultLoggerFactory.DestroyLogger() method, if there are not
        // pointing to custom-made Loggers.
        Logger *SetLogger(String const &logger_name, Logger *logger); // returns previous

        ///////////
        // return previous.
        // As with the SetLogger() method, any returned pointer of a non-custom-made
        // Logger should be fed to the DLF-instance-destroyer.
        Logger *MakeStreamLogger(String const &logger_name, OutputStream &out);
        ///////////
        Logger *MakeVoidLogger(String const &logger_name);
        Logger *MakeStdoutLogger(String const &logger_name);
    }; // class LoggerManager
} // namespace SIN

#endif // __SIN_LOGGERMANAGER_H__
