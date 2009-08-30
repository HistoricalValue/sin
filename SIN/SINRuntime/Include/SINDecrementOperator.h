#ifndef __SIN_DECREMENT_OPERATOR_H__
#define __SIN_DECREMENT_OPERATOR_H__

#include "SINUnaryOperator.h"


namespace SIN {
	
	class DecrementOperator : public UnaryOperator {
	public:
		DecrementOperator(void);
		~DecrementOperator();

		virtual MemoryCell * operator() (const MemoryCell &);

	protected:

	};

}	//namsepace SIN


#endif //__SIN_DECREMENT_OPERATOR_H__