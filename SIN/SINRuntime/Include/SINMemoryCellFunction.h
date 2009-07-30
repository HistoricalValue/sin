#ifndef __SIN_MEMORY_CELL_AST_H__FUNCTION_H__
#define __SIN_MEMORY_CELL_AST_H__FUNCTION_H__


#include "SINMemoryCell.h"
#include "SINASTNode.h"


namespace SIN {

	class MemoryCellFunction : public MemoryCell {
	public:

		MemoryCellFunction(void) : MemoryCell() {}
		MemoryCellFunction(ASTNode *_functionNode) : MemoryCell(), functionNode(_functionNode) {}
		~MemoryCellFunction() {}

		virtual MemoryCellType Type (void) { return MemoryCell::FUNCTION_MCT; }

		void	       SetValue (ASTNode *_functionNode)	{ functionNode = _functionNode; }
		ASTNode *GetValue (void) const	{ return functionNode; }

	private:

		ASTNode *functionNode;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__FUNCTION_H__