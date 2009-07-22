#ifndef __LEX_UTILITY_H__
#define __LEX_UTILITY_H__

namespace LEX {
	class LexUtility {
	public:
		static char *	SaveStr(const char * yytext);
		static int		IgnoreCStyleComments(char * yytext);
		static void		TestingInputAndUnput(char * yytext);
	};
}	//namespace LEX


#endif