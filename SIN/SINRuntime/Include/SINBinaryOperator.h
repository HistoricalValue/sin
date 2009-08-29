#ifndef __SIN_ARITHMETIC_OPERATOR_H__
#define __SIN_ARITHMETIC_OPERATOR_H__

#include "SINOperator.h"


namespace SIN {
	
	class BinaryOperator : public Operator {
	public:
		BinaryOperator(void);
		~BinaryOperator();

	protected:
		String binaryOperator;
		String binaryOperatorType;
		
		virtual MemoryCell * ManageNil				(const MemoryCellNil &, const MemoryCell &);
		virtual MemoryCell * ManageBool				(const MemoryCellBool &, const MemoryCell &);
		virtual MemoryCell * ManageString			(const MemoryCellString &, const MemoryCell &);
		virtual MemoryCell * ManageNumber			(const MemoryCellNumber &, const MemoryCell &);
		virtual MemoryCell * ManageAst				(const MemoryCellAST &, const MemoryCell &);
		virtual MemoryCell * ManageObject			(const MemoryCellObject &, const MemoryCell &);
		virtual MemoryCell * ManageFunction			(const MemoryCellFunction &, const MemoryCell &);
		virtual MemoryCell * ManageLibFunction		(const MemoryCellLibFunction &, const MemoryCell &);
		virtual MemoryCell * ManageNativeResource	(const MemoryCellNativeResource &, const MemoryCell &);
	};

}	//namsepace SIN


#endif __SIN_ARITHMETIC_OPERATOR_H__