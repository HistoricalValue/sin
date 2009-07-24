#ifndef __SIN_PARSER_MANAGE_H__
#define __SIN_PARSER_MANAGE_H__


#include "SINASTNode.h"

namespace SIN {

	class ParserManage {
	public:

		//////////////////////////////////////////////////////////
		// Manage Assigne expression
		static void Manage_AssignExpression	(ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retassignexpr);
		
		//////////////////////////////////////////////////////////
		// Manage Metaexpressions
		static void Manage_MetaExpression_Expression			(ASTNode *_expr, ASTNode **_retmetaexpr);
		static void Manage_MetaExpression_ID					(char *_id, ASTNode **_retmetaexpr);
		static void Manage_MetaExpression_ExecuteMetaExpression(ASTNode *_metaexpr, ASTNode **_retmetaexpr);
		static void Manage_MetaExpression_UnparseMetaExpression(ASTNode *_expr, ASTNode **_retmetaexpr);
		static void Manage_MetaExpression_ParseString			(char *_expr, ASTNode **_retmetaexpr);

		//////////////////////////////////////////////////////////
		// Manage Block
		static void Manage_Block	(ASTNode *_stmtd, ASTNode **_retblock);
		
		//////////////////////////////////////////////////////////
		// Manage Call
		static void Manage_Call_CallCallSuffix						(ASTNode *_call, ASTNode *_callsuffix, ASTNode **_retcall);
		static void Manage_Call_LValueCallSuffix					(ASTNode *_lvalue, ASTNode *_callsuffix, ASTNode **_retcall);
		static void Manage_Call_FunctionDefinitionExpressionList	(ASTNode *_funcdef, ASTNode *_elist, ASTNode **_retcall);
		
		
		//////////////////////////////////////////////////////////
		// Manage Call Suffix
		static void Manage_CallSuffix_NormalCall	(ASTNode *_normalcall, ASTNode **_retcallsuffix);
		static void Manage_CallSuffix_MethodCall	(ASTNode *_methodcall, ASTNode **_retcallsuffix);


		//////////////////////////////////////////////////////////
		// Manage constant
		static void Manage_Constant_Number		(double _number, ASTNode **_retconst);
		static void Manage_Constant_String		(char *_string, ASTNode **_retconst);
		static void Manage_Constant_Nil			(ASTNode **_retconst);
		static void Manage_Constant_True		(ASTNode **_retconst);
		static void Manage_Constant_False		(ASTNode **_retconst);


