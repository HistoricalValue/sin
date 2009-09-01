
#include "SINASTNodes.h"
#include "SINASTVisitor.h"
#include "SINAssert.h"
#include "SINAlloc.h"

//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(NAME, TYPE)					\
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
	unsigned long int NAME##ASTNode::Type(void) const {						\
		return TYPE;														\
	}																		\



//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_NODE_DEFS(NAME)									\
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(NAME, 0x0ul)						\



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
	unsigned long int NAME##ASTNode::Type(void) const {										\
		return 0;																			\
	}																						\


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
	unsigned long int NAME##ASTNode::Type(void) const {										\
		return 0;																			\
	}																						\



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
	unsigned long int OPNAME##ASTNode::Type(void) const {			\
		return 0x0ul;												\
	}																\



namespace SIN{

	SINASTNODE_DEFAULT_NODE_DEFS(SinCode		)
	SINASTNODE_DEFAULT_NODE_DEFS(Assign			)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(Block			, SINASTNODES_BLOCK_TYPE          )
	SINASTNODE_DEFAULT_NODE_DEFS(NormalCall		)
	SINASTNODE_DEFAULT_NODE_DEFS(MethodCall		)
	SINASTNODE_DEFAULT_NODE_DEFS(FuncdefCall	)
	SINASTNODE_DEFAULT_NODE_DEFS(ActualArguments)
	SINASTNODE_DEFAULT_NODE_DEFS(ExpressionList	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(Function			, SINASTNODES_FUNCTION_TYPE       	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(LamdaFunction	, SINASTNODES_FUNCTION_TYPE		  	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(FormalArguments	, SINASTNODES_FORMALARGUMENTS_TYPE	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(ID				, SINASTNODES_ID_TYPE             	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(LocalID			, SINASTNODES_LOCALID_TYPE        	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(GlobalID			, SINASTNODES_GLOBALID_TYPE       	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(If				, SINASTNODES_IF_TYPE				)	
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(IfElse			, SINASTNODES_IFELSE_TYPE			)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(For				, SINASTNODES_FOR_TYPE				)
	SINASTNODE_DEFAULT_NODE_DEFS(ForPreamble	)
	SINASTNODE_DEFAULT_NODE_DEFS(ForAddendum	)
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(While			, SINASTNODES_WHILE_TYPE			)
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
	SINASTNODE_DEFAULT_NODE_DEFS_WITH_TYPE(ObjectMember     , SINASTNODES_OBJECTMEMBER_TYPE    )
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
