#include "SINDivisionOperator.h"
#include "SINAlloc.h"





namespace SIN {

	//------------------------------------------------------

	DivisionOperator::DivisionOperator(void) {	
		binaryOperator		= String("/");
		binaryOperatorType	= String("Arithmetic");
	}
	

	//------------------------------------------------------

	DivisionOperator::~DivisionOperator() {}


	//*******************************
	//	protected methods

	//------------------------------------------------------
	
	MemoryCell * DivisionOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) {
			long num1 = static_cast<long>(mc1.GetValue());
			long num2 = static_cast<long>(static_cast<const MemoryCellNumber &>(mc2).GetValue());
			if(num2 != 0)
				return SINEWCLASS(MemoryCellNumber, (num1/num2));
			else
				return ReturnError("Division with zero");
		}
		
		return ReturnError(CreateErrorMessage("Arithmetic Number / ", mc2));
	}



}	//namespace SIN