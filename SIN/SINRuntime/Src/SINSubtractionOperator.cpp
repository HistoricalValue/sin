#include "SINSubtractionOperator.h"

#include "SINAlloc.h"

namespace SIN {
	//------------------------------------------------------

	SubtractionOperator::SubtractionOperator(void) 
		{	arithmeticOperator = String("-");	}
	

	//------------------------------------------------------

	SubtractionOperator::~SubtractionOperator() {}


	//*******************************
	//	protected methods


	//------------------------------------------------------
	
	MemoryCell * SubtractionOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (mc1.GetValue() - static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Arithmetic Number - ", mc2));
	}

}