#ifndef __SIN_SUBTRACTION_OPERATOR_H__
#define __SIN_SUBTRACTION_OPERATOR_H__

#include "SINBinaryOperator.h"

namespace SIN {
	class SubtractionOperator : public BinaryOperator {
	public:
		SubtractionOperator(void);
		~SubtractionOperator();
	private:
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);

	};

}	//namespace SIN

#endif //__SIN_SUBTRACTION_OPERATOR_H__