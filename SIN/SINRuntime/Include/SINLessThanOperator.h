#ifndef __SIN_LESS_THAN_OPERATOR_H__
#define __SIN_LESS_THAN_OPERATOR_H__


#include "SINBinaryOperator.h"




namespace SIN {
	class LessThanOperator : public BinaryOperator {
	public: 
		LessThanOperator(void);
		~LessThanOperator();
		
	private:
		MemoryCell * ManageString(const MemoryCellString &, const MemoryCell &);
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);
	};

}	//namespace SIN


#endif	//__SIN_LESS_THAN_OPERATOR_H__