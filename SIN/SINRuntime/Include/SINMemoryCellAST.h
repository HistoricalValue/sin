#ifndef __SIN_MEMORY_CELL_AST_H__AST_H__
#define __SIN_MEMORY_CELL_AST_H__AST_H__

#include "SINASTNode.h"
#include "SINMemoryCell.h"

namespace SIN {

	class MemoryCellAST : public MemoryCell {
	public:
		MemoryCellAST(void) : MemoryCell() {}
		//MemoryCellAST(const ASTNode * _node) : MemoryCell(), node(_node) {}
		
		~MemoryCellAST() {}



		virtual enum MemoryCellType Type (void) { return MemoryCell::AST_MCT; }

		
		void			SetValue (const ASTNode* _node)	{ node = const_cast<ASTNode *>(_node); }
		const ASTNode & GetValue (void) const			{ return *node; }


	private:
		ASTNode * node;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__AST_H__