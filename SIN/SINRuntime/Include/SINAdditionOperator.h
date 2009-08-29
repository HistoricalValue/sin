#ifndef __SIN_ADDITION_OPERATOR_H__
#define __SIN_ADDITION_OPERATOR_H__


#include "SINBinaryOperator.h"




namespace SIN {
	class AdditionOperator : public BinaryOperator {
	public: 
		AdditionOperator(void);
		~AdditionOperator();
		
	private:
		MemoryCell * ManageString(const MemoryCellString &, const MemoryCell &);
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);
	};

}	//namespace SIN


#endif	//__SIN_ADDITION_OPERATOR_H__