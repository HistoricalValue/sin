#ifndef __SIN_INCREMENT_OPERATOR_H__
#define __SIN_INCREMENT_OPERATOR_H__

#include "SINUnaryOperator.h"


namespace SIN {
	
	class IncrementOperator : public UnaryOperator {
	public:
		IncrementOperator(void);
		~IncrementOperator();

		virtual MemoryCell * operator() (const MemoryCell &);

	protected:

	};

}	//namsepace SIN


#endif //__SIN_UNARY_OPERATOR_H__