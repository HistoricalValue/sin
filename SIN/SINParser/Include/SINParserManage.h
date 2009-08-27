#ifndef __SIN_PARSER_MANAGE_H__
#define __SIN_PARSER_MANAGE_H__


#include "SINASTNode.h"
#include "LexAndBisonParseArguments.h"

namespace SIN {

	class ParserManage {
	public:

		//////////////////////////////////////////////////////////
		// Manage Assign expression
		static void Manage_AssignExpression	(const int lineNo, ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retassignexpr, LexAndBisonParseArguments *_lbpa);
		
		//////////////////////////////////////////////////////////
		// Manage Metaexpressions
		static void Manage_MetaExpression_ShiftToMetaExpression		(const int lineNo, ASTNode *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_MetaExpression_PreserveAST_ID			(const int lineNo, char *_id, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_MetaExpression_CompileMetaExpression		(const int lineNo, ASTNode *_metaexpr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_MetaExpression_ParseString				(const int lineNo, char *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa);

		//////////////////////////////////////////////////////////
		// Manage Block
		static void Manage_Block	(const int lineNo, ASTNode *_stmtd, ASTNode **_retblock, LexAndBisonParseArguments *_lbpa);
		
		//////////////////////////////////////////////////////////
		// Manage Call
		static void Manage_Call_CallCallSuffix						(const int lineNo, ASTNode *_call, ASTNode *_callsuffix, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa);
		static void Manage_Call_LValueCallSuffix					(const int lineNo, ASTNode *_lvalue, ASTNode *_callsuffix, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa);
		static void Manage_Call_FunctionDefinitionExpressionList	(const int lineNo, ASTNode *_funcdef, ASTNode *_elist, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa);
		
		
		//////////////////////////////////////////////////////////
		// Manage Call Suffix
		static void Manage_CallSuffix_NormalCall	(const int lineNo, ASTNode *_normalcall, ASTNode **_retcallsuffix, LexAndBisonParseArguments *_lbpa = NULL);
		static void Manage_CallSuffix_MethodCall	(const int lineNo, ASTNode *_methodcall, ASTNode **_retcallsuffix, LexAndBisonParseArguments *_lbpa = NULL);


		//////////////////////////////////////////////////////////
		// Manage constant
		static void Manage_Constant_Number		(const int lineNo, double _number, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa);
		static void Manage_Constant_String		(const int lineNo, char *_string, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa);
		static void Manage_Constant_Nil			(const int lineNo, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa);
		static void Manage_Constant_True		(const int lineNo, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa);
		static void Manage_Constant_False		(const int lineNo, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage Expressions
		static void Manage_Expression_AssignExpression				(const int lineNo, ASTNode *_assignexpr, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionADDExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionMINExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionMULExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionDIVExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionMODExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionGTExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionGEExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionLTExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionLEExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionEQExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionNOTEQExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionANDExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionORExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_ExpressionNOTExpression		(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_MetaExpression				(const int lineNo, ASTNode *_metaexpr, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_UnparseMetaExpression			(const int lineNo, ASTNode *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa);
		static void Manage_Expression_Term							(const int lineNo, ASTNode *_term, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage  expression list
		static void Manage_ExpressionList			(const int lineNo, ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist, LexAndBisonParseArguments *_lbpa);
		static void Manage_ExpressionList_Empty		(const int lineNo, ASTNode **_retelist, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage loops statements
		static void Manage_ForStatement		(const int lineNo, ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_WhileStatement	(const int lineNo, ASTNode *_expr, ASTNode *_stmt, ASTNode **_retwhilestmt, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage function definition
		static void Manage_FunctionDefinition_Function			(const int lineNo, char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef, LexAndBisonParseArguments *_lbpa);
		static void Manage_FunctionDefinition_LamdaFunction		(const int lineNo, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage id list
		static void Manage_IDList			(const int lineNo, char *_id, ASTNode *_idlists, ASTNode **_retidlist, LexAndBisonParseArguments *_lbpa);
		static void Manage_IDList_Empty		(const int lineNo, ASTNode **_retidlist, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage if statement
		static void Manage_IfStatement_If		(const int lineNo, ASTNode *_expr, ASTNode *_stmt, ASTNode **_retifstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_IfStatement_IfElse	(const int lineNo, ASTNode *_expr, ASTNode *_stmt1, ASTNode *_stmt2, ASTNode **_retifstmt, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage l-value
		static void Manage_LValue_ID		(const int lineNo, char *_ID, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa);
		static void Manage_LValue_LocalID	(const int lineNo, char *_localID, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa);
		static void Manage_LValue_GlobalID	(const int lineNo, char *_globalID, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa);
		static void Manage_LValue_Member	(const int lineNo, ASTNode *_member, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage member
		static void Manage_Member_LValueID			(const int lineNo, ASTNode *_lvalue, char *_id, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa);
		static void Manage_Member_LValueExpression	(const int lineNo, ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa);
		static void Manage_Member_CallID			(const int lineNo, ASTNode *_call, char *_id, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa);
		static void Manage_Member_CallExpression	(const int lineNo, ASTNode *_call, ASTNode *_expr, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage method and normal call
		static void Manage_MethodCall	(const int lineNo, char *_id, ASTNode *_elist, ASTNode **_retmethodcall, LexAndBisonParseArguments *_lbpa);
		static void Manage_NormalCall	(const int lineNo, ASTNode *_elist, ASTNode **_retnormalcall, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage object definition
		static void Manage_ObjectDefinition_EmptyObject		(const int lineNo, ASTNode **_retobjectdef, LexAndBisonParseArguments *_lbpa);
		static void Manage_ObjectDefinition_ObjectList		(const int lineNo, ASTNode *_objectlist, ASTNode **_retobjectdef, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage object list
		static void Manage_ObjectList_ExpressionObjectLists				(const int lineNo, ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa);
		static void Manage_ObjectList_ExpressionExpressionObjectLists	(const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode *_objectlists, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa);
		static void Manage_ObjectList_Empty								(const int lineNo, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage primary
		static void Manage_Primary_LValue							(const int lineNo, ASTNode *_lvalue, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa);
		static void Manage_Primary_Call								(const int lineNo, ASTNode *_call, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa);
		static void Manage_Primary_ObjectDefinition					(const int lineNo, ASTNode *_objectdef, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa);
		static void Manage_Primary_FunctionDefinitionParentheses	(const int lineNo, ASTNode *_funcdef, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa);
		static void Manage_Primary_Constant							(const int lineNo, ASTNode *_const, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage return statement
		static void Manage_ReturnStatement_Return				(const int lineNo, ASTNode **_retreturnstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_ReturnStatement_ReturnExpression		(const int lineNo, ASTNode *_expr, ASTNode **_retreturnstmt, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage start token
		static void Manage_SinCode	(const int lineNo, ASTNode *_stmts, ASTNode **_retsincode, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage statement
		static void Manage_Statement_Expression			(const int lineNo, ASTNode *_expr, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_IfStatement		(const int lineNo, ASTNode *_ifstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_WhileStatement		(const int lineNo, ASTNode *_whilestmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_ForStatement		(const int lineNo, ASTNode *_forstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_ReturnStatement	(const int lineNo, ASTNode *_returnstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_Break				(const int lineNo, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_Continue			(const int lineNo, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_Block				(const int lineNo, ASTNode *_block, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_FunctionDefinition	(const int lineNo, ASTNode *_funcdef, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_Semicolon			(const int lineNo, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statement_Error				(const int lineNo, ASTNode **_error, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage statements
		static void Manage_Statements		(const int lineNo, ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts, LexAndBisonParseArguments *_lbpa);
		static void Manage_Statements_Empty	(const int lineNo, ASTNode **_retstmts, LexAndBisonParseArguments *_lbpa);


		//////////////////////////////////////////////////////////
		// Manage term
		static void Manage_Term_ExpressionParentheses	(const int lineNo, ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);
		static void Manage_Term_MINExpression			(const int lineNo, ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);
		static void Manage_Term_NOTExpression			(const int lineNo, ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);
		static void Manage_Term_INCRLValue				(const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);
		static void Manage_Term_LValueINCR				(const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);
		static void Manage_Term_DECRLValue				(const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);
		static void Manage_Term_LValueDECR				(const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);
		static void Manage_Term_Primary					(const int lineNo, ASTNode *_primary, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa);


	};

} //namespace SIN

#endif //__SIN_PARSER_MANAGE_H__
