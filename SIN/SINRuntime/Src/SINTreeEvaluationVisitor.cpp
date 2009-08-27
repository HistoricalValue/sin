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

namespace SIN{
	//-----------------------------------------------------------------
	// Privates (hihihi)
	//-----------------------------------------------------------------
	void TreeEvaluationVisitor::resetObjectImp(void) {
		obj_imp = SINEW(Types::Object);
	}

	void TreeEvaluationVisitor::assignObjectImpToMemory(void) {
		MemoryCell::SimpleAssign(memory, SINEWCLASS(MemoryCellObject, (obj_imp)));
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

	TreeEvaluationVisitor::TreeEvaluationVisitor(void) : memory(NULL), lookuped(NULL), preserveNode(NULL), lib(NULL), vm(NULL) { }

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(Library::Library *_lib, VM::VirtualState *_vm) : memory(NULL), lookuped(NULL), preserveNode(NULL), lib(_lib), vm(_vm) { }

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(TreeEvaluationVisitor const&):
		memory(0x00), lookuped(0x00), preserveNode(0x00), lib(0x00), vm(0x00), obj_imp(0x00)
		{ SINASSERT(!"Not allowed"); }

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::~TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

//	void TreeEvaluationVisitor::Visit(ASTNode & _node) { SINASSERT(!"Cannot be here any more"); }

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NumberASTNode & _node){

		memory = SINEWCLASS(MemoryCellNumber, (_node.GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(StringASTNode & _node){

		memory = SINEWCLASS(MemoryCellString, (_node.GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NilASTNode & _node){
	
		memory = SINEW(MemoryCellNil);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(TrueASTNode & _node){
	
		memory = SINEWCLASS(MemoryCellBool, (_node.GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FalseASTNode & _node){

		memory = SINEWCLASS(MemoryCellBool, (_node.GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AddASTNode & _node){	

		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT); //TODO Throw evaluation error
		MemoryCellNumber *tmpmemcell1 = static_cast<MemoryCellNumber*>(memory);

		static_cast<ASTNode&>(*kid++).Accept(this);
		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT); //TODO Throw evaluation error
		MemoryCellNumber *tmpmemcell2 = static_cast<MemoryCellNumber*>(memory);
		
		memory = SINEWCLASS(MemoryCellNumber, (tmpmemcell1->GetValue() + tmpmemcell2->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SubASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()-static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MulASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT); //TODO Throw run-time error
		
		memory = SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()*static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(DivASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()/static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ModASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellNumber, ((int)(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()) % (int)(static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue())));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LtASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() < static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GtASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()>static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()<=static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()>=static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EqASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT( tmpmemcell1->Type() == tmpmemcell2->Type() );
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()==static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT); //TODO Support comparison between other types than number
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()!=static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(OrASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT && tmpmemcell2->Type() == MemoryCell::BOOL_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue() || static_cast<MemoryCellBool*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AndASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT && tmpmemcell2->Type() == MemoryCell::BOOL_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue() && static_cast<MemoryCellBool*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ExpressionListASTNode & _node){
	
		for(ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid)
			static_cast<ASTNode&>(*kid).Accept(this);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForASTNode & _node){

		SINASSERT(_node.NumberOfChildren() == 4);

//		SymbolTable *symTable = _node.LocalEnv();

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid++).Accept(this);

		//ASTNode& condition = static_cast<ASTNode&>(*kid++);
		//condition.Accept(this);
		//MemoryCellBool *tmpmemcell1 = static_cast<MemoryCellBool*>(memory);
		//SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT);

		//ASTNode& elist = static_cast<ASTNode&>(*kid++);

		//while(tmpmemcell1->GetValue() == true){
		//	static_cast<ASTNode&>(*kid).Accept(this);
		//	elist.Accept(this);
		//	condition.Accept
		//}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForPreambleASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForAddendumASTNode & _node) {
		// TODO implement
		SINASSERT(!"Not implemented");
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(WhileASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfElseASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ReturnASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SemicolonASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BreakASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ContinueASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BlockASTNode & _node){
	
		for(ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid)
			static_cast<ASTNode&>(*kid).Accept(this);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AssignASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;
		InstanceProxy<MemoryCell>* lookedup_l = lookuped; // looked-up and memory must be saved after each eval of a kid

		SINASSERT(tmpmemcell1 == 0x00 || tmpmemcell1->Type() != MemoryCell::FUNCTION_MCT); //TODO Throw run-time error

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		MemoryCell::Assign(*lookedup_l, tmpmemcell2);
		memory = tmpmemcell2;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FormalArgumentsASTNode & _node){

		const size_t numberOfChildren = _node.NumberOfChildren();

		/* The corresponding function node should be responsible to put the arguments into the symboltable */
		//SymbolTable *symTable = _node.LocalEnv();

		//if(!symTable)
		//	symTable = _node.GlobalEnv();

		//MemoryCellFunction *funcmemcell = static_cast<MemoryCellFunction*>( symTable->LookupLocal( to_string(static_cast<IDASTNode*>(*(*_node)[0])->Name()) ) );
		//symTable = static_cast<ASTNode*>(*(funcmemcell->GetValue())[1])->LocalEnv();


		ASTNode::iterator kid = _node.begin();

		for(size_t i = 0; i< numberOfChildren; ++i){
			static_cast<ASTNode&>(*kid++).Accept(this);
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ActualArgumentsASTNode & _node){

		SymbolTable *symTable = &vm->CurrentStable();
		Namer argument_namer("arg");

		for(ASTNode::iterator arguments = _node.begin(); arguments != _node.end(); ++arguments){
			static_cast<ASTNode&>(*arguments).Accept(this);
			// NOTICE: symbol Tables hold COPIES OF VALUES! Every assignment is a copy of
			// a value!
			// Conceptually, actual arguments are *assignments* of some variables to the
			// argument-variables of a function.
			// Assignment is needed for correct handling of objects;
			MemoryCell* argument = 0x00;
			MemoryCell::Assign(argument, memory);
			symTable->Insert(argument_namer++, argument);
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NormalCallASTNode & _node){

		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		vm->PushState();

		static_cast<ASTNode&>(*kid++).Accept(this);
//		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::FUNCTION_MCT || tmpmemcell1->Type() == MemoryCell::LIB_FUNCTION_MCT);	//TODO Throw runtime error here

		if(tmpmemcell1->Type() == MemoryCell::FUNCTION_MCT){
//			FunctionASTNode *func = static_cast<FunctionASTNode*>(static_cast<MemoryCellFunction*>(tmpmemcell1)->GetValue().GetASTNode());
			ASTNode::iterator funckid = _node.begin();
			static_cast<ASTNode&>(*++funckid).Accept(this);
		}else{
			Library::Function *libfunc = static_cast<MemoryCellLibFunction*>(tmpmemcell1)->GetValue();

			(*libfunc)(*vm, *lib);
			memory = 0x00;
			MemoryCell::Assign(memory, vm->ReturnValue());
		}
		// TODO restore environment
		vm->RestoreState(); 
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MethodCallASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FuncdefCallASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FunctionASTNode & _node){
	
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LamdaFunctionASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IDASTNode & _node){
		String const& id = _node.Name();
		SymbolTable *localSymTable = _node.LocalEnv();
		SymbolTable *globalSymTable = _node.GlobalEnv();
		lookuped = &localSymTable->Lookup(id);
		if(static_cast<MemoryCell*>(*lookuped) == NULL)
			lookuped = &globalSymTable->Lookup(id);

		// DO NOT ASSIGN TO *lookuped if it is NULL
		if(static_cast<MemoryCell*>(*lookuped) == NULL) {
			// TODO check about inserting in local or global
			localSymTable->Insert(_node.Name(), 0x00);
			lookuped = &localSymTable->Lookup(id);
		}
		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LocalIDASTNode & _node){
	
		SymbolTable *localSymTable = _node.LocalEnv();
		lookuped = &localSymTable->LookupOnlyInCurrentScope(_node.Name());

		if(static_cast<MemoryCell*>(*lookuped) == NULL){
			localSymTable->Insert(_node.Name(), 0x00);
			lookuped = &localSymTable->LookupOnlyInCurrentScope(_node.Name());
		}

		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GlobalIDASTNode & _node){
	
		SymbolTable *globalSymTable = _node.GlobalEnv();
		lookuped = &globalSymTable->Lookup(0, _node.Name());

		if(static_cast<MemoryCell*>(*lookuped) == NULL){
			globalSymTable->Insert(_node.Name(), 0x00);
			lookuped = &globalSymTable->Lookup(0, _node.Name());
		}

		memory = *lookuped;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreIncrASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<MemoryCellNumber*>(tmpmemcell1)->SetValue(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()+1);
		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);

		memory = tmpmemcell1;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostIncrASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);

		memory = tmpmemcell1->Clone();
		static_cast<MemoryCellNumber*>(tmpmemcell1)->SetValue(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()+1);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreDecrASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<MemoryCellNumber*>(tmpmemcell1)->SetValue(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()-1);
		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);

		memory = tmpmemcell1;
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostDecrASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);

		memory = tmpmemcell1->Clone();
		static_cast<MemoryCellNumber*>(tmpmemcell1)->SetValue(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()-1);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryNotASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);

		SINASSERT(memory->Type() == MemoryCell::BOOL_MCT);

		memory = memory->Clone();
		static_cast<MemoryCellBool*>(memory)->SetValue(!(static_cast<MemoryCellBool*>(memory)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryMinASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 1);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid).Accept(this);

		SINASSERT(memory->Type() == MemoryCell::NUMBER_MCT);

		memory = memory->Clone();
		static_cast<MemoryCellNumber*>(memory)->SetValue(-static_cast<MemoryCellNumber*>(memory)->GetValue());
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
		obj_imp->SetValue(memory);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IndexedMemberASTNode & _node) {
		ASTNode::iterator kite(_node.begin());
		IDASTNode const& id = static_cast<IDASTNode const&>(*kite++);
		static_cast<ASTNode&>(*kite++).Accept(this);
		obj_imp->SetValue(id.Name(), memory);
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
