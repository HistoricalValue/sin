#include "SINIncrementOperator.h"
#include "SINAlloc.h"


namespace SIN {


	//---------------------------------------------

	IncrementOperator::IncrementOperator(void) {}

	//---------------------------------------------

	IncrementOperator::~IncrementOperator(){}

	//---------------------------------------------

	MemoryCell * IncrementOperator::operator() (const MemoryCell & mc) {
		if (mc.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (static_cast<const MemoryCellNumber &>(mc).GetValue()+1));

		return ReturnError(	String("Arithmetic ++ ")			+ 
							GetTypeAsStringFromMemoryCell(mc)	+ 
							String(" instruction not alowed!"));
	}


}