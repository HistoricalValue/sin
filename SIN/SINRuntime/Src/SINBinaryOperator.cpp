#include "SINBinaryOperator.h"

#include "SINAssert.h"

namespace SIN {

	//---------------------------------------------
	BinaryOperator::BinaryOperator(void) {
	}
	//---------------------------------------------
	BinaryOperator::~BinaryOperator(void) {
	}
	//---------------------------------------------

	MemoryCell * BinaryOperator::operator ()(const MemoryCell & mc1, const MemoryCell & mc2) {
		MemoryCell* result = 0x00;
		switch(mc1.Type()) {
			case MemoryCell::NIL_MCT:				result = ManageNil(static_cast<const MemoryCellNil &>(mc1), mc2); break;
			case MemoryCell::BOOL_MCT:				result = ManageBool(static_cast<const MemoryCellBool &>(mc1), mc2); break;
			case MemoryCell::STRING_MCT:			result = ManageString(static_cast<const MemoryCellString &>(mc1), mc2); break;
			case MemoryCell::NUMBER_MCT:			result = ManageNumber(static_cast<const MemoryCellNumber &>(mc1), mc2); break;
			case MemoryCell::AST_MCT:				result = ManageAst(static_cast<const MemoryCellAST &>(mc1), mc2); break;
			case MemoryCell::OBJECT_MCT:			result = ManageObject(static_cast<const MemoryCellObject &>(mc1), mc2); break;
			case MemoryCell::FUNCTION_MCT:			result = ManageFunction(static_cast<const MemoryCellFunction &>(mc1), mc2); break;
			case MemoryCell::LIB_FUNCTION_MCT:		result = ManageLibFunction(static_cast<const MemoryCellLibFunction &>(mc1), mc2); break;
			case MemoryCell::NATIVE_RESOURCE_MCT:	result = ManageNativeResource(static_cast<const MemoryCellNativeResource &>(mc1), mc2); break;
			default:								SINASSERT(0); break;
		}
		return result;
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