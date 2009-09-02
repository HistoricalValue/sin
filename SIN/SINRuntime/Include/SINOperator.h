#ifndef __SIN_OPERATORS_H__
#define __SIN_OPERATORS_H__

#include "SINString.h"
#include "SINMemoryCell.h"


namespace SIN {

	class Operator {
	public:
		Operator(void);
		virtual ~Operator();

		virtual MemoryCell * operator() (const MemoryCell &, const MemoryCell &) = 0;
		virtual MemoryCell * operator() (const MemoryCell &) = 0;
		
		virtual bool	HasError(void) const;
		virtual String	ErrorMessage(void) const;

		// Utilities
		static String	 GetTypeAsStringFromMemoryCell(const MemoryCell &);
	protected:		
		virtual MemoryCell * ReturnError(const String &);
		
	private:
		bool	hasError;
		String	errorMessage;
	};
}	//namespace SIN


#endif	//__SIN_OPERATORS_H__