#include "SINStandardLibrary.h"
#include "SINLibraryFunctions.h"
#include "SINAssert.h"
#include "SINAlloc.h"

#define SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(FNAME) if (InstallFunction(functions[i++] = SINEW(Functions::FNAME)).first != false) SINASSERT(false)

namespace SIN {
	namespace Library {
		StandardLibrary::StandardLibrary(void) {
			size_t i = 0;
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(print);
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(println);
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(tostring);
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(strtonum);
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(strsavetofile);
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(typeof);
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(totalarguments);
			SIN_LIBRARY_LIBRARYFUNCTIONS_INSTALL(arguments);
		}

		StandardLibrary::~StandardLibrary(void) {
			size_t const len = sizeof(functions)/sizeof(functions[0]);
			for (size_t i = 0; i < len; ++i)
				SINDELETE(functions[i]);
		}
	} // namespace Library
} // namespace SIN
