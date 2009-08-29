#ifndef __SIN_MULTIPLICATION_OPERATOR_H__
#define __SIN_MULTIPLICATION_OPERATOR_H__

#include "SINBinaryOperator.h"

namespace SIN {
	class MultiplicationOperator : public BinaryOperator {
	public:
		MultiplicationOperator(void);
		~MultiplicationOperator();

	private:
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);


	};
}	//namespace SIN


#endif //__SIN_MULTIPLICATION_OPERATOR_H__