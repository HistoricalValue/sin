#ifndef __SIN_OPERATORS_H__
#define __SIN_OPERATORS_H__

#include "SINString.h"
#include "SINMemoryCell.h"
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

	class Operator {
	public:
		Operator(void);
		virtual ~Operator();

		virtual MemoryCell * operator() (const MemoryCell &, const MemoryCell &);
		
		virtual bool	HasError(void) const;
		virtual String	ErrorMessage(void) const;

	protected:
		virtual String		 CreateErrorMessage(const char *, const MemoryCell &);
		virtual String		 CreateErrorMessage(const String &, const MemoryCell &);
		virtual MemoryCell * ReturnError(const String &);

		virtual bool		 BooleanFormOfMemoryCell(const MemoryCell &);
		virtual MemoryCell * ManageNil				(const MemoryCellNil &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageBool				(const MemoryCellBool &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageString			(const MemoryCellString &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageNumber			(const MemoryCellNumber &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageAst				(const MemoryCellAST &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageObject			(const MemoryCellObject &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageFunction			(const MemoryCellFunction &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageLibFunction		(const MemoryCellLibFunction &, const MemoryCell &) = 0;
		virtual MemoryCell * ManageNativeResource	(const MemoryCellNativeResource &, const MemoryCell &) = 0;
		
	private:
		bool	hasError;
		String	errorMessage;

		void	SetErrorMessage(const String &);
		String	GetTypeAsStringFromMemoryCell(const MemoryCell &);

	};
}	//namespace SIN


#endif	//__SIN_OPERATORS_H__