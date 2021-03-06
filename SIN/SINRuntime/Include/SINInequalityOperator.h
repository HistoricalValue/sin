#ifndef __SIN_INEQUALIITY_OPERATOR_H__
#define __SIN_INEQUALIITY_OPERATOR_H__

#include "SINAlloc.h"
#include "SINBinaryOperator.h"



namespace SIN {
	
	class InequalityOperator : public BinaryOperator {
	public:
		InequalityOperator(void);
		~InequalityOperator();

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


#endif	//__SIN_INEQUALIITY_OPERATOR_H__