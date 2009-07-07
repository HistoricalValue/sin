#include "SINParserManageStatement.h"
#include "SINLoggerManager.h"
#include "SINLogger.h"

namespace SIN{


	//---------------------------------------------------------------------

	void Manage_Statement_Expression (ASTNode *_expr, ASTNode **_retstmt){
	
		*_retstmt = _expr;
	}

	//---------------------------------------------------------------------

	void Manage_Statement_IfStatement (ASTNode *_ifstmt, ASTNode **_retstmt){
	
		*_retstmt = _ifstmt;
	}

	//---------------------------------------------------------------------

	void Manage_Statement_WhileStatement (ASTNode *_whilestmt, ASTNode **_retstmt){
	
		*_retstmt = _whilestmt;
	}

	//---------------------------------------------------------------------

	void Manage_Statement_ForStatement (ASTNode *_forstmt, ASTNode **_retstmt){
	
		*_retstmt = _forstmt;
	}

	//---------------------------------------------------------------------

	void Manage_Statement_ReturnStatement (ASTNode *_returnstmt, ASTNode **_retstmt){
	
		*_retstmt = _returnstmt;
	}

	//---------------------------------------------------------------------

	void Manage_Statement_Break (ASTNode **_retstmt){
	
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered stmt : break Rule");

		*_retstmt = new ASTNode("Break");
	}

	//---------------------------------------------------------------------

	void Manage_Statement_Continue (ASTNode **_retstmt){
	
		*_retstmt = new ASTNode("Continue");
	}

	//---------------------------------------------------------------------

	void Manage_Statement_Block (ASTNode *_block, ASTNode **_retstmt){
	
		*_retstmt = _block;
	}

	//---------------------------------------------------------------------

	void Manage_Statement_FunctionDefinition (ASTNode *_funcdef, ASTNode **_retstmt){
	
		*_retstmt = _funcdef;
	}

	//---------------------------------------------------------------------

	void Manage_Statement_Semicolon (ASTNode **_retstmt){
	
		*_retstmt = new ASTNode(";");
	}

} // namespace SIN