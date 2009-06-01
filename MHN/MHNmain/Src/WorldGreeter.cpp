#include "MHNmain/WorldGreeter.h"

namespace MHNmain {
    WorldGreeter::WorldGreeter(std::string const &_msg, std::ostream &_out):
    msg(_msg), out(_out)
    { }

    WorldGreeter::~WorldGreeter(void)
    { }

    int WorldGreeter::Greet(void) const {
        out << msg;
        return out ? 0 : 1;
    }
} // namespace MHNmain
