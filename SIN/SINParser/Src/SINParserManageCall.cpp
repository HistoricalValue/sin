#include "SINParserManageCall.h"

namespace SIN{

	
	//---------------------------------------------------------------------

	void Manage_Call_CallCallSuffix (ASTNode *_call, ASTNode *_callsuffix, ASTNode **_retcall){
	
		*_retcall = new ASTNode("Calls");

		**_retcall << _call << _callsuffix;
	}
	
	//---------------------------------------------------------------------

	void Manage_Call_LValueCallSuffix (ASTNode *_lvalue, ASTNode *_callsuffix, ASTNode **_retcall){
	
		*_retcall = new ASTNode("lv call");

		**_retcall << _lvalue << _callsuffix;
	}
	
	//---------------------------------------------------------------------

	void Manage_Call_FunctionDefinitionExpressionList (ASTNode *_funcdef, ASTNode *_elist, ASTNode **_retcall){
	
		*_retcall = new ASTNode("funcdef call");

		**_retcall << _funcdef;
		for(ASTNode *nxtExpr; _elist != NULL; _elist = nxtExpr){
			**_retcall << new ASTNode(*_elist);
			nxtExpr = static_cast<ASTNode*>(+(*_elist));
			delete _elist;
		}
	}

} // namespace SIN