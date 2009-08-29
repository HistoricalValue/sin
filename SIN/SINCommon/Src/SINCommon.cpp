#include "SINTypes.h"
#include "SINConstants.h"

namespace SIN {
    READONLYDEF(TRUE);
    READONLYDEF(FALSE);
    READONLYDEF(NIL);
    READONLYDEF(ENDL);

    // ----------- Nil class -------------- //
	bool Types::Nil::operator ==(Types::Nil  const &_o) const { return true; }
	bool Types::Nil::operator ==(long const &_l) const { return _l == 0x00l; }

	bool Types::Nil::operator !=(Types::Nil  const &_o) const { return false; }
} // namespace SIN
