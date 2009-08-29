#include "SINInequalityOperator.h"
#include "SINAlloc.h"

namespace SIN {

	//------------------------------------------------------

	InequalityOperator::InequalityOperator(void) {	
		binaryOperator		= String("!=");
		binaryOperatorType	= String("Relational");
	}
	

	//------------------------------------------------------

	InequalityOperator::~InequalityOperator() {}


	//*******************************
	//	protected methods
	
	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return Inequality<MemoryCell::NIL_MCT, MemoryCellNil>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return Inequality<MemoryCell::BOOL_MCT, MemoryCellBool>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2)
		{	return Inequality<MemoryCell::STRING_MCT, MemoryCellString>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell &mc2) 
		{	return Inequality<MemoryCell::NUMBER_MCT, MemoryCellNumber>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2) 
		{	return Inequality<MemoryCell::AST_MCT, MemoryCellAST>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2) 
		{	return Inequality<MemoryCell::OBJECT_MCT, MemoryCellObject>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2) 
		{	return Inequality<MemoryCell::FUNCTION_MCT, MemoryCellFunction>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2) 
		{	return Inequality<MemoryCell::LIB_FUNCTION_MCT, MemoryCellLibFunction>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2){
		SINASSERT(!"Thes an mesa sthn BooleanFormOfMemoryCell epistrefei swsth timh gia an to == einai swsta");
		MemoryCellBool * boolmc = SINEWCLASS(MemoryCellBool, (false));

		if (mc2.Type() == MemoryCell::NATIVE_RESOURCE_MCT)
			boolmc->SetValue(false);
		
		else if (mc2.Type() == MemoryCell::BOOL_MCT) 
			boolmc->SetValue(BooleanFormOfMemoryCell(mc1) != BooleanFormOfMemoryCell(mc2));

		return boolmc;		
	}

}	//namespace SIN