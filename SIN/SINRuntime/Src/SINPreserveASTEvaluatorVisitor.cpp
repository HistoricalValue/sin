#include "SINPreserveASTEvaluatorVisitor.h"



#include "SINAssert.h"


#define VISIT_SINGLE()			ASTNode::iterator kid = _node.begin();			\
								static_cast<ASTNode&>(*kid++).Accept(this)


#define VISIT_OPERATORS()		VISIT_SINGLE();									\
								static_cast<ASTNode&>(*kid++).Accept(this)


#define VISIT_ASSIGNED()		VISIT_OPERATORS()


namespace SIN{

	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ASTNode & _node)
		{}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(NumberASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(StringASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(NilASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(TrueASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(FalseASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(AddASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(SubASTNode & _node)		
		{ VISIT_OPERATORS(); }



	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MulASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(DivASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ModASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(LtASTNode & _node)
		{ VISIT_OPERATORS(); }



	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(GtASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(LeASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(GeASTNode & _node)		
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(EqASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(NeASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(OrASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(AndASTNode & _node)
		{ VISIT_OPERATORS(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ExpressionListASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ForASTNode & _node){
		for(ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid)
			static_cast<ASTNode&>(*kid).Accept(this);
	}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(WhileASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(IfASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(IfElseASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ReturnASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(SemicolonASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(BreakASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ContinueASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(BlockASTNode & _node){
		for(ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid)
			static_cast<ASTNode&>(*kid).Accept(this);	
	}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(AssignASTNode & _node)
		{ VISIT_ASSIGNED(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(FormalArgumentsASTNode & _node){
	}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ActualArgumentsASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(NormalCallASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MethodCallASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(FuncdefCallASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(FunctionASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(LamdaFunctionASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(IDASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(LocalIDASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(GlobalIDASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PreIncrASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PostIncrASTNode & _node){}

	
	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PreDecrASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PostDecrASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(UnaryNotASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(UnaryMinASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ObjectASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(EmptyObjectASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(UnindexedMemberASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(IndexedMemberASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ObjectMemberASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ObjectIndexASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(CallMemberASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(CallIndexASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaParseASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaPreserveASTNode & _node){
		treeEvalVisitor.Visit(_node);
		*(_node.GetParent()) << treeEvalVisitor.PreserveASTNode();
	}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaEvaluateASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaUnparseASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaParseStringASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(SinCodeASTNode & _node){
	}




} // namespace SIN