#ifndef __SIN_AST_TREE_CTRL_VISITOR_H__
#define __SIN_AST_TREE_CTRL_VISITOR_H__

#include "Common.h"
#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"
#include "SINASTVisitor.h"
#include "SINOutputStream.h"
#include "SINASTTreeVisualisationVisitor.h"

#ifdef _MSC_VER // compiling with Microsoft Visual Studio
//disable the error: not enough actual parameters for macro 'SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE'
#pragma warning(disable:4003)
#endif // _MSC_VER

#define SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(NODENAME) virtual void Visit(NODENAME##ASTNode &)

namespace SIN {
	class ASTTreeCtrlVisitor: public ASTTreeVisualisationVisitor {
	public:
		ASTTreeCtrlVisitor(OutputStream& out);
		virtual ~ASTTreeCtrlVisitor(void);
		

		SIN_AST_TREE_CTRL_VISITOR_VISIT_SIGNATURE(	);
	}; // class ASTTreeCtrlVisitor


} // namespace SIN




#endif // __SIN_AST_TREE_CTRL_VISITOR_H__

