#ifndef __SIN_AST_NODE_H__
#define __SIN_AST_NODE_H__

#include <string>
#include "Common.h"
#include "SINCommon.h"
#include "SINASTCommon.h"
#include "SINTreeNode.h"

namespace SIN {

    class ASTVisitor;	//forward declaration


	#define SINASTNODE_OPNODE_DECL(NAME, OPNAME)            \
    class NAME##ASTNode : public OpASTNode<OP_##OPNAME> {   \
    public:                                                 \
        NAME##ASTNode(void);                                \
        ~NAME##ASTNode(void);                               \
        void Accept(ASTVisitor *);                          \
    }



	//-----------------------------------------------------------------------

	template <enum ConstNodeType _ValueType, typename _ValueT>
	class ValueHolder {
	public:
        typedef _ValueT Value;
		//--------------------------
		ValueHolder(void) {}
		ValueHolder(const Value & val) : value(val) {}
        ValueHolder(const ValueHolder<_ValueType, _ValueT> &other): value(other.value) { }
		~ValueHolder() {}

		//-------------------------
		enum ConstNodeType GetType(void) const { return _ValueType; }


		//-------------------------
		void SetValue(const Value &v) { value = v; }
        void operator =(const Value &_value) { SetValue(_value); }

		const Value &GetValue(void) const { return value; }
		const std::string GetValueStr (void) const { return string_cast(value); }

	private:
		Value value;
	};




	//-----------------------------------------------------------------------
	class ASTNode : public TreeNode {
	public :
		
		//Constructor and destructor 
		ASTNode (void) : TreeNode() {}
		virtual ~ASTNode() {}

		virtual void Accept(ASTVisitor *) = 0;
	};



	//-----------------------------------------------------------------------	
	
	template <enum ConstNodeType _ValueType, typename _ValueT>
	class ConstASTNode : public ASTNode, public ValueHolder<_ValueType, _ValueT> {
	public :
        typedef typename ValueHolder<_ValueType, _ValueT>::Value Value;
        ConstASTNode(Value const &_value): ASTNode(), ValueHolder<_ValueType, _ValueT>(_value) { }
        virtual void Accept(ASTVisitor *) = 0;
	};



	//-----------------------------------------------------------------------

    class NumberASTNode : public ConstASTNode<CONST_NUMBER, Number_t> {
    public:
        NumberASTNode(Number_t const &_value);
        virtual void Accept(ASTVisitor *);
    }; // class NumberASTNode



	//-----------------------------------------------------------------------
    
	class StringASTNode : public ConstASTNode<CONST_STRING, String_t> {
    public:
        StringASTNode(String_t const &_value);
        virtual void Accept(ASTVisitor *);
    }; // class StringASTNode



	//-----------------------------------------------------------------------
    
	class NilASTNode : public ConstASTNode<CONST_NIL, Nil_t> {
    public:
        NilASTNode(void);
        virtual void Accept(ASTVisitor *);
    }; // class NilASTNode



	//-----------------------------------------------------------------------

    class TrueASTNode : public ConstASTNode<CONST_TRUE, Boolean_t> {
    public:
        TrueASTNode(void);
        virtual void Accept(ASTVisitor *);
    }; // class TrueASTNode



	//-----------------------------------------------------------------------
    class FalseASTNode : public ConstASTNode<CONST_FALSE, Boolean_t> {
    public:
        FalseASTNode(void);
        virtual void Accept(ASTVisitor *);
    }; // class FalseASTNode


    
	//-----------------------------------------------------------------------
    
	template <enum SIN::OpValueType>
    class OpASTNode : public ASTNode {
    public:
        OpASTNode(void): ASTNode() { }
        virtual ~OpASTNode(void) { }
        virtual void Accept(ASTVisitor *) = 0;
    };
    SINASTNODE_OPNODE_DECL(Add,ADD);
    SINASTNODE_OPNODE_DECL(Sub,SUB);
    SINASTNODE_OPNODE_DECL(Mul,MUL);
    SINASTNODE_OPNODE_DECL(Div,DIV);
    SINASTNODE_OPNODE_DECL(Mod,MOD);
    SINASTNODE_OPNODE_DECL(Lt ,LT );
    SINASTNODE_OPNODE_DECL(Gt ,GT );
    SINASTNODE_OPNODE_DECL(Le ,LE );
    SINASTNODE_OPNODE_DECL(Ge ,GE );
    SINASTNODE_OPNODE_DECL(Eq ,EQ );
    SINASTNODE_OPNODE_DECL(Ne ,NE );
    SINASTNODE_OPNODE_DECL(Or ,OR );
    SINASTNODE_OPNODE_DECL(And,END);



} // namespace SIN


#endif //__SIN_AST_NODE_H__
