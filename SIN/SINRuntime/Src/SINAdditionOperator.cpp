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

	AdditionOperator::AdditionOperator(void) {}
	AdditionOperator::~AdditionOperator() {}


	//------------------------------------------------------

	MemoryCell * AdditionOperator::Addition(const MemoryCell & mc1, const MemoryCell & mc2) {
		switch(mc1.Type()) {
			case MemoryCell::NIL_MCT:				RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Nil + ", mc2));
			case MemoryCell::BOOL_MCT:				RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Bool + ", mc2));
			case MemoryCell::STRING_MCT:			ManageString(static_cast<const MemoryCellString &>(mc1), mc2);
			case MemoryCell::NUMBER_MCT:			ManageNumber(static_cast<const MemoryCellNumber &>(mc1), mc2);
			case MemoryCell::OBJECT_MCT:			RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Object + ", mc2));
			case MemoryCell::FUNCTION_MCT:			RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic User Function + ", mc2));
			case MemoryCell::LIB_FUNCTION_MCT:		RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Lib Function + ", mc2));
			case MemoryCell::NATIVE_RESOURCE_MCT:	RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic native resource + ", mc2));
			default:								SINASSERT(0);
		}
		return static_cast<SIN::MemoryCell *>(0);
	}


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageNumber(const MemoryCellNumber & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::NUMBER_MCT) 
			return SINEWCLASS(MemoryCellNumber, (mc1.GetValue() + static_cast<const MemoryCellNumber &>(mc2).GetValue()));
		RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Number + ", mc2));
	}


	//------------------------------------------------------
	
	MemoryCell * AdditionOperator::ManageString(const MemoryCellString & mc1, const MemoryCell & mc2) {
		if (mc2.Type() == MemoryCell::STRING_MCT)
			return SINEWCLASS(MemoryCellString, (mc1.GetValue() + static_cast<const MemoryCellString &>(mc2).GetValue()));
		else if (mc2.Type() == MemoryCell::NUMBER_MCT)
			return SINEWCLASS(MemoryCellString, (mc1.GetValue() + to_string(static_cast<const MemoryCellNumber &>(mc2).GetValue())));
		RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic String + ", mc2));
	}

}	//namespace SI