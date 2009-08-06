
/*
 * University of Crete, Greece
 * HY - 340: Languages and Compilers
 */

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



	#include "SINASTNode.h"
	#include "SINParserManage.h"
	#include "LexAndBisonParseArguments.h"
	

	////////////////////////////////////////////////////////////////////////
	// defines
	#define MESSAGE(STR)	fabpa.WriteFine(#STR " destructed")



	////////////////////////////////////////////////////////////////////////
	// functions definitions
	
	void yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage);
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

/*
%destructor { delete $$; MESSAGE("Sin Code"); root = 0;	}	SinCode
%destructor { delete $$; MESSAGE("stmts");				}	stmts
%destructor { delete $$; MESSAGE("stmt");				}	stmt
%destructor { delete $$; MESSAGE("ifstmt");				}	ifstmt
%destructor { delete $$; MESSAGE("whilestmt");			}	whilestmt
%destructor { delete $$; MESSAGE("forstmt");			}	forstmt
%destructor { delete $$; MESSAGE("returnstmt");			}	returnstmt
%destructor { delete $$; MESSAGE("block");				}	block
%destructor { delete $$; MESSAGE("expr");				}	expr
%destructor { delete $$; MESSAGE("assignexpr");			}	assignexpr
%destructor { delete $$; MESSAGE("term");				}	term
%destructor { delete $$; MESSAGE("metaexpr");			}	metaexpr
%destructor { delete $$; MESSAGE("lvalue");				}	lvalue
%destructor { delete $$; MESSAGE("primary");			}	primary
%destructor { delete $$; MESSAGE("call");				}	call
%destructor { delete $$; MESSAGE("objectdef");			}	objectdef
%destructor { delete $$; MESSAGE("funcdef");			}	funcdef
%destructor { delete $$; MESSAGE("const");				}	const
%destructor { delete $$; MESSAGE("member");				}	member
%destructor { delete $$; MESSAGE("callsuffix");			}	callsuffix
%destructor { delete $$; MESSAGE("elist");				}	elist
%destructor { delete $$; MESSAGE("normalcall");			}	normalcall
%destructor { delete $$; MESSAGE("methodcall");			}	methodcall
%destructor { delete $$; MESSAGE("elists");				}	elists
%destructor { delete $$; MESSAGE("objectlist");			}	objectlist
%destructor { delete $$; MESSAGE("objectlists");		}	objectlists
%destructor { delete $$; MESSAGE("stmtd");				}	stmtd
%destructor { delete $$; MESSAGE("idlist");				}	idlist
%destructor { delete $$; MESSAGE("idlists");			}	idlists
*/


////////////////////////////////////////////////////////////////////////
// Untyped tokens
// 
%token '[' ']' '{' '}' '(' ')' ';' ':' ',' '~' '!' '@' '#' DOT DOUBLEDOT
%token IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE LOCAL GLOBAL TRUE FALSE NIL
%token ASSIGN ADD MIN MUL DIV MOD EQ NOTEQ INCR DECR GT LT GE LE AND OR NOT 
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
							SIN::ParserManage::Manage_SinCode($1, &($$), &fabpa);	
							fabpa.SetRoot($$);
						}
				;



stmts:			stmt stmts	{	SIN::ParserManage::Manage_Statements($1, $2, &($$), &fabpa);	}
				|			{	SIN::ParserManage::Manage_Statements_Empty(&($$), &fabpa);		}
				;



stmt:			expr ';'			{	SIN::ParserManage::Manage_Statement_Expression($1, &($$), &fabpa);			}
				|	ifstmt			{	SIN::ParserManage::Manage_Statement_IfStatement($1, &($$), &fabpa);			}
				|	whilestmt		{	SIN::ParserManage::Manage_Statement_WhileStatement($1, &($$), &fabpa);		}
				|	forstmt			{	SIN::ParserManage::Manage_Statement_ForStatement($1, &($$), &fabpa);		}
				|	returnstmt		{	SIN::ParserManage::Manage_Statement_ReturnStatement($1, &($$), &fabpa);		}
				|	BREAK ';'		{	SIN::ParserManage::Manage_Statement_Break(&($$), &fabpa);					}
				|	CONTINUE ';'	{	SIN::ParserManage::Manage_Statement_Continue(&($$), &fabpa);				}
				|	block			{	SIN::ParserManage::Manage_Statement_Block($1, &($$), &fabpa);				}
				|	funcdef			{	SIN::ParserManage::Manage_Statement_FunctionDefinition($1, &($$), &fabpa);	}
				|	';'				{	SIN::ParserManage::Manage_Statement_Semicolon(&($$), &fabpa);				}
				|	error  			{	SIN::ParserManage::Manage_Statement_Error(&($$), &fabpa);		yyclearin;	}
				;



