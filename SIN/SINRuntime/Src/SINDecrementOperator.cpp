#include "SINDecrementOperator.h"
#include "SINAlloc.h"


namespace SIN {


	//---------------------------------------------

	DecrementOperator::DecrementOperator(void) {}

	//---------------------------------------------

	DecrementOperator::~DecrementOperator(){}

	//---------------------------------------------

	MemoryCell * DecrementOperator::operator() (const MemoryCell & mc) {
		if (mc.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (static_cast<const MemoryCellNumber &>(mc).GetValue()-1));

		return ReturnError(	String("Arithmetic -- ")			+ 
							GetTypeAsStringFromMemoryCell(mc)	+ 
							String(" instruction not alowed!"));
	}


}