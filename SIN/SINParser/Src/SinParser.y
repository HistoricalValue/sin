/*
 * University of Crete, Greece
 * HY - 340: Languages and Compilers
 */

%{
	#include <stdio.h>
	#include <assert.h>
	#include <iostream>
	
	int yyerror (char* yaccProvidedMessage);
	
	int PrepareForFile(const char * filePath);
	int PrepareForString(const char * str);
	
	
	int yylex (void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
%}

%start program

%token ID INTEGER

%right      '='
%left       ','
%left	    '+' '-'
%left	    '*' '/'
%nonassoc	UMINUS
%left       '(' ')'

%%

program: 		assignments expressions
				| /* empty */
				;
 
expression:		INTEGER
				| ID
				| expression '+' expression
				| expression '-' expression
				| expression '*' expression
				| expression '/' expression
				| '(' expression ')'
				| '-' expression %prec UMINUS
				;

expr:			expression '\n'

expressions: 	expressions expr
				| expr
				;

assignment: 	ID '=' expression '\n'
				;
				
assignments: 	assignments assignment
				| /* empty */
				;

%%

int yyerror (char* yaccProvidedMessage)
{
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	return 0;
}


int PrepareForFile(const char * filePath) {
	assert (filePath);
	if (!(yyin = fopen(filePath, "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", filePath);
			return 1;
	}
	return 0;
}

int PrepareForString(const char * str) {
	//yy_scan_string(const char * str);
	return 0;
}



//**********************************************************************
/*
int main(int argc, char** argv)
{
	if (argc > 1) {
		if (!(yyin = fopen(argv[1], "r"))) {
				fprintf(stderr, "Cannot read file: %s\n", argv[1]);
				return 1;
		}
	}
	else
		yyin = stdin;

	yyparse();
	return 0;
}
*/