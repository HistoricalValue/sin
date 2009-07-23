#ifndef __LEX_UTILITY_H__
#define __LEX_UTILITY_H__


#include "LexAndBisonParseArguments.h"

namespace SIN {
	namespace LEX {
		class LexUtility {
		public:
			static char *	SaveStr(const char * yytext);
			
			static char *	SaveQuotedString(char (*input)	(void),
											 int *	line,
											 SIN::LexAndBisonParseArguments &);
			
			static void		IgnoreCStyleComments( char (*input)	(void),
												  void (*unput) (char),
												  int *	line,
												  SIN::LexAndBisonParseArguments &);
		};
	}	//namespace LEX
}//namespace SIN


#endif