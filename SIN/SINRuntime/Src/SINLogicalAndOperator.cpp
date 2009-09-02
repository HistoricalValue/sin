#include "SINLogicalAndOperator.h"
#include "SINAlloc.h"

#define MEMORY_CELL_AND		mc1.ToBoolean() && mc2.ToBoolean()

namespace SIN {

	//------------------------------------------------------

	LogicalAndOperator::LogicalAndOperator(void) {	
		binaryOperator		= String("and");
		binaryOperatorType	= String("Logical");
	}
	

	//------------------------------------------------------

	LogicalAndOperator::~LogicalAndOperator() {}


	//*******************************
	//	protected methods
	
	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return SINEWCLASS(MemoryCellBool, (false));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2)
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell &mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2) 
		{	return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));	}

	//------------------------------------------------------

	MemoryCell * LogicalAndOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2){
		SINASSERT(!"Thes an mesa sthn BooleanFormOfMemoryCell epistrefei swsth timh");
		return SINEWCLASS(MemoryCellBool, (MEMORY_CELL_AND));
	}

}	//namespace SIN