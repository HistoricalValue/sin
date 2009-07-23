#include "SINASTTreeEvaluationVisitor.h"

namespace SIN{

	//-----------------------------------------------------------------

	ASTTreeEvaluationVisitor::ASTTreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	ASTTreeEvaluationVisitor::~ASTTreeEvaluationVisitor(void){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(NumberASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(StringASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(NilASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(TrueASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(FalseASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(AddASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(SubASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(MulASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(DivASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ModASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(LtASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(GtASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(LeASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(GeASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(EqASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(NeASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(OrASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(NotASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(AndASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ForASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(WhileASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(IfASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(IfElseASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ReturnASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(SemicolonASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(BreakASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ContinueASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(BlockASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(AssignASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ArgumentsASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(NormalCallASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(MethodCallASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(FuncdefCallASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(FunctionASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(LamdaFunctionASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(IDASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(LocalIDASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(GlobalIDASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(PreIncrASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(PostIncrASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(PreDecrASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(PostDecrASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(UnaryNotASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(UnaryMinASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ObjectASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(EmptyObjectASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(UnindexedMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(IndexedMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ObjectMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(ObjectIndexASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(CallMemberASTNode const& _node){}

	//-----------------------------------------------------------------

	void ASTTreeEvaluationVisitor::Visit(CallIndexASTNode const& _node){}

} // namespace SIN