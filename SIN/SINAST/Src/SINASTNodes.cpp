
#include "SINASTNodes.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"
#include "SINAlloc.h"

//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_NODE_DEFS(NAME)									\
    NAME##ASTNode::NAME##ASTNode(void):	ASTNode() {}						\
	NAME##ASTNode::NAME##ASTNode(	String const &_name,					\
									String const & fileName,				\
									const int line)							\
									: ASTNode(_name, fileName, line) {}		\
	NAME##ASTNode::~NAME##ASTNode(void) {}									\
	void NAME##ASTNode::Accept(ASTVisitor *_v) {							\
        SINASSERT(_v);														\
        _v->Visit(*this);													\
    }																		\
	NAME##ASTNode *NAME##ASTNode::Clone(void) const {						\
		return SINEWCLASS(NAME##ASTNode, (*this));							\
	}																		\
	SymbolTable *NAME##ASTNode::LocalEnv(void) {							\
		return static_cast<ASTNode*>(GetParent())->LocalEnv();				\
	}																		\
	SymbolTable *NAME##ASTNode::GlobalEnv(void) {							\
		return static_cast<ASTNode*>(GetParent())->GlobalEnv();				\
	}


//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_CONSTNODE_DEFS(NAME, TYPE, VALTYPE)                              \
    NAME##ASTNode::NAME##ASTNode(	VALTYPE const &_val,									\
									String const & fileName,								\
									const int line):										\
		ConstASTNode<TYPE, VALTYPE>(_val, fileName, line)									\
	{																						\
	}																						\
    void NAME##ASTNode::Accept(ASTVisitor *_visitor_p) {                                    \
		assert(_visitor_p);																	\
        _visitor_p->Visit(*this);															\
    }																						\
    NAME##ASTNode *NAME##ASTNode::Clone(void) const {	                                    \
		return SINEWCLASS(NAME##ASTNode, (*this));											\
	}																						\
	SymbolTable *NAME##ASTNode::LocalEnv(void) {											\
		return static_cast<ASTNode*>(GetParent())->LocalEnv();								\
	}																						\
	SymbolTable *NAME##ASTNode::GlobalEnv(void) {											\
		return static_cast<ASTNode*>(GetParent())->GlobalEnv();								\
	}

//-------------------------------------------------------------------------------------------------	

#define SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS(NAME, TYPE, VALTYPE, VALUE)             \
	NAME##ASTNode::NAME##ASTNode(String const & fileName, const int line)	:				\
			ConstASTNode<TYPE, VALTYPE>(#VALUE, VALUE, fileName, line) {					\
    }                                                                                       \
    void NAME##ASTNode::Accept(ASTVisitor *_visitor_p) {                                    \
		assert (_visitor_p);																\
        _visitor_p->Visit(*this);															\
    }																						\
    NAME##ASTNode *NAME##ASTNode::Clone(void) const {	                                    \
		return SINEWCLASS(NAME##ASTNode, (*this));											\
	}																						\
	SymbolTable *NAME##ASTNode::LocalEnv(void) {											\
		return static_cast<ASTNode*>(GetParent())->LocalEnv();								\
	}																						\
	SymbolTable *NAME##ASTNode::GlobalEnv(void) {											\
		return static_cast<ASTNode*>(GetParent())->GlobalEnv();								\
	}



//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_OPNODE_DEFS(OPNAME, OPTYPE)          	\
	OPNAME##ASTNode::OPNAME##ASTNode(	String const & fileName,	\
										const int line):			\
		OpASTNode<OPTYPE>(#OPNAME, fileName, line)					\
	{																\
	}																\
																	\
	OPNAME##ASTNode::~OPNAME##ASTNode(void) {                   	\
    }                                                           	\
    void OPNAME##ASTNode::Accept(ASTVisitor *_visitor_p) {      	\
		assert (_visitor_p);										\
        _visitor_p->Visit(*this);									\
    }																\
    OPNAME##ASTNode *OPNAME##ASTNode::Clone(void) const {	    	\
		return SINEWCLASS(OPNAME##ASTNode, (*this));				\
	}																\
	SymbolTable *OPNAME##ASTNode::LocalEnv(void) {					\
		return static_cast<ASTNode*>(GetParent())->LocalEnv();		\
	}																\
	SymbolTable *OPNAME##ASTNode::GlobalEnv(void) {					\
		return static_cast<ASTNode*>(GetParent())->GlobalEnv();		\
	}



namespace SIN{

	//------ SinCodeASTNode ------------------------------
	//-----------------------------------------------------------------

	SinCodeASTNode::SinCodeASTNode(void) : ASTNode() {}


	//-----------------------------------------------------------------

	SinCodeASTNode::SinCodeASTNode(	String const &_name, 
									String const & fileName,
									const int line) : 
		ASTNode(_name, fileName, line) {}


	//-----------------------------------------------------------------

	SinCodeASTNode::~SinCodeASTNode(void) {}


	//-----------------------------------------------------------------

	void SinCodeASTNode::Accept(ASTVisitor *_v) {
        SINASSERT(_v);
        _v->Visit(*this);
    }		


	//-----------------------------------------------------------------

	SinCodeASTNode *SinCodeASTNode::Clone(void) const 
		{	return SINEWCLASS(SinCodeASTNode, (*this));	}


	//-----------------------------------------------------------------

	SymbolTable *SinCodeASTNode::GlobalEnv(void) 
		{	return &symTable;	}


	//-----------------------------------------------------------------

	SymbolTable *SinCodeASTNode::LocalEnv(void) 
		{	return &symTable;	}


	//------ BlockASTNode ------------------------------
	//-----------------------------------------------------------------

