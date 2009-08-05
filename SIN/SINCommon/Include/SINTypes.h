#ifndef __SIN_TYPES_H__
#define __SIN_TYPES_H__

#include "SINString.h"

//TODO we must create types for object, functions 


namespace SIN {

	namespace Types {
		/** Type for the nil class. Should be totally unusable. 
			Is only equal with itself and 0x00.
		  */


		class Nil {
		public:
			bool operator ==(Nil const &) const;
			bool operator ==(long const &) const;
		};

		/** SIN internal constant values' representation types */
		typedef bool		Boolean;
		typedef double      Number;
		typedef String      String_t;
		typedef class Nil   Nil_t;
	}	//namespace Types

	extern String const to_string(SIN::Types::Nil_t const _nil);
	extern String const to_string(SIN::Types::Boolean const boolean);


} // namespace SIN

#endif //__SIN_TYPES_H__
