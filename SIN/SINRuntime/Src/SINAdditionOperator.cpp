#include "SINAdditionOperator.h"
#include "SINAssert.h"
#include "SINAlloc.h"





namespace SIN {

	//------------------------------------------------------

	AdditionOperator::AdditionOperator(void) {	
		binaryOperator		= String("+");
		binaryOperatorType	= String("Arithmetic");
	}
	

	//------------------------------------------------------

	AdditionOperator::~AdditionOperator() {}


	//*******************************
	//	protected methods


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) {
		return SINEWCLASS(MemoryCellString, (mc1.GetValue() + mc2.ToString()));
	}


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (mc1.GetValue() + static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Arithmetic Number + ", mc2));
	}



}	//namespace SIN