#include "SINLogicalOrOperator.h"
#include "SINAlloc.h"

#define MEMORY_CELL_OR		mc1.ToBoolean() || mc2.ToBoolean()	

namespace SIN {

	//------------------------------------------------------

	LogicalOrOperator::LogicalOrOperator(void) {	
		binaryOperator		= String("or");
		binaryOperatorType	= String("Logical");
	}
	

	//------------------------------------------------------

	LogicalOrOperator::~LogicalOrOperator() {}


	//*******************************
	//	protected methods
	
	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return SINEWCLASS(MemoryCellBool, (mc2.ToBoolean()));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2)
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell &mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));	}

	//------------------------------------------------------

	MemoryCell * LogicalOrOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2){
		SINASSERT(!"Thes an mesa sthn BooleanFormOfMemoryCell epistrefei swsth timh");
		return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_OR));
	}

}	//namespace SIN