#include "SINArithmeticOperator.h"


namespace SIN {
	


	//------------------------------------------------------

	MemoryCell * ArithmeticOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(String("Arithmetic Nil") + arithmeticOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * ArithmeticOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(String("Arithmetic Bool") + arithmeticOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * ArithmeticOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(String("Arithmetic AST") + arithmeticOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * ArithmeticOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(String("Arithmetic Object") + arithmeticOperator, mc2));	}


	//------------------------------------------------------
	
	MemoryCell * ArithmeticOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(String("Arithmetic User Function") + arithmeticOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * ArithmeticOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(String("Arithmetic Lib Function") + arithmeticOperator, mc2));	}


	//------------------------------------------------------

	MemoryCell * ArithmeticOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage(String("Arithmetic native resource") + arithmeticOperator, mc2));	}

	
	//------------------------------------------------------
	
	MemoryCell * ArithmeticOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) 
		{	return ReturnError(CreateErrorMessage(String("Arithmetic String") + arithmeticOperator, mc2)); }


	//------------------------------------------------------
	
	MemoryCell * ArithmeticOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) 
		{	return ReturnError(CreateErrorMessage(String("Arithmetic Number") + arithmeticOperator, mc2));	}

}	//namespace SIN