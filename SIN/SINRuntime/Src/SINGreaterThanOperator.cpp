#include "SINGreaterThanOperator.h"
#include "SINAlloc.h"





namespace SIN {

	//------------------------------------------------------

	GreaterThanOperator::GreaterThanOperator(void) {	
		binaryOperator		= String(">");
		binaryOperatorType	= String("Relational");
	}
	

	//------------------------------------------------------

	GreaterThanOperator::~GreaterThanOperator() {}


	//*******************************
	//	protected methods


	//------------------------------------------------------
	
	MemoryCell * GreaterThanOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::STRING_MCT)
			return SINEWCLASS(MemoryCellBool, (mc1.GetValue() > static_cast<const MemoryCellString &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Relational String > ", mc2));
	}


	//------------------------------------------------------
	
	MemoryCell * GreaterThanOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellBool, (mc1.GetValue() > static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Relational Number > ", mc2));
	}



}	//namespace SIN