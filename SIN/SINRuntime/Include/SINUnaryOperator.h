#ifndef __SIN_UNARY_OPERATOR_H__
#define __SIN_UNARY_OPERATOR_H__

#include "SINOperator.h"
#include "SINMemoryCellAST.h"
#include "SINMemoryCellBool.h"
#include "SINMemoryCellFunction.h"
#include "SINMemoryCellLibFunction.h"
#include "SINMemoryCellNativeResource.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellObject.h"
#include "SINMemoryCellString.h"


namespace SIN {
	
	class UnaryOperator : public Operator {
	public:
		BinaryOperator(void);
		~BinaryOperator();

		virtual MemoryCell * operator() (const MemoryCell &, const MemoryCell &);
		virtual MemoryCell * operator() (const MemoryCell &);

	protected:

	};

}	//namsepace SIN


#endif //__SIN_UNARY_OPERATOR_H__