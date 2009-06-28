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
        LoggerManager::SingletonCreate();
        return
            LoggerManager::SingletonCreated()               &&
            LoggerManager::SingletonGetInstance() != 0x00   &&
            true;
    }
} // namespace SIN
