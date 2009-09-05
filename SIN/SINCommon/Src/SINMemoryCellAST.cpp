#include "SINMemoryCellAST.h"

#include "SINAlloc.h"
#include "SINAssert.h"
#include "SINASTUnparseTreeVisitor.h"
#include "SINASTNode.h"


namespace SIN {

	MemoryCellAST::MemoryCellAST(Types::Metacode_t const& node):
		MemoryCell(),
		value(node)
	{ }

	//-----------------------------------------------------------------

	MemoryCellAST::~MemoryCellAST(void) {
		DeleteAST(value);
	}

	//-----------------------------------------------------------------

	MemoryCellAST::MemoryCellAST(const MemoryCellAST & other):
		MemoryCell(),
		value(CopyAST(other.value))
	{ }

	//-----------------------------------------------------------------

	MemoryCell * MemoryCellAST::Clone(void) const
		{ return SINEWCLASS(MemoryCellAST, (*this)); }
	

	//-----------------------------------------------------------------

	MemoryCell::MemoryCellType MemoryCellAST::Type (void)  const
		{ return MemoryCell::AST_MCT; }


	//-----------------------------------------------------------------

	const String MemoryCellAST::ToString(void) const {
		return UnparseAST(*value, true); 
	}
		


	//-----------------------------------------------------------------

	void MemoryCellAST::SetValue (const Types::Metacode_t& node) { 
		SINASSERT(node);
		value = node; 
	}


	//-----------------------------------------------------------------

	Types::Metacode_t MemoryCellAST::GetValue (void) const { 
		SINASSERT(value);
		return value; 
	}
	
	//-----------------------------------------------------------------

	bool MemoryCellAST::ToBoolean(void) const
		{ return true; }
}
