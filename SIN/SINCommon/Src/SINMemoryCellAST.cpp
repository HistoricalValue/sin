#include "SINMemoryCellAST.h"

#include "SINAlloc.h"
#include "SINAssert.h"



namespace SIN {

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellAST::Clone(void)
		{ return SINEW(MemoryCellAST); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellAST::Type (void) 
		{ return MemoryCell::AST_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellAST::ToString(void) const
		{ return to_string(value); }
		


	//-----------------------------------------------------------------

	void MemoryCellAST::SetValue (const ASTNode* node)	{ 
		SINASSERT(node);
		value = const_cast<ASTNode *>(node); 
	}


	//-----------------------------------------------------------------

	ASTNode * MemoryCellAST::GetValue (void) { 
		SINASSERT(value);
		return value; 
	}
	
}