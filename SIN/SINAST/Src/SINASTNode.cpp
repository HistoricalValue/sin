#include "SINASTNode.h"
#include "SINASTVisitor.h"


//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_CONSTNODE_DEFS(NAME, TYPE, VALTYPE)                              \
    NAME##ASTNode::NAME##ASTNode(VALTYPE const &_val): ConstASTNode<TYPE, VALTYPE>(_val) {  \
    }                                                                                       \
    void NAME##ASTNode::Accept(ASTVisitor *_visitor_p) {                                    \
        static_cast<ASTVisitor &>(*_visitor_p).Visit(*this);                                \
    }



//-------------------------------------------------------------------------------------------------	

#define SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS(NAME, TYPE, VALTYPE, VALUE)             \
    NAME##ASTNode::NAME##ASTNode(void): ConstASTNode<TYPE, VALTYPE>(VALUE) {                \
    }                                                                                       \
    void NAME##ASTNode::Accept(ASTVisitor *_visitor_p) {                                    \
        static_cast<ASTVisitor &>(*_visitor_p).Visit(*this);                                \
    }



//-------------------------------------------------------------------------------------------------

#define SINASTNODE_DEFAULT_OPNODE_DEFS(OPNAME, OPTYPE)          \
    OPNAME##ASTNode::OPNAME##ASTNode(void):                     \
        OpASTNode()                                             \
    {                                                           \
    }                                                           \
    OPNAME##ASTNode::~OPNAME##ASTNode(void) {                   \
    }                                                           \
    void OPNAME##ASTNode::Accept(ASTVisitor *_visitor_p) {      \
        static_cast<ASTVisitor &>(*_visitor_p).Visit(*this);    \
    }



namespace SIN {

	
	///--------- ConstNodes ---------
    SINASTNODE_DEFAULT_CONSTNODE_DEFS(           Number, CONST_NUMBER, Number_t         );
    SINASTNODE_DEFAULT_CONSTNODE_DEFS(           String, CONST_STRING, String_t         );
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( Nil   , CONST_NIL   , Nil_t    , NIL   );
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( True  , CONST_TRUE  , Boolean_t, TRUE  );
    SINASTNODE_DEFAULT_VALUELESS_CONSTNODE_DEFS( False , CONST_FALSE , Boolean_t, FALSE );



    ///--------- OpNodes -----------
    SINASTNODE_DEFAULT_OPNODE_DEFS(Add,OP_ADD);
    SINASTNODE_DEFAULT_OPNODE_DEFS(Sub,OP_SUB);
    SINASTNODE_DEFAULT_OPNODE_DEFS(Mul,OP_MUL);
    SINASTNODE_DEFAULT_OPNODE_DEFS(Div,OP_DIV);
    SINASTNODE_DEFAULT_OPNODE_DEFS(Mod,OP_MOD);
    SINASTNODE_DEFAULT_OPNODE_DEFS(Lt ,OP_LT );
    SINASTNODE_DEFAULT_OPNODE_DEFS(Gt ,OP_GT );
    SINASTNODE_DEFAULT_OPNODE_DEFS(Le ,OP_LE );
    SINASTNODE_DEFAULT_OPNODE_DEFS(Ge ,OP_GE );
    SINASTNODE_DEFAULT_OPNODE_DEFS(Eq ,OP_EQ );
    SINASTNODE_DEFAULT_OPNODE_DEFS(Ne ,OP_NE );
    SINASTNODE_DEFAULT_OPNODE_DEFS(Or ,OP_OR );
    SINASTNODE_DEFAULT_OPNODE_DEFS(And,OP_END);

} // namespace SIN
