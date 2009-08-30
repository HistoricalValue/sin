#include "SINBinaryOperator.h"

#include "SINAssert.h"

namespace SIN {


	//---------------------------------------------

	MemoryCell * BinaryOperator::operator ()(const MemoryCell & mc1, const MemoryCell & mc2) {
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

	
	MemoryCell * BinaryOperator::operator() (const MemoryCell &) {
		SINASSERT(0);
		return static_cast<MemoryCell *>(0);
	}


	//*******************************
	//	protected methods

	//---------------------------------------------

	String BinaryOperator::CreateErrorMessage(const char * str, const MemoryCell & mc)
		{	return CreateErrorMessage(String(str), mc); }


	//---------------------------------------------
	
	String BinaryOperator::CreateErrorMessage(const String & str, const MemoryCell & mc)
		{	return str + GetTypeAsStringFromMemoryCell(mc) + String(" Instruction not allowed"); }


	//---------------------------------------------

	bool BooleanFormOfMemoryCell (const MemoryCell & mc) {
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
	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " Nil " + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " Bool " + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " AST " + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " Object " + binaryOperator, mc2));	}


	//------------------------------------------------------
	
	MemoryCell * BinaryOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + "User Function" + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " Lib Function " + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " Native resource " + binaryOperator, mc2));	}

	
	//------------------------------------------------------
	
	MemoryCell * BinaryOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) 
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " String " + binaryOperator, mc2)); }


	//------------------------------------------------------
	
	MemoryCell * BinaryOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) 
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + " Number " + binaryOperator, mc2));	}



	//*******************************
	//	private methods


}	//namespace SIN