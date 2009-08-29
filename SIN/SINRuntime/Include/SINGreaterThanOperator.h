#ifndef __SIN_GREATER_THAN_OPERATOR_H__
#define __SIN_GREATER_THAN_OPERATOR_H__


#include "SINBinaryOperator.h"




namespace SIN {
	class GreaterThanOperator : public BinaryOperator {
	public: 
		GreaterThanOperator(void);
		~GreaterThanOperator();
		
	private:
		MemoryCell * ManageString(const MemoryCellString &, const MemoryCell &);
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);
	};

}	//namespace SIN


#endif	//__SIN_GREATER_THAN_OPERATOR_H__