#include "SINUnaryNegationOperator.h"
#include "SINAlloc.h"


namespace SIN {


	//---------------------------------------------

	UnaryNegationOperator::UnaryNegationOperator(void) {}

	//---------------------------------------------

	UnaryNegationOperator::~UnaryNegationOperator(){}

	//---------------------------------------------

	MemoryCell * UnaryNegationOperator::operator() (const MemoryCell & mc) {
		if (mc.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (static_cast<const MemoryCellNumber &>(mc).GetValue()*(-1)));

		return ReturnError(	String("Arithmetic unary negation ")+ 
							GetTypeAsStringFromMemoryCell(mc)	+ 
							String(" instruction not alowed!"));
	}


}