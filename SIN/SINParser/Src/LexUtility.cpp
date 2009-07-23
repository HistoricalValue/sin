#include "LexUtility.h"


#include <string>
#include <stdio.h>
#include <string.h>


#define EOF_ERROR	fprintf(stderr, "Error. Invalid Comment at End of File\n");	\
					return

#define PUSH_BACK(c)	buffer.push_back(c);	\
						break

namespace LEX {

	//-----------------------------------------------------------------
	
	char * LexUtility::SaveStr(const char * yytext) {
		const size_t yytext_len = strlen(yytext);
		char * stringV			= new char[yytext_len + 1];
		
		strncpy(stringV, yytext, yytext_len);
		stringV[yytext_len] = '\0'; // be safe
		
		return stringV;
	}


	//-----------------------------------------------------------------
	
	void LexUtility::IgnoreCStyleComments(	
		char (*input)	(void),
		void (*unput)	(char),
		int * line
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
			
			if (countSlash < 0){            /*fenetai oti exei klisei kapio sxoleio*/
				fprintf(stderr, "Error. Invalid Comment line%d\n", *line);/*xwreis na exei ani3ei*/
				return;
			}

			if(!countSlash)             /*Oti exei ani3ei exei lisei*/
				break;
		}/*end while*/

		if( c == EOF ) 
			{ EOF_ERROR; }
	}


	//-----------------------------------------------------------------

	char * LexUtility::SaveQuotedString(
		char (*input) (void),
		int * line
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
					default:  fprintf(stderr, "Error begin in line %d. Invalid string\n", line); return 0; 
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

}	//namespace lex