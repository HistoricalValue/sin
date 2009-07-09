#ifndef __SIN_ASTTREEVISUALISATIONVISITOR_H__
#define __SIN_ASTTREEVISUALISATIONVISITOR_H__

#include "SINASTNode.h"
#include "SINASTVisitor.h"
#include "SINOutputStream.h"
#include "Common.h"

namespace SIN {
	class ASTTreeVisualisationVisitor: public ASTVisitor {
		Type<OutputStream>::ref out;
	public:
		ASTTreeVisualisationVisitor(Type<OutputStream>::ref out);
		virtual ~ASTTreeVisualisationVisitor(void);
		
		void Visit(ASTNode const &);
	}; // class ASTTreeVisualisationVisitor
} // namespace SIN

#endif // __SIN_ASTTREEVISUALISATIONVISITOR_H__

