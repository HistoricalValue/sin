#include "SINASTUnparseTreeVisitor.h"

#include <stdio.h>
#include <iostream>

#include "Common.h"
#include "SINAssert.h"
#include "SINASTNodes.h"
#include "SINTreeNode.h"
#include "SINConstants.h"

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(NODENAME)								\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {								\
		Visit(static_cast<ASTNode &>(_node));													\
	}

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(NODENAME, START_S, END_SYM)	\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {								\
		unparseString +=  to_string(START_S) + _node.Name() + to_string(END_SYM);				\
	}

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(NODENAME, START_S, END_SYM)	\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {								\
		SINASSERT(_node.NumberOfChildren() == 1);												\
		unparseString += to_string(START_S);													\
		static_cast<ASTNode &>(*_node.begin()).Accept(this);									\
		unparseString += to_string(END_SYM);													\
	}

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(NODENAME, SYMBOL)				\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {								\
		SINASSERT(_node.NumberOfChildren() == 2);												\
		ASTNode::iterator kid = _node.begin();													\
		static_cast<ASTNode &>(*kid++).Accept(this);											\
		unparseString +=  to_string(SYMBOL);													\
		static_cast<ASTNode &>(*kid++).Accept(this);											\
	}

//-------------------------------------------------------------------------------------------------

#define VISTI_SIN_CODE_OR_BLOCK()																\
	if (true) {																					\
		for (ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid) {				\
			static_cast<ASTNode &>(*kid).Accept(this);											\
			unsigned long type = static_cast<ASTNode &>(*kid).Type();							\
			if (type != SINASTNODES_FUNCTION_TYPE	&&											\
				type != SINASTNODES_BLOCK_TYPE		&&											\
				type != SINASTNODES_FOR_TYPE		&&											\
				type != SINASTNODES_WHILE_TYPE		&&											\
				type != SINASTNODES_SEMICOLON_TYPE	&&											\
				type != SINASTNODES_IF_TYPE			&&											\
				type != SINASTNODES_IFELSE_TYPE													\
				)																				\
				{unparseString +=  to_string(";\n");}											\
		}																						\
	}																							\
	else

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_OBJECT_ACCESS_VISIT_DEFINITION(NODENAME, START_S, END_SYM)		\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {								\
		ASTNode::iterator kid = _node.begin();													\
		static_cast<ASTNode &>(*kid++).Accept(this);											\
		unparseString += to_string(START_S);													\
		while(kid != _node.end()) {																\
			static_cast<ASTNode &>(*kid).Accept(this);											\
			++kid;																				\
			if (kid != _node.end())																\
				unparseString +=  to_string(".");												\
		}																						\
		unparseString +=  to_string(END_SYM);													\
	}

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(NODENAME, START_S, END_SYM)		\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {										\
		unparseString +=  to_string(START_S);															\
		ASTNode::iterator kid = _node.begin();															\
		while(kid != _node.end()) {																		\
			static_cast<ASTNode &>(*kid).Accept(this);													\
			++kid;																						\
			if (kid != _node.end())																		\
				unparseString +=  to_string(", ");														\
		}																								\
		unparseString +=  to_string(END_SYM);															\
	}















namespace SIN {

	//-----------------------------------------------------------------

	ASTUnparseTreeVisitor::ASTUnparseTreeVisitor(void) : unparseString("") {}

	//-----------------------------------------------------------------

	ASTUnparseTreeVisitor::~ASTUnparseTreeVisitor() {}


	//-----------------------------------------------------------------

	void ASTUnparseTreeVisitor::Visit(ASTNode & _node) 
		{	SINASSERT(false);	}


	//-----------------------------------------------------------------
	
	void ASTUnparseTreeVisitor::Visit(SinCodeASTNode & _node)
		{	VISTI_SIN_CODE_OR_BLOCK();	}

	//-----------------------------------------------------------------
	
	void ASTUnparseTreeVisitor::Visit(BlockASTNode & _node) {
		unparseString +=  to_string("{\n");
		VISTI_SIN_CODE_OR_BLOCK();
		unparseString += to_string("}\n");
	}

	//-----------------------------------------------------------------
	
	void ASTUnparseTreeVisitor::Visit(FunctionASTNode & _node) {
		SINASSERT(_node.NumberOfChildren() == 2);
		
		if (_node.Name()[0] == '$')		//we have a lamda id
			unparseString += to_string("(function ");
		else
			unparseString += to_string("function ") + _node.Name();

		ASTNode::iterator kid = _node.begin();				
		static_cast<ASTNode &>(*kid++).Accept(this);		
		static_cast<ASTNode &>(*kid++).Accept(this);		

		if (_node.Name()[0] == '$')
			unparseString += to_string(" )");
	}

