#include "SINBinaryOperator.h"

#include "SINAssert.h"

namespace SIN {

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

}	//namespace SIN