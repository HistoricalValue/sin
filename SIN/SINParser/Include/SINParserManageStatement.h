#ifndef __SIN_PARSER_MANAGE_STATEMENT_H__
#define __SIN_PARSER_MANAGE_STATEMENT_H__

#include "SINASTNode.h"

namespace SIN{

	void Manage_Statement_Expression		(ASTNode *_expr, ASTNode **_retstmt);
	void Manage_Statement_IfStatement		(ASTNode *_ifstmt, ASTNode **_retstmt);
	void Manage_Statement_WhileStatement	(ASTNode *_whilestmt, ASTNode **_retstmt);
	void Manage_Statement_ForStatement		(ASTNode *_forstmt, ASTNode **_retstmt);
	void Manage_Statement_ReturnStatement	(ASTNode *_returnstmt, ASTNode **_retstmt);
	void Manage_Statement_Break				(ASTNode **_retstmt);
	void Manage_Statement_Continue			(ASTNode **_retstmt);
	void Manage_Statement_Block				(ASTNode *_block, ASTNode **_retstmt);
	void Manage_Statement_FunctionDefinition(ASTNode *_funcdef, ASTNode **_retstmt);
	void Manage_Statement_Semicolon			(ASTNode **_retstmt);
}

#endif //__SIN_PARSER_MANAGE_STATEMENT_H__