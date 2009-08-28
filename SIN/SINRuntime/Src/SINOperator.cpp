#include "SINOperator.h"

#include "SINAssert.h"
namespace SIN {

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


	//---------------------------------------------

	void Operator::SetErrorMessage(const String & msg) {
		hasError		= true;
		errorMessage	= msg;
	}


	String Operator::GetTypeAsStringFromMemoryCell(const MemoryCell & mc) {
		switch(mc.Type()) {
			case MemoryCell::NIL_MCT:				return String("Nil");
			case MemoryCell::BOOL_MCT:				return String("Bool");
			case MemoryCell::STRING_MCT:			return String("String");
			case MemoryCell::NUMBER_MCT:			return String("Number");
			case MemoryCell::AST_MCT:				return String("AST");
			case MemoryCell::OBJECT_MCT:			return String("Object");
			case MemoryCell::FUNCTION_MCT:			return String("Function");
			case MemoryCell::LIB_FUNCTION_MCT:		return String("Lib Function");
			case MemoryCell::NATIVE_RESOURCE_MCT:	return String("Native Resource");
			default:	SINASSERT(0);
		}
		return String();
	}

}	//namespace SIN