#include "SINVirtualState.h"

namespace SIN {
	namespace VM {
		void VirtualState::AppendError(String const& _message, char const* _file, unsigned int _line) {
			Print(String(_file) << ':' << _line << ": " << _message << "\n");
			SINASSERT(!"Runtime error occured"); // TODO report runtime errors correctly
			errors.push_back(Error(_message, _file, _line));
		}
	} // namespace VM
} // namespace SIN
