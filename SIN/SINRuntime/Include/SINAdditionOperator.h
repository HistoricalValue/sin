#ifndef __SIN_ADDITION_OPERATOR_H__
#define __SIN_ADDITION_OPERATOR_H__


#include "SINOperator.h"
#include "SINMemoryCell.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellString.h"




namespace SIN {
	class AdditionOperator : public Operator {
	public: 
		AdditionOperator(void);
		~AdditionOperator();

		MemoryCell * Addition (const MemoryCell &, const MemoryCell &);
		
	private:
		MemoryCell * ManageNil				(const MemoryCellNil &, const MemoryCell &);
		MemoryCell * ManageBool				(const MemoryCellBool &, const MemoryCell &);
		MemoryCell * ManageString			(const MemoryCellString &, const MemoryCell &);
		MemoryCell * ManageNumber			(const MemoryCellNumber &, const MemoryCell &);
		MemoryCell * ManageAst				(const MemoryCellAST &, const MemoryCell &);
		MemoryCell * ManageObject			(const MemoryCellObject &, const MemoryCell &);
		MemoryCell * ManageFunction			(const MemoryCellFunction &, const MemoryCell &);
		MemoryCell * ManageLibFunction		(const MemoryCellLibFunction &, const MemoryCell &);
		MemoryCell * ManageNativeResource	(const MemoryCellNativeResource &, const MemoryCell &);
	};

}	//namespace SIN


#endif	//__SIN_ADDITION_OPERATOR_H__