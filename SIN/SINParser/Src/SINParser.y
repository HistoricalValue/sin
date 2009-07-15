
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


	
	//#include "Common.h"
	//#include "SINLogger.h"
	//#include "SINConstants.h"
	//#include "SINLoggerManager.h"
	#include "BisonParseArguments.h"
	

	#include "SINASTNode.h"
	
	#include "SINParserManage.h"
	
/*	
	#include "ParserManageSinCode.h"
	#include "ParserManageStatements.h"
	#include "ParserManageStatement.h"
	#include "ParserManageExpression.h"
	#include "ParserManageTerm.h"
	#include "ParserManageAssignExpression.h"
	#include "ParserManagePrimary.h"
	#include "ParserManageLValue.h"
	#include "ParserManageMember.h"
	#include "ParserManageCall.h"
	#include "ParserManageCallSuffix.h"
	#include "ParserManageNormalCall.h"
	#include "ParserManageMethodCall.h"
	#include "ParserManageExpressionList.h"
	#include "ParserManageObjectDefinition.h"
	#include "ParserManageObjectList.h"
	#include "ParserManageBlock.h"
	#include "ParserManageFunctionDefinition.h"
	#include "ParserManageConstant.h"
	#include "ParserManageIDList.h"
	#include "ParserManageIfStatement.h"
	#include "ParserManageWhileStatement.h"
	#include "ParserManageForStatement.h"
	#include "ParserManageReturnStatement.h"
*/

	////////////////////////////////////////////////////////////////////////
	// defines
	#define MESSAGE(STR)	bpa.WriteFine(#STR " destructed")



	////////////////////////////////////////////////////////////////////////
	// functions definitions
	
	void yyerror (SIN::BisonParseArguments & bpa, char const* yaccProvidedMessage);
	int PrepareForFile(const char * filePath);
	int PrepareForString(const char * str);


	int yylex (void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;	
%}



%parse-param {SIN::BisonParseArguments & bpa}



/*Token types*/
%union {
    const char *	stringV;
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
							SIN::ParserManage::Manage_SinCode($1, &($$));	
							bpa.SetRoot($$);
						}
				;



stmts:			stmt stmts	{	SIN::ParserManage::Manage_Statements($1, $2, &($$));	}
				|			{	SIN::ParserManage::Manage_Statements_Empty(&($$));	}
				;



stmt:			expr ';'			{	SIN::ParserManage::Manage_Statement_Expression($1, &($$));			}
				|	ifstmt			{	SIN::ParserManage::Manage_Statement_IfStatement($1, &($$));			}
				|	whilestmt		{	SIN::ParserManage::Manage_Statement_WhileStatement($1, &($$));		}
				|	forstmt			{	SIN::ParserManage::Manage_Statement_ForStatement($1, &($$));			}
				|	returnstmt		{	SIN::ParserManage::Manage_Statement_ReturnStatement($1, &($$));		}
				|	BREAK ';'		{	SIN::ParserManage::Manage_Statement_Break(&($$));						}
				|	CONTINUE ';'	{	SIN::ParserManage::Manage_Statement_Continue(&($$));					}
				|	block			{	SIN::ParserManage::Manage_Statement_Block($1, &($$));					}
				|	funcdef			{	SIN::ParserManage::Manage_Statement_FunctionDefinition($1, &($$));	}
				|	';'				{	SIN::ParserManage::Manage_Statement_Semicolon(&($$));					}
				|	error  			{yyclearin;}
				;



expr:			assignexpr 					{	SIN::ParserManage::Manage_Expression_AssignExpression($1, &($$));					}
				|	expr	ADD		expr	{	SIN::ParserManage::Manage_Expression_ExpressionADDExpression($1, $3, &($$));		}
				|	expr	MIN		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMINExpression($1, $3, &($$));		}
				|	expr	MUL		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMULExpression($1, $3, &($$));		}
				|	expr	DIV		expr	{	SIN::ParserManage::Manage_Expression_ExpressionDIVExpression($1, $3, &($$));		}
				|	expr	MOD		expr	{	SIN::ParserManage::Manage_Expression_ExpressionMODExpression($1, $3, &($$));		}
				|	expr	GT		expr	{	SIN::ParserManage::Manage_Expression_ExpressionGTExpression($1, $3, &($$));		}
				|	expr	GE		expr	{	SIN::ParserManage::Manage_Expression_ExpressionGEExpression($1, $3, &($$));		}
				|	expr	LT		expr	{	SIN::ParserManage::Manage_Expression_ExpressionLTExpression($1, $3, &($$));		}
				|	expr	LE		expr	{	SIN::ParserManage::Manage_Expression_ExpressionLEExpression($1, $3, &($$));		}
				|	expr	EQ		expr	{	SIN::ParserManage::Manage_Expression_ExpressionEQExpression($1, $3, &($$));		}
				|	expr	NOTEQ	expr	{	SIN::ParserManage::Manage_Expression_ExpressionNOTEQExpression($1, $3, &($$));	}
				|	expr	AND		expr	{	SIN::ParserManage::Manage_Expression_ExpressionANDExpression($1, $3, &($$));		}
				|	expr	OR		expr	{	SIN::ParserManage::Manage_Expression_ExpressionORExpression($1, $3, &($$));		}
				|	expr	NOT		expr	{	SIN::ParserManage::Manage_Expression_ExpressionNOTExpression($1, $3, &($$));		}
				|	metaexpr				{	SIN::ParserManage::Manage_Expression_MetaExpression($1, &($$));					}
				|	term					{	SIN::ParserManage::Manage_Expression_Term($1, &($$));								}
				;
				
				
				
