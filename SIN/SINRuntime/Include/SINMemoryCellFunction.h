#ifndef __SIN_MEMORY_CELL_AST_H__FUNCTION_H__
#define __SIN_MEMORY_CELL_AST_H__FUNCTION_H__


#include "SINASTNode.h"
#include "SINMemoryCell.h"



namespace SIN {

	class MemoryCellFunction : public MemoryCell {
	public:

		MemoryCellFunction(void) : MemoryCell() {}
		MemoryCellFunction(ASTNode *functionNode) : MemoryCell(), value(functionNode) {}
		~MemoryCellFunction() {}

		virtual MemoryCell *	Clone(void);
		virtual MemoryCellType	Type (void);

		void					SetValue (const ASTNode *functionNode);
		ASTNode *				GetValue (void) const;

	private:

		ASTNode *value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__FUNCTION_H__