#include "SINParserManage.h"


#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINASTNodes.h"
#include "SINAlloc.h"

namespace SIN {


	//////////////////////////////////////////////////////////
	// Manage Assign expression
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_AssignExpression (ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retassignexpr, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered lvalue = expr Rule");
		*_retassignexpr = SINEWCLASS(AssignASTNode, ("="));
		_lbpa->AppendToNodeList(*_retassignexpr);

		**_retassignexpr << _lvalue << _expr;
	}
	

	//////////////////////////////////////////////////////////
	// Manage Metaexpressions

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_ShiftToMetaExpression (ASTNode *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaParseASTNode, (".<>."));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _expr;
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_PreserveAST_ID (char *_id, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaPreserveASTNode, (".~"));
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id));
		_lbpa->AppendToNodeList(*_retmetaexpr);
		_lbpa->AppendToNodeList(id);

		**_retmetaexpr << id;

		SINDELETE(_id);
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_CompileMetaExpression (ASTNode *_metaexpr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaEvaluateASTNode, (".!"));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _metaexpr;
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_Expression_UnparseMetaExpression (ASTNode *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaEvaluateASTNode, (".#"));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _expr;
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_ParseString (char *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaEvaluateASTNode, (".@"));
		StringASTNode *expr = SINEWCLASS(StringASTNode, (_expr));
		_lbpa->AppendToNodeList(*_retmetaexpr);
		_lbpa->AppendToNodeList(expr);

		**_retmetaexpr << expr;

		SINDELETE(_expr);
	}

		
	//////////////////////////////////////////////////////////
	// Manage Block

	//-----------------------------------------------------------------

	void ParserManage::Manage_Block	(ASTNode *_stmtd, ASTNode **_retblock, LexAndBisonParseArguments *_lbpa) {
		*_retblock = SINEWCLASS(BlockASTNode, ("Block"));
		_lbpa->AppendToNodeList(*_retblock);

//		for(; _stmtd; _stmtd = static_cast<ASTNode*>(+(*_stmtd)))
			(*_retblock)->ConnectChild(_stmtd);
	}

	
	//////////////////////////////////////////////////////////
	// Manage Call
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_CallCallSuffix (ASTNode *_call, ASTNode *_callsuffix, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa) {	
		*_retcall = _callsuffix;
		*SINPTR(_call) >> **_retcall;
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_LValueCallSuffix (ASTNode *_lvalue, ASTNode *_callsuffix, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa) {	
		*_retcall = _callsuffix;
		*SINPTR(_lvalue) >> **_retcall;
	}
	

	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_FunctionDefinitionExpressionList	(ASTNode *_funcdef, ASTNode *_elist, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa) {
		*_retcall = SINEWCLASS(FuncdefCallASTNode, ("funcdef call"));
		_lbpa->AppendToNodeList(*_retcall);

		**_retcall << _funcdef;
		ASTNode *arguments = SINEWCLASS(ActualArgumentsASTNode, ("Actual Arguments"));

//		for(; _elist; _elist = static_cast<ASTNode*>(+(*_elist)))
			arguments->ConnectChild(_elist);

		**_retcall << arguments;
	}
	
	
	//////////////////////////////////////////////////////////
	// Manage Call Suffix

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_CallSuffix_NormalCall (ASTNode *_normalcall, ASTNode **_retcallsuffix, LexAndBisonParseArguments *_lbpa) 
		{ *_retcallsuffix = _normalcall; }


	//-----------------------------------------------------------------

	void ParserManage::Manage_CallSuffix_MethodCall (ASTNode *_methodcall, ASTNode **_retcallsuffix, LexAndBisonParseArguments *_lbpa) 
		{ *_retcallsuffix = _methodcall; }


	//////////////////////////////////////////////////////////
	// Manage constant
	
	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_Number (double _number, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered const : Number Rule. Number ") + SIN::to_string(_number));

		*_retconst = SINEWCLASS(NumberASTNode, (_number));	
		_lbpa->AppendToNodeList(*_retconst);
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_String (char *_string, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered const : string Rule. String ") + SIN::String(_string));

		*_retconst = SINEWCLASS(StringASTNode, (_string));
		_lbpa->AppendToNodeList(*_retconst);

		logger.Notice((*_retconst)->Name());

		SINDELETE(_string);
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_Nil (ASTNode **_retconst, LexAndBisonParseArguments *_lbpa){
		*_retconst = SINEWCLASS(NilASTNode, ());
		_lbpa->AppendToNodeList(*_retconst);
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_True (ASTNode **_retconst, LexAndBisonParseArguments *_lbpa){
		*_retconst = SINEWCLASS(TrueASTNode, ());
		_lbpa->AppendToNodeList(*_retconst);
	}
	

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_False	(ASTNode **_retconst, LexAndBisonParseArguments *_lbpa){
		*_retconst = SINEWCLASS(FalseASTNode, ());
		_lbpa->AppendToNodeList(*_retconst);
	}



	///////////////////////////////////////////////////////////
	// Manage Expressions
	
	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_AssignExpression (ASTNode *_assignexpr, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = _assignexpr;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionADDExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(AddASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionMINExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(SubASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionMULExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(MulASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionDIVExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(DivASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------
	
	void ParserManage::Manage_Expression_ExpressionMODExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(ModASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionGTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(GtASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionGEExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(GeASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionLTExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(LtASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionLEExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(LeASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionEQExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(EqASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionNOTEQExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(NeASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionANDExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(AndASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionORExpression (ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(OrASTNode, ());
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_MetaExpression (ASTNode *_metaexpr, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = _metaexpr;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_Term (ASTNode *_term, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered expr : term Rule");

		*_retexpr = _term;
	}


	//////////////////////////////////////////////////////////
	// Manage  expression list
	void ParserManage::Manage_ExpressionList (ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist, LexAndBisonParseArguments *_lbpa) {
		*_retelist = _expr;

		if(_elists != NULL)
			(*_retelist)->SetRightSibling(_elists);
	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ExpressionList_Empty (ASTNode **_retelist, LexAndBisonParseArguments *_lbpa)
		{ *_retelist = NULL; }



	//////////////////////////////////////////////////////////
	// Manage loops statements
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ForStatement (ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt, LexAndBisonParseArguments *_lbpa) {
		*_retforstmt = SINEWCLASS(ForASTNode, ("for"));
		_lbpa->AppendToNodeList(*_retforstmt);

		// TODO add a real node for this
		ASTNode* for_preample = SINEWCLASS(ASTNode, ("for-preample"));
//		for(; _elist1; _elist1 = static_cast<ASTNode*>(+(*_elist1)))
//			(*_retforstmt)->ConnectChild(_elist1);
		*for_preample + _elist1; // StrictTree notation: adopt a chain of orphans

		**_retforstmt << for_preample;
		**_retforstmt << _expr; // condition

		// TODO add a real node for this too 
		ASTNode* for_addendum = SINEWCLASS(ASTNode, ("for-addendum"));
//		for(; _elist2; _elist2 = static_cast<ASTNode*>(+(*_elist2)))
//			(*_retforstmt)->ConnectChild(_elist2);
		*for_addendum + _elist2; // StrictTree notation: adopt a chain of orphans

		**_retforstmt << for_addendum;
		**_retforstmt << _stmt;
	}
	

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_WhileStatement (ASTNode *_expr, ASTNode *_stmt, ASTNode **_retwhilestmt, LexAndBisonParseArguments *_lbpa) {
		*_retwhilestmt = SINEWCLASS(WhileASTNode, ("while"));
		_lbpa->AppendToNodeList(*_retwhilestmt);

		**_retwhilestmt << _expr << _stmt;
	}


	//////////////////////////////////////////////////////////
	// Manage function definition

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_FunctionDefinition_Function (char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef, LexAndBisonParseArguments *_lbpa) {
		*_retfuncdef = SINEWCLASS(FunctionASTNode, (_id));
		_lbpa->AppendToNodeList(*_retfuncdef);

		ASTNode *arguments = SINEWCLASS(FormalArgumentsASTNode, ("Formal Arguments"));

//		for(; _idlist; _idlist = static_cast<ASTNode*>(+(*_idlist)))
//			arguments->ConnectChild(_idlist);
		if (_idlist != 0x00)
			*arguments + _idlist;

		**_retfuncdef << arguments << _block;

		SINDELETE(_id);
	}

	
	//-----------------------------------------------------------------
	
	void ParserManage::Manage_FunctionDefinition_LamdaFunction (ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef, LexAndBisonParseArguments *_lbpa) {
		*_retfuncdef = SINEWCLASS(LamdaFunctionASTNode, ());
		_lbpa->AppendToNodeList(*_retfuncdef);

		ASTNode *arguments = SINEWCLASS(FormalArgumentsASTNode, ("Formal Arguments"));

//		for(; _idlist; _idlist = static_cast<ASTNode*>(+(*_idlist)))
//			arguments->ConnectChild(_idlist);
		if (_idlist != 0x00)
			*arguments + _idlist;

		**_retfuncdef << arguments << _block;
	}


	//////////////////////////////////////////////////////////
	// Manage id list

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_IDList (char *_id, ASTNode *_idlists, ASTNode **_retidlist, LexAndBisonParseArguments *_lbpa) {
		*_retidlist = SINEWCLASS(StringASTNode, (_id));
		_lbpa->AppendToNodeList(*_retidlist);

		if(_idlists != NULL)
			(*_retidlist)->SetRightSibling(_idlists);

		SINDELETE(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IDList_Empty (ASTNode **_retidlist, LexAndBisonParseArguments *_lbpa)
		{ *_retidlist = NULL; }


	//////////////////////////////////////////////////////////
	// Manage if statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IfStatement_If	(ASTNode *_expr, ASTNode *_stmt, ASTNode **_retifstmt, LexAndBisonParseArguments *_lbpa) {
		*_retifstmt = SINEWCLASS(IfASTNode, ("if"));
		_lbpa->AppendToNodeList(*_retifstmt);

		**_retifstmt << _expr << _stmt;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IfStatement_IfElse	(ASTNode *_expr, ASTNode *_stmt1, ASTNode *_stmt2, ASTNode **_retifstmt, LexAndBisonParseArguments *_lbpa) {
		*_retifstmt = SINEWCLASS(IfElseASTNode, ("if else"));
		_lbpa->AppendToNodeList(*_retifstmt);

		**_retifstmt << _expr << _stmt1 << _stmt2;
	}


	//////////////////////////////////////////////////////////
	// Manage l-value

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_LValue_ID (char *_id, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered lvalue : id Rule. ID = ") + SIN::String(_id));

		*_retlvalue = SINEWCLASS(IDASTNode, (_id));
		_lbpa->AppendToNodeList(*_retlvalue);

		SINDELETE(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_LocalID (char *_localID, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa){
		*_retlvalue = SINEWCLASS(LocalIDASTNode, (to_string("local ") << _localID));
		_lbpa->AppendToNodeList(*_retlvalue);

		SINDELETE(_localID);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_GlobalID (char *_globalID, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa){
		*_retlvalue = SINEWCLASS(GlobalIDASTNode, (to_string("global ") << _globalID));
		_lbpa->AppendToNodeList(*_retlvalue);

		SINDELETE(_globalID);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_Member	(ASTNode *_member, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa)
		{ *_retlvalue = _member; }


	//////////////////////////////////////////////////////////
	// Manage member
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueID (ASTNode *_lvalue, char *_id, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(ObjectMemberASTNode, ("lv.id"));
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id));
		_lbpa->AppendToNodeList(*_retmember);
		_lbpa->AppendToNodeList(id);

		**_retmember << _lvalue << id;

		SINDELETE(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueExpression (ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(ObjectIndexASTNode, ("lv[expr]"));
		_lbpa->AppendToNodeList(*_retmember);

		**_retmember << _lvalue << _expr;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_CallID (ASTNode *_call, char *_id, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(CallMemberASTNode, ("call.id"));
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id));
		_lbpa->AppendToNodeList(*_retmember);
		_lbpa->AppendToNodeList(id);

		**_retmember << _call << id;

		SINDELETE(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_CallExpression (ASTNode *_call, ASTNode *_expr, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(CallIndexASTNode, ("call[expr]"));
		_lbpa->AppendToNodeList(*_retmember);

		**_retmember << _call << _expr;	
	}


	//////////////////////////////////////////////////////////
	// Manage method and normal call
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_MethodCall (char *_id, ASTNode *_elist, ASTNode **_retmethodcall, LexAndBisonParseArguments *_lbpa) {
		*_retmethodcall = SINEWCLASS(MethodCallASTNode, ("Method call"));
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id));
		_lbpa->AppendToNodeList(*_retmethodcall);
		_lbpa->AppendToNodeList(id);

		**_retmethodcall << id;

		ASTNode *arguments = SINEWCLASS(ActualArgumentsASTNode, ("Actual Arguments"));

//		for(; _elist; _elist = static_cast<ASTNode*>(+(*_elist)))
//			arguments->ConnectChild(_elist);
		if (_elist != 0x00)
			*arguments + _elist;

		**_retmethodcall << arguments;

		SINDELETE(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_NormalCall (ASTNode *_elist, ASTNode **_retnormalcall, LexAndBisonParseArguments *_lbpa) {
		*_retnormalcall = SINEWCLASS(NormalCallASTNode, ("Normal Call"));
		_lbpa->AppendToNodeList(*_retnormalcall);

		ASTNode *arguments = SINEWCLASS(ActualArgumentsASTNode, ("Actual Arguments"));

//		for(; _elist; _elist = static_cast<ASTNode*>(+(*_elist)))
			arguments->ConnectChild(_elist);

		**_retnormalcall << arguments;
	}


	//////////////////////////////////////////////////////////
	// Manage object definition
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectDefinition_EmptyObject (ASTNode **_retobjectdef, LexAndBisonParseArguments *_lbpa){
		*_retobjectdef = SINEWCLASS(EmptyObjectASTNode, ("Empty object"));
		_lbpa->AppendToNodeList(*_retobjectdef);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectDefinition_ObjectList (ASTNode *_objectlist, ASTNode **_retobjectdef, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered objectdef : [ objectlist ] Rule");

		*_retobjectdef = SINEWCLASS(ObjectASTNode, ("Object"));
		_lbpa->AppendToNodeList(*_retobjectdef);

//		for(; _objectlist; _objectlist = static_cast<ASTNode*>(+(*_objectlist)))
			(*_retobjectdef)->ConnectChild(_objectlist);
	}


	//////////////////////////////////////////////////////////
	// Manage object list
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_ExpressionObjectLists (ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa) {
		*_retobjectlists = SINEWCLASS(UnindexedMemberASTNode, ("Unindexed Object"));
		_lbpa->AppendToNodeList(*_retobjectlists);

		**_retobjectlists << _expr;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists (ASTNode *_expr1, ASTNode *_expr2, ASTNode *_objectlists, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa) {
		*_retobjectlists = SINEWCLASS(IndexedMemberASTNode, ("Indexed Object"));
		_lbpa->AppendToNodeList(*_retobjectlists);

		**_retobjectlists << _expr1 << _expr2;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_Empty (ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa) 
		{ *_retobjectlists = NULL; }


	//////////////////////////////////////////////////////////
	// Manage primary
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_LValue	(ASTNode *_lvalue, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _lvalue; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_Call (ASTNode *_call, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _call; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_ObjectDefinition (ASTNode *_objectdef, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _objectdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_FunctionDefinitionParentheses (ASTNode *_funcdef, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _funcdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_Constant (ASTNode *_const, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered primary : constant Rule");

		*_retprimary = _const;
	}


	//////////////////////////////////////////////////////////
	// Manage return statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ReturnStatement_Return (ASTNode **_retreturnstmt, LexAndBisonParseArguments *_lbpa){
		*_retreturnstmt = SINEWCLASS(ReturnASTNode, ("return"));
		_lbpa->AppendToNodeList(*_retreturnstmt);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ReturnStatement_ReturnExpression (ASTNode *_expr, ASTNode **_retreturnstmt, LexAndBisonParseArguments *_lbpa) {
		*_retreturnstmt = SINEWCLASS(ReturnASTNode, ("return expr"));
		_lbpa->AppendToNodeList(*_retreturnstmt);

		**_retreturnstmt << _expr;
	}


	//////////////////////////////////////////////////////////
	// Manage start token
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_SinCode (ASTNode *_stmts, ASTNode **_retsincode, LexAndBisonParseArguments *_lbpa) {
		*_retsincode = SINEWCLASS(SinCodeASTNode, ("AST"));
		_lbpa->AppendToNodeList(*_retsincode);

//		for(; _stmts; _stmts = static_cast<ASTNode*>(+(*_stmts)))
			(*_retsincode)->ConnectChild(_stmts);
		//for(ASTNode *nxtStmt; _stmts != NULL; _stmts = nxtStmt){
			//ASTNode *newstmts = SINPTR(_stmts)->Clone();
			//**_retsincode << newstmts;
			//_lbpa->AppendToNodeList(newstmts);
			//nxtStmt = static_cast<ASTNode*>(+(*_stmts));
			//_lbpa->RemoveNodeFromList(_stmts);
			//SINDELETE(_stmts);
		//}	
	}


	//////////////////////////////////////////////////////////
	// Manage statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Expression (ASTNode *_expr, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa) 
		{ *_retstmt = _expr; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_IfStatement (ASTNode *_ifstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa) 
		{ *_retstmt = _ifstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_WhileStatement (ASTNode *_whilestmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _whilestmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_ForStatement (ASTNode *_forstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _forstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_ReturnStatement (ASTNode *_returnstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _returnstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Break (ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered stmt : break Rule");

		*_retstmt = SINEWCLASS(BreakASTNode, ("Break"));	
		_lbpa->AppendToNodeList(*_retstmt);
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Continue (ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa){
		*_retstmt = SINEWCLASS(ContinueASTNode, ("Continue"));
		_lbpa->AppendToNodeList(*_retstmt);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Block (ASTNode *_block, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _block; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_FunctionDefinition (ASTNode *_funcdef, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _funcdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Semicolon (ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa){
		*_retstmt = SINEWCLASS(SemicolonASTNode, (";"));
		_lbpa->AppendToNodeList(*_retstmt);
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Error (ASTNode **_error, LexAndBisonParseArguments *_lbpa)
		{ *_error = NULL; }


	//////////////////////////////////////////////////////////
	// Manage statements
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statements (ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts, LexAndBisonParseArguments *_lbpa) {

		if(_stmt != NULL){
			*_retstmts = _stmt;
			if(_stmts != NULL)
				(*_retstmts)->SetRightSibling(_stmts);	
		}else
			*_retstmts = _stmts;
	}
		
	
	//-----------------------.------------------------------------------

	void ParserManage::Manage_Statements_Empty (ASTNode **_retstmts, LexAndBisonParseArguments *_lbpa)
		{ *_retstmts = NULL; }


	//////////////////////////////////////////////////////////
	// Manage term
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_ExpressionParentheses (ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa)
		{ *_retterm = _expr; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_MINExpression (ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(UnaryMinASTNode, ("-expr"));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _expr;
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Term_NOTExpression (ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(UnaryNotASTNode, ("not expr"));
		**_retterm << _expr;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_INCRLValue (ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PreIncrASTNode, ("++lvalue"));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_LValueINCR (ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PostIncrASTNode, ("lvalue++"));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_DECRLValue (ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PreDecrASTNode, ("--lvalue"));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_LValueDECR (ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PostDecrASTNode, ("lvalue--"));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_Primary (ASTNode *_primary, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered term : primary Rule");

		*_retterm = _primary;	
	}



}	//namepsace SIN
