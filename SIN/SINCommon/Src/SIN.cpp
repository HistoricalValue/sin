#include "SIN.h"
#include "SINLoggerManager.h"

namespace SIN {
    static bool init_LoggerManager(void);
    bool Initialise(void) {
        return 
            init_LoggerManager()    &&
            true;
    }

    void CleanUp(void) {
    }


    bool init_LoggerManager(void) {
		register bool result = true;
        LoggerManager::SingletonCreate();
		if (
            LoggerManager::SingletonCreated()               &&
            LoggerManager::SingletonGetInstance() != 0x00   &&
            true
		) {
			///// Insert logger-specific initialisation here. For example:
			// LoggerManager::SingletonGetInstance()->MakeVoidLogger("SIN::Tests::Parser::Manage");
			// or
			 LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage")
					.SetCriticalSeverity(Logging::Record::SERIOUS);
		}
		else
			result = false;
		return result;
    }
} // namespace SIN
