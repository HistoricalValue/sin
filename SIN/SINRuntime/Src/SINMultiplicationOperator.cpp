#include "SINMultiplicationOperator.h"
#include "SINAlloc.h"


namespace SIN {

	//------------------------------------------------------

	MultiplicationOperator::MultiplicationOperator(void) {	
		binaryOperator		= String("*");
		binaryOperatorType	= String("Arithmetic");
	}
	

	//------------------------------------------------------

	MultiplicationOperator::~MultiplicationOperator() {}


	//*******************************
	//	protected methods

	//------------------------------------------------------
	
	MemoryCell * MultiplicationOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (mc1.GetValue() * static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Arithmetic Number * ", mc2));
	}

	MemoryCell * MultiplicationOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellString, (mc1.GetValue() * static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Arithmetic String * ", mc2));
	}

}	//namespace SIN