#ifndef __SIN_EQUALIITY_OPERATOR_H__
#define __SIN_EQUALIITY_OPERATOR_H__

#include "SINAlloc.h"
#include "SINBinaryOperator.h"



namespace SIN {
	
	class EqualityOperator : public BinaryOperator {
	public:
		EqualityOperator(void);
		~EqualityOperator();

	protected:
		virtual MemoryCell * ManageNil				(const MemoryCellNil &, const MemoryCell &);
		virtual MemoryCell * ManageBool				(const MemoryCellBool &, const MemoryCell &);
		virtual MemoryCell * ManageString			(const MemoryCellString &, const MemoryCell &);
		virtual MemoryCell * ManageNumber			(const MemoryCellNumber &, const MemoryCell &);
		virtual MemoryCell * ManageAst				(const MemoryCellAST &, const MemoryCell &);
		virtual MemoryCell * ManageObject			(const MemoryCellObject &, const MemoryCell &);
		virtual MemoryCell * ManageFunction			(const MemoryCellFunction &, const MemoryCell &);
		virtual MemoryCell * ManageLibFunction		(const MemoryCellLibFunction &, const MemoryCell &);
		virtual MemoryCell * ManageNativeResource	(const MemoryCellNativeResource &, const MemoryCell &);
	
	private:
		
		
		template<enum MemoryCell::MemoryCellType T, class C>
		MemoryCell * Equality(const C & mc1, const MemoryCell & mc2); 

	};
	


	template<enum MemoryCell::MemoryCellType T, class C>
	
	inline  MemoryCell * Equality(const C & mc1, const MemoryCell & mc2){
		MemoryCellBool * boolmc = SINEWCLASS(MemoryCellBool, (false));

		if (mc2.Type() == T)
			boolmc->SetValue(mc1.GetValue() == static_cast<const C &>(mc2).GetValue());
		
		else if (mc2.Type() == MemoryCell::BOOL_MCT) 
			boolmc->SetValue(BooleanFormOfMemoryCell(mc1) == BooleanFormOfMemoryCell(mc2));

		return boolmc;
	}

}	//namspace SIN


#endif	//__SIN_EQUALIITY_OPERATOR_H__