#ifndef __SIN_BLOCK_AST_NODE_H__
#define __SIN_BLOCK_AST_NODE_H__

#include "SINASTNode.h"
#include "SINSymbolTable.h"

namespace SIN{
	
	class BlockASTNode : public ASTNode {

	public:

		BlockASTNode(void);
		BlockASTNode(String const &name);
		virtual ~BlockASTNode(void);

		virtual void Accept(ASTVisitor *) const;

		SymbolTable getSymbolTable(void) { return symTable; }
		void setSymbolTable(SymbolTable _symTable){ symTable = _symTable; }

	private:
		SymbolTable symTable;
	};

} // namespace SIN

#endif //__SIN_BLOCK_AST_NODE_H__