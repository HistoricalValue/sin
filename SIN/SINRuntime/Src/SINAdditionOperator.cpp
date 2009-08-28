#include "SINAdditionOperator.h"
#include "SINAssert.h"
#include "SINAlloc.h"





namespace SIN {

	//------------------------------------------------------

	AdditionOperator::AdditionOperator(void) 
		{	arithmeticOperator = String("+");	}
	

	//------------------------------------------------------

	AdditionOperator::~AdditionOperator() {}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::Addition(const MemoryCell & mc1, const MemoryCell & mc2) 
		{	return Action(mc1, mc2);	}


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::STRING_MCT)
			return SINEWCLASS(MemoryCellString, (mc1.GetValue() + static_cast<const MemoryCellString &>(mc2).GetValue()));
		else if (mc2.Type() == MemoryCell::NUMBER_MCT)
			return SINEWCLASS(MemoryCellString, (mc1.GetValue() + to_string(static_cast<const MemoryCellNumber &>(mc2).GetValue())));
		
		return ReturnError(CreateErrorMessage("Arithmetic String + ", mc2));
	}


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (mc1.GetValue() + static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Arithmetic Number + ", mc2));
	}



}	//namespace SIN