		//////////////////////////////////////////////////////////
		// Manage Expressions
		static void Manage_Expression_AssignExpression				(ASTNode *_assignexpr, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionADDExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionMINExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionMULExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionDIVExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionMODExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionGTExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionGEExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionLTExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionLEExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionEQExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionNOTEQExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionANDExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionORExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_ExpressionNOTExpression		(ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr);
		static void Manage_Expression_MetaExpression				(ASTNode *_metaexpr, ASTNode **_retexpr);
		static void Manage_Expression_Term							(ASTNode *_term, ASTNode **_retexpr);


		//////////////////////////////////////////////////////////
		// Manage  expression list
		static void Manage_ExpressionList			(ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist);
		static void Manage_ExpressionList_Empty		(ASTNode **_retelist);


		//////////////////////////////////////////////////////////
		// Manage loops statements
		static void Manage_ForStatement		(ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt);
		static void Manage_WhileStatement	(ASTNode *_expr, ASTNode *_stmt, ASTNode **_retwhilestmt);


		//////////////////////////////////////////////////////////
		// Manage function definition
		static void Manage_FunctionDefinition_Function			(char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef);
		static void Manage_FunctionDefinition_LamdaFunction		(ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef);


		//////////////////////////////////////////////////////////
		// Manage id list
		static void Manage_IDList			(char *_id, ASTNode *_idlists, ASTNode **_retidlist);
		static void Manage_IDList_Empty		(ASTNode **_retidlist);


		//////////////////////////////////////////////////////////
		// Manage if statement
		static void Manage_IfStatement_If		(ASTNode *_expr, ASTNode *_stmt, ASTNode **_retifstmt);
		static void Manage_IfStatement_IfElse	(ASTNode *_expr, ASTNode *_stmt1, ASTNode *_stmt2, ASTNode **_retifstmt);


		//////////////////////////////////////////////////////////
		// Manage l-value
		static void Manage_LValue_ID		(char *_ID, ASTNode **_retlvalue);
		static void Manage_LValue_LocalID	(char *_localID, ASTNode **_retlvalue);
		static void Manage_LValue_GlobalID	(char *_globalID, ASTNode **_retlvalue);
		static void Manage_LValue_Member	(ASTNode *_member, ASTNode **_retlvalue);


		//////////////////////////////////////////////////////////
		// Manage member
		static void Manage_Member_LValueID			(ASTNode *_lvalue, char *_id, ASTNode **_retmember);
		static void Manage_Member_LValueExpression	(ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retmember);
		static void Manage_Member_CallID			(ASTNode *_call, char *_id, ASTNode **_retmember);
		static void Manage_Member_CallExpression	(ASTNode *_call, ASTNode *_expr, ASTNode **_retmember);


		//////////////////////////////////////////////////////////
		// Manage method and normal call
		static void Manage_MethodCall	(char *_id, ASTNode *_elist, ASTNode **_retmethodcall);
		static void Manage_NormalCall	(ASTNode *_elist, ASTNode **_retnormalcall);


		//////////////////////////////////////////////////////////
		// Manage object definition
		static void Manage_ObjectDefinition_EmptyObject		(ASTNode **_retobjectdef);
		static void Manage_ObjectDefinition_ObjectList		(ASTNode *_objectlist, ASTNode **_retobjectdef);


		//////////////////////////////////////////////////////////
		// Manage object list
		static void Manage_ObjectList_ExpressionObjectLists				(ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists);
		static void Manage_ObjectList_ExpressionExpressionObjectLists	(ASTNode *_expr1, ASTNode *_expr2, ASTNode *_objectlists, ASTNode **_retobjectlists);
		static void Manage_ObjectList_Empty								(ASTNode **_retobjectlists);


		//////////////////////////////////////////////////////////
		// Manage primary
		static void Manage_Primary_LValue							(ASTNode *_lvalue, ASTNode **_retprimary);
		static void Manage_Primary_Call								(ASTNode *_call, ASTNode **_retprimary);
		static void Manage_Primary_ObjectDefinition					(ASTNode *_objectdef, ASTNode **_retprimary);
		static void Manage_Primary_FunctionDefinitionParentheses	(ASTNode *_funcdef, ASTNode **_retprimary);
		static void Manage_Primary_Constant							(ASTNode *_const, ASTNode **_retprimary);


		//////////////////////////////////////////////////////////
		// Manage return statement
		static void Manage_ReturnStatement_Return				(ASTNode **_retreturnstmt);
		static void Manage_ReturnStatement_ReturnExpression		(ASTNode *_expr, ASTNode **_retreturnstmt);


		//////////////////////////////////////////////////////////
		// Manage start token
		static void Manage_SinCode	(ASTNode *_stmts, ASTNode **_retsincode);


		//////////////////////////////////////////////////////////
		// Manage statement
		static void Manage_Statement_Expression			(ASTNode *_expr, ASTNode **_retstmt);
		static void Manage_Statement_IfStatement		(ASTNode *_ifstmt, ASTNode **_retstmt);
		static void Manage_Statement_WhileStatement		(ASTNode *_whilestmt, ASTNode **_retstmt);
		static void Manage_Statement_ForStatement		(ASTNode *_forstmt, ASTNode **_retstmt);
		static void Manage_Statement_ReturnStatement	(ASTNode *_returnstmt, ASTNode **_retstmt);
		static void Manage_Statement_Break				(ASTNode **_retstmt);
		static void Manage_Statement_Continue			(ASTNode **_retstmt);
		static void Manage_Statement_Block				(ASTNode *_block, ASTNode **_retstmt);
		static void Manage_Statement_FunctionDefinition	(ASTNode *_funcdef, ASTNode **_retstmt);
		static void Manage_Statement_Semicolon			(ASTNode **_retstmt);
		static void Manage_Statement_Error				(ASTNode **_error);


		//////////////////////////////////////////////////////////
		// Manage statements
		static void Manage_Statements		(ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts);
		static void Manage_Statements_Empty	(ASTNode **_retstmts);


		//////////////////////////////////////////////////////////
		// Manage term
		static void Manage_Term_ExpressionParentheses	(ASTNode *_expr, ASTNode **_retterm);
		static void Manage_Term_MINExpression			(ASTNode *_expr, ASTNode **_retterm);
		static void Manage_Term_NOTExpression			(ASTNode *_expr, ASTNode **_retterm);
		static void Manage_Term_INCRLValue				(ASTNode *_lvalue, ASTNode **_retterm);
		static void Manage_Term_LValueINCR				(ASTNode *_lvalue, ASTNode **_retterm);
		static void Manage_Term_DECRLValue				(ASTNode *_lvalue, ASTNode **_retterm);
		static void Manage_Term_LValueDECR				(ASTNode *_lvalue, ASTNode **_retterm);
		static void Manage_Term_Primary					(ASTNode *_primary, ASTNode **_retterm);


	};

} //namespace SIN

#endif //__SIN_PARSER_MANAGE_H__