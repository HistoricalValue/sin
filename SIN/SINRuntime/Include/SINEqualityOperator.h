#ifndef __SIN_EQUALIITY_OPERATOR_H__
#define __SIN_EQUALIITY_OPERATOR_H__


#include "SINMemoryCell.h"

namespace SIN {
	
	class EqualityOperator {
	public:
		EqualityOperator(void);
		~EqualityOperator();

		friend MemoryCell * operator == (const MemoryCell &, const MemoryCell &);
	};
	
	extern MemoryCell * operator == (const MemoryCell &, const MemoryCell &);

}	//namspace SIN


#endif	//__SIN_EQUALIITY_OPERATOR_H__