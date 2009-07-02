%{
	#include "SINParser.h" /**/
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
number			{digit}+(\.{digit}*)?
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



"+"				{ return ADD; }
"-"				{ return MIN; }
"*"				{ return MUL; }
"/"				{ return DIV; }
"%"				{ return MOD; }
"="				{ return ASSIGN; }


".<"			{ return DOT_LT;		}
".>"			{ return DOT_GT;		}
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


{ws}			{/*We do not do nothing in this case*/}
{lineComm}		{}

{id}			{ return ID;		}
{number}		{ return NUMBER;	}
{string}		{ return STRING;	}


.				{ fprintf(stderr, "Cannot match character `%s' with any rule\n", yytext); }
