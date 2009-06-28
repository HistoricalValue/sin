#include "SINNamer.h"
#include <cstdio>
#include <cstring>

namespace SIN {

    Namer::Namer(char const _base[SINNAMER_BASELEN]):
        counter(0x00ul),
        base_offset(min<size_t>(strlen(_base), SINNAMER_BASELEN)),
        number_maximun_length(ULONG_MAX_STR_LEN)
    {
        strncpy(base, _base, SINNAMER_BASELEN);
    }

    Namer::Namer(Namer const &_other):
        counter(_other.counter),
        base_offset(_other.base_offset),
        number_maximun_length(_other.number_maximun_length)
    {
        strncpy(base, _other.base, SINNAMER_BASELEN);
    }

    Namer::~Namer(void) {
    }

    char const *Namer::operator ++(void) {
        sprintf(base + base_offset, "%0*lu", number_maximun_length, ++counter);
        return base;
    }

    char const *Namer::operator ++(int) {
        sprintf(base + base_offset, "%0*lu", number_maximun_length, counter++);
        return base;
    }

} // namespace SIN
