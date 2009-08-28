#include "SINAdditionOperator.h"
#include "SINAssert.h"
#include "SINAlloc.h"
#include "SINString.h"


#define CREATE_ERRROR_MESSAGE(STR, MC)	String(STR)							+	\
										GetTypeAsStringFromMemoryCell(mc2)	+	\
										String(" Instruction not allowed")

#define RETURN_ERROR(ERROR_MSG)			SetErrorMessage(ERROR_MSG);				\
										return static_cast<SIN::MemoryCell *>(0)



namespace SIN {

	//------------------------------------------------------

	AdditionOperator::AdditionOperator(void) {}
	

	//------------------------------------------------------

	AdditionOperator::~AdditionOperator() {}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::Addition(const MemoryCell & mc1, const MemoryCell & mc2) 
		{	return Action(mc1, mc2);	}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::ManageNil(const MemoryCellNil & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage("Arithmetic Nil + ", mc2));	}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::ManageBool(const MemoryCellBool & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage("Arithmetic Bool + ", mc2));	}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::ManageAst(const MemoryCellAST & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage("Arithmetic AST + ", mc2));	}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::ManageObject(const MemoryCellObject & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage("Arithmetic Object + ", mc2));	}


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageFunction(const MemoryCellFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage("Arithmetic User Function + ", mc2));	}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::ManageLibFunction(const MemoryCellLibFunction & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage("Arithmetic Lib Function + ", mc2));	}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::ManageNativeResource(const MemoryCellNativeResource & mc1, const MemoryCell & mc2)
		{	return ReturnError(CreateErrorMessage("Arithmetic native resource + ", mc2));	}

	
	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::STRING_MCT)
			return SINEWCLASS(MemoryCellString, (mc1.GetValue() + static_cast<const MemoryCellString &>(mc2).GetValue()));
		else if (mc2.Type() == MemoryCell::NUMBER_MCT)
			return SINEWCLASS(MemoryCellString, (mc1.GetValue() + to_string(static_cast<const MemoryCellNumber &>(mc2).GetValue())));
		
		return ReturnError(CreateErrorMessage("Arithmetic String + ", mc2));
	}


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (mc1.GetValue() + static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		
		return ReturnError(CreateErrorMessage("Arithmetic Number + ", mc2));
	}



}	//namespace SI