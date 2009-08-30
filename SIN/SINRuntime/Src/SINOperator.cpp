#include "SINOperator.h"

#include "SINAssert.h"
namespace SIN {


	//*******************************
	//	public methods


	//---------------------------------------------
	Operator::Operator(void) {}

	//---------------------------------------------
	Operator::~Operator()	{}


	//---------------------------------------------

	bool Operator::HasError(void) const
		{	return hasError;	}
	

	//---------------------------------------------
	
	String Operator::ErrorMessage(void) const
		{	return errorMessage;	}




	//*******************************
	//	protected methods

	//---------------------------------------------

	MemoryCell * Operator::ReturnError(const String & msg) {
		hasError		= true;
		errorMessage	= msg;
		return static_cast<SIN::MemoryCell *>(0);
	}





}	//namespace SIN