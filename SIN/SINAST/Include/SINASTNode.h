#ifndef __SIN_AST_NODE_H__
#define __SIN_AST_NODE_H__

#include <string>
#include "Common.h"
#include "SINASTCommon.h"
#include "SINStrictTreeNode.h"
#include "SINString.h"
#include "SINNamer.h"
#include "SINSymbolTable.h"


//using namespace SIN::Types;

namespace SIN {

	// Visitors' forward declarations
    class ASTVisitor;
	class ASTTreeVisualisationVisitor;


	///***************	ValueHolder	***************
	
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
		const String GetValueStr (void) const { return to_string(value); }

	private:
		Value value;
	};




	///***************	ASTNode	***************

	class ASTNode : public StrictTreeNode {
	public :
		typedef unsigned long int ID_t;

		//Constructor and destructor 
		ASTNode(void);
        ASTNode(String const &name, String const & fileName = "",const int line = 0);
		ASTNode(ASTNode const&);
		virtual ~ASTNode(void);

        virtual String const &Name(void) const;
		ID_t const& ID(void) const;

		virtual SymbolTable *GlobalEnv (void);
		virtual SymbolTable *LocalEnv (void);

		virtual void Accept(ASTVisitor *) = 0;
		virtual void Accept(ASTTreeVisualisationVisitor *);

		virtual ASTNode *Clone(void) const;
    private:
        String const	name;
		String const	assosciatedFileName;
		const int		associatedFileLine;
		ID_t id;
	
	}; // class ASTNode
	extern String const to_string(SIN::ASTNode const &_val);



	///***************	ASTNodeFactory	***************
	
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
        
		ConstASTNode(	Value const &_value,
						String const & fileName = "",
						const int line = 0) : 
			ASTNode(to_string(_value), fileName, line), 
			ValueHolder<_ValueT>(_value) 
		{ 
		}

		ConstASTNode(	String const &_name, 
						Value const &_value,
						String const & fileName = "",
						const int line = 0) : 
			ASTNode(_name, fileName, line), 
			ValueHolder<_ValueT>(_value) 
		{ 
		}

        virtual void Accept(ASTVisitor *) = 0;
		virtual ConstASTNode *Clone(void) const = 0;
		virtual SymbolTable *GlobalEnv (void) = 0;
		virtual SymbolTable *LocalEnv (void) = 0;
	};


} // namespace SIN


#endif //__SIN_AST_NODE_H__
