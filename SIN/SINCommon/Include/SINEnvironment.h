#ifndef __SIN_ENVIRONMENT_H__
#define __SIN_ENVIRONMENT_H__

#include "SINSymbolTable.h"

namespace SIN {
	class Environment {
		SymbolTable stable;
	public:
		SymbolTable& SymbolTable(void);
	}; // class Environment
} // namespace 

#endif // __SIN_ENVIRONMENT_H__
