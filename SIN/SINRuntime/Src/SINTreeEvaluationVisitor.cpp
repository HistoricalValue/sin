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

#define VISIT_KIDS_SERIALLY												\
		ASTNode::iterator const end = _node.end();						\
		for(ASTNode::iterator kid = _node.begin(); kid != end; ++kid)	\
			static_cast<ASTNode&>(*kid).Accept(this)					\


namespace SIN{
	//-----------------------------------------------------------------
	// Privates (hihihi) -- not in class -- utils
	//-----------------------------------------------------------------
	template <typename _MathOpT>
	inline static void evaluateBasicMathematics(
		TreeEvaluationVisitor* const _evaluator_p,
		MemoryCell*& _result,
		void (TreeEvaluationVisitor::*_insertTemporary)(InstanceProxy<MemoryCell> const&),
		ASTNode& _node,
		_MathOpT const& _math_op
	) {
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(_evaluator_p);
		SINASSERT(_result->Type() == MemoryCell::NUMBER_MCT); //TODO Throw evaluation error
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(_result);

		static_cast<ASTNode&>(*kid++).Accept(_evaluator_p);
		SINASSERT(_result->Type() == MemoryCell::NUMBER_MCT); //TODO Throw evaluation error
		MemoryCellNumber *tmpmemcell2 = static_cast<MemoryCellNumber*>(_result);
		
		(_evaluator_p->*_insertTemporary)(
			_result = SINEWCLASS(MemoryCellNumber, (_math_op(tmpmemcell1->GetValue(), tmpmemcell2->GetValue())))
		);
	}
#define EVALUATE_BASIC_MATHEMATIC_OPERATION(OP_NAME) \
		evaluateBasicMathematics(this, memory, &TreeEvaluationVisitor::insertTemporary, _node, OP_NAME<Types::Number_t>());

	template <typename _LogOpT>
	inline static void evaluateBasicLogicalOperation(
		TreeEvaluationVisitor* const _evaluator_p,
		MemoryCell*& _result,
		void (TreeEvaluationVisitor::*_insertTemporary)(InstanceProxy<MemoryCell> const&),
		ASTNode& _node,
		_LogOpT const& _log_op
	) {
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(_evaluator_p);
		SINASSERT(_result->Type() == MemoryCell::BOOL_MCT); //TODO Throw evaluation error
		MemoryCellBool *tmpmemcell1 = static_cast<MemoryCellBool*>(_result);

		static_cast<ASTNode&>(*kid++).Accept(_evaluator_p);
		SINASSERT(_result->Type() == MemoryCell::BOOL_MCT); //TODO Throw evaluation error
		MemoryCellBool *tmpmemcell2 = static_cast<MemoryCellBool*>(_result);
		
		(_evaluator_p->*_insertTemporary)(
			_result = SINEWCLASS(MemoryCellBool, (_log_op(tmpmemcell1->GetValue(), tmpmemcell2->GetValue())))
		);
	}
#define EVALUATE_BASIC_LOGICAL_OPERATION(OP_NAME) \
		evaluateBasicLogicalOperation(this, memory, &TreeEvaluationVisitor::insertTemporary, _node, OP_NAME<Types::Boolean_t>());

