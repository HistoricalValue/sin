#include "SINTreeEvaluationVisitor.h"


#include "SINAlloc.h"
#include "SINAssert.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellBool.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellFunction.h"
#include "SINMemoryCellLibFunction.h"
#include "SINLibraryFunction.h"
#include "SINPreserveASTEvaluatorVisitor.h"
#include "SINAdditionOperator.h"
#include "SINDivisionOperator.h"
#include "SINModulusOperator.h"
#include "SINMultiplicationOperator.h"
#include "SINSubtractionOperator.h"
#include "SINLogicalAndOperator.h"
#include "SINLogicalOrOperator.h"
#include "SINEqualityOperator.h"
#include "SINGreaterThanOperator.h"
#include "SINGreaterThanOrEqualToOperator.h"
#include "SINInequalityOperator.h"
#include "SINLessThanOperator.h"
#include "SINLessThanOrEqualToOperator.h"
#include "SINUnaryNegationOperator.h"
#include "SINLogicalNotOperator.h"


#define VISIT_KIDS_SERIALLY												\
		ASTNode::iterator const end = _node.end();						\
		for(ASTNode::iterator kid = _node.begin(); kid != end; ++kid)	\
			static_cast<ASTNode&>(*kid).Accept(this)					\

#define ERROR(MSG, FILE, LINE) vs->AppendError(MSG, FILE, LINE)
#define ERRO(MSG) ERROR(MSG, _node.AssociatedFileName().c_str(), _node.AssociatedFileLine());

namespace SIN {
	//-----------------------------------------------------------------
	// Privates (hihihi) -- not in class -- utils
	//-----------------------------------------------------------------
	namespace {
		class AcceptanceForwardationOperator {
		public:
			typedef TreeEvaluationVisitor* acceptable_t;
			typedef StrictTreeNode& acceptor1_t;
			typedef ASTNode& acceptor2_t;
			AcceptanceForwardationOperator(acceptable_t const& _acceptable): acceptable(_acceptable) { }
			bool operator ()(acceptor1_t _acceptor) const {
				static_cast<acceptor2_t>(_acceptor).Accept(acceptable);
				return true;
			}
		private:
			acceptable_t const& acceptable;
		}; // class Acceptor

	//-----------------------------------------------------------------
		template <typename _OperatorT>
		static void evaluateBinaryOperation(
			TreeEvaluationVisitor& _evaluator,
			void (TreeEvaluationVisitor::* _insertTemporary_p)(InstanceProxy<MemoryCell> const&),
			ASTNode& _node,
			MemoryCell*& _result
		) {
			ASTNode::iterator kite(_node.begin());
			// get operand 1
			static_cast<ASTNode&>(*kite++).Accept(&_evaluator);
			SINASSERT(_result != 0x00);
			MemoryCell* const operand0 = _result;
			// get operand 2
			static_cast<ASTNode&>(*kite++).Accept(&_evaluator);
			SINASSERT(_result != 0x00);
			MemoryCell* const operand1 = _result;
			// get result and store
			(_evaluator.*_insertTemporary_p)(_result = _OperatorT()(*operand0, *operand1));
		}
	} // namespace
#define EVALUATE_BINARY_OPERATION(OPERATOR)	evaluateBinaryOperation<OPERATOR>(*this, &TreeEvaluationVisitor::insertTemporary, _node, memory);


#define EVALUATE_BASIC_MATHEMATIC_OPERATION(OPERATOR)  EVALUATE_BINARY_OPERATION(OPERATOR)
#define EVALUATE_BASIC_LOGICAL_OPERATION(OPERATOR)     EVALUATE_BINARY_OPERATION(OPERATOR)
#define EVALUATE_BASIC_COMPARISON_OPERATION(OPERATOR)  EVALUATE_BINARY_OPERATION(OPERATOR)

#define EVALUATE_AND_ADVANCE(KITE) static_cast<ASTNode&>(*KITE++).Accept(this)

	//-----------------------------------------------------------------
	// Privates (hihihi)
	//-----------------------------------------------------------------
	inline void TreeEvaluationVisitor::resetObjectImp(void) {
		obj_imp = SINEW(Types::Object);
	}

