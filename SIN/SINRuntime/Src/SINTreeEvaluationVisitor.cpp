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

		memstack.push(SINEWCLASS(MemoryCellNumber, (_node.GetValue())));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(StringASTNode & _node){

		memstack.push(SINEWCLASS(MemoryCellString, (_node.GetValue())));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NilASTNode & _node){
	
		memstack.push(SINEWCLASS(MemoryCellNil, ()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(TrueASTNode & _node){
	
		memstack.push(SINEWCLASS(MemoryCellBool, (_node.GetValue())));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FalseASTNode & _node){

		memstack.push(SINEWCLASS(MemoryCellBool, (_node.GetValue())));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AddASTNode & _node){	

		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode&>(*kid++/*[0]*/).Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode&>(*kid++/*[1]*/).Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT); //TODO Throw evaluation error
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()+static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SubASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()-static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MulASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()*static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(DivASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()/static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ModASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, ((int)(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()) % (int)(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())))); // TODO how to support modulo for Numnber type
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LtASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() < static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GtASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() > static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() <= static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() >= static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EqASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() == static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NeASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() != static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(OrASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT || tmpmemcell1->Type() == MemoryCell::BOOL_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue() || static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NotASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT || tmpmemcell1->Type() == MemoryCell::BOOL_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (! static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AndASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT || tmpmemcell1->Type() == MemoryCell::BOOL_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue() && static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForASTNode & _node){}

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

	void TreeEvaluationVisitor::Visit(BlockASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AssignASTNode & _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[1]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SymbolTable *symTable = _node.LocalEnv();
		if(!symTable)
			symTable = _node.GlobalEnv();

		MemoryCell *value = symTable->LookupLocal((static_cast<MemoryCellString*>(tmpmemcell1))->GetValue()); //TODO Check for scope redefinition

		if(value)
			SINDELETE(value);
		
		value = tmpmemcell2;
		symTable->SetLocal((static_cast<MemoryCellString*>(tmpmemcell1))->GetValue(), value);
		memstack.push(value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FormalArgumentsASTNode & _node){

		const size_t numberOfChildren = _node.NumberOfChildren();

		/* The corresponding function node should be responsible to put the arguments into the symboltable */
		//SymbolTable *symTable = _node.LocalEnv();

		//if(!symTable)
		//	symTable = _node.GlobalEnv();

		//MemoryCellFunction *funcmemcell = static_cast<MemoryCellFunction*>( symTable->LookupLocal( string_cast(static_cast<IDASTNode*>(*(*_node)[0])->Name()) ) );
		//symTable = static_cast<ASTNode*>(*(funcmemcell->GetValue())[1])->LocalEnv();


		ASTNode::iterator const end = _node.end();
		for (ASTNode::iterator ite = _node.begin(); ite != end; ++ite)
			static_cast<ASTNode&>(*ite).Accept(this);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ActualArgumentsASTNode & _node){

		const size_t numberOfChildren = _node.NumberOfChildren();

		SymbolTable *symTable = _node.LocalEnv();

		if(!symTable)
			symTable = _node.GlobalEnv();

		SINASSERT(symTable);

		MemoryCellFunction *funcmemcell = static_cast<MemoryCellFunction*>( symTable->LookupLocal( string_cast(static_cast<ASTNode*>(_node.GetParent()->begin()->GetParent())->ID()) ) );
		SINASSERT(funcmemcell->Type() == MemoryCell::FUNCTION_MCT);	//TODO Throw runtime error here

		ASTNode *funcnode = funcmemcell->GetValue();
		ASTNode::iterator imp = funcnode->begin();
		ASTNode *arguments = static_cast<ASTNode*>(&*imp++/*[0]*/);
		symTable = static_cast<ASTNode*>(&*imp++/*[1]*/)->LocalEnv();

		ASTNode::iterator const end = _node.end();
		ASTNode::iterator node_iter = _node.begin(), args_iter = arguments->begin();
		for (; node_iter != end; ++node_iter, ++args_iter) {
			static_cast<ASTNode*>(&*imp)->Accept(this);
			MemoryCell *tmpmemcell = memstack.top();
			memstack.pop();
			symTable->SetArgument( static_cast<ASTNode*>(&*args_iter)->Name(), tmpmemcell); //TODO Support more arguments than defined
		}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NormalCallASTNode & _node){

		SINASSERT(_node.NumberOfChildren() == 2);
		ASTNode::iterator kid = _node.begin();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();

		static_cast<ASTNode*>(&*kid++/*[0]*/)->Accept(this);
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SymbolTable *symTable = _node.LocalEnv();

		if(!symTable)
			symTable = _node.GlobalEnv();

		SINASSERT(symTable);

		MemoryCellFunction *funcmemcell = static_cast<MemoryCellFunction*>(symTable->LookupLocal(static_cast<MemoryCellString*>(tmpmemcell1)->GetValue()));
		SINASSERT(funcmemcell->Type() == MemoryCell::FUNCTION_MCT);	//TODO Throw runtime error here

		ASTNode::iterator imp = funcmemcell->GetValue()->GetParent()->begin();
		static_cast<ASTNode*>(&*++imp)->Accept(this);
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
	
		memstack.push(SINEWCLASS(MemoryCellString, (string_cast(_node.Name()))));

		SymbolTable *symTable = _node.LocalEnv();

		if(!symTable)
			symTable = _node.GlobalEnv();

//		symTable->SetLocal(string_cast(_node.Name()), NULL);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LocalIDASTNode & _node){
	
		memstack.push(SINEWCLASS(MemoryCellString, (string_cast(_node.ID()))));

		SymbolTable *symTable = _node.LocalEnv();

		if(!symTable)
			symTable = _node.GlobalEnv();

		symTable->SetLocal(string_cast(_node.Name()), memstack.top());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GlobalIDASTNode & _node){
	
		memstack.push(SINEWCLASS(MemoryCellString, (string_cast(_node.ID()))));

		SymbolTable *symTable = _node.GlobalEnv();

		symTable->SetLocal(string_cast(_node.ID()), memstack.top());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreIncrASTNode & _node){
	

	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostIncrASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreDecrASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostDecrASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryNotASTNode & _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryMinASTNode & _node){}

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
		ASTNode::iterator const end = _node.end();
		for (ASTNode::iterator ite = _node.begin(); ite != end; ++ite) {
			static_cast<ASTNode*>(&*ite)->Accept(this);
			memstack.empty();
		}

	} //TODO Here we should cleanup stack after every Accept
} // namespace SIN
