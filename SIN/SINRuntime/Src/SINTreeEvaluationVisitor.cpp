#include "SINTreeEvaluationVisitor.h"

#include "SINAlloc.h"
#include "SINAssert.h"

namespace SIN{

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::~TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NumberASTNode const& _node){

		memstack.push(SINEWCLASS(MemoryCellNumber, (_node.GetValue())));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(StringASTNode const& _node){

		memstack.push(SINEWCLASS(MemoryCellString, (_node.GetValue())));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NilASTNode const& _node){
	
		memstack.push(new MemoryCellNil());
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(TrueASTNode const& _node){
	
		memstack.push(new MemoryCellBool(_node.GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FalseASTNode const& _node){

		memstack.push(new MemoryCellBool(_node.GetValue()));
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AddASTNode const& _node){	

		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()+static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SubASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()-static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MulASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()*static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(DivASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()/static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ModASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellNumber, ((int)(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue()) % (int)(static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())))); // TODO how to support modulo for Numnber type
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LtASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() < static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GtASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() > static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LeASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() <= static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GeASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() >= static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EqASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() == static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NeASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::NUMBER_MCT || tmpmemcell1->Type() == MemoryCell::NUMBER_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue() != static_cast<MemoryCellNumber*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(OrASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT || tmpmemcell1->Type() == MemoryCell::BOOL_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue() || static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NotASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT || tmpmemcell1->Type() == MemoryCell::BOOL_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue() || static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue()))); //TODO What operand to use?
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AndASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		SINASSERT(tmpmemcell1->Type() == MemoryCell::BOOL_MCT || tmpmemcell1->Type() == MemoryCell::BOOL_MCT);
		
		memstack.push(SINEWCLASS(MemoryCellBool, (static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue() && static_cast<MemoryCellBool*>(tmpmemcell1)->GetValue())));
		SINDELETE(tmpmemcell1);
		SINDELETE(tmpmemcell2);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ForASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(WhileASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IfElseASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ReturnASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SemicolonASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BreakASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ContinueASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(BlockASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AssignASTNode const& _node){
	
		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
		MemoryCell *tmpmemcell1 = memstack.top();
		memstack.pop();
		MemoryCell *tmpmemcell2 = memstack.top();
		memstack.pop();

		ASTNode *blocknode;
		for(blocknode = static_cast<ASTNode*>(*_node); _node.Type() != ASTNode::SinCodeASTNode_T && _node.Type() != ASTNode::BlockASTNode_T; blocknode = static_cast<ASTNode*>(*_node));
		SymbolTable symTable = (static_cast<BlockASTNode*>(blocknode))->getSymbolTable();
		MemoryCell *value = symTable.LookupLocal((static_cast<MemoryCellString*>(tmpmemcell1))->GetValue()); //TODO Check for scope redefinition

		if(value)
			SINDELETE(value);
		
		value = tmpmemcell2;
		symTable.SetLocal((static_cast<MemoryCellString*>(tmpmemcell1))->GetValue(), value);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ArgumentsASTNode const& _node){

		const size_t numberOfChildren = _node.NumberOfChildren();

		for(size_t i = 0; i< numberOfChildren; ++i){}
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NormalCallASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MethodCallASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FuncdefCallASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FunctionASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LamdaFunctionASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IDASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LocalIDASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GlobalIDASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreIncrASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostIncrASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PreDecrASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(PostDecrASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryNotASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnaryMinASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EmptyObjectASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(UnindexedMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(IndexedMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ObjectIndexASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(CallIndexASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaParseASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaPreserveASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaEvaluateASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaUnparseASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MetaParseStringASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SinCodeASTNode const& _node){}
} // namespace SIN