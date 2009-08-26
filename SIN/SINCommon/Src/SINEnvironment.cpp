#include "SINEnvironment.h"

namespace SIN {

	SymbolTable& Environment::SymbolTable(void) {
		return stable;
	}

} // namespace SIN
