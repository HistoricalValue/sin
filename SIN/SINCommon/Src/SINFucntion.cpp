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


		//-----------------------------------------------------------------

		bool Function::operator== (const Function & f) const 
			{ return *node == *f.node; }
		

		//-----------------------------------------------------------------

		bool Function::operator!= (const Function &f) const
			{ return *node != *f.node; }
	
	}	//namespace Types

	
	//-----------------------------------------------------------------

	String const to_string(Types::Function const & val) { 
		return	to_string("Program function ( name: ")				+ 
				val.Name()											+
				to_string(" , file: ")								+
				val.GetASTNode()->AssociatedFileName()				+
				to_string(" , line: ")								+
				to_string(val.GetASTNode()->AssociatedFileLine())	+
				to_string(" )");
	}


	//-----------------------------------------------------------------

	String const to_string(Types::Function const * val)  { 
		return	to_string("Program function ( name: ")				+ 
				val->Name()											+
				to_string(" , file: ")								+
				val->GetASTNode()->AssociatedFileName()				+
				to_string(" , line: ")								+
				to_string(val->GetASTNode()->AssociatedFileLine())	+
				to_string(" )");
	}
	

}	//namespace SIN
