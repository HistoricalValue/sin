#ifndef __SIN_ADDITION_OPERATOR_H__
#define __SIN_ADDITION_OPERATOR_H__


#include "SINArithmeticOperator.h"




namespace SIN {
	class AdditionOperator : public ArithmeticOperator {
	public: 
		AdditionOperator(void);
		~AdditionOperator();
		
	private:
		MemoryCell * ManageString(const MemoryCellString &, const MemoryCell &);
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);
	};

}	//namespace SIN


#endif	//__SIN_ADDITION_OPERATOR_H__