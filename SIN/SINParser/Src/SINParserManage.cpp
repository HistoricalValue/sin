#include "SINParserManage.h"


#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINASTNodes.h"
#include "SINAlloc.h"

namespace SIN {
	
	bool ParserManage::methodCall = false;

	//////////////////////////////////////////////////////////
	// Manage Assign expression
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_AssignExpression (const int lineNo, ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retassignexpr, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered lvalue = expr Rule");
		*_retassignexpr = SINEWCLASS(AssignASTNode, ("=", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retassignexpr);

		**_retassignexpr << _lvalue << _expr;
	}
	

	//////////////////////////////////////////////////////////
	// Manage Metaexpressions

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_ShiftToMetaExpression (const int lineNo, ASTNode *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaParseASTNode, (".<>.", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _expr;
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_PreserveAST_ID (const int lineNo, char *_id, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaPreserveASTNode, (".~", _lbpa->GetFileName(), lineNo));
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id));
		_lbpa->AppendToNodeList(*_retmetaexpr);
		_lbpa->AppendToNodeList(id);

		**_retmetaexpr << id;

		SINDELETEARRAY(_id);
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_PreserveAST_Expression	(const int lineNo, ASTNode *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa) {
		*_retmetaexpr = SINEWCLASS(MetaPreserveASTNode, (".~", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _expr;
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_PreserveAST_CALL (const int lineNo, ASTNode *_call, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa) {
		*_retmetaexpr = SINEWCLASS(MetaPreserveASTNode, (".~", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _call;
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_CompileMetaExpression (const int lineNo, ASTNode *_metaexpr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaEvaluateASTNode, (".!", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _metaexpr;
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_Expression_UnparseMetaExpression (const int lineNo, ASTNode *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaUnparseASTNode, (".#", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmetaexpr);

		**_retmetaexpr << _expr;
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_MetaExpression_ParseString (const int lineNo, char *_expr, ASTNode **_retmetaexpr, LexAndBisonParseArguments *_lbpa){
		*_retmetaexpr = SINEWCLASS(MetaParseStringASTNode, (".@", _lbpa->GetFileName(), lineNo));
		StringASTNode *expr = SINEWCLASS(StringASTNode, (_expr, _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmetaexpr);
		_lbpa->AppendToNodeList(expr);

		**_retmetaexpr << expr;

		SINDELETEARRAY(_expr);
	}

		
	//////////////////////////////////////////////////////////
	// Manage Block

	//-----------------------------------------------------------------

	void ParserManage::Manage_Block	(const int lineNo, ASTNode *_stmtd, ASTNode **_retblock, LexAndBisonParseArguments *_lbpa) {
		*_retblock = SINEWCLASS(BlockASTNode, ("Block", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retblock);

//		for(; _stmtd; _stmtd = static_cast<ASTNode*>(+(*_stmtd)))
			(*_retblock)->ConnectChild(_stmtd);
	}

	
	//////////////////////////////////////////////////////////
	// Manage Call
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_CallCallSuffix (const int lineNo, ASTNode *_call, ASTNode *_callsuffix, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa) {	
		*_retcall = _callsuffix;
		*SINPTR(_call) >> **_retcall;
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_LValueCallSuffix (const int lineNo, ASTNode *_lvalue, ASTNode *_callsuffix, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa) {	
		*_retcall = _callsuffix;

		if (methodCall) {
			*SINPTR(_lvalue) >> (*(*_retcall)->begin());

			IDASTNode *id = SINEWCLASS(IDASTNode, (_lvalue->Name(), _lbpa->GetFileName(), lineNo));
			_lbpa->AppendToNodeList(id);
			
			*SINPTR(id) >> (*(*_retcall)->rbegin());

			methodCall = false;
		}
		else 
			*SINPTR(_lvalue) >> **_retcall;
	}
	

	//-----------------------------------------------------------------

	void ParserManage::Manage_Call_FunctionDefinitionExpressionList	(const int lineNo, ASTNode *_funcdef, ASTNode *_elist, ASTNode **_retcall, LexAndBisonParseArguments *_lbpa) {
		*_retcall = SINEWCLASS(FuncdefCallASTNode, ("funcdef call", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retcall);

		**_retcall << _funcdef;
		ASTNode *arguments = SINEWCLASS(ActualArgumentsASTNode, ("Actual Arguments", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(arguments);
		if (_elist != 0x00)
			*arguments + _elist;
		else
			; // TODO ELSE WHAT?!?!?

		**_retcall << arguments;
	}
	
	
	//////////////////////////////////////////////////////////
	// Manage Call Suffix

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_CallSuffix_NormalCall (const int lineNo, ASTNode *_normalcall, ASTNode **_retcallsuffix, LexAndBisonParseArguments *_lbpa) 
		{ *_retcallsuffix = _normalcall; }


	//-----------------------------------------------------------------

	void ParserManage::Manage_CallSuffix_MethodCall (const int lineNo, ASTNode *_methodcall, ASTNode **_retcallsuffix, LexAndBisonParseArguments *_lbpa) 
		{ *_retcallsuffix = _methodcall; }


	//////////////////////////////////////////////////////////
	// Manage constant
	
	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_Number (const int lineNo, double _number, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered const : Number Rule. Number ") + SIN::to_string(_number));

		*_retconst = SINEWCLASS(NumberASTNode, (_number, _lbpa->GetFileName(), lineNo));	
		_lbpa->AppendToNodeList(*_retconst);
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_String (const int lineNo, char *_string, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered const : string Rule. String ") + SIN::String(_string));

		*_retconst = SINEWCLASS(StringASTNode, (_string, _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retconst);

		logger.Notice((*_retconst)->Name());

		SINDELETEARRAY(_string);
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_Nil (const int lineNo, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa){
		*_retconst = SINEWCLASS(NilASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retconst);
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_True (const int lineNo, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa){
		*_retconst = SINEWCLASS(TrueASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retconst);
	}
	

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Constant_False	(const int lineNo, ASTNode **_retconst, LexAndBisonParseArguments *_lbpa){
		*_retconst = SINEWCLASS(FalseASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retconst);
	}



	///////////////////////////////////////////////////////////
	// Manage Expressions
	
	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_AssignExpression (const int lineNo, ASTNode *_assignexpr, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = _assignexpr;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionADDExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(AddASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionMINExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(SubASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionMULExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(MulASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionDIVExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(DivASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------
	
	void ParserManage::Manage_Expression_ExpressionMODExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(ModASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionGTExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(GtASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionGEExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(GeASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionLTExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(LtASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionLEExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(LeASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionEQExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(EqASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionNOTEQExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(NeASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionANDExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(AndASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_ExpressionORExpression (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = SINEWCLASS(OrASTNode, (_lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retexpr);

		**_retexpr << _expr1 << _expr2;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_MetaExpression (const int lineNo, ASTNode *_metaexpr, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		*_retexpr = _metaexpr;
	}

	//---------------------------------------------------------------------

	void ParserManage::Manage_Expression_Term (const int lineNo, ASTNode *_term, ASTNode **_retexpr, LexAndBisonParseArguments *_lbpa){

		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered expr : term Rule");

		*_retexpr = _term;
	}


	//////////////////////////////////////////////////////////
	// Manage  expression list
	void ParserManage::Manage_ExpressionList (const int lineNo, ASTNode *_expr, ASTNode *_elists, ASTNode **_retelist, LexAndBisonParseArguments *_lbpa) {
		*_retelist = _expr;

		if(_elists != NULL)
			(*_retelist)->SetRightSibling(_elists);
	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ExpressionList_Empty (const int lineNo, ASTNode **_retelist, LexAndBisonParseArguments *_lbpa)
		{ *_retelist = NULL; }



	//////////////////////////////////////////////////////////
	// Manage loops statements
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ForStatement (const int lineNo, ASTNode *_elist1, ASTNode *_expr, ASTNode *_elist2, ASTNode *_stmt, ASTNode **_retforstmt, LexAndBisonParseArguments *_lbpa) {
		*_retforstmt = SINEWCLASS(ForASTNode, ("for", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retforstmt);

		ForPreambleASTNode* for_preamble = SINEWCLASS(ForPreambleASTNode, ("ForPreamble", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(for_preamble);
		*for_preamble + _elist1; // StrictTree notation: adopt a chain of orphans

		**_retforstmt << for_preamble;
		**_retforstmt << _expr; // condition

		ForAddendumASTNode* for_addendum = SINEWCLASS(ForAddendumASTNode, ("ForAddendum", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(for_addendum);
		*for_addendum + _elist2; // StrictTree notation: adopt a chain of orphans

		**_retforstmt << for_addendum;
		**_retforstmt << _stmt;
		--_lbpa->parsingCounters.loops;
	}
	

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_WhileStatement (const int lineNo, ASTNode *_expr, ASTNode *_stmt, ASTNode **_retwhilestmt, LexAndBisonParseArguments *_lbpa) {
		*_retwhilestmt = SINEWCLASS(WhileASTNode, ("while", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retwhilestmt);

		**_retwhilestmt << _expr << _stmt;
		--_lbpa->parsingCounters.loops;
	}


	//////////////////////////////////////////////////////////
	// Manage function definition


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_FunctionDefinition_Function (const int lineNo, char *_id, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef, LexAndBisonParseArguments *_lbpa) {
		*_retfuncdef = SINEWCLASS(FunctionASTNode, (_id, _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retfuncdef);

		ASTNode *arguments = SINEWCLASS(FormalArgumentsASTNode, ("Formal Arguments", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(arguments);

//		for(; _idlist; _idlist = static_cast<ASTNode*>(+(*_idlist)))
//			arguments->ConnectChild(_idlist);
		if (_idlist != 0x00)
			*arguments + _idlist;

		**_retfuncdef << arguments << _block;

		SINDELETEARRAY(_id);

		--_lbpa->parsingCounters.functions;
	}

	
	//-----------------------------------------------------------------
	
	void ParserManage::Manage_FunctionDefinition_LamdaFunction (const int lineNo, ASTNode *_idlist, ASTNode *_block, ASTNode **_retfuncdef, LexAndBisonParseArguments *_lbpa) {
		*_retfuncdef = SINEWCLASS(	FunctionASTNode, 
									(	String("$lamda") + to_string(_lbpa->parsingCounters.nextLamdaFunctionId++), 
										_lbpa->GetFileName(), 
										lineNo
									)
								);
		_lbpa->AppendToNodeList(*_retfuncdef);

		ASTNode *arguments = SINEWCLASS(FormalArgumentsASTNode, ("Formal Arguments", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(arguments);

		if (_idlist != 0x00)
			*arguments + _idlist;

		**_retfuncdef << arguments << _block;

		--_lbpa->parsingCounters.functions;
	}


	//////////////////////////////////////////////////////////
	// Manage id list

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_IDList (const int lineNo, char *_id, ASTNode *_idlists, ASTNode **_retidlist, LexAndBisonParseArguments *_lbpa) {
		*_retidlist = SINEWCLASS(StringASTNode, (_id, _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retidlist);

		if(_idlists != NULL)
			(*_retidlist)->SetRightSibling(_idlists);

		SINDELETEARRAY(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IDList_Empty (const int lineNo, ASTNode **_retidlist, LexAndBisonParseArguments *_lbpa)
		{ *_retidlist = NULL; }


	//////////////////////////////////////////////////////////
	// Manage if statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IfStatement_If	(const int lineNo, ASTNode *_expr, ASTNode *_stmt, ASTNode **_retifstmt, LexAndBisonParseArguments *_lbpa) {
		*_retifstmt = SINEWCLASS(IfASTNode, ("if", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retifstmt);

		**_retifstmt << _expr << _stmt;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_IfStatement_IfElse	(const int lineNo, ASTNode *_expr, ASTNode *_stmt1, ASTNode *_stmt2, ASTNode **_retifstmt, LexAndBisonParseArguments *_lbpa) {
		*_retifstmt = SINEWCLASS(IfElseASTNode, ("if else", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retifstmt);

		**_retifstmt << _expr << _stmt1 << _stmt2;
	}


	//////////////////////////////////////////////////////////
	// Manage l-value

	//-----------------------------------------------------------------
	
	void ParserManage::Manage_LValue_ID (const int lineNo, char *_id, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice(SIN::String("Entered lvalue : id Rule. ID = ") + SIN::String(_id));

		*_retlvalue = SINEWCLASS(IDASTNode, (_id, _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retlvalue);

		SINDELETEARRAY(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_LocalID (const int lineNo, char *_localID, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa){
		*_retlvalue = SINEWCLASS(LocalIDASTNode, (to_string( _localID), _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retlvalue);

		SINDELETEARRAY(_localID);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_GlobalID (const int lineNo, char *_globalID, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa){
		*_retlvalue = SINEWCLASS(GlobalIDASTNode, (to_string(_globalID), _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retlvalue);

		SINDELETEARRAY(_globalID);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_LValue_Member	(const int lineNo, ASTNode *_member, ASTNode **_retlvalue, LexAndBisonParseArguments *_lbpa)
		{ *_retlvalue = _member; }


	//////////////////////////////////////////////////////////
	// Manage member
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueID (const int lineNo, ASTNode *_lvalue, char *_id, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(ObjectMemberASTNode, ("lv.id", _lbpa->GetFileName(), lineNo));
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id));
		_lbpa->AppendToNodeList(*_retmember);
		_lbpa->AppendToNodeList(id);

		**_retmember << _lvalue << id;

		SINDELETEARRAY(_id);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueKEYS(const int lineNo, ASTNode *_lvalue, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(ObjectKeysASTNode, ("Object.$keys", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmember);

		**_retmember << _lvalue;
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueSIZE(const int lineNo, ASTNode *_lvalue, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(ObjectSizeASTNode, ("Object.$size", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmember);

		**_retmember << _lvalue;
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_LValueExpression (const int lineNo, ASTNode *_lvalue, ASTNode *_expr, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(ObjectIndexASTNode, ("lv[expr]", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmember);

		**_retmember << _lvalue << _expr;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_CallID (const int lineNo, ASTNode *_call, char *_id, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(CallMemberASTNode, ("call.id", _lbpa->GetFileName(), lineNo));
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id, _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmember);
		_lbpa->AppendToNodeList(id);

		**_retmember << _call << id;

		SINDELETEARRAY(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Member_CallExpression (const int lineNo, ASTNode *_call, ASTNode *_expr, ASTNode **_retmember, LexAndBisonParseArguments *_lbpa) {
		*_retmember = SINEWCLASS(CallIndexASTNode, ("call[expr]", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmember);

		**_retmember << _call << _expr;	
	}


	//////////////////////////////////////////////////////////
	// Manage method and normal call
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_MethodCall (const int lineNo, char *_id, ASTNode *_elist, ASTNode **_retmethodcall, LexAndBisonParseArguments *_lbpa) {
		methodCall = true;

		*_retmethodcall = SINEWCLASS(NormalCallASTNode, ("Normal call", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retmethodcall);
		
		
		IDASTNode *id = SINEWCLASS(IDASTNode, (_id, _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(id);


		ObjectMemberASTNode * lvalue = SINEWCLASS(ObjectMemberASTNode, ("lv.id", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(lvalue);
		
		*lvalue << id;

		**_retmethodcall << lvalue;

		ASTNode *arguments = SINEWCLASS(ActualArgumentsASTNode, ("Actual Arguments", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(arguments);

		if (_elist != 0x00)
			*arguments + _elist;

		**_retmethodcall << arguments;
		SINDELETEARRAY(_id);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_NormalCall (const int lineNo, ASTNode *_elist, ASTNode **_retnormalcall, LexAndBisonParseArguments *_lbpa) {
		*_retnormalcall = SINEWCLASS(NormalCallASTNode, ("Normal Call", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retnormalcall);

		ASTNode *arguments = SINEWCLASS(ActualArgumentsASTNode, ("Actual Arguments", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(arguments);

		arguments->ConnectChild(_elist);

		**_retnormalcall << arguments;
	}


	//////////////////////////////////////////////////////////
	// Manage object definition
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectDefinition_EmptyObject (const int lineNo, ASTNode **_retobjectdef, LexAndBisonParseArguments *_lbpa){
		*_retobjectdef = SINEWCLASS(EmptyObjectASTNode, ("Empty object", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retobjectdef);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectDefinition_ObjectList (const int lineNo, ASTNode *_objectlist, ASTNode **_retobjectdef, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered objectdef : [ objectlist ] Rule");

		*_retobjectdef = SINEWCLASS(ObjectASTNode, ("Object", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retobjectdef);

//		for(; _objectlist; _objectlist = static_cast<ASTNode*>(+(*_objectlist)))
			(*_retobjectdef)->ConnectChild(_objectlist);
	}


	//////////////////////////////////////////////////////////
	// Manage object list
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_ExpressionObjectLists (const int lineNo, ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa) {
		*_retobjectlists = SINEWCLASS(UnindexedMemberASTNode, ("Unindexed Object", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retobjectlists);

		**_retobjectlists << _expr;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_ObjectList_ExpressionFunckdefObjectLists (const int lineNo, ASTNode *_expr, ASTNode *_objectlists, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa) {
		*_retobjectlists = SINEWCLASS(IndexedMemberASTNode, ("Indexed Object", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retobjectlists);

		ASTNode * functionName = SINEWCLASS(StringASTNode, (_expr->Name(), _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(functionName);

		**_retobjectlists << functionName << _expr;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists (const int lineNo, ASTNode *_expr1, ASTNode *_expr2, ASTNode *_objectlists, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa) {
		*_retobjectlists = SINEWCLASS(IndexedMemberASTNode, ("Indexed Object", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retobjectlists);

		**_retobjectlists << _expr1 << _expr2;
		if(_objectlists != NULL)
			(*_retobjectlists)->SetRightSibling(_objectlists);
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ObjectList_Empty (const int lineNo, ASTNode **_retobjectlists, LexAndBisonParseArguments *_lbpa) 
		{ *_retobjectlists = NULL; }


	//////////////////////////////////////////////////////////
	// Manage primary
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_LValue	(const int lineNo, ASTNode *_lvalue, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _lvalue; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_Call (const int lineNo, ASTNode *_call, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _call; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_ObjectDefinition (const int lineNo, ASTNode *_objectdef, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _objectdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_FunctionDefinitionParentheses (const int lineNo, ASTNode *_funcdef, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) 
		{ *_retprimary = _funcdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Primary_Constant (const int lineNo, ASTNode *_const, ASTNode **_retprimary, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered primary : constant Rule");

		*_retprimary = _const;
	}


	//////////////////////////////////////////////////////////
	// Manage return statement
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ReturnStatement_Return (const int lineNo, ASTNode **_retreturnstmt, LexAndBisonParseArguments *_lbpa){
		if (_lbpa->parsingCounters.functions == 0)
			_lbpa->SetError(LexAndBisonParseArguments::ErrorInfo("Use of 'return' while not in a function!", lineNo));
	
		*_retreturnstmt = SINEWCLASS(ReturnASTNode, ("return", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retreturnstmt);
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_ReturnStatement_ReturnExpression (const int lineNo, ASTNode *_expr, ASTNode **_retreturnstmt, LexAndBisonParseArguments *_lbpa) {
		if (_lbpa->parsingCounters.functions == 0)
			_lbpa->SetError(LexAndBisonParseArguments::ErrorInfo("Use of 'return' while not in a function!", lineNo));
		
		*_retreturnstmt = SINEWCLASS(ReturnASTNode, ("return expr", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retreturnstmt);

		**_retreturnstmt << _expr;
	}


	//////////////////////////////////////////////////////////
	// Manage start token
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_SinCode (const int lineNo, ASTNode *_stmts, ASTNode **_retsincode, LexAndBisonParseArguments *_lbpa) {
		*_retsincode = SINEWCLASS(SinCodeASTNode, ("AST", _lbpa->GetFileName(), lineNo));
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

	void ParserManage::Manage_Statement_Expression (const int lineNo, ASTNode *_expr, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa) 
		{ *_retstmt = _expr; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_IfStatement (const int lineNo, ASTNode *_ifstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa) 
		{ *_retstmt = _ifstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_WhileStatement (const int lineNo, ASTNode *_whilestmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _whilestmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_ForStatement (const int lineNo, ASTNode *_forstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _forstmt; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_ReturnStatement (const int lineNo, ASTNode *_returnstmt, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _returnstmt; }
	


	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Break (const int lineNo, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered stmt : break Rule");

		if (_lbpa->parsingCounters.loops == 0)
			_lbpa->SetError(LexAndBisonParseArguments::ErrorInfo("Use of 'break' while not in a loop!", lineNo));

		*_retstmt = SINEWCLASS(BreakASTNode, ("Break", _lbpa->GetFileName(), lineNo));	
		_lbpa->AppendToNodeList(*_retstmt);
	}

	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Continue (const int lineNo, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa){
		if (_lbpa->parsingCounters.loops == 0)
			_lbpa->SetError(LexAndBisonParseArguments::ErrorInfo("Use of 'continue' while not in a loop!", lineNo));
		
		
		*_retstmt = SINEWCLASS(ContinueASTNode, ("Continue", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retstmt);
	}
	
	

	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Block (const int lineNo, ASTNode *_block, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _block; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_FunctionDefinition (const int lineNo, ASTNode *_funcdef, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa)
		{ *_retstmt = _funcdef; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Semicolon (const int lineNo, ASTNode **_retstmt, LexAndBisonParseArguments *_lbpa){
		*_retstmt = SINEWCLASS(SemicolonASTNode, (";"));
		_lbpa->AppendToNodeList(*_retstmt);
	}


	//-----------------------------------------------------------------

	void ParserManage::Manage_Statement_Error (const int lineNo, ASTNode **_error, LexAndBisonParseArguments *_lbpa)
		{ *_error = NULL; }


	//////////////////////////////////////////////////////////
	// Manage statements
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Statements (const int lineNo, ASTNode *_stmt, ASTNode *_stmts, ASTNode **_retstmts, LexAndBisonParseArguments *_lbpa) {

		if(_stmt != NULL){
			*_retstmts = _stmt;
			if(_stmts != NULL)
				(*_retstmts)->SetRightSibling(_stmts);	
		}else
			*_retstmts = _stmts;
	}
		
	
	//-----------------------.------------------------------------------

	void ParserManage::Manage_Statements_Empty (const int lineNo, ASTNode **_retstmts, LexAndBisonParseArguments *_lbpa)
		{ *_retstmts = NULL; }


	//////////////////////////////////////////////////////////
	// Manage term
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_ExpressionParentheses (const int lineNo, ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa)
		{ *_retterm = _expr; }
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_MINExpression (const int lineNo, ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(UnaryMinASTNode, ("-expr", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _expr;
	}


	//-----------------------------------------------------------------
	
	void ParserManage::Manage_Term_NOTExpression (const int lineNo, ASTNode *_expr, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(UnaryNotASTNode, ("not expr", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retterm);
		**_retterm << _expr;
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_INCRLValue (const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PreIncrASTNode, ("++lvalue", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;
	}
	
	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_LValueINCR (const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PostIncrASTNode, ("lvalue++", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_DECRLValue (const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PreDecrASTNode, ("--lvalue", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_LValueDECR (const int lineNo, ASTNode *_lvalue, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		*_retterm = SINEWCLASS(PostDecrASTNode, ("lvalue--", _lbpa->GetFileName(), lineNo));
		_lbpa->AppendToNodeList(*_retterm);

		**_retterm << _lvalue;	
	}

	
	//-----------------------------------------------------------------

	void ParserManage::Manage_Term_Primary (const int lineNo, ASTNode *_primary, ASTNode **_retterm, LexAndBisonParseArguments *_lbpa) {
		SIN::Logger &logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Parser::Manage");
		logger.Notice("Entered term : primary Rule");

		*_retterm = _primary;	
	}



}	//namepsace SIN
