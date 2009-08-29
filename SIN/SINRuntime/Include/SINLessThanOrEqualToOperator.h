#ifndef __SIN_LESS_THAN_OR_EQUAL_TO_OPERATOR_H__
#define __SIN_LESS_THAN_OR_EQUAL_TO_OPERATOR_H__


#include "SINBinaryOperator.h"




namespace SIN {
	class LessThanOrEqualToOperator : public BinaryOperator {
	public: 
		LessThanOrEqualToOperator(void);
		~LessThanOrEqualToOperator();
		
	private:
		MemoryCell * ManageString(const MemoryCellString &, const MemoryCell &);
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);
	};

}	//namespace SIN


#endif	//__SIN_LESS_THAN_OR_EQUAL_TO_OPERATOR_H__