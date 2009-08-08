#include "SINFunction.h"


namespace SIN {
	namespace Types {


		//-----------------------------------------------------------------
		
		ASTNode * Function::GetASTNode(void) const 
			{ return node; }
		

		//-----------------------------------------------------------------

		const String &  Function::Name(void) const
			{ return node->Name(); }
		
		
		void Function::SetASTNode(ASTNode * _node)
			{ node = _node; }
	
	}	//namespace Types

	
	//-----------------------------------------------------------------

	String const to_string(Types::Function const & val)
		{ return val.Name(); }


	//-----------------------------------------------------------------

	String const to_string(Types::Function const * val)
		{ return val->Name(); }
	

}	//namespace SIN