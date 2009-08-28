#ifndef __SIN_OPERATORS_H__
#define __SIN_OPERATORS_H__

#include "SINString.h"
#include "SINMemoryCell.h"


namespace SIN {

	class Operator {
	public:
		Operator(void);
		virtual ~Operator();

		
		virtual bool	HasError(void) const;
		virtual String	ErrorMessage(void) const;

	protected:
		bool	hasError;
		String	errorMessage;


		void	SetErrorMessage(const String &);
		String	GetTypeAsStringFromMemoryCell(const MemoryCell &);
	};
}	//namespace SIN


#endif	//__SIN_OPERATORS_H__