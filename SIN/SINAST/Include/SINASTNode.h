#ifndef __SIN_AST_NODE_H__
#define __SIN_AST_NODE_H__

#include <string>
#include "Common.h"
#include "SINTreeNode.h"

class SINASTVisitor;	//forward declaration

namespace SIN {

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
	template<unsigned TypeId, unsigned TypeValue, class Value>
	class ASTNode : public TreeNode, public ValueHolder<TypeValue, Value> {
	public :

		//-------------------------
		enum { Type = TypeId } ;
		virtual unsigned GetType () { return Type; }

		ASTNode (void) : TreeNode() {}
		virtual ~ ASTNode(){}

		//******************************************************************
		// Visitor support
		//
		virtual void Accept(SINASTVisitor *);
	};




	/*///--------------------------------------------
	class ASTNode : public TreeNode {
	public :
		
		//Constructor and destructor 
		ASTNode (void) : TreeNode() {}
		virtual ~ASTNode() {}

		virtual void Accept(SINASTVisitor *) = 0;
		
	};*/




	///--------------------------------------------
	/*template<unsigned TypeId, unsigned TypeValue, class Value>
	class LeafASTNode : public ASTNode, public ValueHolder<TypeValue, Value> {
	public :

		//-------------------------
		enum { Type = TypeId } ;
		virtual unsigned GetType () { return Type; }


		//******************************************************************
		// Visitor support
		//
		virtual void Accept(SINASTVisitor *);
	};*/


	



} // namespace SIN


#endif //__SIN_AST_NODE_H__