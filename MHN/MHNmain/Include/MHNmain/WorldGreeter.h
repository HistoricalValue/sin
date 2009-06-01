#ifndef __WorldGreeter_h__
#define __WorldGreeter_h__

#include <iostream>
#include <string>

namespace MHNmain {
    class WorldGreeter {
        std::string msg;
        std::ostream &out; // write to this stream
    public:
        WorldGreeter(
            std::string const &_msg = "Hello, lol.",
            std::ostream &_output_stream = std::cout);
        ~WorldGreeter(void);

        int Greet(void) const;
    }; // class WorldGreeter
} // namespace MHNmain

#endif /* __WorldGreeter_h__ */
