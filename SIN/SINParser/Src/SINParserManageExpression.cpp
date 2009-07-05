#include "SINParserManageExpression.h"
#include "SINConstants.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"

namespace SIN{

	//---------------------------------------------------------------------

	void Manage_Expression_AssignExpression (ASTNode *_assignexpr, ASTNode **_retexpr){

		*_retexpr = _assignexpr;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionADDExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("+");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionMINExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("-");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionMULExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("*");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionDIVExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("/");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------
	
	void Manage_Expression_ExpressionMODExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("%");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionGTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode(">");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionGEExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode(">=");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionLTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("<");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionLEExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("<=");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionEQExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("==");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionNOTEQExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("!=");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionANDExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("and");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionORExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("or");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_ExpressionNOTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ASTNode("not");

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_MetaExpression (ASTNode *_metaexpr, ASTNode **_retexpr){

		*_retexpr = _metaexpr;
	}

	//---------------------------------------------------------------------

	void Manage_Expression_Term (ASTNode *_term, ASTNode **_retexpr){

		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered expr : term Rule");

		*_retexpr = _term;
	}


} // namespace SIN