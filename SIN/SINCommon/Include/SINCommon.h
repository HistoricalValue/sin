#ifndef __SIN_SIN_COMMON_H__
#define __SIN_SIN_COMMON_H__

#include "Common.h"

namespace SIN {

    /** SIN internal constant values' representation types */
    typedef signed long int Number_t;
    typedef std::string     String_t;
    typedef void const*     Nil_t;
    typedef unsigned char   Boolean_t;

    /** Boolean conventions */
    READONLY(TRUE, Boolean_t, 0x01u);
    READONLY(FALSE, Boolean_t, 0x00u);

    /** Nil value convention */
    READONLY(NIL, Nil_t, 0x00u);

} // namespace SIN

#endif //__SIN_SIN_COMMON_H__
