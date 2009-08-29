#ifndef __SIN_SUBTRACTION_OPERATOR_H__
#define __SIN_SUBTRACTION_OPERATOR_H__

#include "SINArithmeticOperator.h"

namespace SIN {
	class SubtractionOperator : public ArithmeticOperator {
	public:
		SubtractionOperator(void);
		~SubtractionOperator();
	private:
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);

	};

}	//namespace SIN

#endif //__SIN_SUBTRACTION_OPERATOR_H__