#include "SINTreeEvaluationVisitor.h"

#include "SINAssert.h"

namespace SIN{

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	TreeEvaluationVisitor::~TreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NumberASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(StringASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NilASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(TrueASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(FalseASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AddASTNode const& _node){	

		SINASSERT(_node.NumberOfChildren() == 2);

		static_cast<ASTNode*>(_node[0])->Accept(this);
		static_cast<ASTNode*>(_node[1])->Accept(this);
	}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(SubASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(MulASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(DivASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ModASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LtASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GtASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(LeASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(GeASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(EqASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NeASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(OrASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(NotASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(AndASTNode const& _node){}

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

	void TreeEvaluationVisitor::Visit(AssignASTNode const& _node){}

	//-----------------------------------------------------------------

	void TreeEvaluationVisitor::Visit(ArgumentsASTNode const& _node){}

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