/*
 * University of Crete, Greece
 * HY - 340: Languages and Compilers
 */

%{
	#include "SinParser.hpp" /* <- will be generated from parser.y */
%}
 
/* Flex options */
%option noyywrap
%option yylineno

/* Flex macros */
id			[a-zA-Z][a-zA-Z_0-9]*
integer		[0-9]+

%%

"+"			{ return '+'; }
"-"			{ return '-'; }
"*"			{ return '*'; }
"/"			{ return '/'; }
"("			{ return '('; }
")"			{ return ')'; }
"="			{ return '='; }
[\n]+		{ return '\n'; }

{integer}	{ return INTEGER; }
{id}		{ return ID; }

[ \t]+		{}

.			{ fprintf(stderr, "Cannot match character `%s' with any rule\n", yytext); }
