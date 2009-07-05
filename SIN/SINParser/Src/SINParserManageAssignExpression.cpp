#include "SINParserManageAssignExpression.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_AssignExpression (ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retassignexpr){

		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered lvalue = expr Rule");

		*_retassignexpr = new ASTNode("=");

		**_retassignexpr << _lvalue << _expr;
	}

} // namespace SIN