#ifndef __SIN_CONSTANTS_H__
#define __SIN_CONSTANTS_H__

#include "Common.h"
#include "SINTypes.h"

namespace SIN {

    /** Boolean constants */
    READONLY(TRUE, Boolean_t, 0x01u);
    READONLY(FALSE, Boolean_t, 0x00u);

    /** Nil value constants */
    READONLY(NIL, Nil_t, Nil());

    /** End of line constants */
    READONLY(ENDL, char const *, "\n");

} // namespace SIN

#endif //__SIN_CONSTANTS_H__
