#ifndef __LEX_UTILITY_H__
#define __LEX_UTILITY_H__

namespace LEX {
	class LexUtility {
	public:
		static char *	SaveStr(const char * yytext);
		
		static char *	SaveQuotedString(char (*input)	(void),
										 int *	line);
		
		static void		IgnoreCStyleComments( char (*input)	(void),
											  void (*unput) (char),
											  int *	line);
	};
}	//namespace LEX


#endif