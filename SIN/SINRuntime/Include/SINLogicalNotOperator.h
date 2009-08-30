#ifndef __SIN_LOGICAL_NOT_OPERATOR_H__
#define __SIN_LOGICAL_NOT_OPERATOR_H__

#include "SINUnaryOperator.h"


namespace SIN {
	
	class LogicalNotOperator : public UnaryOperator {
	public:
		LogicalNotOperator(void);
		~LogicalNotOperator();

		virtual MemoryCell * operator() (const MemoryCell &);

	protected:

	};

}	//namsepace SIN


#endif //__SIN_LOGICAL_NOT_OPERATOR_H__