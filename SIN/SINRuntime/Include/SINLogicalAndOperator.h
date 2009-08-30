#ifndef __SIN_LOGICAL_AND_OPERATOR_H__
#define __SIN_LOGICAL_AND_OPERATOR_H__

#include "SINBinaryOperator.h"



namespace SIN {
	
	class LogicalAndOperator : public BinaryOperator {
	public:
		LogicalAndOperator(void);
		~LogicalAndOperator();

	protected:
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
	
}	//namspace SIN


#endif	//__SIN_LOGICAL_AND_OPERATOR_H__