metaexpr:		DOT_LT	expr  GT_DOT			{}
				|	DOT_TILDE		ID			{/*i am not sure if this is corect*/}
				|	DOT_EXCl_MARK	metaexpr	{}
				|	DOT_NUM_SIGN	STRING		{}
				|	DOT_AT			metaexpr	{}
				;
				
				

term:			'(' expr ')'					{	SIN::ParserManage::Manage_Term_ExpressionParentheses($2, &($$));	}
				|	MIN		expr %prec UMINUS	{	SIN::ParserManage::Manage_Term_MINExpression($2, &($$));			}	
				|	NOT		expr				{	SIN::ParserManage::Manage_Term_NOTExpression($2, &($$));			}
				|	INCR	lvalue				{	SIN::ParserManage::Manage_Term_INCRLValue($2, &($$));				}
				|	lvalue	INCR				{	SIN::ParserManage::Manage_Term_LValueINCR($1, &($$));				}
				|	DECR	lvalue				{	SIN::ParserManage::Manage_Term_DECRLValue($2, &($$));				}
				|	lvalue	DECR				{	SIN::ParserManage::Manage_Term_LValueDECR($1, &($$));				}
				|	primary						{	SIN::ParserManage::Manage_Term_Primary($1, &($$));				}
				;
				


assignexpr:		lvalue ASSIGN expr				{	SIN::ParserManage::Manage_AssignExpression($1, $3, &($$));	}
				;



primary:		lvalue							{	SIN::ParserManage::Manage_Primary_LValue($1, &($$));							}
				|	call						{	SIN::ParserManage::Manage_Primary_Call($1, &($$));							}
				|	objectdef					{	SIN::ParserManage::Manage_Primary_ObjectDefinition($1, &($$));				}
				|	'(' funcdef ')'				{	SIN::ParserManage::Manage_Primary_FunctionDefinitionParentheses($2, &($$));	}
				|	const						{	SIN::ParserManage::Manage_Primary_Constant($1, &($$));						}
				;



lvalue:			ID 								{	SIN::ParserManage::Manage_LValue_ID(yytext, &($$));		}
				|	LOCAL ID					{	SIN::ParserManage::Manage_LValue_LocalID(yytext, &($$));	}
				|	GLOBAL ID					{	SIN::ParserManage::Manage_LValue_GlobalID(yytext, &($$));	}
				|	member						{	SIN::ParserManage::Manage_LValue_Member($1, &($$));				}
				;


    
member:			lvalue '.' ID					{	SIN::ParserManage::Manage_Member_LValueID($1, yytext, &($$));	}
				|	lvalue	'[' expr ']'		{	SIN::ParserManage::Manage_Member_LValueExpression($1, $3, &($$));		}
				|	call	'.' ID				{	SIN::ParserManage::Manage_Member_CallID($1, yytext, &($$));	}
				|	call	'[' expr ']'		{	SIN::ParserManage::Manage_Member_CallExpression($1, $3, &($$));		}
				;



	
call:			call callsuffix						{	SIN::ParserManage::Manage_Call_CallCallSuffix($1, $2, &($$));						}
				|	lvalue callsuffix				{	SIN::ParserManage::Manage_Call_LValueCallSuffix($1, $2, &($$));					}
				|	'(' funcdef ')' '(' elist ')'	{	SIN::ParserManage::Manage_Call_FunctionDefinitionExpressionList($2, $5, &($$));	}
				;



