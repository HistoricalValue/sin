#ifndef __SIN_ENVIRONMENT_H__
#define __SIN_ENVIRONMENT_H__

#include "SINSymbolTable.h"

namespace SIN {
	class Environment {
	public:
		Environment(void): stable() { }
		Environment(Environment const& _o): stable(_o.stable) { }

		SymbolTable stable;
		SymbolTable& SymbolTable(void) { return stable; }
	}; // class Environment
} // namespace 

#endif // __SIN_ENVIRONMENT_H__