	//-----------------------------------------------------------------

#define UNPARSE_STMT(START_SYMBOL, END_SYMBOL)		unparseString +=  to_string(START_SYMBOL);		\
													ASTNode::iterator kid = _node.begin();			\
													static_cast<ASTNode &>(*kid++).Accept(this);	\
													unparseString +=  to_string(END_SYMBOL);		\
													static_cast<ASTNode &>(*kid++).Accept(this)



	void ASTUnparseTreeVisitor::Visit(WhileASTNode & _node) {	
		SINASSERT(_node.NumberOfChildren() == 2);
		UNPARSE_STMT("while (", ")");
	}

	void ASTUnparseTreeVisitor::Visit(IfASTNode & _node) {	
		SINASSERT(_node.NumberOfChildren() == 2);
		UNPARSE_STMT("if (", ")");
	}

	void ASTUnparseTreeVisitor::Visit(IfElseASTNode & _node) {	
		SINASSERT(_node.NumberOfChildren() == 3);
		UNPARSE_STMT("if (", ")");
		unparseString +=  to_string("else\n");
		static_cast<ASTNode &>(*kid++).Accept(this);
	}


/*
	void ASTUnparseTreeVisitor::Visit(ObjectASTNode & _node) {						
		unparseString +=  to_string("[");				
		ASTNode::iterator kid = _node.begin();			
		while(kid != _node.end()) {						
			static_cast<ASTNode &>(*kid).Accept(this);	
			++kid;										
			if (kid != _node.end())						
				unparseString +=  to_string(", ");		
		}												
		unparseString +=  to_string("] ");				
	}

*/


/*
	void ASTUnparseTreeVisitor::Visit(UnaryNotASTNode & _node) {	
		unparseString +=  to_string("not") + to_string(" (");
		static_cast<ASTNode &>(*_node.begin()).Accept(this);
		unparseString +=  to_string(")");
	}
	
	void ASTUnparseTreeVisitor::Visit(UnaryMinASTNode & _node) {	
		unparseString +=  to_string("not") + to_string(" -");
		static_cast<ASTNode &>(*_node.begin()).Accept(this);
		unparseString +=  to_string(")");
	}
*/

	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(Number	, ""		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(String	, "\""		, "\""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(Nil		, ""		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(True		, ""		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(False	, ""		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(ID		, ""		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(Break	, ""		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(Continue	, ""		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(Semicolon, ""		, "\n"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(LocalID	, "local "	, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(GlobalID	, "global "	, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(ObjectKeys, ""	, ".$keys"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(ObjectSize, ""	, ".$size"		)


	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(FormalArguments	, "(", ")"	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(ActualArguments	, "(", ")"	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(Object			, "[", "]"	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(EmptyObject		, "[", "]"	)
	
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PreIncr	, "++"		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PostIncr	, ""		, "++"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PreDecr	, "--"		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PostDecr	, ""		,"--"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(UnaryMin	, "- ("		, ")"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(UnaryNot	, "not ("	, ")"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(UnindexedMember, ""	, ""		)	
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaParse		, ".<"	, ">."		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaPreserve	, ".~"	, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaEvaluate	, ".!"	, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaUnparse	, ".# "	, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaParseString, ".@ "	, ""		)



	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Assign	, " = "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Add		, " + "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Sub		, " - "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Mul		, " * "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Div		, " / "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Mod		, " % "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Lt		, " < "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Gt		, " > "		)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Le		, " <= "	)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Ge		, " >= "	)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Eq		, " == "	)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Ne		, " != "	)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(And		, " and "	)
	SIN_UNPARSE_TREE_VISITOR_BINARY_OPERATOR_VISIT_DEFINITION(Or		, " or "	)
	
	SIN_UNPARSE_TREE_VISITOR_OBJECT_ACCESS_VISIT_DEFINITION(ObjectMember, ".", "")
	SIN_UNPARSE_TREE_VISITOR_OBJECT_ACCESS_VISIT_DEFINITION(ObjectIndex, "[", "]")




	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(For		)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(ForPreamble)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(ForAddendum)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(Return		)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(NormalCall		)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(MethodCall		)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(FuncdefCall	)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(ExpressionList	)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(IndexedMember	)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(CallMember		)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(CallIndex		)
	


	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(Not)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(LamdaFunction	)


} // namespace SIN
