#include <assert.h>
#include "SINConstants.h"
#include "SINASTNode.h"
#include "SINASTVisitor.h"
#include "SINASTTreeVisualisationVisitor.h"
#include "SINAssert.h"


//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_CONSTNODE_DEFS(NAME, TYPE, VALTYPE)                              \
    NAME##ASTNode::NAME##ASTNode(VALTYPE const &_val): ConstASTNode<TYPE, VALTYPE>(_val) {  \
    }                                                                                       \
    void NAME##ASTNode::Accept(ASTVisitor *_visitor_p) {                                    \
		assert(_visitor_p);																	\
        _visitor_p->Visit(*this);															\
    }



//-------------------------------------------------------------------------------------------------	

#define SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS(NAME, TYPE, VALTYPE, VALUE)             \
    NAME##ASTNode::NAME##ASTNode(void): ConstASTNode<TYPE, VALTYPE>(VALUE) {                \
    }                                                                                       \
    void NAME##ASTNode::Accept(ASTVisitor *_visitor_p) {                                    \
		assert (_visitor_p);																\
        _visitor_p->Visit(*this);															\
    }



//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_OPNODE_DEFS(OPNAME, OPTYPE)          \
    OPNAME##ASTNode::OPNAME##ASTNode(void):                     \
        OpASTNode<OPTYPE>()                                     \
    {                                                           \
    }                                                           \
    OPNAME##ASTNode::~OPNAME##ASTNode(void) {                   \
    }                                                           \
    void OPNAME##ASTNode::Accept(ASTVisitor *_visitor_p) {      \
		assert (_visitor_p);									\
        _visitor_p->Visit(*this);								\
    }



namespace SIN {

    ///--------- SIN AST ---------
	
	//---------------------------------------------------
	
	ASTNode::ASTNode(void):
		name(ASTNodeFactory::NextName()),
		id(ASTNodeFactory::NextID())
	{}


	//---------------------------------------------------

    ASTNode::ASTNode(String const &_name): name(_name) {}


	//---------------------------------------------------

    ASTNode::~ASTNode(void) {}


	//---------------------------------------------------

    String const &ASTNode::Name(void) const {
        return name;
    }


	//---------------------------------------------------

	ASTNode::ID_t const& ASTNode::ID(void) const {
		return id;
	}


	//---------------------------------------------------

    void ASTNode::Accept(ASTVisitor *_v) const {
        SINASSERT(_v);
        _v->Visit(*this);
    }
	
	
	//---------------------------------------------------

	void ASTNode::Accept(ASTTreeVisualisationVisitor *_v) const {
		SINASSERT(_v);
		_v->Visit(*this);
		_v->IncreaseIndentationLevel();
		for (size_t i = 0; i < NumberOfChildren(); ++i) {
			TreeNode* _child = (*this)[i];
			SINASSERT(dynamic_cast<ASTNode*>(_child) != 0x00);
			ASTNode* child = static_cast<ASTNode*>(_child);
			child->Accept(_v);
		}
		_v->DecreaseIndentationLevel();
	}
	

	//---------------------------------------------------

	String const string_cast(ASTNode const &_node) {
		return string_cast(_node.Name());
	}

	///--------- AST Node Factory ----------
	ASTNodeFactory::ASTNodeFactory(void): namer("ASTNode-"), next_id(0x00ul) {
	}


	//---------------------------------------------------

	ASTNodeFactory::ASTNodeFactory(ASTNodeFactory const& _other): namer(""), next_id(0xbee1cebul) {
		SINASSERT(!"Copy constructor called for singleton class SIN::ASTNodeFactory");
		throw String("Copy constructor called for singleton class SIN::ASTNodeFactory");
	}
	
	
	//---------------------------------------------------
	ASTNodeFactory::~ASTNodeFactory(void) {}
	
	
	//---------------------------------------------------
	// singleton related
	ASTNodeFactory* ASTNodeFactory::singleton = 0x00;
	
	
	//---------------------------------------------------
	
	bool ASTNodeFactory::singleton_created = false;
	
	
	//---------------------------------------------------
	
	void ASTNodeFactory::SingletonCreate(void) {
		SINASSERT(!singleton_created);
		if ((singleton = new ASTNodeFactory) != 0x00)
			singleton_created = true;
	}
	
	
	//---------------------------------------------------
	
	bool ASTNodeFactory::SingletonCreated(void) {
		return singleton_created;
	}
	
	
	//---------------------------------------------------

	void ASTNodeFactory::SingletonDestroy(void) {
		SINASSERT(singleton_created);
		delete singleton;
		singleton_created = false;
	}
	
	
	//---------------------------------------------------

	ASTNodeFactory& ASTNodeFactory::SingletonInstance(void) {
		SINASSERT(singleton_created);
		return *(singleton_created ? singleton : 0x00);
	}
	
	
	//---------------------------------------------------
	// convenience methods
	String const ASTNodeFactory::NextName(void) {
		return SingletonInstance().iNextName();
	}
	
	
	//---------------------------------------------------
	
	ASTNode::ID_t const ASTNodeFactory::NextID(void) {
		return SingletonInstance().iNextID();
	}
	
	
	//---------------------------------------------------
	// instance factory methods
	String const ASTNodeFactory::iNextName(void) {
		return namer++;
	}


	//---------------------------------------------------

	ASTNode::ID_t const ASTNodeFactory::iNextID(void) {
		return next_id++;
	}

	///--------- ConstNodes ---------
    SINASTNODE_DEFAULT_CONSTNODE_DEFS(           Number, CONST_NUMBER, Number_t         )
    SINASTNODE_DEFAULT_CONSTNODE_DEFS(           String, CONST_STRING, String_t         )
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( Nil   , CONST_NIL   , Nil_t    , NIL   )
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( True  , CONST_TRUE  , Boolean_t, TRUE  )
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( False , CONST_FALSE , Boolean_t, FALSE )



    ///--------- OpNodes -----------
    SINASTNODE_DEFAULT_OPNODE_DEFS(Add,OP_ADD)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Sub,OP_SUB)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Mul,OP_MUL)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Div,OP_DIV)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Mod,OP_MOD)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Lt ,OP_LT )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Gt ,OP_GT )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Le ,OP_LE )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Ge ,OP_GE )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Eq ,OP_EQ )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Ne ,OP_NE )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Or ,OP_OR )
    SINASTNODE_DEFAULT_OPNODE_DEFS(And,OP_END)

} // namespace SIN
