#include "SINLogicalNotOperator.h"
#include "SINAlloc.h"


namespace SIN {


	//---------------------------------------------

	LogicalNotOperator::LogicalNotOperator(void) {}

	//---------------------------------------------

	LogicalNotOperator::~LogicalNotOperator(){}

	//---------------------------------------------

	MemoryCell * LogicalNotOperator::operator() (const MemoryCell & mc) 
		{	return SINEWCLASS(MemoryCellBool, (!mc.ToBoolean()));	}


}