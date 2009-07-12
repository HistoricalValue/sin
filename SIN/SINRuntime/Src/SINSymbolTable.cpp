#include "SINSymbolTable.h"


#include "SINAssert.h"



//-----------------------------------------------------------------
#define LOOKUP_(WHERE, ITERATOR, STR)	MemoryMap::ITERATOR mit;						\
										if ((mit = WHERE.find(str)) != WHERE.end())		\
											return mit->second;							\
										return static_cast<MemoryCell *>(0)


//-----------------------------------------------------------------
#define LOOKUP_LOCALS(STR)				LOOKUP_(locals, iterator, STR)
#define LOOKUP_LOCALS_CONST(STR)		LOOKUP_(locals, const_iterator, STR)



//-----------------------------------------------------------------
#define LOOKUP_ARGUMENTS(STR)			LOOKUP_(arguments, iterator, STR)
#define LOOKUP_ARGUMENTS_CONST(STR)		LOOKUP_(arguments, const_iterator, STR)




//-----------------------------------------------------------------

#define SET_VALUE(WHERE, STR, MC)	SINASSERT(MC && STR != "");	\
									WHERE[STR] = MC	

#define SET_VALUES(WHERE, LIST)		std::list<SymbolTableValue>::const_iterator clit = LIST.begin();	\
									for (; clit != LIST.end(); ++clit) {								\
										SET_VALUE(WHERE, clit->first, clit->second);					\
									}


//-----------------------------------------------------------------

#define SET_LOCAL(STR, MC)			SET_VALUE(locals, STR, MC)
#define SET_ARGUMENT(STR, MC)		SET_VALUE(arguments, STR, MC)


//-----------------------------------------------------------------

#define SET_LOCAL_P(PAIR)			SET_VALUE(locals, PAIR.first, PAIR.second)
#define SET_ARGUMENT_P(PAIR)		SET_VALUE(arguments, PAIR.first, PAIR.second)


//-----------------------------------------------------------------

#define SET_LOCALS(LIST)			SET_VALUES(locals, LIST)
#define SET_ARGUMENTS(LIST)			SET_VALUES(arguments, LIST)

namespace SIN {
	

	//-----------------------------------------------------------------
	SymbolTable::SymbolTable(void) {}


	//-----------------------------------------------------------------
	SymbolTable::~SymbolTable() {
		locals.clear();
		arguments.clear();
	}


	//-----------------------------------------------------------------
	void SymbolTable::SetArgument (const String & str, MemoryCell * mc) 
		{ SET_ARGUMENT(str, mc); }
	

	//-----------------------------------------------------------------
	void SymbolTable::SetArgument (const SymbolTableValue & stv) 
		{ SET_ARGUMENT_P(stv); }
	
	//-----------------------------------------------------------------

	void SymbolTable::SetArguments (const std::list<SymbolTableValue> & _arguments) 
		{ SET_ARGUMENTS(_arguments) }
	

	//-----------------------------------------------------------------
	void SymbolTable::SetLocal (const String & str, MemoryCell * mc) 
		{ SET_LOCAL(str, mc); }
	

	//-----------------------------------------------------------------

	void SymbolTable::SetLocal (const SymbolTableValue & stv)
		{ SET_LOCAL_P(stv); }
	
	
	//-----------------------------------------------------------------

	void SymbolTable::SetLocals (const std::list<SymbolTableValue> & _locals) 
		{ SET_LOCALS(_locals) }


	//-----------------------------------------------------------------

	const MemoryCell * SymbolTable::LookupLocal (const String & str) const 
		{ LOOKUP_LOCALS_CONST(str); }
	

	//-----------------------------------------------------------------
	
	MemoryCell * SymbolTable::LookupLocal (const String & str) 
		{ LOOKUP_LOCALS(str); }


	//-----------------------------------------------------------------

	const MemoryCell * SymbolTable::LookupArgument (const String & str) const 
		{ LOOKUP_ARGUMENTS_CONST(str); }
	
	
	//-----------------------------------------------------------------

	MemoryCell * SymbolTable::LookupArgument (const String & str) 
		{ LOOKUP_ARGUMENTS(str); }

}	//namepsace SIN