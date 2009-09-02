%{
	#include <stdlib.h>
	#include <stdarg.h>
	
	#include "LexUtility.h"
	#include "SINParser.h" /**/
	#include "SINString.h"
	#include "SINParserAPI.h"
	#include "LexAndBisonParseArguments.h"
	
	#define YY_NEVER_INTERACTIVE 1

	#define YY_DECL int yylex(SIN::LexAndBisonParseArguments & fabpa)

	static char InputWrapper (void);
	static void UnputWrapper (char c);
	

	//--------------------------------------------------------
	
	int SIN::ParserAPI::ParseText(char const *_input) {
        yy_scan_string(_input);
		if ( !ParserString())
			return 0;
        return -1;
    }	

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


string			"\""
ccomments		"/*"
lineComm		\/\/.*
number			{digit}+(\.{digit}+)?


%%


"["				{ return '[';			}
"]"				{ return ']';			}
"{"				{ return '{';			}
"}"				{ return '}';			}
"("				{ return '(';			}
")"				{ return ')';			}
";"				{ return ';';			}
":"				{ return ':';			}
","				{ return ',';			}	
".<"			{ return DOT_LT;		}
">."			{ return GT_DOT;		}
".~"			{ return DOT_TILDE;		}
".!"			{ return DOT_EXCl_MARK;	}
".@"			{ return DOT_AT;		}
".#"			{ return DOT_HASH;		}
"."				{ return DOT;			}
".."			{ return DOUBLEDOT;		}



"+"				{ return ADD;		}
"-"				{ return MIN;		}
"*"				{ return MUL;		}
"/"				{ return DIV;		}
"%"				{ return MOD;		}
"<"				{ return LT;		}
">"				{ return GT;		}
"<="			{ return LE;		}
">="			{ return GE;		}
"=="			{ return EQ;		}
"!="			{ return NOTEQ;		}
"++"			{ return INCR;		}
"--"			{ return DECR;		}
"="				{ return ASSIGN;	}


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


"$keys"			{ return KEYS_MEMBER;	}
"$size"			{ return SIZE_MEMBER;	}


{ccomments}		{	SIN::LEX::LexUtility::IgnoreCStyleComments(InputWrapper, UnputWrapper, &yylineno, fabpa); }

{lineComm}		{}

{ws}			{}

{id}			{
					yylval.stringV = SIN::LEX::LexUtility::SaveStr(yytext);
					return ID;
				}
				
{number}		{ 
					yylval.realV = atof(yytext);
					return NUMBER;	
				}
				
{string}		{ 
					yylval.stringV = SIN::LEX::LexUtility::SaveQuotedString(InputWrapper, &yylineno, fabpa);
					return STRING;	
				}


.				{	SIN::String error;
					error<<"Cannot match character " << SIN::String(yytext) << "with any rule";
					fabpa.SetError(std::make_pair(error, yylineno));
					return yytext[0]; 
				}


%%

static char InputWrapper (void)		{ return yyinput(); }
static void UnputWrapper (char c)	{ unput(c); }
