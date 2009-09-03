#include "SIN.h"
#include "SINAlloc.h"
#include "SINAssert.h"
#include "SINObject.h"
#include "SINASTNode.h"
#include "SINLoggerManager.h"

// TODO remove
#include "SINConstants.h"

namespace SIN {
    bool init_LoggerManager(void) {
		bool result = true;
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
	static bool init_ObjectFactory(void) {
		Types::ObjectFactory::SingletonCreate();
		return
			Types::ObjectFactory::SingletonCreated()			&&
			&Types::ObjectFactory::SingletonInstance() != 0	&&
			true;
	}
	

	/////////////////////////////////////////////////////////////////
	static bool init_Allocation(void) {
		return
			SIN::Alloc::Initialise()	&&
			SIN::Alloc::IsInitialised()	&&
			true;
	}
	
	
	/////////////////////////////////////////////////////////////////
    bool Initialise(void) {
        return
			init_Allocation()		&&
            init_LoggerManager()    &&
			init_ASTNodeFactory()	&&
			init_ObjectFactory() &&
            true;
    }

    void CleanUp(void) {
		SINASSERT(Types::ObjectFactory::SingletonCreated());
		Types::ObjectFactory::SingletonDestroy();
		
		SINASSERT(ASTNodeFactory::SingletonCreated());
		ASTNodeFactory::SingletonDestroy();

		SINASSERT(LoggerManager::SingletonCreated());
		LoggerManager::SingletonDestroy();

		#ifdef _DEBUG
		SIN::Alloc::MemoryAllocator mallocator;
		SIN::Alloc::Allocator<char> allocator(&mallocator);

		SIN::Alloc::String memlik((to_string("Memory leak: ") << SIN::Alloc::MemoryLeaking() << " bytes").c_str(),
				allocator);
		SIN::Alloc::ChunksMap undeallocated_chunks(SIN::Alloc::UndeallocatedChunks());
		static_cast<SIN::OutputStream&>(SIN::STDOUT) << memlik.c_str() << SIN::ENDL; // TODO remove
		#endif
		SINASSERT(SIN::Alloc::IsInitialised());
		SIN::Alloc::CleanUp();
    }


	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	String const to_string(Types::Nil_t const _nil) {
		return "NIL";
	}


	String const to_string(Types::Boolean_t const boolean) 
		{ return boolean? "true" : "false";}



} // namespace SINCreated
