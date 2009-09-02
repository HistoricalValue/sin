#include "SINInequalityOperator.h"
#include "SINAlloc.h"

namespace SIN {

	namespace {
		template<typename C>
		inline  MemoryCell * Inequality(const C & mc1, const MemoryCell & mc2){
			MemoryCellBool * boolmc = SINEWCLASS(MemoryCellBool, (false));

			if (mc2.Type() == mc1.Type())
				boolmc->SetValue(mc1.GetValue() != static_cast<const C &>(mc2).GetValue());
			
			else if (mc2.Type() == MemoryCell::BOOL_MCT) 
				boolmc->SetValue(mc1.ToBoolean() != mc2.ToBoolean());

			return boolmc;
		}
	}

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
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2)
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell &mc2) 
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2) 
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2) 
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2) 
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2) 
		{	return Inequality(mc1, mc2);	}

	//------------------------------------------------------

	MemoryCell * InequalityOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2){
		SINASSERT(!"Thes an mesa sthn BooleanFormOfMemoryCell epistrefei swsth timh gia an to == einai swsta");
		MemoryCellBool * boolmc = SINEWCLASS(MemoryCellBool, (false));

		if (mc2.Type() == MemoryCell::NATIVE_RESOURCE_MCT)
			boolmc->SetValue(false);
		
		else if (mc2.Type() == MemoryCell::BOOL_MCT) 
			boolmc->SetValue(mc1.ToBoolean() != mc2.ToBoolean());

		return boolmc;		
	}

}	//namespace SIN