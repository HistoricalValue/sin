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
		virtual const String		ToString(void) const;

		
		void						SetValue (const ASTNode*);
		ASTNode *					GetValue (void);



	private:
		ASTNode * value;
	};
}

#endif	//__SIN_MEMORY_CELL_AST_H__AST_H__