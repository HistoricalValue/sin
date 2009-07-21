#ifndef __SIN_AST_NODE_H__
#define __SIN_AST_NODE_H__

#include <string>
#include "Common.h"
#include "SINTypes.h"
#include "SINASTCommon.h"
#include "SINTreeNode.h"
#include "SINString.h"
#include "SINNamer.h"

namespace SIN {

	// Visitors' forward declarations
    class ASTVisitor;
	class ASTTreeVisualisationVisitor;


	#define SINASTNODE_OPNODE_DECL(NAME, OPNAME)            \
    class NAME##ASTNode : public OpASTNode<OP_##OPNAME> {   \
    public:                                                 \
        NAME##ASTNode(void);                                \
        ~NAME##ASTNode(void);                               \
        void Accept(ASTVisitor *);                          \
		NAME##ASTNode *Clone(void) const;					\
    }



	//-----------------------------------------------------------------------

	template <typename _ValueT>
	class ValueHolder {
	public:
        typedef _ValueT Value;
		//--------------------------
		ValueHolder(void) {}
		ValueHolder(const Value & val) : value(val) {}
        ValueHolder(const ValueHolder<_ValueT> &other): value(other.value) { }
		~ValueHolder() {}

		//-------------------------
		void SetValue(const Value &v) { value = v; }
        void operator =(const Value &_value) { SetValue(_value); }

		const Value &GetValue(void) const { return value; }
		const String GetValueStr (void) const { return string_cast(value); }

	private:
		Value value;
	};




	//-----------------------------------------------------------------------

	class ASTNode : public TreeNode {
	public :
		typedef unsigned long int ID_t;

		//Constructor and destructor 
		ASTNode(void);
        ASTNode(String const &name);
		virtual ~ASTNode(void);

        virtual String const &Name(void) const;
		ID_t const& ID(void) const;

		virtual void Accept(ASTVisitor *) const;
		virtual void Accept(ASTTreeVisualisationVisitor *) const;

		virtual ASTNode *Clone(void) const;
    private:
        String const name;
		ID_t id;
	}; // class ASTNode
	extern String const string_cast(SIN::ASTNode const        &_val);

	class ASTNodeFactory {
		Namer namer;
		ASTNode::ID_t next_id;

		ASTNodeFactory(void);
		ASTNodeFactory(ASTNodeFactory const&);
		~ASTNodeFactory(void);

		static ASTNodeFactory* singleton;
		static bool singleton_created;
	public:
		static void SingletonCreate(void);
		static bool SingletonCreated(void);
		static void SingletonDestroy(void);
		static ASTNodeFactory& SingletonInstance(void);

		// convenience methods
		static String const NextName(void);
		static ASTNode::ID_t const NextID(void);

		// normal methods
		String const iNextName(void);
		ASTNode::ID_t const iNextID(void);
	}; // class ASTNodeFactory

	//-----------------------------------------------------------------------	
	
	template <enum ConstNodeType _ValueType, typename _ValueT>
	class ConstASTNode : public ASTNode, public ValueHolder<_ValueT> {
	public :
        typedef typename ValueHolder<_ValueT>::Value Value;
        ConstASTNode(Value const &_value): ASTNode(string_cast(_value)), ValueHolder<_ValueT>(_value) { }
		ConstASTNode(String const &_name, Value const &_value): ASTNode(_name), ValueHolder<_ValueT>(_value) { }
        virtual void Accept(ASTVisitor *) = 0;
		virtual ConstASTNode *Clone(void) const = 0;
	};



	//-----------------------------------------------------------------------

    class NumberASTNode : public ConstASTNode<CONST_NUMBER, Number_t> {
    public:
        NumberASTNode(Number_t const &_value = 0);
        virtual void Accept(ASTVisitor *);
		virtual NumberASTNode *Clone(void) const;
    }; // class NumberASTNode



	//-----------------------------------------------------------------------
    
	class StringASTNode : public ConstASTNode<CONST_STRING, String_t> {
    public:
        StringASTNode(String_t const &_value = "");
        virtual void Accept(ASTVisitor *);
		virtual StringASTNode *Clone(void) const;
    }; // class StringASTNode



	//-----------------------------------------------------------------------
    
	class NilASTNode : public ConstASTNode<CONST_NIL, Nil_t> {
    public:
        NilASTNode(void);
        virtual void Accept(ASTVisitor *);
		virtual NilASTNode *Clone(void) const;
    }; // class NilASTNode



	//-----------------------------------------------------------------------

    class TrueASTNode : public ConstASTNode<CONST_TRUE, Boolean_t> {
    public:
        TrueASTNode(void);
        virtual void Accept(ASTVisitor *);
		virtual TrueASTNode *Clone(void) const;
    }; // class TrueASTNode



	//-----------------------------------------------------------------------

    class FalseASTNode : public ConstASTNode<CONST_FALSE, Boolean_t> {
    public:
        FalseASTNode(void);
        virtual void Accept(ASTVisitor *);
		virtual FalseASTNode *Clone(void) const;
    }; // class FalseASTNode


    
	//-----------------------------------------------------------------------
    
	template <enum SIN::OpValueType>
    class OpASTNode : public ASTNode {
    public:
        OpASTNode(String const &_name): ASTNode(_name) { }
        virtual ~OpASTNode(void) { }
        virtual void Accept(ASTVisitor *) = 0;
		virtual OpASTNode *Clone(void) const = 0;
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
    SINASTNODE_OPNODE_DECL(And,AND);
    SINASTNODE_OPNODE_DECL(Not,NOT);


} // namespace SIN


#endif //__SIN_AST_NODE_H__
