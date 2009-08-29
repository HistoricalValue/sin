#ifndef __SIN_GREATER_THAN_OR_EQUAL_TO_OPERATOR_H__
#define __SIN_GREATER_THAN_OR_EQUAL_TO_OPERATOR_H__


#include "SINBinaryOperator.h"




namespace SIN {
	class GreaterThanOrEqualToOperator : public BinaryOperator {
	public: 
		GreaterThanOrEqualToOperator(void);
		~GreaterThanOrEqualToOperator();
		
	private:
		MemoryCell * ManageString(const MemoryCellString &, const MemoryCell &);
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);
	};

}	//namespace SIN


#endif	//__SIN_GREATER_THAN_OR_EQUAL_TO_OPERATOR_H__