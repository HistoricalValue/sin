#ifndef __SIN_ADDITION_OPERATOR_H__
#define __SIN_ADDITION_OPERATOR_H__


#include "SINOperator.h"
#include "SINMemoryCell.h"





namespace SIN {
	class AdditionOperator : public Operator {
	public: 
		AdditionOperator(void);
		~AdditionOperator();

		MemoryCell * Addition (const MemoryCell &, const MemoryCell &);

		//friend MemoryCell * operator + (const MemoryCell &, const MemoryCell &);
	
	};
	//extern MemoryCell * operator + (const MemoryCell &, const MemoryCell &);

}	//namespace SIN


#endif	//__SIN_ADDITION_OPERATOR_H__