#ifndef __SIN_ENVIRONMENT_H__
#define __SIN_ENVIRONMENT_H__

#include "SINSymbolTable.h"
#include "SINNamer.h"
#include "SINMemoryCell.h"
#include <vector>

namespace SIN {
	class Environment {
	public:
		Environment(void): stable(), avrilNamer("avril"), argument_list_p(0x00) { }
		Environment(Environment const& _o): stable(_o.stable), avrilNamer(_o.avrilNamer), argument_list_p(_o.argument_list_p) { }

		SymbolTable stable;
		SymbolTable& Stable(void) { return stable; }

		Namer avrilNamer;

		typedef std::vector<MemoryCell*> argument_list_t;
		argument_list_t* argument_list_p;
	}; // class Environment
} // namespace 

#endif // __SIN_ENVIRONMENT_H__
