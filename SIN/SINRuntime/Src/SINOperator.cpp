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


	//---------------------------------------------

	MemoryCell * Operator::operator ()(const MemoryCell & mc1, const MemoryCell & mc2) {
		switch(mc1.Type()) {
			case MemoryCell::NIL_MCT:				ManageNil(static_cast<const MemoryCellNil &>(mc1), mc2);
			case MemoryCell::BOOL_MCT:				ManageBool(static_cast<const MemoryCellBool &>(mc1), mc2);
			case MemoryCell::STRING_MCT:			ManageString(static_cast<const MemoryCellString &>(mc1), mc2);
			case MemoryCell::NUMBER_MCT:			ManageNumber(static_cast<const MemoryCellNumber &>(mc1), mc2);
			case MemoryCell::AST_MCT:				ManageAst(static_cast<const MemoryCellAST &>(mc1), mc2);
			case MemoryCell::OBJECT_MCT:			ManageObject(static_cast<const MemoryCellObject &>(mc1), mc2);
			case MemoryCell::FUNCTION_MCT:			ManageFunction(static_cast<const MemoryCellFunction &>(mc1), mc2);
			case MemoryCell::LIB_FUNCTION_MCT:		ManageLibFunction(static_cast<const MemoryCellLibFunction &>(mc1), mc2);
			case MemoryCell::NATIVE_RESOURCE_MCT:	ManageNativeResource(static_cast<const MemoryCellNativeResource &>(mc1), mc2);
			default:								SINASSERT(0);
		}
		return static_cast<SIN::MemoryCell *>(0);
	}


	//*******************************
	//	protected methods


	//---------------------------------------------

	String Operator::CreateErrorMessage(const char * str, const MemoryCell & mc)
		{	return CreateErrorMessage(String(str), mc); }


	//---------------------------------------------
	
	String Operator::CreateErrorMessage(const String & str, const MemoryCell & mc)
		{	return str + GetTypeAsStringFromMemoryCell(mc) + String(" Instruction not allowed"); }


	//---------------------------------------------

	MemoryCell * Operator::ReturnError(const String & msg) {
		hasError		= true;
		errorMessage	= msg;
		return static_cast<SIN::MemoryCell *>(0);
	}


	//*******************************
	//	private methods

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



}	//namespace SIN