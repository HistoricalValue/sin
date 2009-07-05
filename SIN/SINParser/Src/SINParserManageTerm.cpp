#include "SINParserManageTerm.h"
#include "SINConstants.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Term_ExpressionParentheses (ASTNode *_expr, ASTNode **_retterm){

		*_retterm = _expr;
	}

	//---------------------------------------------------------------------

	void Manage_Term_MINExpression (ASTNode *_expr, ASTNode **_retterm){

		*_retterm = new ASTNode("-expr");

		**_retterm << _expr;
	}

	//---------------------------------------------------------------------

	void Manage_Term_NOTExpression (ASTNode *_expr, ASTNode **_retterm){

		*_retterm = new ASTNode("not expr");

		**_retterm << _expr;
	}

	//---------------------------------------------------------------------

	void Manage_Term_INCRLValue (ASTNode *_lvalue, ASTNode **_retterm){

		*_retterm = new ASTNode("++lvalue");

		**_retterm << _lvalue;
	}

	//---------------------------------------------------------------------

	void Manage_Term_LValueINCR (ASTNode *_lvalue, ASTNode **_retterm){

		*_retterm = new ASTNode("lvalue++");

		**_retterm << _lvalue;
	}

	//---------------------------------------------------------------------

	void Manage_Term_DECRLValue (ASTNode *_lvalue, ASTNode **_retterm){

		*_retterm = new ASTNode("--lvalue");

		**_retterm << _lvalue;
	}

	//---------------------------------------------------------------------

	void Manage_Term_LValueDECR (ASTNode *_lvalue, ASTNode **_retterm){

		*_retterm = new ASTNode("lvalue--");

		**_retterm << _lvalue;
	}

	//---------------------------------------------------------------------

	void Manage_Term_Primary (ASTNode *_primary, ASTNode **_retterm){

		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered term : primary Rule");

		*_retterm = _primary;
	}


}  // namespace SIN