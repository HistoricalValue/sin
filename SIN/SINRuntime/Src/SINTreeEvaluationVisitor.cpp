#include "SINTreeEvaluationVisitor.h"

#include "SINAlloc.h"
#include "SINAssert.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellBool.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellFunction.h"

namespace SIN{

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::~TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ASTNode & _node){}

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
	
		memory = SINEWCLASS(MemoryCellNil, ());
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

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT); //TODO Throw evaluation error
		
		memory = SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()+static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SubASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		SymbolTable *symTable = _node.LocalEnv();

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

		SymbolTable *symTable = _node.LocalEnv();

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

		SymbolTable *symTable = _node.LocalEnv();

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

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellNumber, ((int)(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()) % (int)(static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()))); // TODO how to support modulo for Numnber type
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LtASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		SymbolTable *symTable = _node.LocalEnv();

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

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() > static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() <= static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT);
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() >= static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EqASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT( tmpmemcell1->Type() == tmpmemcell2->Type() );
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() == static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT && tmpmemcell2->Type() == MemoryCell::NUMBER_MCT); //TODO Support comparison between other types than number
		
		memory = SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() != static_cast<MemoryCellNumber*>(tmpmemcell2)->GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(OrASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		SymbolTable *symTable = _node.LocalEnv();

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

		SymbolTable *symTable = _node.LocalEnv();

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
	
		SINASSERT(_node.NumberOfChildren() == 4);

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		//for(  )
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 4);

		SymbolTable *symTable = _node.LocalEnv();

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		//for(  )
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(WhileASTNode & _node){}

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
	
		const size_t numberOfChildren = _node.NumberOfChildren();

		ASTNode::iterator kid = _node.begin();

		for(size_t i = 0; i< numberOfChildren; ++i){
			static_cast<ASTNode&>(*kid++).Accept(this);
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AssignASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell1 = memory;

		SINASSERT(tmpmemcell1->Type() != MemoryCell::FUNCTION_MCT); //TODO Throw run-time error

		static_cast<ASTNode&>(*kid++).Accept(this);
		MemoryCell *tmpmemcell2 = memory;

		SymbolTable *symTable = _node.LocalEnv();

		symTable->SetLocal( static_cast<ASTNode&>(*(_node.begin())).Name(), tmpmemcell2);
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

		//const size_t numberOfChildren = _node.NumberOfChildren();

		//SymbolTable *symTable = _node.LocalEnv();

		//SINASSERT(symTable);

		//MemoryCellFunction *funcmemcell = static_cast<MemoryCellFunction*>( symTable->LookupLocal( to_string(static_cast<ASTNode&>(*(_node.begin())).ID()) ) );
		//SINASSERT(funcmemcell->Type() == MemoryCell::FUNCTION_MCT);	//TODO Throw runtime error here

		//ASTNode *funcnode = funcmemcell->GetValue();
		//ASTNode::iterator kid = funcnode->begin();

		//ASTNode::iterator arguments = static_cast<ASTNode&>(*kid++);
		//symTable = static_cast<ASTNode&>(*kid++).LocalEnv();

		//for(size_t i = 0; i< numberOfChildren; ++i){
		//	static_cast<ASTNode&>(*kid++).Accept(this);
		//	MemoryCell *tmpmemcell = memory;
		//	symTable->SetArgument( static_cast<ASTNode*>((*arguments)[i])->Name(), tmpmemcell); //TODO Support more arguments than defined
		//}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NormalCallASTNode & _node){

		//SINASSERT(_node.NumberOfChildren() == 2);

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid++).Accept(this);
		//MemoryCell *tmpmemcell1 = memstack.top();
		//memstack.pop();

		//static_cast<ASTNode&>(*kid++).Accept(this);
		//MemoryCell *tmpmemcell2 = memstack.top();
		//memstack.pop();

		//SymbolTable *symTable = _node.LocalEnv();

		//SINASSERT(symTable);

		//MemoryCellFunction *funcmemcell = static_cast<MemoryCellFunction*>(symTable->LookupLocal(static_cast<MemoryCellString*>(tmpmemcell1)->GetValue()));
		//SINASSERT(funcmemcell->Type() == MemoryCell::FUNCTION_MCT);	//TODO Throw runtime error here

		//static_cast<ASTNode*>(*(funcmemcell->GetValue())[1])->Accept(this);
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
	
		SymbolTable *localSymTable = _node.LocalEnv();
		SymbolTable *globalSymTable = _node.GlobalEnv();
		MemoryCell * memcell = localSymTable->LookupLocal(_node.Name());
		if(!memcell)
			memcell = globalSymTable->LookupLocal(_node.Name());

		if(memcell)
			memory = memcell;
		else{
			memory = SINEWCLASS(MemoryCellNil, ());
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LocalIDASTNode & _node){
	
		SymbolTable *localSymTable = _node.LocalEnv();
		MemoryCell * memcell = localSymTable->LookupLocal(_node.Name());

		if(memcell)
			memory = memcell;
		else{
			memory = SINEWCLASS(MemoryCellNil, ());
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GlobalIDASTNode & _node){
	
		SymbolTable *globalSymTable = _node.GlobalEnv();
		MemoryCell * memcell = globalSymTable->LookupLocal(_node.Name());

		if(memcell)
			memory = memcell;
		else{
			memory = SINEWCLASS(MemoryCellNil, ());
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreIncrASTNode & _node){
	
		//SINASSERT(_node.NumberOfChildren() == 1);

		//SymbolTable *symTable = _node.LocalEnv();

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid).Accept(this);
		//MemoryCell *tmpmemcell1 = memory;

		//MemoryCell *value;
		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	value = symTable->LookupLocal( static_cast<MemoryCellID*>(tmpmemcell1)->GetValue() );
		//else
		//	value = tmpmemcell1;
		//
		//static_cast<MemoryCellNumber*>(value)->SetValue(static_cast<MemoryCellNumber*>(value)->GetValue()+1);
		//SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || (tmpmemcell1->Type() == MemoryCell::ID_MCT && value->Type() == MemoryCell::NUMBER_MCT) );

		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	symTable->SetLocal(static_cast<MemoryCellID*>(tmpmemcell1)->GetValue(), value);

		//memstack.push(value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostIncrASTNode & _node){
	
		//SINASSERT(_node.NumberOfChildren() == 1);

		//SymbolTable *symTable = _node.LocalEnv();

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid).Accept(this);
		//MemoryCell *tmpmemcell1 = memstack.top();
		//memstack.pop();

		//MemoryCell *value;
		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	value = symTable->LookupLocal( static_cast<MemoryCellID*>(tmpmemcell1)->GetValue() );
		//else
		//	value = tmpmemcell1;
		//
		//memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(value)->GetValue())));
		//static_cast<MemoryCellNumber*>(value)->SetValue(static_cast<MemoryCellNumber*>(value)->GetValue()+1);
		//SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || (tmpmemcell1->Type() == MemoryCell::ID_MCT && value->Type() == MemoryCell::NUMBER_MCT) );

		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	symTable->SetLocal(static_cast<MemoryCellID*>(tmpmemcell1)->GetValue(), value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreDecrASTNode & _node){
	
		//SINASSERT(_node.NumberOfChildren() == 1);

		//SymbolTable *symTable = _node.LocalEnv();

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid).Accept(this);
		//MemoryCell *tmpmemcell1 = memstack.top();
		//memstack.pop();

		//MemoryCell *value;
		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	value = symTable->LookupLocal( static_cast<MemoryCellID*>(tmpmemcell1)->GetValue() );
		//else
		//	value = tmpmemcell1;
		//
		//static_cast<MemoryCellNumber*>(value)->SetValue(static_cast<MemoryCellNumber*>(value)->GetValue()-1);
		//SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || (tmpmemcell1->Type() == MemoryCell::ID_MCT && value->Type() == MemoryCell::NUMBER_MCT) );

		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	symTable->SetLocal(static_cast<MemoryCellID*>(tmpmemcell1)->GetValue(), value);

		//memstack.push(value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostDecrASTNode & _node){
	
		//SINASSERT(_node.NumberOfChildren() == 1);

		//SymbolTable *symTable = _node.LocalEnv();

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid).Accept(this);
		//MemoryCell *tmpmemcell1 = memstack.top();
		//memstack.pop();

		//MemoryCell *value;
		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	value = symTable->LookupLocal( static_cast<MemoryCellID*>(tmpmemcell1)->GetValue() );
		//else
		//	value = tmpmemcell1;
		//
		//memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(value)->GetValue())));
		//static_cast<MemoryCellNumber*>(value)->SetValue(static_cast<MemoryCellNumber*>(value)->GetValue()-1);
		//SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || (tmpmemcell1->Type() == MemoryCell::ID_MCT && value->Type() == MemoryCell::NUMBER_MCT) );

		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	symTable->SetLocal(static_cast<MemoryCellID*>(tmpmemcell1)->GetValue(), value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryNotASTNode & _node){
	
		//SINASSERT(_node.NumberOfChildren() == 1);

		//SymbolTable *symTable = _node.LocalEnv();

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid).Accept(this);
		//MemoryCell *tmpmemcell1 = memstack.top();
		//memstack.pop();

		//MemoryCell *value;
		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	value = symTable->LookupLocal( static_cast<MemoryCellID*>(tmpmemcell1)->GetValue() );
		//else
		//	value = tmpmemcell1;

		//SINASSERT(value->Type() == MemoryCell::BOOL_MCT);

		//static_cast<MemoryCellBool*>(value)->SetValue( !(static_cast<MemoryCellBool*>(value)->GetValue()) );
		//memstack.push(value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryMinASTNode & _node){
	
		//SINASSERT(_node.NumberOfChildren() == 1);

		//SymbolTable *symTable = _node.LocalEnv();

		//ASTNode::iterator kid = _node.begin();

		//static_cast<ASTNode&>(*kid).Accept(this);
		//MemoryCell *tmpmemcell1 = memstack.top();
		//memstack.pop();

		//MemoryCell *value;
		//if(tmpmemcell1->Type() == MemoryCell::ID_MCT)
		//	value = symTable->LookupLocal( static_cast<MemoryCellID*>(tmpmemcell1)->GetValue() );
		//else
		//	value = tmpmemcell1;

		//SINASSERT(value->Type() == MemoryCell::NUMBER_MCT);

		//static_cast<MemoryCellNumber*>(value)->SetValue( -(static_cast<MemoryCellNumber*>(value)->GetValue()) );
		//memstack.push(value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EmptyObjectASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnindexedMemberASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IndexedMemberASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectMemberASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectIndexASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallMemberASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallIndexASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaParseASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaPreserveASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaEvaluateASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaUnparseASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaParseStringASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SinCodeASTNode & _node){

		const size_t numberOfChildren = _node.NumberOfChildren();

		ASTNode::iterator kid = _node.begin();

		for(size_t i = 0; i< numberOfChildren; ++i){
			static_cast<ASTNode&>(*kid++).Accept(this);
		}

	} //TODO Here we should cleanup stack after every Accept
} // namespace SIN