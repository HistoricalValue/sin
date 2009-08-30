#ifndef __SIN_BINARY_OPERATOR_H__
#define __SIN_BINARY_OPERATOR_H__

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
	
	class BinaryOperator : public Operator {
	public:
		BinaryOperator(void);
		~BinaryOperator();

		virtual MemoryCell * operator() (const MemoryCell &, const MemoryCell &);
		virtual MemoryCell * operator() (const MemoryCell &);

	protected:
		String binaryOperator;
		String binaryOperatorType;

		virtual String		 CreateErrorMessage(const char *, const MemoryCell &);
		virtual String		 CreateErrorMessage(const String &, const MemoryCell &);

		virtual MemoryCell * ManageNil				(const MemoryCellNil &, const MemoryCell &);
		virtual MemoryCell * ManageBool				(const MemoryCellBool &, const MemoryCell &);
		virtual MemoryCell * ManageString			(const MemoryCellString &, const MemoryCell &);
		virtual MemoryCell * ManageNumber			(const MemoryCellNumber &, const MemoryCell &);
		virtual MemoryCell * ManageAst				(const MemoryCellAST &, const MemoryCell &);
		virtual MemoryCell * ManageObject			(const MemoryCellObject &, const MemoryCell &);
		virtual MemoryCell * ManageFunction			(const MemoryCellFunction &, const MemoryCell &);
		virtual MemoryCell * ManageLibFunction		(const MemoryCellLibFunction &, const MemoryCell &);
		virtual MemoryCell * ManageNativeResource	(const MemoryCellNativeResource &, const MemoryCell &);

	private:
		void	SetErrorMessage(const String &);

	};

}	//namsepace SIN


#endif //__SIN_BINARY_OPERATOR_H__