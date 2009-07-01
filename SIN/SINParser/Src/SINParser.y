
/*
 * University of Crete, Greece
 * HY - 340: Languages and Compilers
 */

%{
	#include <stdio.h>
	#include <assert.h>
	#include <iostream>
	
	#include "SINASTNode.h"
	#include "SINParserManageExpression.h"
	
	int yyerror (char* yaccProvidedMessage);
	
	int PrepareForFile(const char * filePath);
	int PrepareForString(const char * str);
	
	
	int yylex (void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;

%}



%start program

/*Token types*/
%union {
    char *stringValue;
    double realValue;
};

/*Non terminal types*/
%union {
    class SIN::ASTNode *AST;
};

 
%token IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE LOCAL GLOBAL TRUE FALSE NIL
%token ASSIGN ADD MIN MUL DIV MOD EQ NOTEQ INCR DECR GT LT GE LE AND OR NOT
%token '[' ']' '{' '}' '(' ')' ';' ':' '.' ',' DOUBLEDOT
%token <realV>   NUMBER
%token <stringV> ID STRING

%left		ASSIGN
%left		OR
%left		AND
%nonassoc	EQ NOTEQ
%nonassoc	GT GE LT LE
%left		ADD MIN
%left		MUL DIV MOD
%right		NOT INCR DECR UMINUS
%left		'.'
%left		'[' ']'
%left		'{' '}'
%left		'(' ')'

%type <AST> expr assignexpr term


%%

program:		stmts {}
				;



stmts:			stmt stmts
				|
				;



stmt:			expr ';'			{}
				|	ifstmt			{}
				|	whilestmt		{}
				|	forstmt			{}			
				|	returnstmt		{}
				|	BREAK ';'		{}
				|	CONTINUE ';'	{}
				|	block			{}
				|	funcdef			{}
				|	';'				{}
				|	error  			{}
				;



expr:			assignexpr 					{	$$ = SIN::Manage_Expression_AssignExpression($1);				}
				|	expr	ADD		expr	{	$$ = SIN::Manage_Expression_ExpressionADDExpression($1, $3);	}
				|	expr	MIN		expr	{	$$ = SIN::Manage_Expression_ExpressionMINExpression($1, $3);	}
				|	expr	MUL		expr	{	$$ = SIN::Manage_Expression_ExpressionMULExpression($1, $3);	}
				|	expr	DIV		expr	{	$$ = SIN::Manage_Expression_ExpressionDIVExpression($1, $3);	}
				|	expr	MOD		expr	{	$$ = SIN::Manage_Expression_ExpressionMODExpression($1, $3);	}
				|	expr	GT		expr	{	$$ = SIN::Manage_Expression_ExpressionGTExpression($1, $3);		}
				|	expr	GE		expr	{	$$ = SIN::Manage_Expression_ExpressionGEExpression($1, $3);		}
				|	expr	LT		expr	{	$$ = SIN::Manage_Expression_ExpressionLTExpression($1, $3);		}
				|	expr	LE		expr	{	$$ = SIN::Manage_Expression_ExpressionLEExpression($1, $3);		}
				|	expr	EQ		expr	{	$$ = SIN::Manage_Expression_ExpressionEQExpression($1, $3);		}
				|	expr	NOTEQ	expr	{	$$ = SIN::Manage_Expression_ExpressionNOTEQExpression($1, $3);	}
				|	expr	AND		expr	{	$$ = SIN::Manage_Expression_ExpressionANDExpression($1, $3);	}
				|	expr	OR		expr	{	$$ = SIN::Manage_Expression_ExpressionORExpression($1, $3);		}
				|	expr	NOT		expr	{	$$ = SIN::Manage_Expression_ExpressionNOTExpression($1, $3);	}
				|	term					{	$$ = SIN::Manage_Expression_Term($1);							}
				;



term:			'(' expr ')'{}
				|	MIN		expr %prec UMINUS	{}	
				|	NOT		expr				{}
				|	INCR	lvalue				{}
				|	lvalue	INCR				{}
				|	DECR	lvalue				{}
				|	lvalue	DECR				{}
				|	primary						{}
				;



assignexpr:		lvalue ASSIGN expr				{}
				;



primary:		lvalue							{}
				|	call						{}
				|	objectdef					{}
				|	'(' funcdef ')'				{}
				|	const
				;



lvalue:			ID 								{}
				|	LOCAL ID					{}
				|	GLOBAL ID					{}
				|	member						{}
				;


    
member:			lvalue '.' ID					{}
				|	lvalue	'[' expr ']'		{}
				|	call	'.' ID				{}
				|	call	'[' expr ']'		{}
				;



	
call:			call callsuffix						{}
				|	lvalue callsuffix				{}
				|	'(' funcdef ')' '(' elist ')'	{}
				;



callsuffix:		normalcall							{}
				|	methodcall						{}
				;



normalcall:		'(' elist ')'						{}
				;
				
				
				
methodcall:		DOUBLEDOT ID '(' elist ')'			{/*equivalent to lvalue.id(lvalue, elist)*/}	
				;



elist:			expr elists							{}
				| 									{}
				;



elists:			',' expr elists						{}
				|									{}
				;



objectdef:		'[' ']'
				|	'[' objectlist ']'
				;
			
			
			
objectlist:	 	expr objectlists
				|	expr ':' expr objectlists
				;



objectlists:	',' expr objectlists
				|	',' expr ':' expr objectlists
				|
				;



block:			'{' {} stmtd '}' 
				;



stmtd:			stmt stmtd	{}
				|			{}
				;



funcdef:		FUNCTION ID	'(' idlist ')' block 
				|	FUNCTION '(' idlist ')' block 
				;


const:			NUMBER 				{}
				|	STRING 			{}
				|	NIL 			{}
				|	TRUE 			{}
				|	FALSE			{}
				;


idlist:			ID idlists			{}
				|	/*empty*/		{}
				;



idlists:		',' ID idlists	    {}
				|	    {}
				;



ifstmt:			IF '(' expr	')' stmt {}
				|	IF '(' expr ')' stmt ELSE stmt 
				;

whilestmt:		WHILE '(' expr ')' stmt {}
				;

forstmt:		FOR '(' elist ';' expr ';' elist ')' stmt
				;

returnstmt:		RETURN ';' {}
				|	RETURN expr ';' {}
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
