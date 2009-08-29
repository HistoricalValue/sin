#include "SINEqualityOperator.h"
#include "SINAlloc.h"

namespace SIN {

	//------------------------------------------------------

	EqualityOperator::EqualityOperator(void) {	
		binaryOperator		= String("==");
		binaryOperatorType	= String("Relational");
	}
	

	//------------------------------------------------------

	EqualityOperator::~EqualityOperator() {}


	//*******************************
	//	protected methods
	
	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return Equality<MemoryCell::NIL_MCT, MemoryCellNil>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return Equality<MemoryCell::BOOL_MCT, MemoryCellBool>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2)
		{	return Equality<MemoryCell::STRING_MCT, MemoryCellString>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell &mc2) 
		{	return Equality<MemoryCell::NUMBER_MCT, MemoryCellNumber>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2) 
		{	return Equality<MemoryCell::AST_MCT, MemoryCellAST>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2) 
		{	return Equality<MemoryCell::OBJECT_MCT, MemoryCellObject>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2) 
		{	return Equality<MemoryCell::FUNCTION_MCT, MemoryCellFunction>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2) 
		{	return Equality<MemoryCell::LIB_FUNCTION_MCT, MemoryCellLibFunction>(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2){
		SINASSERT(!"Thes an mesa sthn BooleanFormOfMemoryCell epistrefei swsth timh gia an to == einai swsta");
		MemoryCellBool * boolmc = SINEWCLASS(MemoryCellBool, (false));

		if (mc2.Type() == MemoryCell::NATIVE_RESOURCE_MCT)
			boolmc->SetValue(true);
		
		else if (mc2.Type() == MemoryCell::BOOL_MCT) 
			boolmc->SetValue(BooleanFormOfMemoryCell(mc1) == BooleanFormOfMemoryCell(mc2));

		return boolmc;		
	}

}	//namespace SIN