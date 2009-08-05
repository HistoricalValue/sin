#ifndef __SIN_CONSTANTS_H__
#define __SIN_CONSTANTS_H__

#include "Common.h"
#include "SINTypes.h"


namespace SIN {
	
    /** Boolean constants */
	READONLY(TRUE, Types::Boolean_t, 0x01u);
    READONLY(FALSE, Types::Boolean_t, 0x00u);

    /** Nil value constants */
    READONLY(NIL, Types::Nil_t, Types::Nil());

    /** End of line constants */
    READONLY(ENDL, char const *, "\n");

} // namespace SIN

#endif //__SIN_CONSTANTS_H__
