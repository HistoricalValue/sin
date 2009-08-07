#include "SINPreserveASTEvaluatorVisitor.h"



#include "SINAssert.h"

#define VISIT_NODE_WITH_ONE_CHILD()			ASTNode::iterator kid = _node.begin();			\
											static_cast<ASTNode&>(*kid++).Accept(this)

#define VISIT_NODE_WITH_TWO_CHILDREN()		VISIT_NODE_WITH_ONE_CHILD();					\
											static_cast<ASTNode&>(*kid++).Accept(this)

#define VISIT_NODE_WITH_MANY_CHILDREN()		for(ASTNode::iterator kid = _node.begin();		\
												kid != _node.end();							\
												++kid)										\
												static_cast<ASTNode&>(*kid).Accept(this)
								

namespace SIN{

	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ASTNode & _node) {}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(NumberASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(StringASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(NilASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(TrueASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(FalseASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(AddASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(SubASTNode & _node)		
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }



	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MulASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(DivASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ModASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(LtASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }



	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(GtASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(LeASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(GeASTNode & _node)		
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(EqASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(NeASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(OrASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(AndASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ExpressionListASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ForASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(WhileASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(IfASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(IfElseASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ReturnASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD();	}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(SemicolonASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(BreakASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(ContinueASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(BlockASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(AssignASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(FormalArgumentsASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ActualArgumentsASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(NormalCallASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MethodCallASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(FuncdefCallASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(FunctionASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(LamdaFunctionASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(IDASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(LocalIDASTNode & _node){}


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(GlobalIDASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PreIncrASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PostIncrASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }

	
	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PreDecrASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(PostDecrASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(UnaryNotASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(UnaryMinASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------
	
	void PreserveASTEvaluatorVisitor::Visit(ObjectASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN(); }


	//-----------------------------------------------------------------
	//no visit
	void PreserveASTEvaluatorVisitor::Visit(EmptyObjectASTNode & _node){}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(UnindexedMemberASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(IndexedMemberASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }

	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ObjectMemberASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(ObjectIndexASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }

	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(CallMemberASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(CallIndexASTNode & _node)
		{ VISIT_NODE_WITH_TWO_CHILDREN(); }


	//-----------------------------------------------------------------
	//Edw 8a soze ton kombo mou kai 8a 
	//mporei kapoios na ton parei apo mena
	void PreserveASTEvaluatorVisitor::Visit(MetaParseASTNode & _node){ 
		VISIT_NODE_WITH_ONE_CHILD(); 
		memCellAst = SINEWCLASS(MemoryCellAST, (&_node));
	}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaPreserveASTNode & _node){
		treeEvalVisitor.Visit(_node);
		//*(_node.GetParent()) << treeEvalVisitor.PreserveASTNode();
	}


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaEvaluateASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaUnparseASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(MetaParseStringASTNode & _node)
		{ VISIT_NODE_WITH_ONE_CHILD(); }


	//-----------------------------------------------------------------

	void PreserveASTEvaluatorVisitor::Visit(SinCodeASTNode & _node)
		{ VISIT_NODE_WITH_MANY_CHILDREN();	}




} // namespace SIN