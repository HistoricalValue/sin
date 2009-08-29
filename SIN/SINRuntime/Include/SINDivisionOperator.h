#ifndef __SIN_DIVISION_OPERATOR_H__
#define __SIN_DIVISION_OPERATOR_H__

#include "SINArithmeticOperator.h"

namespace SIN {
	class DivisionOperator : public ArithmeticOperator {
	public:
		DivisionOperator(void);
		~DivisionOperator();

	private:
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);


	};
}	//namespace SIN


#endif //__SIN_MULTIPLICATION_OPERATOR_H__