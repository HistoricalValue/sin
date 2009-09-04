%{
	#include <stdio.h>
	#include <utility>
	#include <assert.h>
	#include <iostream>
	#include <string.h>
	
	
	// Bison assumes alloca is the memory allocation
	// function.
	//
	#ifndef	alloca
	#define alloca malloc
	#endif



	#include "SINString.h"
	#include "SINASTNode.h"
	#include "SINParserManage.h"
	#include "LexAndBisonParseArguments.h"
	

	////////////////////////////////////////////////////////////////////////
	// defines
	


	////////////////////////////////////////////////////////////////////////
	// functions definitions
	
	int yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage);
	int PrepareForFile(const char * filePath);
	int PrepareForString(const char * str);


	int yylex(SIN::LexAndBisonParseArguments & fabpa);
	//
	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;	
%}



%parse-param {SIN::LexAndBisonParseArguments & fabpa}
%lex-param   {SIN::LexAndBisonParseArguments & fabpa}



/*Token types*/
%union {
    char *	stringV;
    double			realV;
    SIN::ASTNode *	AST;
};


%start SinCode

%type <AST>	SinCode stmts
%type <AST> stmt ifstmt whilestmt forstmt returnstmt block
%type <AST> expr assignexpr term metaexpr
%type <AST> lvalue primary
%type <AST> call objectdef funcdef objectfuncdef const
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
%token '[' ']' '{' '}' '(' ')' ';' ':' ',' '~' '!' '@' '#' DOT DOUBLEDOT
%token IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE LOCAL GLOBAL TRUE FALSE NIL
%token ASSIGN ADD MIN MUL DIV MOD EQ NOTEQ INCR DECR GT LT GE LE AND OR NOT 
%token DOT_LT GT_DOT DOT_TILDE DOT_EXCl_MARK DOT_AT DOT_HASH DOT_KEYS_MEMBER DOT_SIZE_MEMBER
%token KEYS_MEMBER SIZE_MEMBER


%left		ASSIGN
%left		OR
%left		AND
%nonassoc	EQ NOTEQ
%nonassoc	GT GE LT LE
%left		ADD MIN
%left		MUL DIV MOD
%right		NOT INCR DECR UMINUS
%left		DOT
%left		'[' ']'
%left		'{' '}'
%left		'(' ')'


%%

SinCode:		stmts	{	
							SIN::ParserManage::Manage_SinCode(yylineno, $1, &($$), &fabpa);	
							fabpa.SetRoot($$);
						}
				;



stmts:			stmt stmts	{	SIN::ParserManage::Manage_Statements(yylineno, $1, $2, &($$), &fabpa);	}
				|			{	SIN::ParserManage::Manage_Statements_Empty(yylineno, &($$), &fabpa);		}
				;



stmt:			expr ';'			{	SIN::ParserManage::Manage_Statement_Expression(yylineno, $1, &($$), &fabpa);			}
				|	ifstmt			{	SIN::ParserManage::Manage_Statement_IfStatement(yylineno, $1, &($$), &fabpa);			}
				|	whilestmt		{	SIN::ParserManage::Manage_Statement_WhileStatement(yylineno, $1, &($$), &fabpa);		}
				|	forstmt			{	SIN::ParserManage::Manage_Statement_ForStatement(yylineno, $1, &($$), &fabpa);		}
				|	returnstmt		{	SIN::ParserManage::Manage_Statement_ReturnStatement(yylineno, $1, &($$), &fabpa);		}
				|	BREAK ';'		{	SIN::ParserManage::Manage_Statement_Break(yylineno, &($$), &fabpa);					}
				|	CONTINUE ';'	{	SIN::ParserManage::Manage_Statement_Continue(yylineno, &($$), &fabpa);				}
				|	block			{	SIN::ParserManage::Manage_Statement_Block(yylineno, $1, &($$), &fabpa);				}
				|	funcdef			{	SIN::ParserManage::Manage_Statement_FunctionDefinition(yylineno, $1, &($$), &fabpa);	}
				|	';'				{	SIN::ParserManage::Manage_Statement_Semicolon(yylineno, &($$), &fabpa);				}
				|	error  ';'		{	SIN::ParserManage::Manage_Statement_Error(yylineno, &($$), &fabpa);		yyclearin;	}
				;