expr:			assignexpr 					{	SIN::ParserManage::Manage_Expression_AssignExpression($1, &($$), &fabpa);				}
				|	expr	ADD		expr	{	SIN::ParserManage::Manage_Expression_ExpressionADDExpression($1, $3, &($$), &fabpa);	}
				|	expr	MIN		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMINExpression($1, $3, &($$), &fabpa);	}
				|	expr	MUL		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMULExpression($1, $3, &($$), &fabpa);	}
				|	expr	DIV		expr	{	SIN::ParserManage::Manage_Expression_ExpressionDIVExpression($1, $3, &($$), &fabpa);	}
				|	expr	MOD		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMODExpression($1, $3, &($$), &fabpa);	}
				|	expr	GT		expr	{	SIN::ParserManage::Manage_Expression_ExpressionGTExpression($1, $3, &($$), &fabpa);		}
				|	expr	GE		expr	{	SIN::ParserManage::Manage_Expression_ExpressionGEExpression($1, $3, &($$), &fabpa);		}
				|	expr	LT		expr	{	SIN::ParserManage::Manage_Expression_ExpressionLTExpression($1, $3, &($$), &fabpa);		}
				|	expr	LE		expr	{	SIN::ParserManage::Manage_Expression_ExpressionLEExpression($1, $3, &($$), &fabpa);		}
				|	expr	EQ		expr	{	SIN::ParserManage::Manage_Expression_ExpressionEQExpression($1, $3, &($$), &fabpa);		}
				|	expr	NOTEQ	expr	{	SIN::ParserManage::Manage_Expression_ExpressionNOTEQExpression($1, $3, &($$), &fabpa);	}
				|	expr	AND		expr	{	SIN::ParserManage::Manage_Expression_ExpressionANDExpression($1, $3, &($$), &fabpa);	}
				|	expr	OR		expr	{	SIN::ParserManage::Manage_Expression_ExpressionORExpression($1, $3, &($$), &fabpa);		}
				|	metaexpr				{	SIN::ParserManage::Manage_Expression_MetaExpression($1, &($$), &fabpa);					}
				|	term					{	SIN::ParserManage::Manage_Expression_Term($1, &($$), &fabpa);							}
				;
				
				
				
metaexpr:		DOT LT	expr  GT DOT		{	SIN::ParserManage::Manage_MetaExpression_ShiftToMetaExpression($3, &($$), &fabpa);	}
				|	DOT '~'	'(' expr ')'	{}
				|	DOT '~' ID				{	SIN::ParserManage::Manage_MetaExpression_PreserveAST($3, &($$), &fabpa);			}
				|	DOT '~' call			{}
				|	DOT '!'	metaexpr		{	SIN::ParserManage::Manage_MetaExpression_CompileMetaExpression($3, &($$), &fabpa);	}
				|	DOT '@'	STRING			{	SIN::ParserManage::Manage_MetaExpression_ParseString($3, &($$), &fabpa);			}
				|	DOT '#'	metaexpr		{	SIN::ParserManage::Manage_MetaExpression_UnparseMetaExpression($3, &($$), &fabpa);		}
				;
				
				

