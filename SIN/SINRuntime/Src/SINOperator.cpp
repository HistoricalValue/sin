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


	//---------------------------------------------
	
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

	//---------------------------------------------

	/*bool Operator::BooleanFormOfMemoryCell (const MemoryCell & mc) {
		switch(mc.Type()) {
			case MemoryCell::NIL_MCT:				return false;
			case MemoryCell::BOOL_MCT:				return static_cast<const MemoryCellBool &>(mc).GetValue();
			case MemoryCell::STRING_MCT:			return static_cast<const MemoryCellString &>(mc).GetValue() == "" ? false : true;
			case MemoryCell::NUMBER_MCT:			return static_cast<const MemoryCellNumber &>(mc).GetValue() == 0 ? false : true;
			case MemoryCell::AST_MCT:				return true;
			case MemoryCell::OBJECT_MCT:			return true;
			case MemoryCell::FUNCTION_MCT:			return true;
			case MemoryCell::LIB_FUNCTION_MCT:		return true;
			case MemoryCell::NATIVE_RESOURCE_MCT:	return true;
			default:								SINASSERT(0);
		}
		return false;
	}*/



}	//namespace SIN