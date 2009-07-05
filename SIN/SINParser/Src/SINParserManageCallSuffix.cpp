#include "SINParserManageCallSuffix.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_CallSuffix_NormalCall (ASTNode *_normalcall, ASTNode **_retcallsuffix){

		*_retcallsuffix = _normalcall;
	}

	//---------------------------------------------------------------------

	void Manage_CallSuffix_MethodCall (ASTNode *_methodcall, ASTNode **_retcallsuffix){

		*_retcallsuffix = _methodcall;
	}

} // namespace SIN