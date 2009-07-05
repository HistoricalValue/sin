#include "SINParserManageSinCode.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_SinCode	(ASTNode *_stmts, ASTNode **_retsincode){
	
		*_retsincode = new ASTNode("AST");

		**_retsincode << _stmts;
	}

} // namespace SIN