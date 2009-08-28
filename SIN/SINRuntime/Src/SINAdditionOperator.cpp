#include "SINAdditionOperator.h"
#include "SINAssert.h"

#include "SINString.h"
#include "SINMemoryCellObject.h"


#define CREATE_ERRROR_MESSAGE(STR, MC)	String(STR)							+	\
										GetTypeAsStringFromMemoryCell(mc2)	+	\
										String(" Instruction not allowed")

#define RETURN_ERROR(ERROR_MSG)			SetErrorMessage(ERROR_MSG);				\
										return static_cast<SIN::MemoryCell *>(0)



namespace SIN {

	AdditionOperator::AdditionOperator(void) {}
	AdditionOperator::~AdditionOperator() {}


	MemoryCell * AdditionOperator::Addition(const MemoryCell & mc1, const MemoryCell & mc2) {
		switch(mc1.Type()) {
			case MemoryCell::NIL_MCT:				RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Nil + ", mc2));
			case MemoryCell::BOOL_MCT:				RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Bool + ", mc2));
			case MemoryCell::STRING_MCT:	
			case MemoryCell::NUMBER_MCT:	
			case MemoryCell::OBJECT_MCT:			RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Object + ", mc2));
			case MemoryCell::FUNCTION_MCT:			RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic User Function + ", mc2));
			case MemoryCell::LIB_FUNCTION_MCT:		RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic Lib Function + ", mc2));
			case MemoryCell::NATIVE_RESOURCE_MCT:	RETURN_ERROR(CREATE_ERRROR_MESSAGE("Arithmetic native resource + ", mc2));
			default:								SINASSERT(0);
		}
		return static_cast<SIN::MemoryCell *>(0);
	}


/*
	extern MemoryCell * operator + (const MemoryCell & mc1, const MemoryCell & mc2) {
		
		switch(mc1.Type()) {
			case MemoryCell::OBJECT_MCT:
				
				//static_cast<const MemoryCellObject &>(mc1).GetValue();
				
				break;
			default:
				SINASSERT(0);
		}
		return 0;
	}
*/

}	//namespace SI