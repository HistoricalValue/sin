#include "SIN.h"
#include "SINLoggerManager.h"
#include "SINAssert.h"
#include "SINASTNode.h"

namespace SIN {
    bool init_LoggerManager(void) {
		register bool result = true;
        LoggerManager::SingletonCreate();
		if (
            LoggerManager::SingletonCreated()               &&
            LoggerManager::SingletonGetInstance() != 0x00   &&
            true
		) {
			LoggerManager &manager(*LoggerManager::SingletonGetInstance());
			///// Insert logger-specific initialisation here. For example:
			// manger.MakeVoidLogger("SIN::Tests::Parser::Manage");
			// or
			// manager.GetLogger("SIN::Tests::Parser::Manage")
			//		.SetCriticalSeverity(Logging::Record::SERIOUS);
			manager.GetLogger("SIN::Tests::Parser::Manage").
					SetCriticalSeverity(Logging::Record::SERIOUS);
		}
		else
			result = false;
		return result;
    }
	/////////////////////////////////////////////////////////////////
	static bool init_ASTNodeFactory(void) {
		ASTNodeFactory::SingletonCreate();
		return
			ASTNodeFactory::SingletonCreated()				&&
			&ASTNodeFactory::SingletonInstance() != 0x00	&&
			true;
	}
	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////

    bool Initialise(void) {
        return 
            init_LoggerManager()    &&
			init_ASTNodeFactory()	&&
            true;
    }

    void CleanUp(void) {
		SINASSERT(LoggerManager::SingletonCreated());
		LoggerManager::SingletonDestroy();
    }

} // namespace SIN
