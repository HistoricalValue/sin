#ifndef __SIN_ENVIRONMENT_H__
#define __SIN_ENVIRONMENT_H__

#include "SINSymbolTable.h"
#include "SINNamer.h"

namespace SIN {
	class Environment {
	public:
		Environment(void): stable(), avrilNamer("avril") { }
		Environment(Environment const& _o): stable(_o.stable), avrilNamer(_o.avrilNamer) { }

		SymbolTable stable;
		SymbolTable& Stable(void) { return stable; }

		Namer avrilNamer;
	}; // class Environment
} // namespace 

#endif // __SIN_ENVIRONMENT_H__