	BlockASTNode::BlockASTNode(void) : ASTNode() {}


	//-----------------------------------------------------------------

	BlockASTNode::BlockASTNode(	String const &_name, 
								String const & fileName, 
								const int line) : 
		ASTNode(_name, fileName, line) 
	{
	}


	//-----------------------------------------------------------------

	BlockASTNode::~BlockASTNode(void) {}


	//-----------------------------------------------------------------

	void BlockASTNode::Accept(ASTVisitor *_v) {
        SINASSERT(_v);
        _v->Visit(*this);
    }		


	//-----------------------------------------------------------------

	BlockASTNode *BlockASTNode::Clone(void) const 
		{	return SINEWCLASS(BlockASTNode, (*this));	}

	//-----------------------------------------------------------------

	SymbolTable *BlockASTNode::GlobalEnv(void) 
		{	return static_cast<ASTNode*>(GetParent())->GlobalEnv();	}

	//-----------------------------------------------------------------

	SymbolTable *BlockASTNode::LocalEnv(void) 
		{	return &symTable;	}


//	SINASTNODE_DEFAULT_NODE_DEFS(SinCode		)
	SINASTNODE_DEFAULT_NODE_DEFS(Assign			)
//	SINASTNODE_DEFAULT_NODE_DEFS(Block			)
	SINASTNODE_DEFAULT_NODE_DEFS(NormalCall		)
	SINASTNODE_DEFAULT_NODE_DEFS(MethodCall		)
	SINASTNODE_DEFAULT_NODE_DEFS(FuncdefCall	)
	SINASTNODE_DEFAULT_NODE_DEFS(ActualArguments)
	SINASTNODE_DEFAULT_NODE_DEFS(ExpressionList	)
	SINASTNODE_DEFAULT_NODE_DEFS(Function		)
	SINASTNODE_DEFAULT_NODE_DEFS(LamdaFunction	)
	SINASTNODE_DEFAULT_NODE_DEFS(FormalArguments)
	SINASTNODE_DEFAULT_NODE_DEFS(ID				)
	SINASTNODE_DEFAULT_NODE_DEFS(LocalID		)
	SINASTNODE_DEFAULT_NODE_DEFS(GlobalID		)
	SINASTNODE_DEFAULT_NODE_DEFS(If				)
	SINASTNODE_DEFAULT_NODE_DEFS(IfElse			)
	SINASTNODE_DEFAULT_NODE_DEFS(For			)
	SINASTNODE_DEFAULT_NODE_DEFS(ForPreamble	)
	SINASTNODE_DEFAULT_NODE_DEFS(ForAddendum	)
	SINASTNODE_DEFAULT_NODE_DEFS(While			)
	SINASTNODE_DEFAULT_NODE_DEFS(PreIncr		)
	SINASTNODE_DEFAULT_NODE_DEFS(PostIncr		)
	SINASTNODE_DEFAULT_NODE_DEFS(PreDecr		)
	SINASTNODE_DEFAULT_NODE_DEFS(PostDecr		)
	SINASTNODE_DEFAULT_NODE_DEFS(UnaryNot		)
	SINASTNODE_DEFAULT_NODE_DEFS(UnaryMin		)
	SINASTNODE_DEFAULT_NODE_DEFS(Continue		)
	SINASTNODE_DEFAULT_NODE_DEFS(Break			)
	SINASTNODE_DEFAULT_NODE_DEFS(Object			)
	SINASTNODE_DEFAULT_NODE_DEFS(EmptyObject	)
	SINASTNODE_DEFAULT_NODE_DEFS(UnindexedMember)
	SINASTNODE_DEFAULT_NODE_DEFS(IndexedMember	)
	SINASTNODE_DEFAULT_NODE_DEFS(ObjectMember	)
	SINASTNODE_DEFAULT_NODE_DEFS(ObjectIndex	)
	SINASTNODE_DEFAULT_NODE_DEFS(CallMember		)
	SINASTNODE_DEFAULT_NODE_DEFS(CallIndex		)
	SINASTNODE_DEFAULT_NODE_DEFS(Return			)
	SINASTNODE_DEFAULT_NODE_DEFS(Semicolon		)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaParse		)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaPreserve	)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaEvaluate	)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaUnparse	)
	SINASTNODE_DEFAULT_NODE_DEFS(MetaParseString)





	///--------- ConstNodes ---------
    SINASTNODE_DEFAULT_CONSTNODE_DEFS(           Number, CONST_NUMBER, Types::Number_t			)
    SINASTNODE_DEFAULT_CONSTNODE_DEFS(           String, CONST_STRING, Types::String_t			)
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( Nil   , CONST_NIL   , Types::Nil_t    , NIL	)
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( True  , CONST_TRUE  , Types::Boolean_t, TRUE	)
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( False , CONST_FALSE , Types::Boolean_t, FALSE	)



    ///--------- OpNodes -----------
    SINASTNODE_DEFAULT_OPNODE_DEFS(Add, OP_ADD)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Sub, OP_SUB)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Mul, OP_MUL)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Div, OP_DIV)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Mod, OP_MOD)
    SINASTNODE_DEFAULT_OPNODE_DEFS(Lt , OP_LT )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Gt , OP_GT )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Le , OP_LE )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Ge , OP_GE )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Eq , OP_EQ )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Ne , OP_NE )
    SINASTNODE_DEFAULT_OPNODE_DEFS(Or , OP_OR )
    SINASTNODE_DEFAULT_OPNODE_DEFS(And, OP_AND)
	SINASTNODE_DEFAULT_OPNODE_DEFS(Not, OP_NOT)

} // namespace SIN
