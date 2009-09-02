#include "SINEqualityOperator.h"
#include "SINAlloc.h"

namespace SIN {

	namespace {
		template<typename C>
		inline  MemoryCell * Equality(const C & mc1, const MemoryCell & mc2){
			MemoryCellBool * boolmc = SINEWCLASS(MemoryCellBool, (false));

			if (mc2.Type() == mc1.Type())
				boolmc->SetValue(mc1.GetValue() == static_cast<const C &>(mc2).GetValue());
			
			else if (mc2.Type() == MemoryCell::BOOL_MCT) 
				boolmc->SetValue(mc1.ToBoolean() == mc2.ToBoolean());

			return boolmc;
		}
	}

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
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2)
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell &mc2) 
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2) 
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2) 
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2) 
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2) 
		{	return Equality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * EqualityOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2){
		SINASSERT(!"Thes an mesa sthn BooleanFormOfMemoryCell epistrefei swsth timh gia an to == einai swsta");
		MemoryCellBool * boolmc = SINEWCLASS(MemoryCellBool, (false));

		if (mc2.Type() == MemoryCell::NATIVE_RESOURCE_MCT)
			boolmc->SetValue(true);
		
		else if (mc2.Type() == MemoryCell::BOOL_MCT) 
			boolmc->SetValue(mc1.ToBoolean() == mc2.ToBoolean());

		return boolmc;		
	}

}	//namespace SIN