term:			'(' expr ')'					{	SIN::ParserManage::Manage_Term_ExpressionParentheses($2, &($$), &fabpa);	}
				|	MIN		expr %prec UMINUS	{	SIN::ParserManage::Manage_Term_MINExpression($2, &($$), &fabpa);			}	
				|	NOT		expr				{	SIN::ParserManage::Manage_Term_NOTExpression($2, &($$), &fabpa);			}
				|	INCR	lvalue				{	SIN::ParserManage::Manage_Term_INCRLValue($2, &($$), &fabpa);				}
				|	lvalue	INCR				{	SIN::ParserManage::Manage_Term_LValueINCR($1, &($$), &fabpa);				}
				|	DECR	lvalue				{	SIN::ParserManage::Manage_Term_DECRLValue($2, &($$), &fabpa);				}
				|	lvalue	DECR				{	SIN::ParserManage::Manage_Term_LValueDECR($1, &($$), &fabpa);				}
				|	primary						{	SIN::ParserManage::Manage_Term_Primary($1, &($$), &fabpa);					}
				;
				


assignexpr:		lvalue ASSIGN expr				{	SIN::ParserManage::Manage_AssignExpression($1, $3, &($$), &fabpa);	}
				;



primary:		lvalue							{	SIN::ParserManage::Manage_Primary_LValue($1, &($$), &fabpa);						}
				|	call						{	SIN::ParserManage::Manage_Primary_Call($1, &($$), &fabpa);							}
				|	objectdef					{	SIN::ParserManage::Manage_Primary_ObjectDefinition($1, &($$), &fabpa);				}
				|	'(' funcdef ')'				{	SIN::ParserManage::Manage_Primary_FunctionDefinitionParentheses($2, &($$), &fabpa);	}
				|	const						{	SIN::ParserManage::Manage_Primary_Constant($1, &($$), &fabpa);						}
				;



lvalue:			ID 								{	SIN::ParserManage::Manage_LValue_ID($1, &($$), &fabpa);			}
				|	LOCAL ID					{	SIN::ParserManage::Manage_LValue_LocalID($2, &($$), &fabpa);	}
				|	GLOBAL ID					{	SIN::ParserManage::Manage_LValue_GlobalID($2, &($$), &fabpa);	}
				|	member						{	SIN::ParserManage::Manage_LValue_Member($1, &($$), &fabpa);		}
				;


    
member:			lvalue DOT ID					{	SIN::ParserManage::Manage_Member_LValueID($1, $3, &($$), &fabpa);			}
				|	lvalue DOT KEYS_MEMBER		{	}
				|	lvalue DOT SIZE_MEMBER		{	}
				|	lvalue	'[' expr ']'		{	SIN::ParserManage::Manage_Member_LValueExpression($1, $3, &($$), &fabpa);	}
				|	call	DOT ID				{	SIN::ParserManage::Manage_Member_CallID($1, $3, &($$), &fabpa);				}
				|	call	'[' expr ']'		{	SIN::ParserManage::Manage_Member_CallExpression($1, $3, &($$), &fabpa);		}
				;



	
call:			call callsuffix						{	SIN::ParserManage::Manage_Call_CallCallSuffix($1, $2, &($$), &fabpa);					}
				|	lvalue callsuffix				{	SIN::ParserManage::Manage_Call_LValueCallSuffix($1, $2, &($$), &fabpa);					}
				|	'(' funcdef ')' '(' elist ')'	{	SIN::ParserManage::Manage_Call_FunctionDefinitionExpressionList($2, $5, &($$), &fabpa);	}
				;



callsuffix:		normalcall							{	SIN::ParserManage::Manage_CallSuffix_NormalCall($1, &($$), &fabpa);	}
				|	methodcall						{	SIN::ParserManage::Manage_CallSuffix_MethodCall($1, &($$), &fabpa);	}
				;



normalcall:		'(' elist ')'						{	SIN::ParserManage::Manage_NormalCall($2, &($$), &fabpa);	}
				;
				
				
				
methodcall:		DOUBLEDOT ID '(' elist ')'			{	SIN::ParserManage::Manage_MethodCall($2, $4, &($$), &fabpa);	}	/*equivalent to lvalue.id(lvalue, elist)*/
				;



elist:			expr elists							{	SIN::ParserManage::Manage_ExpressionList($1, $2, &($$), &fabpa);	}
				| 									{	SIN::ParserManage::Manage_ExpressionList_Empty(&($$), &fabpa);		}
				;



elists:			',' expr elists						{	SIN::ParserManage::Manage_ExpressionList($2, $3, &($$), &fabpa);	}
				|									{	SIN::ParserManage::Manage_ExpressionList_Empty(&($$), &fabpa);		}
				;



