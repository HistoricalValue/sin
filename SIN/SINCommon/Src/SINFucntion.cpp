#include "SINFunction.h"


namespace SIN {
	namespace Types {


		//-----------------------------------------------------------------
		
		ASTNode * Function::GetASTNode(void) 
			{ return node; }
		

		//-----------------------------------------------------------------

		const String &  Function::Name(void) const
			{ return node->Name(); }
		
		
		void Function::SetASTNode(const ASTNode * _node)
			{ node = const_cast<ASTNode *>(_node); }
	
	}	//namespace Types

	
	//-----------------------------------------------------------------

	String const to_string(SIN::Types::Function const & val)
		{ return val.Name(); }


	//-----------------------------------------------------------------

	String const to_string(SIN::Types::Function const * val)
		{ return val->Name(); }
	

}	//namespace SIN