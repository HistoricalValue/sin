#ifndef __SIN_ENVIRONMENT_H__
#define __SIN_ENVIRONMENT_H__

#include "SINSymbolTable.h"
#include "SINNamer.h"
#include "SINMemoryCell.h"
#include <vector>

namespace SIN {
	class Environment {
	public:
		Environment(void):
			stable(),
			avrilNamer("_avril"),
			argument_list_p(0x00),
			returnValue_p(0x00),
			returnTriggered(false)
		{ }
		Environment(Environment const& _o):
			stable(_o.stable),
			avrilNamer(_o.avrilNamer),
			argument_list_p(_o.argument_list_p),
			returnValue_p(_o.returnValue_p),
			returnTriggered(_o.returnTriggered)
		{ }

		SymbolTable stable;
		SymbolTable& Stable(void) { return stable; }

		Namer avrilNamer;

		typedef std::vector<MemoryCell*> argument_list_t;
		argument_list_t* argument_list_p;

		InstanceProxy<MemoryCell>* returnValue_p;
		bool returnTriggered;
	}; // class Environment
} // namespace 

#endif // __SIN_ENVIRONMENT_H__
