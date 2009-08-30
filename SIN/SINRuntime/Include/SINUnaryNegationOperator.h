#ifndef __SIN_UNARY_NEGATION_OPERATOR_H__
#define __SIN_UNARY_NEGATION_OPERATOR_H__

#include "SINUnaryOperator.h"


namespace SIN {
	
	class UnaryNegationOperator : public UnaryOperator {
	public:
		UnaryNegationOperator(void);
		~UnaryNegationOperator();

		virtual MemoryCell * operator() (const MemoryCell &);

	protected:

	};

}	//namsepace SIN


#endif //__SIN_UNARY_NEGATION_OPERATOR_H__