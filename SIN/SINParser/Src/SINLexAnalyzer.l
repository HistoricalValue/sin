%{
	#include <stdlib.h>
	#include "LexUtility.h"
	#include "SINParser.h" /**/
	#include "SINString.h"
	#define YY_NEVER_INTERACTIVE 1
	
	
	static char InputWrapper (void);//		{ return yyinput(); }
	static void UnputWrapper (char c);//	{ unput(c); }

%}


 
/* Flex options */
%option noyywrap
%option yylineno

/* Flex macros */
ws				[ \t\r\v\n]+

digit			[0-9]
letter			[a-zA-Z]
underscore		[_]
id				{letter}({letter}|{underscore}|{digit})*


string			\"([^"\n]|\\\")*\"
number			{digit}+(\.{digit}+)?
lineComm		\/\/.*

%%


"["				{ return '['; }
"]"				{ return ']'; }
"{"				{ return '{'; }
"}"				{ return '}'; }
"("				{ return '('; }
")"				{ return ')'; }
";"				{ return ';'; }
":"				{ return ':'; }
"."				{ return '.'; }
","				{ return ','; }
".."			{ return DOUBLEDOT; }



"+"				{ return ADD;	}
"-"				{ return MIN;	}
"*"				{ return MUL;	}
"/"				{ return DIV;	}
"%"				{ return MOD;	}
"<"				{ return LT;	}
">"				{ return GT;	}
"<="			{ return LE;	}
">="			{ return GE;	}
"=="			{ return EQ;	}
"!="			{ return NOTEQ;	}
"++"			{ return INCR;	}
"--"			{ return DECR;	}
"="				{ return ASSIGN; }


".<"			{ return DOT_LT;		}
">."			{ return GT_DOT;		}
".~"			{ return DOT_TILDE;		}
".!"			{ return DOT_EXCl_MARK; }
".@"			{ return DOT_AT;		}
".#"			{ return DOT_NUM_SIGN;	}


"if"			{ return IF;		}
"else"			{ return ELSE;		}
"for"			{ return FOR;		}
"while"			{ return WHILE;		}
"break"			{ return BREAK;		}
"continue"		{ return CONTINUE;	}
"function"		{ return FUNCTION;	}
"return"		{ return RETURN;	}
"local"			{ return LOCAL;		}
"global"		{ return GLOBAL;	}
"true"			{ return TRUE;		}
"false"			{ return FALSE;		}
"nil"			{ return NIL;		}
"not"			{ return NOT;		}
"and"			{ return AND;		}
"or"			{ return OR;		}	


"/*"			{	LEX::LexUtility::IgnoreCStyleComments(yytext); }

{ws}			{}
{lineComm}		{}

{id}			{

					yylval.stringV = LEX::LexUtility::SaveStr(yytext);
					UnputWrapper(InputWrapper());
					return ID;
				}
{number}		{ 
					yylval.realV = atof(yytext);
					return NUMBER;	
				}
				
{string}		{ 
					yylval.stringV = LEX::LexUtility::SaveStr(yytext);
					return STRING;	
				}


.				{ fprintf(stderr, "Cannot match character `%s' with any rule\n", yytext); return yytext[0]; }


%%

static char InputWrapper (void)		{ return yyinput(); }
static void UnputWrapper (char c)	{ unput(c); }
