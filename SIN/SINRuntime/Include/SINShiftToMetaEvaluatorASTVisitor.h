#ifndef __SIN_SHIFT_TO_META_EVALUATOR_AST_VISITOR_H__
#define __SIN_SHIFT_TO_META_EVALUATOR_AST_VISITOR_H__

#include <list>

#include "SINASTNodes.h"
#include "SINASTCloneVisitor.h"
#include "SINTreeEvaluationVisitor.h"



namespace SIN {
	
	class ShiftToMetaEvaluatorASTVisitor: public ASTCloneVisitor {
	public:

		ShiftToMetaEvaluatorASTVisitor(TreeEvaluationVisitor & visitor);
		ShiftToMetaEvaluatorASTVisitor(ShiftToMetaEvaluatorASTVisitor const&);
		~ShiftToMetaEvaluatorASTVisitor(void);

		SINASTVISITOR_VISIT_SIGNATURE(MetaPreserve		);
	
	private:
		TreeEvaluationVisitor & treeEvalVisitor;


	}; // class ShiftToMetaEvaluatorASTVisitor

	


} // namespace SIN

#endif // __SIN_SHIFT_TO_META_EVALUATOR_AST_VISITOR_H__