callsuffix:		normalcall							{	SIN::ParserManage::Manage_CallSuffix_NormalCall($1, &($$));	}
				|	methodcall						{	SIN::ParserManage::Manage_CallSuffix_MethodCall($1, &($$));	}
				;



normalcall:		'(' elist ')'						{	SIN::ParserManage::Manage_NormalCall($2, &($$));	}
				;
				
				
				
methodcall:		DOUBLEDOT ID '(' elist ')'			{	SIN::ParserManage::Manage_MethodCall(yytext, $4, &($$));	}	/*equivalent to lvalue.id(lvalue, elist)*/
				;



elist:			expr elists							{	SIN::ParserManage::Manage_ExpressionList($1, $2, &($$));	}
				| 									{	SIN::ParserManage::Manage_ExpressionList_Empty(&($$));	}
				;



elists:			',' expr elists						{	SIN::ParserManage::Manage_ExpressionList($2, $3, &($$));	}
				|									{	SIN::ParserManage::Manage_ExpressionList_Empty(&($$));	}
				;



objectdef:		'[' ']'								{	SIN::ParserManage::Manage_ObjectDefinition_EmptyObject(&($$));	}
				|	'[' objectlist ']'				{	SIN::ParserManage::Manage_ObjectDefinition_ObjectList($2, &($$));	}
				;
			
			
			
objectlist:	 	expr objectlists					{	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists($1, $2, &($$));				}
				|	expr ':' expr objectlists		{	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists($1, $3, $4, &($$));	}
				;



objectlists:	',' expr objectlists				{	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists($2, $3, &($$));				}
				|	',' expr ':' expr objectlists	{	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists($2, $4, $5, &($$));	}
				|									{	SIN::ParserManage::Manage_ObjectList_Empty(&($$));										}
				;



block:			'{' {} stmtd '}'					{	SIN::ParserManage::Manage_Block($3, &($$));	}
				;



stmtd:			stmt stmtd	{	SIN::ParserManage::Manage_Statements($1, $2, &($$));	}
				|			{	SIN::ParserManage::Manage_Statements_Empty(&($$));	}
				;



funcdef:		FUNCTION ID	'(' idlist ')' block	{	SIN::ParserManage::Manage_FunctionDefinition_Function(const_cast<char *>($2), $4, $6, &($$));	}
				|	FUNCTION '(' idlist ')' block	{	SIN::ParserManage::Manage_FunctionDefinition_LamdaFunction($3, $5, &($$));			}
				;


const:			NUMBER 				{	SIN::ParserManage::Manage_Constant_Number(atof(yytext), &($$));	}
				|	STRING 			{	SIN::ParserManage::Manage_Constant_String(yytext, &($$));	}
				|	NIL 			{	SIN::ParserManage::Manage_Constant_Nil(&($$));					}
				|	TRUE 			{	SIN::ParserManage::Manage_Constant_True(&($$));					}
				|	FALSE			{	SIN::ParserManage::Manage_Constant_False(&($$));					}
				;


idlist:			ID idlists			{	SIN::ParserManage::Manage_IDList(yytext, $2, &($$));	}
				|	/*empty*/		{	SIN::ParserManage::Manage_IDList_Empty(&($$));		}
				;



idlists:		',' ID idlists	    {	SIN::ParserManage::Manage_IDList(yytext, $3, &($$));	}
				|				    {	SIN::ParserManage::Manage_IDList_Empty(&($$));		}
				;



ifstmt:			IF '(' expr	')' stmt						{	SIN::ParserManage::Manage_IfStatement_If($3, $5, &($$));			}
				|	IF '(' expr ')' stmt ELSE stmt			{	SIN::ParserManage::Manage_IfStatement_IfElse($3, $5, $7, &($$));	}
				;

whilestmt:		WHILE '(' expr ')' stmt						{	SIN::ParserManage::Manage_WhileStatement($3, $5, &($$));	}
				;

forstmt:		FOR '(' elist ';' expr ';' elist ')' stmt	{	SIN::ParserManage::Manage_ForStatement($3, $5, $7, $9, &($$));	}
				;

returnstmt:		RETURN ';'			{	SIN::ParserManage::Manage_ReturnStatement_Return(&($$));					}
				|	RETURN expr ';' {	SIN::ParserManage::Manage_ReturnStatement_ReturnExpression($2, &($$));	}
				;

%%

void yyerror (SIN::BisonParseArguments & bpa, char const* yaccProvidedMessage)
{
	fprintf(stderr, "%s: at line %d, before token: >%s<\n", yaccProvidedMessage, yylineno, yytext);
	bpa.SetError(yaccProvidedMessage);
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