#include "LexUtility.h"


#include <string.h>


#define EOF_ERROR	fprintf(stderr, "Error. Invalid Comment at End of File\n");	\
					return -1
						

namespace LEX {

	void LexUtility::TestingInputAndUnput(char * yytext) {

		//yyinput();
		//unput(input());
	}


	char * LexUtility::SaveStr(const char * yytext) {
		const size_t yytext_len = strlen(yytext);
		char * stringV			= new char[yytext_len + 1];
		
		strncpy(stringV, yytext, yytext_len);
		stringV[yytext_len] = '\0'; // be safe
		
		return stringV;
	}


	int LexUtility::IgnoreCStyleComments(char * yytext) {
	#if 0
		char c				= '\0';
		unsigned countSlash = 1;

		while( (c = input()) != EOF ){
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
				return -1;
			}

			if(!countSlash)             /*Oti exei ani3ei exei lisei*/
				break;
		}/*end while*/

		if( c == EOF ) 
			{ EOF_ERROR; }
		return 0;
	#endif
		return 1;
	}


}	//namespace lex