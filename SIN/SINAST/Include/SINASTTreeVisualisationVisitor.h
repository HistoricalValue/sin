#ifndef __SIN_ASTTREEVISUALISATIONVISITOR_H__
#define __SIN_ASTTREEVISUALISATIONVISITOR_H__

#include "SINASTNode.h"
#include "SINASTVisitor.h"

namespace SIN {
	class ASTTreeVisualisationVisitor: public ASTVisitor {
	public:
		void Visit(ASTNode const &);
	}; // class ASTTreeVisualisationVisitor
} // namespace SIN

#endif // __SIN_ASTTREEVISUALISATIONVISITOR_H__

