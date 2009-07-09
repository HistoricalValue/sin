#include "SINASTTreeVisualisationVisitor.h"
#include "SINAssert.h"

namespace SIN {

	ASTTreeVisualisationVisitor::ASTTreeVisualisationVisitor(OutputStream& _out):
	out(_out)
	{ }

	ASTTreeVisualisationVisitor::~ASTTreeVisualisationVisitor(void) {
	}

	void ASTTreeVisualisationVisitor::Visit(Type<ASTNode>::const_ref node) {
		// TODO do what must be done
		SINASSERT(!"not implemented");
		throw String("not implemented");
	}
	
} // namespace SIN
