#ifndef __SIN_LIBRARY_LIBRARY_FUNCTIONS_H__
#define __SIN_LIBRARY_LIBRARY_FUNCTIONS_H__

#include "SINLibraryFunction.h"

#define SIN_FUNCTIONLIBRARY_FUNC(FNAME)											\
	class FNAME: public Function {												\
	public:																		\
		inline FNAME(void): Function(#FNAME) { }								\
		virtual inline ~FNAME(void) { }											\
		virtual return_type operator ()(SIN_FUNCTIONLIBRARY_FUNC_ARGS) const;	\
	}

namespace SIN {
	namespace Library {
		namespace Functions {
			SIN_FUNCTIONLIBRARY_FUNC(tostring);
			SIN_FUNCTIONLIBRARY_FUNC(strtonum);
			SIN_FUNCTIONLIBRARY_FUNC(strsavetofile);
			SIN_FUNCTIONLIBRARY_FUNC(typeof);
			SIN_FUNCTIONLIBRARY_FUNC(input);
			SIN_FUNCTIONLIBRARY_FUNC(print);
			SIN_FUNCTIONLIBRARY_FUNC(println);
			SIN_FUNCTIONLIBRARY_FUNC(openfile);
			SIN_FUNCTIONLIBRARY_FUNC(closefile);
			SIN_FUNCTIONLIBRARY_FUNC(writefile);
			SIN_FUNCTIONLIBRARY_FUNC(totalarguments);
			SIN_FUNCTIONLIBRARY_FUNC(arguments);
			SIN_FUNCTIONLIBRARY_FUNC(objectcopy);
		} // namespace Functions
	} // namespace Library
} // namespace SIN

#endif // __SIN_LIBRARY_LIBRARY_FUNCTIONS_H__
