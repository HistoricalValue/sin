#include "SINLessThanOrEqualToOperator.h"
#include "SINAlloc.h"





namespace SIN {

	//------------------------------------------------------

	LessThanOrEqualToOperator::LessThanOrEqualToOperator(void) {	
		binaryOperator		= String("<=");
		binaryOperatorType	= String("Relational");
	}
	

	//------------------------------------------------------

	LessThanOrEqualToOperator::~LessThanOrEqualToOperator() {}


	//*******************************
	//	protected methods


	//------------------------------------------------------
	
	MemoryCell * LessThanOrEqualToOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::STRING_MCT)
			return SINEWCLASS(MemoryCellBool, (mc1.GetValue() <= static_cast<const MemoryCellString &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Relational String <= ", mc2));
	}


	//------------------------------------------------------
	
	MemoryCell * LessThanOrEqualToOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellBool, (mc1.GetValue() <= static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Relational Number <= ", mc2));
	}



}	//namespace SIN