	inline void TreeEvaluationVisitor::assignObjectImpToMemory(void) {
		memory = 0x00;
		MemoryCell::SimpleAssign(memory, SINEWCLASS(MemoryCellObject, (obj_imp)));
		insertTemporary(memory);
	}

	inline void TreeEvaluationVisitor::insertTemporary(InstanceProxy<MemoryCell> const& _tmp) {
		vs->CurrentStable().Insert(vs->CurrentAvrilNamer()++, _tmp);
	}

	inline void TreeEvaluationVisitor::lookup(String const& _id) {
		SymbolTable& stable = vs->CurrentStable();
		lookuped = &stable.Lookup(_id);
		if (lookup_failed())
			lookuped = &vs->BaseStable().Lookup(_id);
	}

	inline void TreeEvaluationVisitor::lookup(String const& _id, SymbolTable::scope_id const _scope) {
		SymbolTable& stable = vs->CurrentStable();
		lookuped = &stable.Lookup(_scope, _id);
	}

	inline void TreeEvaluationVisitor::lookup_global(String const& _id) {
		SymbolTable& stable = vs->BaseStable();
		lookuped = &stable.Lookup(_id);
	}

	inline void TreeEvaluationVisitor::lookup_local(String const& _id) {
		SymbolTable& stable = vs->CurrentStable();
		lookuped = &stable.LookupOnlyInCurrentScope(_id);
	}

	inline bool TreeEvaluationVisitor::lookup_failed(void) const {
		return vs->CurrentStable().LookupFailed(*lookuped) || vs->BaseStable().LookupFailed(*lookuped);
	}

	inline void TreeEvaluationVisitor::insert(String const& _id, MemoryCell* const _val) {
		vs->CurrentStable().Insert(_id, _val);
	}

	inline void TreeEvaluationVisitor::insert(String const& _id, MemoryCell* const _val, SymbolTable::scope_id const _scope) {
		vs->CurrentStable().Insert(_id, _val, _scope);
	}

	inline void TreeEvaluationVisitor::insert_global(String const& _id, MemoryCell* const _val) {
		vs->BaseStable().Insert(_id, _val, 0);
	}

	inline void TreeEvaluationVisitor::triggerReturn(MemoryCell* _returnValue) {
		// Copy return value
		MemoryCell::UnobtrusiveAssign(*vs->CurrentEnvironment().returnValue_p, _returnValue);
		// Notify block iteration to stop
		vs->CurrentEnvironment().returnTriggered = true;
	}

	inline bool TreeEvaluationVisitor::returnTriggered(void) const {
		return vs->CurrentEnvironment().returnTriggered;
	}

