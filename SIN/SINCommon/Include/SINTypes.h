#ifndef __SIN_TYPES_H__
#define __SIN_TYPES_H__

#include "SINString.h"

namespace SIN {

    /** Type for the nil class. Should be totally unusable. 
        Is only equal with itself and 0x00.
      */
    class Nil {
    public:
        bool operator ==(Nil const &) const;
        bool operator ==(long const &) const;
    };

    /** SIN internal constant values' representation types */
    typedef        double   Number_t;
    typedef String          String_t;
    typedef Nil             Nil_t;
    typedef unsigned char   Boolean_t;

} // namespace SIN

#endif //__SIN_TYPES_H__
