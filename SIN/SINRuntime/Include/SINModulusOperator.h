#ifndef __SIN_MODULUS_OPERATOR_H__
#define __SIN_MODULUS_OPERATOR_H__

#include "SINBinaryOperator.h"

namespace SIN {
	class ModulusOperator : public BinaryOperator {
	public:
		ModulusOperator(void);
		~ModulusOperator();

	private:
		MemoryCell * ManageNumber(const MemoryCellNumber &, const MemoryCell &);


	};
}	//namespace SIN


#endif //__SIN_MODULUS_OPERATOR_H__