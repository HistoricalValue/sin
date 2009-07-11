
/*
 * University of Crete, Greece
 * HY - 340: Languages and Compilers
 */

%{
	#include <stdio.h>
	#include <assert.h>
	#include <iostream>
	#include <string.h>
	
	
	// Bison assumes alloca is the memory allocation
	// function.
	//
	#ifndef	alloca
	#define alloca malloc
	#endif



	#include "SINASTNode.h"
	#include "SINParserManageSinCode.h"
	#include "SINParserManageStatements.h"
	#include "SINParserManageStatement.h"
	#include "SINParserManageExpression.h"
	#include "SINParserManageTerm.h"
	#include "SINParserManageAssignExpression.h"
	#include "SINParserManagePrimary.h"
	#include "SINParserManageLValue.h"
	#include "SINParserManageMember.h"
	#include "SINParserManageCall.h"
	#include "SINParserManageCallSuffix.h"
	#include "SINParserManageNormalCall.h"
	#include "SINParserManageMethodCall.h"
	#include "SINParserManageExpressionList.h"
	#include "SINParserManageObjectDefinition.h"
	#include "SINParserManageObjectList.h"
	#include "SINParserManageBlock.h"
	#include "SINParserManageFunctionDefinition.h"
	#include "SINParserManageConstant.h"
	#include "SINParserManageIDList.h"
	#include "SINParserManageIfStatement.h"
	#include "SINParserManageWhileStatement.h"
	#include "SINParserManageForStatement.h"
	#include "SINParserManageReturnStatement.h"


	////////////////////////////////////////////////////////////////////////
	// functions definitions
	
	int yyerror (bool hasError, SIN::ASTNode **	root, char const* yaccProvidedMessage);
	int PrepareForFile(const char * filePath);
	int PrepareForString(const char * str);


	int yylex (void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;

////////////////////////////////////////////////////////////////////////
	
%}


%parse-param {bool				hasError}
%parse-param {SIN::ASTNode **	root}




/*Token types*/
%union {
    char *			stringV;
    double			realV;
    SIN::ASTNode *	AST;
};


%start SinCode

%type <AST>	SinCode stmts
%type <AST> stmt ifstmt whilestmt forstmt returnstmt block
%type <AST> expr assignexpr term metaexpr
%type <AST> lvalue primary
%type <AST> call objectdef funcdef const
%type <AST> member
%type <AST> callsuffix elist
%type <AST> normalcall methodcall
%type <AST> elists
%type <AST> objectlist objectlists
%type <AST> stmtd
%type <AST> idlist idlists
%token <realV>   NUMBER
%token <stringV> ID STRING




////////////////////////////////////////////////////////////////////////
// Untyped tokens
// 
%token '[' ']' '{' '}' '(' ')' ';' ':' '.' ',' DOUBLEDOT
%token IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE LOCAL GLOBAL TRUE FALSE NIL
%token ASSIGN ADD MIN MUL DIV MOD EQ NOTEQ INCR DECR GT LT GE LE AND OR NOT 
%token DOT_LT GT_DOT DOT_TILDE DOT_EXCl_MARK DOT_NUM_SIGN DOT_AT


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


%%

SinCode:		stmts	{	
							SIN::Manage_SinCode($1, &($$));	
							root = &$$;
						}
				;



stmts:			stmt stmts	{	SIN::Manage_Statements($1, $2, &($$));	}
				|			{	SIN::Manage_Statements_Empty(&($$));	}
				;



stmt:			expr ';'			{	SIN::Manage_Statement_Expression($1, &($$));			}
				|	ifstmt			{	SIN::Manage_Statement_IfStatement($1, &($$));			}
				|	whilestmt		{	SIN::Manage_Statement_WhileStatement($1, &($$));		}
				|	forstmt			{	SIN::Manage_Statement_ForStatement($1, &($$));			}
				|	returnstmt		{	SIN::Manage_Statement_ReturnStatement($1, &($$));		}
				|	BREAK ';'		{	SIN::Manage_Statement_Break(&($$));						}
				|	CONTINUE ';'	{	SIN::Manage_Statement_Continue(&($$));					}
				|	block			{	SIN::Manage_Statement_Block($1, &($$));					}
				|	funcdef			{	SIN::Manage_Statement_FunctionDefinition($1, &($$));	}
				|	';'				{	SIN::Manage_Statement_Semicolon(&($$));					}
				|	error  			{yyclearin;}
				;



expr:			assignexpr 					{	SIN::Manage_Expression_AssignExpression($1, &($$));					}
				|	expr	ADD		expr	{	SIN::Manage_Expression_ExpressionADDExpression($1, $3, &($$));		}
				|	expr	MIN		expr	{	SIN::Manage_Expression_ExpressionMINExpression($1, $3, &($$));		}
				|	expr	MUL		expr	{	SIN::Manage_Expression_ExpressionMULExpression($1, $3, &($$));		}
				|	expr	DIV		expr	{	SIN::Manage_Expression_ExpressionDIVExpression($1, $3, &($$));		}
				|	expr	MOD		expr	{	SIN::Manage_Expression_ExpressionMODExpression($1, $3, &($$));		}
				|	expr	GT		expr	{	SIN::Manage_Expression_ExpressionGTExpression($1, $3, &($$));		}
				|	expr	GE		expr	{	SIN::Manage_Expression_ExpressionGEExpression($1, $3, &($$));		}
				|	expr	LT		expr	{	SIN::Manage_Expression_ExpressionLTExpression($1, $3, &($$));		}
				|	expr	LE		expr	{	SIN::Manage_Expression_ExpressionLEExpression($1, $3, &($$));		}
				|	expr	EQ		expr	{	SIN::Manage_Expression_ExpressionEQExpression($1, $3, &($$));		}
				|	expr	NOTEQ	expr	{	SIN::Manage_Expression_ExpressionNOTEQExpression($1, $3, &($$));	}
				|	expr	AND		expr	{	SIN::Manage_Expression_ExpressionANDExpression($1, $3, &($$));		}
				|	expr	OR		expr	{	SIN::Manage_Expression_ExpressionORExpression($1, $3, &($$));		}
				|	expr	NOT		expr	{	SIN::Manage_Expression_ExpressionNOTExpression($1, $3, &($$));		}
				|	metaexpr				{	SIN::Manage_Expression_MetaExpression($1, &($$));					}
				|	term					{	SIN::Manage_Expression_Term($1, &($$));								}
				;
				
				
				
metaexpr:		DOT_LT	expr  GT_DOT			{}
				|	DOT_TILDE		ID			{/*i am not sure if this is corect*/}
				|	DOT_EXCl_MARK	metaexpr	{}
				|	DOT_NUM_SIGN	STRING		{}
				|	DOT_AT			metaexpr	{}
				;
				
				

term:			'(' expr ')'					{	SIN::Manage_Term_ExpressionParentheses($2, &($$));	}
				|	MIN		expr %prec UMINUS	{	SIN::Manage_Term_MINExpression($2, &($$));			}	
				|	NOT		expr				{	SIN::Manage_Term_NOTExpression($2, &($$));			}
				|	INCR	lvalue				{	SIN::Manage_Term_INCRLValue($2, &($$));				}
				|	lvalue	INCR				{	SIN::Manage_Term_LValueINCR($1, &($$));				}
				|	DECR	lvalue				{	SIN::Manage_Term_DECRLValue($2, &($$));				}
				|	lvalue	DECR				{	SIN::Manage_Term_LValueDECR($1, &($$));				}
				|	primary						{	SIN::Manage_Term_Primary($1, &($$));				}
				;
				


assignexpr:		lvalue ASSIGN expr				{	SIN::Manage_AssignExpression($1, $3, &($$));	}
				;



primary:		lvalue							{	SIN::Manage_Primary_LValue($1, &($$));							}
				|	call						{	SIN::Manage_Primary_Call($1, &($$));							}
				|	objectdef					{	SIN::Manage_Primary_ObjectDefinition($1, &($$));				}
				|	'(' funcdef ')'				{	SIN::Manage_Primary_FunctionDefinitionParentheses($2, &($$));	}
				|	const						{	SIN::Manage_Primary_Constant($1, &($$));						}
				;



lvalue:			ID 								{	SIN::Manage_LValue_ID(yytext, &($$));		}
				|	LOCAL ID					{	SIN::Manage_LValue_LocalID(yytext, &($$));	}
				|	GLOBAL ID					{	SIN::Manage_LValue_GlobalID(yytext, &($$));	}
				|	member						{	SIN::Manage_LValue_Member($1, &($$));				}
				;


    
member:			lvalue '.' ID					{	SIN::Manage_Member_LValueID($1, yytext, &($$));	}
				|	lvalue	'[' expr ']'		{	SIN::Manage_Member_LValueExpression($1, $3, &($$));		}
				|	call	'.' ID				{	SIN::Manage_Member_CallID($1, yytext, &($$));	}
				|	call	'[' expr ']'		{	SIN::Manage_Member_CallExpression($1, $3, &($$));		}
				;



	
call:			call callsuffix						{	SIN::Manage_Call_CallCallSuffix($1, $2, &($$));						}
				|	lvalue callsuffix				{	SIN::Manage_Call_LValueCallSuffix($1, $2, &($$));					}
				|	'(' funcdef ')' '(' elist ')'	{	SIN::Manage_Call_FunctionDefinitionExpressionList($2, $5, &($$));	}
				;



callsuffix:		normalcall							{	SIN::Manage_CallSuffix_NormalCall($1, &($$));	}
				|	methodcall						{	SIN::Manage_CallSuffix_MethodCall($1, &($$));	}
				;



normalcall:		'(' elist ')'						{	SIN::Manage_NormalCall($2, &($$));	}
				;
				
				
				
methodcall:		DOUBLEDOT ID '(' elist ')'			{	SIN::Manage_MethodCall(yytext, $4, &($$));	}	/*equivalent to lvalue.id(lvalue, elist)*/
				;



elist:			expr elists							{	SIN::Manage_ExpressionList($1, $2, &($$));	}
				| 									{	SIN::Manage_ExpressionList_Empty(&($$));	}
				;



elists:			',' expr elists						{	SIN::Manage_ExpressionList($2, $3, &($$));	}
				|									{	SIN::Manage_ExpressionList_Empty(&($$));	}
				;



objectdef:		'[' ']'								{	SIN::Manage_ObjectDefinition_EmptyObject(&($$));	}
				|	'[' objectlist ']'				{	SIN::Manage_ObjectDefinition_ObjectList($2, &($$));	}
				;
			
			
			
objectlist:	 	expr objectlists					{	SIN::Manage_ObjectList_ExpressionObjectLists($1, $2, &($$));				}
				|	expr ':' expr objectlists		{	SIN::Manage_ObjectList_ExpressionExpressionObjectLists($1, $3, $4, &($$));	}
				;



objectlists:	',' expr objectlists				{	SIN::Manage_ObjectList_ExpressionObjectLists($2, $3, &($$));				}
				|	',' expr ':' expr objectlists	{	SIN::Manage_ObjectList_ExpressionExpressionObjectLists($2, $4, $5, &($$));	}
				|									{	SIN::Manage_ObjectList_Empty(&($$));										}
				;



block:			'{' {} stmtd '}'					{	SIN::Manage_Block($3, &($$));	}
				;



stmtd:			stmt stmtd	{	SIN::Manage_Statements($1, $2, &($$));	}
				|			{	SIN::Manage_Statements_Empty(&($$));	}
				;



funcdef:		FUNCTION ID	'(' idlist ')' block	{	SIN::Manage_FunctionDefinition_Function(yytext, $4, $6, &($$));	}
				|	FUNCTION '(' idlist ')' block	{	SIN::Manage_FunctionDefinition_LamdaFunction($3, $5, &($$));			}
				;


const:			NUMBER 				{	SIN::Manage_Constant_Number(atof(yytext), &($$));	}
				|	STRING 			{	SIN::Manage_Constant_String(yytext, &($$));	}
				|	NIL 			{	SIN::Manage_Constant_Nil(&($$));					}
				|	TRUE 			{	SIN::Manage_Constant_True(&($$));					}
				|	FALSE			{	SIN::Manage_Constant_False(&($$));					}
				;


idlist:			ID idlists			{	SIN::Manage_IDList(yytext, $2, &($$));	}
				|	/*empty*/		{	SIN::Manage_IDList_Empty(&($$));		}
				;



idlists:		',' ID idlists	    {	SIN::Manage_IDList(yytext, $3, &($$));	}
				|				    {	SIN::Manage_IDList_Empty(&($$));		}
				;



ifstmt:			IF '(' expr	')' stmt						{	SIN::Manage_IfStatement_If($3, $5, &($$));			}
				|	IF '(' expr ')' stmt ELSE stmt			{	SIN::Manage_IfStatement_IfElse($3, $5, $7, &($$));	}
				;

whilestmt:		WHILE '(' expr ')' stmt						{	SIN::Manage_WhileStatement($3, $5, &($$));	}
				;

forstmt:		FOR '(' elist ';' expr ';' elist ')' stmt	{	SIN::Manage_ForStatement($3, $5, $7, $9, &($$));	}
				;

returnstmt:		RETURN ';'			{	SIN::Manage_ReturnStatement_Return(&($$));					}
				|	RETURN expr ';' {	SIN::Manage_ReturnStatement_ReturnExpression($2, &($$));	}
				;

%%

int yyerror (bool hasError, SIN::ASTNode **	root, char const* yaccProvidedMessage)
{
	hasError = true;
	fprintf(stderr, "%s: at line %d, before token: >%s<\n", yaccProvidedMessage, yylineno, yytext);
	return -1;
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
//	//yy_scan_string(const char * str);
	return 0;
}