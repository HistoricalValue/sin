#ifndef __SIN_AST_NODE_H__
#define __SIN_AST_NODE_H__

#include <string>
#include "Common.h"
#include "SINTreeNode.h"

class SINASTVisitor;	//forward declaration

namespace SIN {


	enum ConstValueType {
		CONST_NUMBER = 0,
		CONST_STRING,
		CONST_NIL,
		CONST_TRUE,
		CONST_FALSE
	};



	template <unsigned TypeValue, class Value>
	class ValueHolder {
	public:
		//--------------------------
		ValueHolder(void) {}
		ValueHolder(const Value & val) : value(val) {}
		~ValueHolder() {}

		//-------------------------
		enum { Type = TypeValue } ;
		virtual unsigned GetType () { return TypeValue; }


		//-------------------------
		void SetValue(const Value & v) { value = v; }
		const Value & GetValue() const { return value; }
		const std::string GetValueStr (void) const { return string_cast<Value>(value)}

	private:
		Value value;
	};





	///--------------------------------------------
	class ASTNode : public TreeNode {
	public :
		
		//Constructor and destructor 
		ASTNode (void) : TreeNode() {}
		virtual ~ASTNode() {}

		virtual void Accept(SINASTVisitor *) = 0;
		
	};




	///--------------------------------------------
	template<unsigned TypeId, unsigned TypeValue, class Value>
	class LeafASTNode : public ASTNode, public ValueHolder<TypeValue, Value> {
	public :

		//-------------------------
		enum { Type = TypeId } ;
		virtual unsigned GetType () { return Type; }


		//******************************************************************
		// Visitor support
		//
		virtual void Accept(SINASTVisitor *);
	};


} // namespace SIN


#endif //__SIN_AST_NODE_H__