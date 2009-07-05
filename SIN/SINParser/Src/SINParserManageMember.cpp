#include "SINParserManageMember.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Member_LValueID (ASTNode *_lvalue, char *_id, ASTNode **_retmember){

		*_retmember = new ASTNode("lv.id");
		StringASTNode *id = new StringASTNode(_id);

		**_retmember << _lvalue << id;
	}

	//---------------------------------------------------------------------

	void Manage_Member_LValueExpression (ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retmember){
	
		*_retmember = new ASTNode("lv[expr]");

		**_retmember << _lvalue << _expr;
	}

	//---------------------------------------------------------------------

	void Manage_Member_CallID (ASTNode *_call, char *_id, ASTNode **_retmember){
	
		*_retmember = new ASTNode("call.id");
		StringASTNode *id = new StringASTNode(_id);

		**_retmember << _call << id;
	}

	//---------------------------------------------------------------------

	void Manage_Member_CallExpression (ASTNode *_call, ASTNode *_expr, ASTNode **_retmember){
	
		*_retmember = new ASTNode("call[expr]");

		**_retmember << _call << _expr;
	}

} // namespace SIN