objectdef:		'[' ']'								{	SIN::ParserManage::Manage_ObjectDefinition_EmptyObject(&($$), &fabpa);		}
				|	'[' objectlist ']'				{	SIN::ParserManage::Manage_ObjectDefinition_ObjectList($2, &($$), &fabpa);	}
				;
			
			
			
objectlist:	 	expr objectlists					{	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists($1, $2, &($$), &fabpa);					}
				|	expr ':' expr objectlists		{	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists($1, $3, $4, &($$), &fabpa);	}
				|	funcdef objectlists				{}
				;



objectlists:	',' expr objectlists				{	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists($2, $3, &($$), &fabpa);					}
				|	',' expr ':' expr objectlists	{	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists($2, $4, $5, &($$), &fabpa);	}
				|	',' objectfuncdef objectlists	{}
				|									{	SIN::ParserManage::Manage_ObjectList_Empty(&($$), &fabpa);											}
				;



block:			'{' {} stmtd '}'					{	SIN::ParserManage::Manage_Block($3, &($$), &fabpa);	}
				;



stmtd:			stmt stmtd							{	SIN::ParserManage::Manage_Statements($1, $2, &($$), &fabpa);	}
				|									{	SIN::ParserManage::Manage_Statements_Empty(&($$), &fabpa);		}
				;
				
objectfuncdef:	FUNCTION ID	'(' idlist ')' block	{}
				|	FUNCTION '(' idlist ')' block	{}
				;

				
funcdef:		FUNCTION ID	'(' idlist ')' block	{	SIN::ParserManage::Manage_FunctionDefinition_Function($2, $4, $6, &($$), &fabpa);	}
				|	FUNCTION '(' idlist ')' block	{	SIN::ParserManage::Manage_FunctionDefinition_LamdaFunction($3, $5, &($$), &fabpa);	}
				;


const:			NUMBER 				{	SIN::ParserManage::Manage_Constant_Number(atof(yytext), &($$), &fabpa);	}
				|	STRING 			{	SIN::ParserManage::Manage_Constant_String($1, &($$), &fabpa);			}
				|	NIL 			{	SIN::ParserManage::Manage_Constant_Nil(&($$), &fabpa);					}
				|	TRUE 			{	SIN::ParserManage::Manage_Constant_True(&($$), &fabpa);					}
				|	FALSE			{	SIN::ParserManage::Manage_Constant_False(&($$), &fabpa);				}
				;


idlist:			ID idlists			{	SIN::ParserManage::Manage_IDList($1, $2, &($$), &fabpa);	}
				|	/*empty*/		{	SIN::ParserManage::Manage_IDList_Empty(&($$), &fabpa);		}
				;



idlists:		',' ID idlists	    {	SIN::ParserManage::Manage_IDList($2, $3, &($$), &fabpa);	}
				|				    {	SIN::ParserManage::Manage_IDList_Empty(&($$), &fabpa);		}
				;



ifstmt:			IF '(' expr	')' stmt						{	SIN::ParserManage::Manage_IfStatement_If($3, $5, &($$), &fabpa);			}
				|	IF '(' expr ')' stmt ELSE stmt			{	SIN::ParserManage::Manage_IfStatement_IfElse($3, $5, $7, &($$), &fabpa);	}
				;

whilestmt:		WHILE '(' expr ')' stmt						{	SIN::ParserManage::Manage_WhileStatement($3, $5, &($$), &fabpa);	}
				;

forstmt:		FOR '(' elist ';' expr ';' elist ')' stmt	{	SIN::ParserManage::Manage_ForStatement($3, $5, $7, $9, &($$), &fabpa);	}
				;

returnstmt:		RETURN ';'			{	SIN::ParserManage::Manage_ReturnStatement_Return(&($$), &fabpa);				}
				|	RETURN expr ';' {	SIN::ParserManage::Manage_ReturnStatement_ReturnExpression($2, &($$), &fabpa);	}
				;

%%

void yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage)
{
	//fprintf(stderr, "%s: at line %d, before token: >%s<\n", yaccProvidedMessage, yylineno, yytext);
	fabpa.SetError(std::make_pair(yaccProvidedMessage, yylineno));
	//return -1;
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
