#include "SINParserManage.h"


#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINASTNodes.h"

namespace SIN {


	//////////////////////////////////////////////////////////
	// Manage Assign expression
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_AssignExpression (ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retassignexpr) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered lvalue = expr Rule");
		*_retassignexpr = new AssignASTNode("=");
		**_retassignexpr << _lvalue << _expr;
	}
	

	//////////////////////////////////////////////////////////
	// Manage Block

	//-----------------------------------------------------------------

	void ParserManage::Manage_Block	(ASTNode *_stmtd, ASTNode **_retblock) {
		*_retblock = new BlockASTNode("Block");

		for(ASTNode *nxtStmt; _stmtd != NULL; _stmtd = nxtStmt){
			**_retblock << _stmtd->Clone();
			nxtStmt = static_cast<ASTNode*>(+(*_stmtd));
			delete _stmtd;
		}	
	}

	
	//////////////////////////////////////////////////////////
	// Manage Call
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_CallCallSuffix (ASTNode *_call, ASTNode *_callsuffix, ASTNode **_retcall) {	
		*_retcall = _callsuffix;
		*_call >> *_retcall;
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_LValueCallSuffix (ASTNode *_lvalue, ASTNode *_callsuffix, ASTNode **_retcall) {	
		*_retcall = _callsuffix;
		*_lvalue >> *_retcall;
	}
	

	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_FunctionDefinitionExpressionList	(ASTNode *_funcdef, ASTNode *_elist, ASTNode **_retcall) {
		*_retcall = new FuncdefCallASTNode("funcdef call");

		**_retcall << _funcdef;
		ASTNode *arguments = new ArgumentsASTNode("Arguments");
		for(ASTNode *nxtExpr; _elist != NULL; _elist = nxtExpr){
			*arguments << _elist->Clone();
			nxtExpr = static_cast<ASTNode*>(+(*_elist));
			delete _elist;
		}
		**_retcall << arguments;
	}
	
	
	//////////////////////////////////////////////////////////
	// Manage Call Suffix

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_CallSuffix_NormalCall (ASTNode *_normalcall, ASTNode **_retcallsuffix) 
		{ *_retcallsuffix = _normalcall; }


	//-----------------------------------------------------------------

	void ParserManage::Manage_CallSuffix_MethodCall (ASTNode *_methodcall, ASTNode **_retcallsuffix) 
		{ *_retcallsuffix = _methodcall; }


	//////////////////////////////////////////////////////////
	// Manage constant
	
	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_Number (double _number, ASTNode **_retconst) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered const : Number Rule. Number ") + SIN::string_cast(_number));

		*_retconst = new NumberASTNode(_number);	
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_String (char *_string, ASTNode **_retconst) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered const : string Rule. String ") + SIN::String(_string));

		*_retconst = new StringASTNode(_string);
		logger.Notice((*_retconst)->Name());

		delete _string;
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_Nil (ASTNode **_retconst)
		{ *_retconst = new NilASTNode(); }


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_True (ASTNode **_retconst) 
		{ *_retconst = new TrueASTNode(); }
	

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_False	(ASTNode **_retconst)
		{ *_retconst = new FalseASTNode(); }



	///////////////////////////////////////////////////////////
	// Manage Expressions
	
	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_AssignExpression (ASTNode *_assignexpr, ASTNode **_retexpr){

		*_retexpr = _assignexpr;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionADDExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new AddASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionMINExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new SubASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionMULExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new MulASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionDIVExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new DivASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------
	
	void ParserManage::Manage_Expression_ExpressionMODExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new ModASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionGTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new GtASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionGEExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new GeASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionLTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new LtASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionLEExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new LeASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionEQExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new EqASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionNOTEQExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new NeASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionANDExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new AndASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionORExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new OrASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionNOTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr){

		*_retexpr = new NotASTNode();

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_MetaExpression (ASTNode *_metaexpr, ASTNode **_retexpr){

		*_retexpr = _metaexpr;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_Term (ASTNode *_term, ASTNode **_retexpr){

		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered expr : term Rule");

		*_retexpr = _term;
	}


	//////////////////////////////////////////////////////////
	// Manage  expression list
	void ParserManage::Manage_ExpressionList (ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist) {
		*_retelist = _expr;

		if(_elists != NULL)
			(*_retelist)->SetRightSibling(_elists);
	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ExpressionList_Empty (ASTNode **_retelist)
		{ *_retelist = NULL; }



	//////////////////////////////////////////////////////////
	// Manage loops statements
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ForStatement (ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt) {
		*_retforstmt = new ForASTNode("for");

		for(ASTNode *nxtExpr; _elist1 != NULL; _elist1 = nxtExpr){
			**_retforstmt << _elist1->Clone();
			nxtExpr = static_cast<ASTNode*>(+(*_elist1));
			delete _elist1;
		}
		**_retforstmt << _expr;
		for(ASTNode *nxtExpr; _elist2 != NULL; _elist2 = nxtExpr){
			**_retforstmt << _elist2->Clone();
			nxtExpr = static_cast<ASTNode*>(+(*_elist2));
			delete _elist2;
		}
		**_retforstmt << _stmt;	
	}
	

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_WhileStatement (ASTNode *_expr, ASTNode *_stmt, ASTNode **_retwhilestmt) {
		*_retwhilestmt = new WhileASTNode("while");
		**_retwhilestmt << _expr << _stmt;
	}


	//////////////////////////////////////////////////////////
	// Manage function definition

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_FunctionDefinition_Function (char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef) {
		*_retfuncdef = new FunctionASTNode("Function");
		StringASTNode *id = new StringASTNode(_id);

		**_retfuncdef << id;	// To remove(No need to keep function names after we use unique IDs)
		for(ASTNode *nxtID; _idlist != NULL; _idlist = nxtID){
			**_retfuncdef << _idlist->Clone();
			nxtID = static_cast<ASTNode*>(+(*_idlist));
			delete _idlist;
		}
		**_retfuncdef << _block;

		delete _id;
	}

	
	//-----------------------------------------------------------------
	
	void ParserManage::Manage_FunctionDefinition_LamdaFunction (ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef) {
		*_retfuncdef = new LamdaFunctionASTNode("Lamda Function");

		for(ASTNode *nxtID; _idlist != NULL; _idlist = nxtID){
			**_retfuncdef << _idlist->Clone();
			nxtID = static_cast<ASTNode*>(+(*_idlist));
			delete _idlist;
		}
		**_retfuncdef << _block;	
	}


	//////////////////////////////////////////////////////////
	// Manage id list

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_IDList (char *_id, ASTNode *_idlists, ASTNode **_retidlist) {
		*_retidlist = new StringASTNode(_id);

		if(_idlists != NULL)
			(*_retidlist)->SetRightSibling(_idlists);

		delete _id;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IDList_Empty (ASTNode **_retidlist)
		{ *_retidlist = NULL; }


	//////////////////////////////////////////////////////////
	// Manage if statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IfStatement_If	(ASTNode *_expr, ASTNode *_stmt, ASTNode **_retifstmt) {
		*_retifstmt = new IfASTNode("if");
		**_retifstmt << _expr << _stmt;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IfStatement_IfElse	(ASTNode *_expr, ASTNode *_stmt1, ASTNode *_stmt2, ASTNode **_retifstmt) {
		*_retifstmt = new IfElseASTNode("if else");
		**_retifstmt << _expr << _stmt1 << _stmt2;
	}


	//////////////////////////////////////////////////////////
	// Manage l-value

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_LValue_ID (char *_id, ASTNode **_retlvalue) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered lvalue : id Rule. ID = ") + SIN::String(_id));

		*_retlvalue = new IDASTNode(_id);

		delete _id;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_LocalID (char *_localID, ASTNode **_retlvalue){
		*_retlvalue = new LocalIDASTNode(string_cast("local ")+string_cast(_localID));

		delete _localID;
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_GlobalID (char *_globalID, ASTNode **_retlvalue){
		*_retlvalue = new GlobalIDASTNode(string_cast("global ")+string_cast(_globalID));

		delete _globalID;
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_Member	(ASTNode *_member, ASTNode **_retlvalue)
		{ *_retlvalue = _member; }


	//////////////////////////////////////////////////////////
	// Manage member
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueID (ASTNode *_lvalue, char *_id, ASTNode **_retmember) {
		*_retmember = new ObjectMemberASTNode("lv.id");
		StringASTNode *id = new StringASTNode(_id);

		**_retmember << _lvalue << id;

		delete _id;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueExpression (ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retmember) {
		*_retmember = new ObjectIndexASTNode("lv[expr]");
		**_retmember << _lvalue << _expr;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_CallID (ASTNode *_call, char *_id, ASTNode **_retmember) {
		*_retmember = new CallMemberASTNode("call.id");
		StringASTNode *id = new StringASTNode(_id);
		**_retmember << _call << id;

		delete _id;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_CallExpression (ASTNode *_call, ASTNode *_expr, ASTNode **_retmember) {
		*_retmember = new CallIndexASTNode("call[expr]");
		**_retmember << _call << _expr;	
	}


	//////////////////////////////////////////////////////////
	// Manage method and normal call
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_MethodCall (char *_id, ASTNode *_elist, ASTNode **_retmethodcall) {
		*_retmethodcall = new MethodCallASTNode("Method call");
		StringASTNode *id = new StringASTNode(_id);

		**_retmethodcall << id;

		ASTNode *arguments = new ArgumentsASTNode("Arguments");
		for(ASTNode *nxtExpr; _elist != NULL; _elist = nxtExpr){
			*arguments << _elist->Clone();
			nxtExpr = static_cast<ASTNode*>(+(*_elist));
			delete _elist;
		}
		**_retmethodcall << arguments;

		delete _id;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_NormalCall (ASTNode *_elist, ASTNode **_retnormalcall) {
		*_retnormalcall = new NormalCallASTNode("Normal Call");

		ASTNode *arguments = new ArgumentsASTNode("Arguments");
		for(ASTNode *nxtExpr; _elist != NULL; _elist = nxtExpr){
			*arguments << _elist->Clone();
			nxtExpr = static_cast<ASTNode*>(+(*_elist));
			delete _elist;
		}
		**_retnormalcall << arguments;
	}


	//////////////////////////////////////////////////////////
	// Manage object definition
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectDefinition_EmptyObject (ASTNode **_retobjectdef) 
		{ *_retobjectdef = new EmptyObjectASTNode("Empty object"); }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectDefinition_ObjectList (ASTNode *_objectlist, ASTNode **_retobjectdef) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered objectdef : [ objectlist ] Rule");

		*_retobjectdef = new ObjectASTNode("Object");

		for(ASTNode *nxtObject; _objectlist != NULL; _objectlist = nxtObject){
			**_retobjectdef << _objectlist->Clone();
			nxtObject = static_cast<ASTNode*>(+(*_objectlist));
			delete _objectlist;
		}	
	}


	//////////////////////////////////////////////////////////
	// Manage object list
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_ExpressionObjectLists (ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists) {
		*_retobjectlists = new UnindexedMemberASTNode("Unindexed Object");

		**_retobjectlists << _expr;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists (ASTNode *_expr1, ASTNode *_expr2, ASTNode *_objectlists, ASTNode **_retobjectlists) {
		*_retobjectlists = new IndexedMemberASTNode("Indexed Object");

		**_retobjectlists << _expr1 << _expr2;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_Empty (ASTNode **_retobjectlists) 
		{ *_retobjectlists = NULL; }


	//////////////////////////////////////////////////////////
	// Manage primary
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_LValue	(ASTNode *_lvalue, ASTNode **_retprimary) 
		{ *_retprimary = _lvalue; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_Call (ASTNode *_call, ASTNode **_retprimary) 
		{ *_retprimary = _call; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_ObjectDefinition (ASTNode *_objectdef, ASTNode **_retprimary) 
		{ *_retprimary = _objectdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_FunctionDefinitionParentheses (ASTNode *_funcdef, ASTNode **_retprimary) 
		{ *_retprimary = _funcdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_Constant (ASTNode *_const, ASTNode **_retprimary) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered primary : constant Rule");
		if(_retprimary == NULL)
			logger.Error("Const node is Nil");

		*_retprimary = _const;	
	}


	//////////////////////////////////////////////////////////
	// Manage return statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ReturnStatement_Return (ASTNode **_retreturnstmt)
		{ *_retreturnstmt = new ReturnASTNode("return"); }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ReturnStatement_ReturnExpression (ASTNode *_expr, ASTNode **_retreturnstmt) {
		*_retreturnstmt = new ReturnASTNode("return expr");
		**_retreturnstmt << _expr;	
	}


	//////////////////////////////////////////////////////////
	// Manage start token
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_SinCode (ASTNode *_stmts, ASTNode **_retsincode) {
		*_retsincode = new ASTNode("AST");

		for(ASTNode *nxtStmt; _stmts != NULL; _stmts = nxtStmt){
			**_retsincode << _stmts->Clone();
			nxtStmt = static_cast<ASTNode*>(+(*_stmts));
			delete _stmts;
		}	
	}


	//////////////////////////////////////////////////////////
	// Manage statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Expression (ASTNode *_expr, ASTNode **_retstmt) 
		{ *_retstmt = _expr; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_IfStatement (ASTNode *_ifstmt, ASTNode **_retstmt) 
		{ *_retstmt = _ifstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_WhileStatement (ASTNode *_whilestmt, ASTNode **_retstmt)
		{ *_retstmt = _whilestmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_ForStatement (ASTNode *_forstmt, ASTNode **_retstmt)
		{ *_retstmt = _forstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_ReturnStatement (ASTNode *_returnstmt, ASTNode **_retstmt)
		{ *_retstmt = _returnstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Break (ASTNode **_retstmt) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered stmt : break Rule");

		*_retstmt = new BreakASTNode("Break");	
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Continue (ASTNode **_retstmt)
		{ *_retstmt = new ContinueASTNode("Continue"); }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Block (ASTNode *_block, ASTNode **_retstmt)
		{ *_retstmt = _block; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_FunctionDefinition (ASTNode *_funcdef, ASTNode **_retstmt)
		{ *_retstmt = _funcdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Semicolon (ASTNode **_retstmt)
		{ *_retstmt = new SemicolonASTNode(";"); }


	//////////////////////////////////////////////////////////
	// Manage statements
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statements (ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts) {
		*_retstmts = _stmt;

		if(_stmts != NULL)
			(*_retstmts)->SetRightSibling(_stmts);	
	}
		
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statements_Empty (ASTNode **_retstmts)
		{ *_retstmts = NULL; }


	//////////////////////////////////////////////////////////
	// Manage term
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_ExpressionParentheses (ASTNode *_expr, ASTNode **_retterm)
		{ *_retterm = _expr; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_MINExpression (ASTNode *_expr, ASTNode **_retterm) {
		*_retterm = new UnaryMinASTNode("-expr");
		**_retterm << _expr;
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Term_NOTExpression (ASTNode *_expr, ASTNode **_retterm) {
		*_retterm = new UnaryNotASTNode("not expr");
		**_retterm << _expr;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_INCRLValue (ASTNode *_lvalue, ASTNode **_retterm) {
		*_retterm = new PreIncrASTNode("++lvalue");
		**_retterm << _lvalue;
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_LValueINCR (ASTNode *_lvalue, ASTNode **_retterm) {
		*_retterm = new PostIncrASTNode("lvalue++");
		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_DECRLValue (ASTNode *_lvalue, ASTNode **_retterm) {
		*_retterm = new PreDecrASTNode("--lvalue");
		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_LValueDECR (ASTNode *_lvalue, ASTNode **_retterm) {
		*_retterm = new PostDecrASTNode("lvalue--");
		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_Primary (ASTNode *_primary, ASTNode **_retterm) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered term : primary Rule");

		*_retterm = _primary;	
	}



}	//namepsace SIN