expr:			assignexpr 					{	SIN::ParserManage::Manage_Expression_AssignExpression(yylineno, $1, &($$), &fabpa);				}
				|	expr	ADD		expr	{	SIN::ParserManage::Manage_Expression_ExpressionADDExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	expr	MIN		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMINExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	expr	MUL		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMULExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	expr	DIV		expr	{	SIN::ParserManage::Manage_Expression_ExpressionDIVExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	expr	MOD		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMODExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	expr	GT		expr	{	SIN::ParserManage::Manage_Expression_ExpressionGTExpression(yylineno, $1, $3, &($$), &fabpa);		}
				|	expr	GE		expr	{	SIN::ParserManage::Manage_Expression_ExpressionGEExpression(yylineno, $1, $3, &($$), &fabpa);		}
				|	expr	LT		expr	{	SIN::ParserManage::Manage_Expression_ExpressionLTExpression(yylineno, $1, $3, &($$), &fabpa);		}
				|	expr	LE		expr	{	SIN::ParserManage::Manage_Expression_ExpressionLEExpression(yylineno, $1, $3, &($$), &fabpa);		}
				|	expr	EQ		expr	{	SIN::ParserManage::Manage_Expression_ExpressionEQExpression(yylineno, $1, $3, &($$), &fabpa);		}
				|	expr	NOTEQ	expr	{	SIN::ParserManage::Manage_Expression_ExpressionNOTEQExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	expr	AND		expr	{	SIN::ParserManage::Manage_Expression_ExpressionANDExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	expr	OR		expr	{	SIN::ParserManage::Manage_Expression_ExpressionORExpression(yylineno, $1, $3, &($$), &fabpa);		}
				|	metaexpr				{	SIN::ParserManage::Manage_Expression_MetaExpression(yylineno, $1, &($$), &fabpa);					}
				|	DOT_HASH	metaexpr	{	SIN::ParserManage::Manage_Expression_UnparseMetaExpression(yylineno, $2, &($$), &fabpa);			}
				|	term					{	SIN::ParserManage::Manage_Expression_Term(yylineno, $1, &($$), &fabpa);							}
				;
				
				
				
metaexpr:		DOT_LT	SinCode  GT_DOT			{	SIN::ParserManage::Manage_MetaExpression_ShiftToMetaExpression(yylineno, $2, &($$), &fabpa);	}
				|	DOT_LT	expr  GT_DOT		{	SIN::ParserManage::Manage_MetaExpression_ShiftToMetaExpression(yylineno, $2, &($$), &fabpa);	}
				|	DOT_TILDE lvalue			{	SIN::ParserManage::Manage_MetaExpression_PreserveAST_Lvalue(yylineno, $2, &($$), &fabpa);		}
				|	DOT_TILDE call				{	SIN::ParserManage::Manage_MetaExpression_PreserveAST_CALL(yylineno, $2, &($$), &fabpa);			}
				|	DOT_EXCl_MARK	metaexpr	{	SIN::ParserManage::Manage_MetaExpression_CompileMetaExpression(yylineno, $2, &($$), &fabpa);	}
				|	DOT_AT	lvalue				{	SIN::ParserManage::Manage_MetaExpression_ParseString(yylineno, $2, &($$), &fabpa);				}
				;
				
				

term:			'(' expr ')'					{	SIN::ParserManage::Manage_Term_ExpressionParentheses(yylineno, $2, &($$), &fabpa);	}
				|	MIN		expr %prec UMINUS	{	SIN::ParserManage::Manage_Term_MINExpression(yylineno, $2, &($$), &fabpa);			}	
				|	NOT		expr				{	SIN::ParserManage::Manage_Term_NOTExpression(yylineno, $2, &($$), &fabpa);			}
				|	INCR	lvalue				{	SIN::ParserManage::Manage_Term_INCRLValue(yylineno, $2, &($$), &fabpa);				}
				|	lvalue	INCR				{	SIN::ParserManage::Manage_Term_LValueINCR(yylineno, $1, &($$), &fabpa);				}
				|	DECR	lvalue				{	SIN::ParserManage::Manage_Term_DECRLValue(yylineno, $2, &($$), &fabpa);				}
				|	lvalue	DECR				{	SIN::ParserManage::Manage_Term_LValueDECR(yylineno, $1, &($$), &fabpa);				}
				|	primary						{	SIN::ParserManage::Manage_Term_Primary(yylineno, $1, &($$), &fabpa);				}
				;
				


assignexpr:		lvalue ASSIGN expr				{	SIN::ParserManage::Manage_AssignExpression(yylineno, $1, $3, &($$), &fabpa);	}
				;



primary:		lvalue							{	SIN::ParserManage::Manage_Primary_LValue(yylineno, $1, &($$), &fabpa);							}
				|	call						{	SIN::ParserManage::Manage_Primary_Call(yylineno, $1, &($$), &fabpa);							}
				|	objectdef					{	SIN::ParserManage::Manage_Primary_ObjectDefinition(yylineno, $1, &($$), &fabpa);				}
				|	'(' funcdef ')'				{	SIN::ParserManage::Manage_Primary_FunctionDefinitionParentheses(yylineno, $2, &($$), &fabpa);	}
				|	const						{	SIN::ParserManage::Manage_Primary_Constant(yylineno, $1, &($$), &fabpa);						}
				;



lvalue:			ID 								{	SIN::ParserManage::Manage_LValue_ID(yylineno, $1, &($$), &fabpa);		}
				|	LOCAL ID					{	SIN::ParserManage::Manage_LValue_LocalID(yylineno, $2, &($$), &fabpa);	}
				|	GLOBAL ID					{	SIN::ParserManage::Manage_LValue_GlobalID(yylineno, $2, &($$), &fabpa);	}
				|	member						{	SIN::ParserManage::Manage_LValue_Member(yylineno, $1, &($$), &fabpa);	}
				;


    
member:			lvalue DOT ID					{	SIN::ParserManage::Manage_Member_LValueID(yylineno, $1, $3, &($$), &fabpa);			}
				|	lvalue DOT KEYS_MEMBER		{	SIN::ParserManage::Manage_Member_LValueKEYS(yylineno, $1, &($$), &fabpa);			}
				|	lvalue DOT SIZE_MEMBER		{	SIN::ParserManage::Manage_Member_LValueSIZE(yylineno, $1, &($$), &fabpa);			}
				|	lvalue	'[' expr ']'		{	SIN::ParserManage::Manage_Member_LValueExpression(yylineno, $1, $3, &($$), &fabpa);	}
				|	call	DOT ID				{	SIN::ParserManage::Manage_Member_CallID(yylineno, $1, $3, &($$), &fabpa);			}
				|	call	'[' expr ']'		{	SIN::ParserManage::Manage_Member_CallExpression(yylineno, $1, $3, &($$), &fabpa);	}
				;



	
call:			call callsuffix						{	SIN::ParserManage::Manage_Call_CallCallSuffix(yylineno, $1, $2, &($$), &fabpa);						}
				|	lvalue callsuffix				{	SIN::ParserManage::Manage_Call_LValueCallSuffix(yylineno, $1, $2, &($$), &fabpa);					}
				|	'(' funcdef ')' '(' elist ')'	{	SIN::ParserManage::Manage_Call_FunctionDefinitionExpressionList(yylineno, $2, $5, &($$), &fabpa);	}
				;



callsuffix:		normalcall							{	SIN::ParserManage::Manage_CallSuffix_NormalCall(yylineno, $1, &($$), &fabpa);	}
				|	methodcall						{	SIN::ParserManage::Manage_CallSuffix_MethodCall(yylineno, $1, &($$), &fabpa);	}
				;



normalcall:		'(' elist ')'						{	SIN::ParserManage::Manage_NormalCall(yylineno, $2, &($$), &fabpa);	}
				;
				
				
				
methodcall:		DOUBLEDOT ID '(' elist ')'			{	SIN::ParserManage::Manage_MethodCall(yylineno, $2, $4, &($$), &fabpa);	}	/*equivalent to lvalue.id(lvalue, elist)*/
				;



elist:			expr elists							{	SIN::ParserManage::Manage_ExpressionList(yylineno, $1, $2, &($$), &fabpa);	}
				| 									{	SIN::ParserManage::Manage_ExpressionList_Empty(yylineno, &($$), &fabpa);	}
				;



elists:			',' expr elists						{	SIN::ParserManage::Manage_ExpressionList(yylineno, $2, $3, &($$), &fabpa);	}
				|									{	SIN::ParserManage::Manage_ExpressionList_Empty(yylineno, &($$), &fabpa);	}
				;



objectdef:		'[' ']'								{	SIN::ParserManage::Manage_ObjectDefinition_EmptyObject(yylineno, &($$), &fabpa);	}
				|	'[' objectlist ']'				{	SIN::ParserManage::Manage_ObjectDefinition_ObjectList(yylineno, $2, &($$), &fabpa);	}
				;
			
			
			
objectlist:	 	expr objectlists					{	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists(yylineno, $1, $2, &($$), &fabpa);				}
				|	expr ':' expr objectlists		{	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists(yylineno, $1, $3, $4, &($$), &fabpa);	}
				|	funcdef objectlists				{	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists(yylineno, $1, $2, &($$), &fabpa);				}
				;



objectlists:	',' expr objectlists				{	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists(yylineno, $2, $3, &($$), &fabpa);					}
				|	',' expr ':' expr objectlists	{	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists(yylineno, $2, $4, $5, &($$), &fabpa);	}
				|	',' objectfuncdef objectlists	{	SIN::ParserManage::Manage_ObjectList_ExpressionFunckdefObjectLists(yylineno, $2, $3, &($$), &fabpa);					}
				|									{	SIN::ParserManage::Manage_ObjectList_Empty(yylineno, &($$), &fabpa);											}
				;



block:			'{' {} stmtd '}'					{	SIN::ParserManage::Manage_Block(yylineno, $3, &($$), &fabpa);	}
				;



stmtd:			stmt stmtd							{	SIN::ParserManage::Manage_Statements(yylineno, $1, $2, &($$), &fabpa);	}
				|									{	SIN::ParserManage::Manage_Statements_Empty(yylineno, &($$), &fabpa);	}
				;
				
objectfuncdef:	FUNCTION							{	++fabpa.parsingCounters.functions;																}
				ID	'(' idlist ')' block			{	SIN::ParserManage::Manage_FunctionDefinition_Function(yylineno, $3, $5, $7, &($$), &fabpa);		}
				|	FUNCTION						{	++fabpa.parsingCounters.functions;																}
					'(' idlist ')' block			{	SIN::ParserManage::Manage_FunctionDefinition_LamdaFunction(yylineno, $4, $6, &($$), &fabpa);	}
				;

				
funcdef:		FUNCTION							{	++fabpa.parsingCounters.functions;																}
				ID	'(' idlist ')' block			{	SIN::ParserManage::Manage_FunctionDefinition_Function(yylineno, $3, $5, $7, &($$), &fabpa);		}
				|	FUNCTION						{	++fabpa.parsingCounters.functions;																}
					'(' idlist ')' block			{	SIN::ParserManage::Manage_FunctionDefinition_LamdaFunction(yylineno, $4, $6, &($$), &fabpa);	}
				;


const:			NUMBER 				{	SIN::ParserManage::Manage_Constant_Number(yylineno, atof(yytext), &($$), &fabpa);	}
				|	STRING 			{	SIN::ParserManage::Manage_Constant_String(yylineno, $1, &($$), &fabpa);				}
				|	NIL 			{	SIN::ParserManage::Manage_Constant_Nil(yylineno, &($$), &fabpa);					}
				|	TRUE 			{	SIN::ParserManage::Manage_Constant_True(yylineno, &($$), &fabpa);					}
				|	FALSE			{	SIN::ParserManage::Manage_Constant_False(yylineno, &($$), &fabpa);					}
				;


idlist:			ID idlists			{	SIN::ParserManage::Manage_IDList(yylineno, $1, $2, &($$), &fabpa);	}
				|	/*empty*/		{	SIN::ParserManage::Manage_IDList_Empty(yylineno, &($$), &fabpa);	}
				;



idlists:		',' ID idlists	    {	SIN::ParserManage::Manage_IDList(yylineno, $2, $3, &($$), &fabpa);	}
				|				    {	SIN::ParserManage::Manage_IDList_Empty(yylineno, &($$), &fabpa);	}
				;



ifstmt:			IF '(' expr	')' stmt						{	SIN::ParserManage::Manage_IfStatement_If(yylineno, $3, $5, &($$), &fabpa);			}
				|	IF '(' expr ')' stmt ELSE stmt			{	SIN::ParserManage::Manage_IfStatement_IfElse(yylineno, $3, $5, $7, &($$), &fabpa);	}
				;

whilestmt:		WHILE										{	++fabpa.parsingCounters.loops;												}
				'(' expr ')' stmt							{	SIN::ParserManage::Manage_WhileStatement(yylineno, $4, $6, &($$), &fabpa);	}
				;

forstmt:		FOR											{	++fabpa.parsingCounters.loops;														}
				'(' elist ';' expr ';' elist ')' stmt		{	SIN::ParserManage::Manage_ForStatement(yylineno, $4, $6, $8, $10, &($$), &fabpa);	}
				;

returnstmt:		RETURN ';'			{	SIN::ParserManage::Manage_ReturnStatement_Return(yylineno, &($$), &fabpa);					}
				|	RETURN expr ';' {	SIN::ParserManage::Manage_ReturnStatement_ReturnExpression(yylineno, $2, &($$), &fabpa);	}
				;

%%

int yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage)
{
	//fprintf(stderr, "%s: at line %d, before token: >%s<\n", yaccProvidedMessage, yylineno, yytext);
	SIN::String error = SIN::String() << yaccProvidedMessage;
	
	if (*yytext == 0)
		error << " maybe missing ';'";
	else
		error << ", before token: " << yytext;
	fabpa.SetError(std::make_pair(error, yylineno));
	return 1;
}


int PrepareForFile(const char * filePath) {
	assert (filePath);
	if (!(yyin = fopen(filePath, "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", filePath);
			return 1;
	}
	return 0;
}