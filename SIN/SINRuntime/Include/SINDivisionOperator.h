#ifndef __SIN_DIVISION_OPERATOR_H__
#define __SIN_DIVISION_OPERATOR_H__

#include "SINBinaryOperator.h"

namespace SIN {
	class DivisionOperator : public BinaryOperator {
	public:
		DivisionOperator(void);
		~DivisionOperator();

	private:
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);


	};
}	//namespace SIN


#endif //__SIN_DIVISION_OPERATOR_H__