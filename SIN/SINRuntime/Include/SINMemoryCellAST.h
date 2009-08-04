#ifndef __SIN_MEMORY_CELL_AST_H__AST_H__
#define __SIN_MEMORY_CELL_AST_H__AST_H__

#include "SINASTNode.h"
#include "SINMemoryCell.h"

namespace SIN {

	class MemoryCellAST : public MemoryCell {
	public:
		MemoryCellAST(void) : MemoryCell() {}
		MemoryCellAST(ASTNode * node) : MemoryCell(), value(node) {}
		
		~MemoryCellAST() {}


		virtual MemoryCell *		Clone(void);
		virtual enum MemoryCellType Type (void);

		
		void						SetValue (const ASTNode*);
		const ASTNode &				GetValue (void) const;


	private:
		ASTNode * value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__AST_H__