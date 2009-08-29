#include "SINBinaryOperator.h"


namespace SIN {
	


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}


	//------------------------------------------------------
	
	MemoryCell * BinaryOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * BinaryOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}

	
	//------------------------------------------------------
	
	MemoryCell * BinaryOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) 
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2)); }


	//------------------------------------------------------
	
	MemoryCell * BinaryOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) 
		{	return ReturnError(CreateErrorMessage(binaryOperatorType + binaryOperator, mc2));	}

}	//namespace SIN