	inline void TreeEvaluationVisitor::performCall(
		MemoryCell* const _funcmemcell,
		String const& _func_desc,
		String const& _file_name,
		unsigned int const _file_line,
		ASTNode& _actual_args_astnode
	) {
		if (_funcmemcell->Type() != MemoryCell::FUNCTION_MCT && _funcmemcell->Type() != MemoryCell::LIB_FUNCTION_MCT)
			ERROR(to_string("Calling non-callable: ") << _func_desc.c_str(), _file_name.c_str(), _file_line);
		
		// Evaluate actual arguments
		argument_lists.push(argument_list_t(0u));
		argument_lists.top().reserve(20u);
		_actual_args_astnode.Accept(this); // argument list gets filled here
		
		// New stack frame (new env)
		vs->PushState();

		// Set the argument list in the current environment
		vs->CurrentEnvironment().argument_list_p = &argument_lists.top();

		// Set the return value destination
		InstanceProxy<MemoryCell> returnValue;
		vs->CurrentEnvironment().returnValue_p = &returnValue;

		// Evaluate function code
		if(_funcmemcell->Type() == MemoryCell::FUNCTION_MCT) {
			MemoryCellFunction* func = static_cast<MemoryCellFunction*>(_funcmemcell);
			Types::Function_t function(func->GetValue());
			ASTNode* func_node_ast = func->GetValue().GetASTNode();
			SINASSERT(func_node_ast->Type() == SINASTNODES_FUNCTION_TYPE);
			// We must not revisit the function node itself because it evaluates to inserting
			// the function value in the environment (under its name) (or doing something else
			// if it a nameless/value function).
			// Instead, we must evaluate its formal args and then its body.
			ASTNode::iterator kite = func_node_ast->begin();
			ASTNode& formal_args_ast_node = static_cast<ASTNode&>(*kite++);
			SINASSERT(formal_args_ast_node.Type() == SINASTNODES_FORMALARGUMENTS_TYPE);
			formal_args_ast_node.Accept(this); // insert arguments as formals in env
			ASTNode& body_block_ast_node = static_cast<ASTNode&>(*kite++);
			SINASSERT(body_block_ast_node.Type() == SINASTNODES_BLOCK_TYPE);
			body_block_ast_node.Accept(this); // evaluate the body in the new env
			if (returnValue == 0x00)
				memory = SINEW(MemoryCellNil);
			else
				memory = returnValue;
		} else { // LibFunc
			// add actual arguments to the new environment's symbol table
			Namer arg_namer("$arg_avril_");
			SymbolTable& stable = vs->CurrentStable();
			argument_list_t const& al = argument_lists.top();
			argument_list_t::const_iterator const end = al.end();
			for (argument_list_t::const_iterator ite = al.begin(); ite != end; ++ite)
				stable.Insert(arg_namer++, *ite);

			Library::Function *libfunc = static_cast<MemoryCellLibFunction*>(_funcmemcell)->GetValue();

			(*libfunc)(*vs, *lib);
			memory = 0x00;
			MemoryCell::Assign(memory, vs->ReturnValue());
		}

		// Restore environment
		vs->RestoreState(); 

		// Add return result as a temporary
		insertTemporary(memory);

		// Pop actual arguments' list
		argument_lists.pop();
	} // performCall()

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(void) : memory(NULL), lookuped(NULL), preserveNode(NULL), lib(NULL), vs(NULL), argument_lists() { }

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(Library::Library *_lib, VM::VirtualState *_vs) : 
		memory(NULL), 
		lookuped(NULL), 
		preserveNode(NULL), 
		lib(_lib), 
		vs(_vs), 
		argument_lists(),
		triggeredBreak(false),
		triggeredContinue(false)
		{ }

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(TreeEvaluationVisitor const&):
		memory(0x00), 
		lookuped(0x00), 
		preserveNode(0x00), 
		lib(0x00), 
		vs(0x00), 
		obj_imp(0x00),
		triggeredBreak(false),
		triggeredContinue(false)
		{ SINASSERT(!"Not allowed"); }

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::~TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

//	void TreeEvaluationVisitor::Visit(ASTNode & _node) { SINASSERT(!"Cannot be here any more"); }

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NumberASTNode & _node) {
		insertTemporary(
			memory = SINEWCLASS(MemoryCellNumber, (_node.GetValue()))
		);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(StringASTNode & _node) {
		insertTemporary(
			memory = SINEWCLASS(MemoryCellString, (_node.GetValue()))
		);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NilASTNode & _node) {
		insertTemporary(
			memory = SINEW(MemoryCellNil)
		);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(TrueASTNode & _node) {
		insertTemporary(
			memory = SINEWCLASS(MemoryCellBool, (_node.GetValue()))
		);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FalseASTNode & _node) {
		insertTemporary(
			memory = SINEWCLASS(MemoryCellBool, (_node.GetValue()))
		);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AddASTNode & _node) {	
		EVALUATE_BASIC_MATHEMATIC_OPERATION(AdditionOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SubASTNode & _node) {
		EVALUATE_BASIC_MATHEMATIC_OPERATION(SubtractionOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MulASTNode & _node) {
		EVALUATE_BASIC_MATHEMATIC_OPERATION(MultiplicationOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(DivASTNode & _node) {
		EVALUATE_BASIC_MATHEMATIC_OPERATION(DivisionOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ModASTNode & _node) {
		EVALUATE_BASIC_MATHEMATIC_OPERATION(ModulusOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LtASTNode & _node) {
		EVALUATE_BASIC_COMPARISON_OPERATION(LessThanOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GtASTNode & _node) {
		EVALUATE_BASIC_COMPARISON_OPERATION(GreaterThanOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LeASTNode & _node) {
		EVALUATE_BASIC_COMPARISON_OPERATION(LessThanOrEqualToOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GeASTNode & _node) {
		EVALUATE_BASIC_COMPARISON_OPERATION(GreaterThanOrEqualToOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EqASTNode & _node) {
		EVALUATE_BASIC_COMPARISON_OPERATION(EqualityOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NeASTNode & _node) {
		EVALUATE_BASIC_COMPARISON_OPERATION(InequalityOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(OrASTNode & _node) {
		EVALUATE_BASIC_LOGICAL_OPERATION(LogicalOrOperator);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AndASTNode & _node) {
		EVALUATE_BASIC_LOGICAL_OPERATION(LogicalAndOperator);
	}


	#define ACCEPT_ALL_THE_KIDS()	for(ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid)	\
										static_cast<ASTNode&>(*kid).Accept(this);

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ExpressionListASTNode & _node)
		{	ACCEPT_ALL_THE_KIDS();	}




	#define EVAL_EXPR()				expr.Accept(this);											\
									SINASSERT(memory != 0x00);									\
									SINASSERT(memory->Type() == MemoryCell::BOOL_MCT);			\
									exprMemoryCell = static_cast<MemoryCellBool *>(memory)


	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForASTNode & _node) {

		SINASSERT(_node.NumberOfChildren() == 4);

		MemoryCellBool * exprMemoryCell	= static_cast<MemoryCellBool *>(0);
		ASTNode::iterator kids			= _node.begin();
		
		ASTNode	& elist1				= static_cast<ASTNode&>(*kids++);
		ASTNode & expr					= static_cast<ASTNode&>(*kids++);
		ASTNode & elist2				= static_cast<ASTNode&>(*kids++);
		ASTNode & stmt					= static_cast<ASTNode&>(*kids);

		elist1.Accept(this);
		
		EVAL_EXPR();
		while(exprMemoryCell->GetValue() == true) {
			stmt.Accept(this);
			if (triggeredBreak)
				break;
			elist2.Accept(this);
			EVAL_EXPR();
		}
		triggeredBreak		= false;
		triggeredContinue	= false;
	}


	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForPreambleASTNode & _node) 		
		{	ACCEPT_ALL_THE_KIDS();	}
	
	
	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForAddendumASTNode & _node) 		
		{	ACCEPT_ALL_THE_KIDS();	}


	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(WhileASTNode & _node) {
		MemoryCellBool * exprMemoryCell	= static_cast<MemoryCellBool *>(0);
		ASTNode &  expr			= static_cast<ASTNode&>(*_node.begin());
		ASTNode &  stmt			= static_cast<ASTNode&>(*_node.rbegin());

		EVAL_EXPR();

		while(exprMemoryCell->GetValue() == true) {
			stmt.Accept(this);
			if (triggeredBreak)
				break;
			EVAL_EXPR();
		}
		triggeredBreak		= false;
		triggeredContinue	= false;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfASTNode & _node) {
		MemoryCellBool * exprMemoryCell	= static_cast<MemoryCellBool *>(0);
		ASTNode &  expr			= static_cast<ASTNode&>(*_node.begin());
		ASTNode &  stmt			= static_cast<ASTNode&>(*_node.rbegin());

		EVAL_EXPR();

		if(exprMemoryCell->GetValue() == true)
			stmt.Accept(this);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfElseASTNode & _node) {
		MemoryCellBool * exprMemoryCell	= static_cast<MemoryCellBool *>(0);

		ASTNode::iterator kids			= _node.begin();
		
		ASTNode & expr					= static_cast<ASTNode&>(*kids++);
		ASTNode & stmt1					= static_cast<ASTNode&>(*kids++);
		ASTNode & stmt2					= static_cast<ASTNode&>(*kids);

		EVAL_EXPR();

		if(exprMemoryCell->GetValue() == true)
			stmt1.Accept(this);
		else
			stmt2.Accept(this);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ReturnASTNode & _node) {
		// Evaluate only child
		static_cast<ASTNode&>(*_node.begin()).Accept(this);
		// and
		triggerReturn(memory);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SemicolonASTNode & _node) {
		// TODO implement
		//SINASSERT(!"Not implemented");	Do nothing actually
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BreakASTNode & _node) 
		{	triggeredBreak = true;	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ContinueASTNode & _node) 
		{	triggeredContinue = true;	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BlockASTNode & _node) {
		vs->CurrentStable().IncreaseScope();

		ASTNode::iterator const end = _node.end();						
		for(ASTNode::iterator kid = _node.begin(); kid != end; ++kid) {	
			static_cast<ASTNode&>(*kid).Accept(this);			
			if (triggeredBreak || triggeredContinue || returnTriggered())
				break;
		}

		vs->CurrentStable().DecreaseScope();
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AssignASTNode & _node) {
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		ASTNode& kid0 = static_cast<ASTNode&>(*kid++);
		SINASSERT(kid0.Type() == SINASTNODES_ID_TYPE || kid0.Type() == SINASTNODES_LOCALID_TYPE || kid0.Type() == SINASTNODES_GLOBALID_TYPE || kid0.Type() == SINASTNODES_OBJECTMEMBER_TYPE);

		kid0.Accept(this);
		SINASSERT(memory != 0x00);
		SINASSERT(lookuped != 0x00);
		SINASSERT(memory == *lookuped);
		if (memory->Type() == MemoryCell::FUNCTION_MCT || memory->Type() == MemoryCell::LIB_FUNCTION_MCT)
			// TODO this check is wrong because:
			//     a = println;
			//     a = 3;
			// fails. Fix this.
			ERRO("Assigning to a function");
		MemoryCell *tmpmemcell1 = memory;
		InstanceProxy<MemoryCell>* lookedup_l = lookuped; // looked-up and memory must be saved after each eval of a kid

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;
		SINASSERT(tmpmemcell2 != NULL);

		MemoryCell::Assign(*lookedup_l, tmpmemcell2);
		SINASSERT(*lookedup_l != NULL);
		memory = tmpmemcell2;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FormalArgumentsASTNode & _node) {
		// Insert the actual arguments into the symbol table with the formal arguments names
		// For extra arguments use the default namer.
		SymbolTable& stable = vs->CurrentStable();
		Namer arg_namer("_arg_avril_");
		argument_list_t& actuals = *vs->CurrentEnvironment().argument_list_p;

		typedef argument_list_t::const_iterator actuals_iter_t;
		typedef ASTNode::iterator formals_iter_t;
		
		actuals_iter_t const actuals_end = actuals.end();
		actuals_iter_t actuals_ite = actuals.begin(); 
		formals_iter_t const formals_end = _node.end();
		formals_iter_t formals_ite = _node.begin();
		for(; actuals_ite != actuals_end && formals_ite != formals_end; ++actuals_ite, ++formals_ite)
			stable.Insert(static_cast<ASTNode&>(*formals_ite).Name(), *actuals_ite);

		// If there are extra actuals, fill them in with default naming
		bool extra_actuals;
		if ((extra_actuals = (actuals_ite != actuals_end)))
			for (; actuals_ite != actuals_end; ++actuals_ite)
				stable.Insert(arg_namer++, *actuals_ite);

		// If there are extra formals (in which case there should be no extra actuals as well)
		// we insert them as nil values
		if (formals_ite != formals_end) {
			SINASSERT(!extra_actuals);
			for (; formals_ite != formals_end; ++formals_ite)
				stable.Insert(static_cast<ASTNode&>(*formals_ite).Name(), SINEW(MemoryCellNil));
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ActualArgumentsASTNode & _node) {
		argument_list_t& argument_list = argument_lists.top();

		for(ASTNode::iterator arguments = _node.begin(); arguments != _node.end(); ++arguments){
			static_cast<ASTNode&>(*arguments).Accept(this);
			SINASSERT(memory != 0x00);
			// NOTICE: symbol Tables hold COPIES OF VALUES! Every assignment is a copy of
			// a value!
			// Conceptually, actual arguments are *assignments* of some variables to the
			// argument-variables of a function.
			// Assignment is needed for correct handling of objects;
			MemoryCell* argument = 0x00;
			MemoryCell::Assign(argument, memory);
			argument_list.push_back(argument);
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NormalCallASTNode & _node) {
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		// Lookup the function
		ASTNode& func_id = static_cast<ASTNode&>(*kid++);
		func_id.Accept(this);
		ASTNode& actual_args_astnode = static_cast<ASTNode&>(*kid++);
		performCall(memory, func_id.Name(), _node.AssociatedFileName(), _node.AssociatedFileLine(), actual_args_astnode);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MethodCallASTNode & _node) 
		{	SINASSERT(!"Not ned to implement this. (We did tree hack)");	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FuncdefCallASTNode & _node) {
		ASTNode::iterator kite(_node.begin());
		ASTNode& lambda_astnode = static_cast<ASTNode&>(*kite++);
		SINASSERT(lambda_astnode.Type() == SINASTNODES_FUNCTION_TYPE);
		lambda_astnode.Accept(this);
		SINASSERT(memory->Type() == MemoryCell::FUNCTION_MCT);
		ASTNode& actual_args_astnode = static_cast<ASTNode&>(*kite++);
		// TODO insert a new field in LambdaASTNode and don't use Name() as
		// a description
		performCall(memory, lambda_astnode.Name(), _node.AssociatedFileName(), _node.AssociatedFileLine(),
				actual_args_astnode);		
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FunctionASTNode & _node) {
		// Generally, the function must be added as a value to the current
		// scope.

		// Get the function ID
		String const& func_id = _node.Name();
		// Create the function object and the resulting memcell
		MemoryCellFunction* result = SINEWCLASS(MemoryCellFunction, (Types::Function_t(&_node)));;
		// Lookup and insert the function memcell
		lookup_local(func_id);
		if (lookup_failed())
			// ok here
			insert(func_id, result);
		else
			// lookup succeeded. Fail.
			vs->AppendError(to_string("definition of function with name \"") << func_id << 
				"\" is not possible because there is a variable defined with that name in the same scope",
				_node.AssociatedFileName().c_str(), _node.AssociatedFileLine());

		memory = result;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LamdaFunctionASTNode & _node) {
		// Create the function object and the resulting memcell
		insertTemporary(memory = SINEWCLASS(MemoryCellFunction, (Types::Function_t(&_node))));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IDASTNode & _node) {
		String const& id = _node.Name();
		lookup(id);

		if (lookup_failed()) {
			insert(id, SINEW(MemoryCellNil));
			lookup_local(id);
			SINASSERT(!lookup_failed());
			SINASSERT(static_cast<MemoryCell*>(*lookuped) != 0x00);
			SINASSERT((*lookuped)->Type() == MemoryCell::NIL_MCT);
		}
		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LocalIDASTNode & _node) {
		String const& id = _node.Name();
		lookup_local(id);

		if(lookup_failed()) {
			insert(id, SINEW(MemoryCellNil));
			lookup_local(id);
			SINASSERT(!lookup_failed());
			SINASSERT(static_cast<MemoryCell*>(*lookuped) != 0x00);
			SINASSERT((*lookuped)->Type() == MemoryCell::NIL_MCT);
		}
		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GlobalIDASTNode & _node) {
		String const& id = _node.Name();
		lookup_global(id);

		if(lookup_failed()) {
			insert_global(id, SINEW(MemoryCellNil));
			lookup_global(id);
			SINASSERT(!lookup_failed());
			SINASSERT(static_cast<MemoryCell*>(*lookuped) != 0x00);
			SINASSERT((*lookuped)->Type() == MemoryCell::NIL_MCT);
		}
		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreIncrASTNode & _node) {
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(memory);

		tmpmemcell1->SetValue(tmpmemcell1->GetValue() + 1);

		memory = tmpmemcell1;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostIncrASTNode & _node)  {
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(memory);

		insertTemporary(memory = tmpmemcell1->Clone());
		tmpmemcell1->SetValue(tmpmemcell1->GetValue() + 1);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreDecrASTNode & _node){
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(memory);

		tmpmemcell1->SetValue(tmpmemcell1->GetValue() - 1);

		memory = tmpmemcell1;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostDecrASTNode & _node) {
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(memory);

		insertTemporary(memory = tmpmemcell1->Clone());
		tmpmemcell1->SetValue(tmpmemcell1->GetValue() - 1);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryNotASTNode & _node) {
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::BOOL_MCT);
		MemoryCellBool* boolean = static_cast<MemoryCellBool*>(memory = memory->Clone());
		insertTemporary(memory);

		boolean->SetValue(!boolean->GetValue());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryMinASTNode & _node) {
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);
		MemoryCellNumber* num = static_cast<MemoryCellNumber*>(memory = memory->Clone());
		insertTemporary(memory);

		num->SetValue(-num->GetValue());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectASTNode & _node) {
		resetObjectImp();
		VISIT_KIDS_SERIALLY;
		assignObjectImpToMemory();
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EmptyObjectASTNode & _node) {
		resetObjectImp();
		assignObjectImpToMemory();
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnindexedMemberASTNode & _node) {
		static_cast<ASTNode&>(*_node.begin()).Accept(this);
		MemoryCell* assigned = 0x00;
		MemoryCell::Assign(assigned, memory);
		obj_imp->SetValue(assigned);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IndexedMemberASTNode & _node) {
		ASTNode::iterator kite(_node.begin());
		// Get indexed element's key-name
		EVALUATE_AND_ADVANCE(kite);
		String const member_name = memory->ToString();
		// Get indexed element's value (to set)
		EVALUATE_AND_ADVANCE(kite);
		SINASSERT(memory != 0x00);
		MemoryCell* assigned = 0x00;
		MemoryCell::Assign(assigned, memory);
		obj_imp->SetValue(member_name, assigned);
		// assert there were only two kids
		SINASSERT(kite == _node.end());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectMemberASTNode & _node) {
		ASTNode::iterator kite(_node.begin());
		// Evaluate first kid, should return an object
		EVALUATE_AND_ADVANCE(kite);
		if (memory->Type() != MemoryCell::OBJECT_MCT)
			vs->AppendError(to_string("Accessing member \"") << static_cast<ASTNode&>(*kite).Name()
			<< "\" on non-object type " << Operator::GetTypeAsStringFromMemoryCell(*memory),
			_node.AssociatedFileName().c_str(), _node.AssociatedFileLine());
		MemoryCellObject* const obj_ref = static_cast<MemoryCellObject*>(memory);
		Types::Object_t obj_p  = obj_ref->GetValue();
		// Look-up in object
		SINASSERT(static_cast<ASTNode&>(*kite).Type() == SINASTNODES_ID_TYPE);
		// TODO add a field for the id node and don't use its Name()
		String const& member_id = static_cast<ASTNode&>(*kite).Name();
		lookuped = &obj_p->GetValue(member_id);
		if (static_cast<MemoryCell*>(*lookuped) == 0x00) {
			// not found, insert Nil
			obj_p->SetValue(member_id, SINEW(MemoryCellNil));
			lookuped = &obj_p->GetValue(member_id);
			SINASSERT(static_cast<MemoryCell const* const>(*static_cast<InstanceProxy<MemoryCell> const* const>(lookuped)) != 0x00);
		}
		memory = *static_cast<InstanceProxy<MemoryCell> const*>(lookuped);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectIndexASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallMemberASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallIndexASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------
	void TreeEvaluationVisitor::Visit(MetaParseASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaPreserveASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaEvaluateASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaUnparseASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaParseStringASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SinCodeASTNode & _node) {
		VISIT_KIDS_SERIALLY;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NotASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}
} // namespace SIN