	template <typename _OpT>
	inline static void evaluateBinaryOperation(
		TreeEvaluationVisitor* const _evaluator_p,
		MemoryCell*& _result,
		void (TreeEvaluationVisitor::*_insertTemporary)(InstanceProxy<MemoryCell> const&),
		ASTNode& _node,
		_OpT const& _op
	) {
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(_evaluator_p);
		MemoryCell *tmpmemcell1 = _result;

		static_cast<ASTNode&>(*kid++).Accept(_evaluator_p);
		MemoryCell *tmpmemcell2 = _result;
		
		(_evaluator_p->*_insertTemporary)(
			_result = SINEWCLASS(MemoryCellBool, (_op(*tmpmemcell1, *tmpmemcell2)))
		);
	}
#define EVALUATE_BASIC_BINARY_OPERATION(OP_NAME)																	\
	evaluateBinaryOperation(this, memory, &TreeEvaluationVisitor::insertTemporary, _node, OP_NAME<MemoryCell>())	\


#define EVALUATE_BASIC_COMPARISON_OPERATION(OPERATOR)																		\
	EVALUATE_BASIC_MATHEMATIC_OPERATION(OPERATOR);																			\
	SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);																	\
	MemoryCell::UnobtrusiveAssign(memory, SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(memory)->GetValue())));	\
	// the old memory value will be delete at temporary variables clean up time


	//-----------------------------------------------------------------
	// Privates (hihihi)
	//-----------------------------------------------------------------
	inline void TreeEvaluationVisitor::resetObjectImp(void) {
		obj_imp = SINEW(Types::Object);
	}

	inline void TreeEvaluationVisitor::assignObjectImpToMemory(void) {
		MemoryCell::SimpleAssign(memory, SINEWCLASS(MemoryCellObject, (obj_imp)));
	}

	inline void TreeEvaluationVisitor::insertTemporary(InstanceProxy<MemoryCell> const& _tmp) {
		vs->CurrentStable().Insert(vs->CurrentAvrilNamer()++, _tmp);
	}

	inline void TreeEvaluationVisitor::lookup(String const& _id) {
		SymbolTable& stable = vs->CurrentStable();
		lookuped = &stable.Lookup(_id);
	}

	inline void TreeEvaluationVisitor::lookup(String const& _id, SymbolTable::scope_id const _scope) {
		SymbolTable& stable = vs->CurrentStable();
		lookuped = &stable.Lookup(_scope, _id);
	}

	inline void TreeEvaluationVisitor::lookup_local(String const& _id) {
		SymbolTable& stable = vs->CurrentStable();
		lookuped = &stable.LookupOnlyInCurrentScope(_id);
	}

	inline bool TreeEvaluationVisitor::lookup_failed(void) const {
		return vs->CurrentStable().LookupFailed(*lookuped);
	}

	inline void TreeEvaluationVisitor::insert(String const& _id, MemoryCell* const _val) {
		vs->CurrentStable().Insert(_id, _val);
	}

	inline void TreeEvaluationVisitor::insert(String const& _id, MemoryCell* const _val, SymbolTable::scope_id const _scope) {
		vs->CurrentStable().Insert(_id, _val, _scope);
	}

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
	} // namespace

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
		EVALUATE_BASIC_MATHEMATIC_OPERATION(std::plus);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SubASTNode & _node) {
		EVALUATE_BASIC_MATHEMATIC_OPERATION(std::minus);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MulASTNode & _node) {
		EVALUATE_BASIC_MATHEMATIC_OPERATION(std::multiplies);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(DivASTNode & _node){
		EVALUATE_BASIC_MATHEMATIC_OPERATION(std::divides);
	}

	//-----------------------------------------------------------------

	namespace {template <typename _Ignored> struct sinnumber_t_modulus_op {
		typedef Types::Number_t num;
		num const operator ()(const num& a, const num& b) const {
			return static_cast<signed long int>(a) % static_cast<signed long int>(b);
		}
	}; // struct sinnumber_t_modulus_op
	} // namespace
	void TreeEvaluationVisitor::Visit(ModASTNode & _node){
		EVALUATE_BASIC_MATHEMATIC_OPERATION(sinnumber_t_modulus_op);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LtASTNode & _node){
		EVALUATE_BASIC_COMPARISON_OPERATION(std::less);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GtASTNode & _node){
		EVALUATE_BASIC_COMPARISON_OPERATION(std::greater);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LeASTNode & _node){
		EVALUATE_BASIC_COMPARISON_OPERATION(std::less_equal);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GeASTNode & _node){
		EVALUATE_BASIC_COMPARISON_OPERATION(std::greater_equal);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EqASTNode & _node){
		EVALUATE_BASIC_COMPARISON_OPERATION(std::equal_to);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NeASTNode & _node){
		EVALUATE_BASIC_COMPARISON_OPERATION(std::not_equal_to);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(OrASTNode & _node){
		EVALUATE_BASIC_LOGICAL_OPERATION(std::logical_or);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AndASTNode & _node){
		EVALUATE_BASIC_LOGICAL_OPERATION(std::logical_and);
	}


	#define ACCEPT_ALL_THE_KIDS()	for(ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid)	\
										static_cast<ASTNode&>(*kid).Accept(this);

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ExpressionListASTNode & _node)
		{	ACCEPT_ALL_THE_KIDS();	}




	#define EVAL_LOOP_EXPR()		expr.Accept(this);											\
									SINASSERT(memory != 0x00);									\
									exprMemoryCell = static_cast<MemoryCellBool *>(memory)


	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForASTNode & _node){

		SINASSERT(_node.NumberOfChildren() == 4);

		MemoryCellBool * exprMemoryCell	= static_cast<MemoryCellBool *>(0);
		ASTNode::iterator kids			= _node.begin();
		
		ASTNode	& elist1				= static_cast<ASTNode&>(*kids++);
		ASTNode & expr					= static_cast<ASTNode&>(*kids++);
		ASTNode & elist2				= static_cast<ASTNode&>(*kids++);
		ASTNode & stmt					= static_cast<ASTNode&>(*kids++);

		elist1.Accept(this);
		
		EVAL_LOOP_EXPR();
		while(exprMemoryCell->GetValue() == true) {
			stmt.Accept(this);
			if (triggeredBreak)
				break;
			elist2.Accept(this);
			EVAL_LOOP_EXPR();
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

	void TreeEvaluationVisitor::Visit(WhileASTNode & _node){
		MemoryCellBool * exprMemoryCell	= static_cast<MemoryCellBool *>(0);
		ASTNode &  expr			= static_cast<ASTNode&>(*_node.begin());
		ASTNode &  stmt			= static_cast<ASTNode&>(*_node.rbegin());

		EVAL_LOOP_EXPR();

		while(exprMemoryCell->GetValue() == true) {
			stmt.Accept(this);
			if (triggeredBreak)
				break;
			EVAL_LOOP_EXPR();
		}
		triggeredBreak		= false;
		triggeredContinue	= false;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfASTNode & _node){
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfElseASTNode & _node){
		// TODO implement
		SINASSERT(!"Not implemented");}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ReturnASTNode & _node){
		// TODO implement
		SINASSERT(!"Not implemented");}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SemicolonASTNode & _node){
		// TODO implement
		SINASSERT(!"Not implemented");}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BreakASTNode & _node) {
		triggeredBreak = true;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ContinueASTNode & _node) {
		triggeredContinue = true;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BlockASTNode & _node) {
		vs->CurrentStable().IncreaseScope();

		ASTNode::iterator const end = _node.end();						
		for(ASTNode::iterator kid = _node.begin(); kid != end; ++kid) {	
			static_cast<ASTNode&>(*kid).Accept(this);			
			if (triggeredBreak || triggeredContinue)
				break;
		}

		vs->CurrentStable().DecreaseScope();
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AssignASTNode & _node) {
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		ASTNode& kid0 = static_cast<IDASTNode&>(*kid++);
		SINASSERT(kid0.Type() == SINASTNODES_IDASTNODE_TYPE || kid0.Type() == SINASTNODES_LOCALIDASTNODE_TYPE || kid0.Type() == SINASTNODES_GLOBALIDASTNODE_TYPE);

		kid0.Accept(this);
		MemoryCell *tmpmemcell1 = memory;
		InstanceProxy<MemoryCell>* lookedup_l = lookuped; // looked-up and memory must be saved after each eval of a kid

		SINASSERT(tmpmemcell1 == 0x00 || tmpmemcell1->Type() != MemoryCell::FUNCTION_MCT); //TODO Throw run-time error
		SINASSERT(tmpmemcell1 == 0x00 || tmpmemcell1->Type() != MemoryCell::LIB_FUNCTION_MCT); //TODO Throw run-time error

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

	void TreeEvaluationVisitor::Visit(NormalCallASTNode & _node){

		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		// Lookup the function
		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;
		SINASSERT(tmpmemcell1->Type() == MemoryCell::FUNCTION_MCT || tmpmemcell1->Type() == MemoryCell::LIB_FUNCTION_MCT);	//TODO Throw runtime error here
		
		// Evaluate actual arguments
		argument_lists.push(argument_list_t(0u));
		argument_lists.top().reserve(20u);
		static_cast<ASTNode&>(*kid++).Accept(this); // argument list gets filled here
		
		// New stack frame (new env)
		vs->PushState();

		// Set the argument list in the current environment
		vs->CurrentEnvironment().argument_list_p = &argument_lists.top();

		// Evaluate function code
		if(tmpmemcell1->Type() == MemoryCell::FUNCTION_MCT) {
			ASTNode::iterator kids = _node.begin();
			static_cast<ASTNode&>(*++kids).Accept(this);
		} else {
			// add actual arguments to the new environment's symbol table
			Namer arg_namer("_arg_avril_");
			SymbolTable& stable = vs->CurrentStable();
			argument_list_t const& al = argument_lists.top();
			argument_list_t::const_iterator const end = al.end();
			for (argument_list_t::const_iterator ite = al.begin(); ite != end; ++ite)
				stable.Insert(arg_namer++, *ite);

			Library::Function *libfunc = static_cast<MemoryCellLibFunction*>(tmpmemcell1)->GetValue();

			(*libfunc)(*vs, *lib);
			memory = 0x00;
			MemoryCell::Assign(memory, vs->ReturnValue());
		}

		// Restore environment
		vs->RestoreState(); 

		// Pop actual arguments' list
		argument_lists.pop();
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MethodCallASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FuncdefCallASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FunctionASTNode & _node) {
		// Add this function as a symbol
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LamdaFunctionASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IDASTNode & _node){
		String const& id = _node.Name();
		lookup(id);

		if(lookup_failed()) {
			insert(id, 0x00);
			lookup_local(id);
			SINASSERT(!lookup_failed());
			SINASSERT(static_cast<MemoryCell*>(*lookuped) == 0x00);
		}
		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LocalIDASTNode & _node){
		String const& id = _node.Name();
		lookup_local(id);

		if(lookup_failed()) {
			insert(id, 0x00);
			lookup_local(id);
			SINASSERT(!lookup_failed());
			SINASSERT(static_cast<MemoryCell*>(*lookuped) == 0x00);
		}
		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GlobalIDASTNode & _node){
		String const& id = _node.Name();
		lookup(id, 0);

		if(lookup_failed()) {
			insert(id, 0x00, 0);
			lookup(id, 0);
			SINASSERT(!lookup_failed());
			SINASSERT(static_cast<MemoryCell*>(*lookuped) == 0x00);
		}
		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreIncrASTNode & _node){
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(memory);

		tmpmemcell1->SetValue(tmpmemcell1->GetValue() + 1);

		memory = tmpmemcell1;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostIncrASTNode & _node){
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

	void TreeEvaluationVisitor::Visit(PostDecrASTNode & _node){
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(memory);

		insertTemporary(memory = tmpmemcell1->Clone());
		tmpmemcell1->SetValue(tmpmemcell1->GetValue() - 1);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryNotASTNode & _node){
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::BOOL_MCT);
		MemoryCellBool* boolean = static_cast<MemoryCellBool*>(memory = memory->Clone());
		insertTemporary(memory);

		boolean->SetValue(!boolean->GetValue());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryMinASTNode & _node){
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
		_node.for_each(AcceptanceForwardationOperator(this));
		assignObjectImpToMemory();
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EmptyObjectASTNode & _node){
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
		IDASTNode const& id = static_cast<IDASTNode const&>(*kite++);
		// Get indexed element's value (to set)
		static_cast<ASTNode&>(*kite++).Accept(this);
		MemoryCell* assigned = 0x00;
		MemoryCell::Assign(assigned, memory);
		obj_imp->SetValue(id.Name(), assigned);
		// assert there were only two kids
		SINASSERT(kite == _node.end());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectMemberASTNode & _node) {
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectIndexASTNode & _node) {
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallMemberASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallIndexASTNode & _node){}

	//-----------------------------------------------------------------
	void TreeEvaluationVisitor::Visit(MetaParseASTNode & _node){
		PreserveASTEvaluatorVisitor * preservVisitor = SINEWCLASS(PreserveASTEvaluatorVisitor, (*this));
		preservVisitor->Visit(_node);
//		MemoryCellAST * a = preservVisitor->GetMemoryCellAST();
		SINDELETE(preservVisitor);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaPreserveASTNode & _node){
		preserveNode = &_node;
		
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaEvaluateASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaUnparseASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaParseStringASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SinCodeASTNode & _node){

		for(ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid)
			static_cast<ASTNode&>(*kid).Accept(this);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NotASTNode & _node){}
} // namespace SIN
