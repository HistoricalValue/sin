#include "LexUtility.h"


#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>

#include "SINAlloc.h"

#define ERROR_(MSG, RETVAL)		labpa.SetError(std::make_pair(MSG, *line));	\
								return RETVAL

#define ERROR(MSG)				labpa.SetError(std::make_pair(MSG, *line));	\
								return

#define PUSH_BACK(C)			buffer.push_back(C);	\
								break

namespace SIN {
namespace LEX {

	//-----------------------------------------------------------------
	
	char * LexUtility::SaveStr(const char * yytext) {
		const size_t yytext_len = strlen(yytext);
		char* stringV			= SINEWARRAY(char, yytext_len + 1);
		
		SIN::Alloc::memcpy(stringV, yytext, sizeof(char)*(yytext_len + 1));
		stringV[yytext_len] = '\0'; // be safe
		
		return stringV;
	}


	//-----------------------------------------------------------------
	
	void LexUtility::IgnoreCStyleComments(	
		char (*input)	(void),
		void (*unput)	(char),
		int * line,
		SIN::LexAndBisonParseArguments & labpa
	) {
		char c				= '\0';
		unsigned countSlash = 1;

		while( (c = input()) != EOF){
			switch(c){
				case '/':								//Anigei neo sxoleio  (malon)
					if ((c = input()) == '*')			//anigma enos nomimou neou sxoliou
						countSlash++;
					else
						unput(c);						//kanoume push back ton xaraktira pou pirame
					break;

				case '*':								
					if ((c = input()) == '/')			//klisimo enos nomimou sxoleiou
						countSlash--;
					 else
						unput(c);
					break;

				case '\n': ++*line; break;
				
				default:	break;
			}	/*end of switch*/
			
			if (countSlash < 0)
				{ ERROR("Error. Invalid Comment"); }

			if(!countSlash)             /*Oti exei ani3ei exei lisei*/
				break;
		}/*end while*/

		if( c == EOF ) 
			{ ERROR("Error. Invalid Comment at End of File"); }
	}


	//-----------------------------------------------------------------

	char * LexUtility::SaveQuotedString(
		char (*input) (void),
		int * line,
		SIN::LexAndBisonParseArguments & labpa
	){
		char c = '\0';
		std::string buffer;

		while((c = input()) != EOF) {
			if (c == '\"') 
				break;
			else if (c == '\\')
				switch(c = input()) {
					case 'n':	PUSH_BACK('\n');
					case 't':	PUSH_BACK('\t');
					case 'v':	PUSH_BACK('\v');
					case 'r':	PUSH_BACK('\r');
					case 'f':	PUSH_BACK('\f');
					case 'b':	PUSH_BACK('\b');
					case '\\':	PUSH_BACK('\\');
					case '\'':	PUSH_BACK('\'');
					case '\"':	PUSH_BACK('\"');
					case '\0':	PUSH_BACK('\0');
					case '\n':	PUSH_BACK('\n');
					default:  ERROR_("Error begin in line. Invalid string\n", 0);
				}
			else if (c == '\n') {
				buffer.push_back(c);
				++*line;
			}
			else
				buffer.push_back(c);
		}//end of while
		return SaveStr(buffer.c_str());
	}

}	//namespace LEX
}	//namespace SIN