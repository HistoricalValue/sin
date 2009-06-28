#include "SINTypes.h"
#include "SINConstants.h"

namespace SIN {
    READONLYDEF(TRUE);
    READONLYDEF(FALSE);
    READONLYDEF(NIL);
    READONLYDEF(ENDL);

    // ----------- Nil class -------------- //
    bool Nil::operator ==(Nil  const &_o) const { return true       ; }
    bool Nil::operator ==(long const &_l) const { return _l == 0x00l; }
} // namespace SIN
