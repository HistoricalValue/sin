#include "SINUnaryOperator.h"

#include "SINAssert.h"


namespace SIN {

	UnaryOperator::UnaryOperator(void){}
	UnaryOperator::~UnaryOperator(){}


	//-----------------------------------------------------------------

	MemoryCell * UnaryOperator::operator() (const MemoryCell &, const MemoryCell &) {
		SINASSERT(!"You call binary operator inside unary");
		return 	ReturnError("You call binary operator inside unary");
	}
}	//namspace SIN