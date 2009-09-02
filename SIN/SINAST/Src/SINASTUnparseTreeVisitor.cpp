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

#define SIN_UNPARSE_TREE_VISITOR_WITH_NO_CHILDREN_VISIT_DEFINITION(NODENAME, START_S, SUMBOL_E)	\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {								\
		unparseString +=  to_string(START_S) + _node.Name() + to_string(SUMBOL_E);				\
	}

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(NODENAME, START_S, SUMBOL_E)	\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {								\
		SINASSERT(_node.NumberOfChildren() == 1);												\
		unparseString += to_string(START_S);													\
		static_cast<ASTNode &>(*_node.begin()).Accept(this);									\
		unparseString += to_string(SUMBOL_E);													\
	}

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(NODENAME, SYMBOL_S, SYMBOL_M, SYMBOL_E)	\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {										\
		SINASSERT(_node.NumberOfChildren() == 2);														\
		ASTNode::iterator kid = _node.begin();															\
		unparseString +=  to_string(SYMBOL_S);															\
		static_cast<ASTNode &>(*kid++).Accept(this);													\
		unparseString +=  to_string(SYMBOL_M);															\
		static_cast<ASTNode &>(*kid++).Accept(this);													\
		unparseString +=  to_string(SYMBOL_E);															\
	}

//-------------------------------------------------------------------------------------------------

#define ADD_SEMICOLONO_IF_YOU_CAN()		if (true) {														\
											unsigned long type = static_cast<ASTNode &>(*kid).Type();	\
											if (type != SINASTNODES_FUNCTION_TYPE	&&					\
												type != SINASTNODES_BLOCK_TYPE		&&					\
												type != SINASTNODES_FOR_TYPE		&&					\
												type != SINASTNODES_WHILE_TYPE		&&					\
												type != SINASTNODES_SEMICOLON_TYPE	&&					\
												type != SINASTNODES_IF_TYPE			&&					\
												type != SINASTNODES_IFELSE_TYPE							\
												)														\
												unparseString +=  to_string(";\n");						\
										}																\
										else


//-------------------------------------------------------------------------------------------------

#define VISTI_SIN_CODE_OR_BLOCK()																\
	if (true) {																					\
		for (ASTNode::iterator kid = _node.begin(); kid != _node.end(); ++kid) {				\
			static_cast<ASTNode &>(*kid).Accept(this);											\
			ADD_SEMICOLONO_IF_YOU_CAN();														\
		}																						\
	}																							\
	else

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_OBJECT_ACCESS_VISIT_DEFINITION(NODENAME, START_S, SUMBOL_E)	\
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
		unparseString +=  to_string(SUMBOL_E);													\
	}

//-------------------------------------------------------------------------------------------------

#define SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(NODENAME, START_S, SUMBOL_E)		\
	void ASTUnparseTreeVisitor::Visit(NODENAME##ASTNode & _node) {										\
		unparseString +=  to_string(START_S);															\
		ASTNode::iterator kid = _node.begin();															\
		while(kid != _node.end()) {																		\
			static_cast<ASTNode &>(*kid).Accept(this);													\
			++kid;																						\
			if (kid != _node.end())																		\
				unparseString +=  to_string(", ");														\
		}																								\
		unparseString +=  to_string(SUMBOL_E);															\
	}

//-------------------------------------------------------------------------------------------------

#define UNPARSE_STMT(START_SYMBOL, END_SYMBOL)		unparseString +=  to_string(START_SYMBOL);			\
													ASTNode::iterator kid = _node.begin();				\
													static_cast<ASTNode &>(*kid++).Accept(this);		\
													unparseString +=  to_string(END_SYMBOL);			\
													static_cast<ASTNode &>(*kid).Accept(this);			\
													ADD_SEMICOLONO_IF_YOU_CAN()















namespace SIN {

	//-----------------------------------------------------------------

	ASTUnparseTreeVisitor::ASTUnparseTreeVisitor(void) : unparseString(""), indexedObjectFunctionCounter(0) {}

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
		
		bool lamda = _node.Name()[0] == '$' || indexedObjectFunctionCounter;
		if (lamda)		//we have a lamda id
			unparseString += to_string("(function ");
		else
			unparseString += to_string("function ") + _node.Name();

		ASTNode::iterator kid = _node.begin();				
		static_cast<ASTNode &>(*kid++).Accept(this);		
		static_cast<ASTNode &>(*kid++).Accept(this);		

		if (lamda)
			unparseString += to_string(" )");
	}

	//-----------------------------------------------------------------

	void ASTUnparseTreeVisitor::Visit(WhileASTNode & _node) {	
		SINASSERT(_node.NumberOfChildren() == 2);
		UNPARSE_STMT("while (", ")");
	}

	//-----------------------------------------------------------------

	void ASTUnparseTreeVisitor::Visit(IfASTNode & _node) {	
		SINASSERT(_node.NumberOfChildren() == 2);
		UNPARSE_STMT("if (", ")");
	}

	//-----------------------------------------------------------------

	void ASTUnparseTreeVisitor::Visit(IfElseASTNode & _node) {	
		SINASSERT(_node.NumberOfChildren() == 3);
		UNPARSE_STMT("if (", ")");
		unparseString +=  to_string("else\n");
		static_cast<ASTNode &>(*(++kid)).Accept(this);
	}

	//-----------------------------------------------------------------

	void ASTUnparseTreeVisitor::Visit(IndexedMemberASTNode & _node) {						
		SINASSERT( _node.NumberOfChildren() == 2);
		
		ASTNode::iterator kid = _node.begin();			
		
		static_cast<ASTNode &>(*kid++).Accept(this);	
		unparseString += to_string(" : ");

		//Edw 8eloume na doume an to idex dixnei se function.
		//An einai kanonikh function (einai syndactic sugar gia indexed lamda function)
		//den 8eloume na ths baloume 3ana onoma
		bool increseCounter	= false;
		ASTNode & seconKid  = static_cast<ASTNode &>(*kid);
		
		if ( seconKid.NumberOfChildren()						== 2								 &&
			 static_cast<ASTNode &>(*seconKid.begin()).Type()	== SINASTNODES_FORMALARGUMENTS_TYPE
			 ) 
		{
			increseCounter = true;
			++indexedObjectFunctionCounter;
		}

		static_cast<ASTNode &>(*kid++).Accept(this);

		if (increseCounter){
			increseCounter = false;
			--indexedObjectFunctionCounter;
		}
	}

	//-----------------------------------------------------------------
	
	void ASTUnparseTreeVisitor::Visit(ForASTNode & _node) {	
		unparseString +=  to_string("for (");
		ASTNode::iterator kid =  _node.begin();

		static_cast<ASTNode &>(*kid++).Accept(this);	//first child
		unparseString +=  to_string("; ");

		static_cast<ASTNode &>(*kid++).Accept(this);	//second child
		unparseString +=  to_string("; ");

		static_cast<ASTNode &>(*kid++).Accept(this);	//third child
		unparseString +=  to_string(") ");

		static_cast<ASTNode &>(*kid).Accept(this);		//forth child
		ADD_SEMICOLONO_IF_YOU_CAN();
	}

	//-----------------------------------------------------------------
	
	void ASTUnparseTreeVisitor::Visit(ReturnASTNode & _node) {	
		size_t numberOfChildren = _node.NumberOfChildren();
		SINASSERT(numberOfChildren == 0 || numberOfChildren == 1);
		unparseString +=  to_string("return ");

		if (numberOfChildren == 1)
			static_cast<ASTNode &>(*_node.begin()).Accept(this);
	}

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


	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(FormalArguments	, "(", ")"	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(ActualArguments	, "(", ")"	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(Object			, "[", "]"	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(EmptyObject		, "[", "]"	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(ForPreamble		, "" , ""	)
	SIN_UNPARSE_TREE_VISITOR_ARGUMENTS_AND_OBJECT_VISIT_DEFINITION(ForAddendum		, "" , ""	)
	

	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PreIncr	, "++"		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PostIncr	, ""		, "++"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PreDecr	, "--"		, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(PostDecr	, ""		,"--"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(UnaryMin	, "- ("		, ")"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(UnaryNot	, "not ("	, ")"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(ObjectKeys	, ""		, ".$keys"	)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(ObjectSize	, ""		, ".$size"	)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(UnindexedMember, ""	, ""		)	
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaParse		, ".<"	, ">."		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaPreserve	, ".~("	, ")"		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaEvaluate	, ".!"	, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaUnparse	, ".# "	, ""		)
	SIN_UNPARSE_TREE_VISITOR_WITH_ONE_CHILD_VISIT_DEFINITION(MetaParseString, ".@ "	, ""		)


	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Assign	, "", " = ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Add		, "", " + ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Sub		, "", " - ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Mul		, "", " * ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Div		, "", " / ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Mod		, "", " % ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Lt		, "", " < ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Gt		, "", " > ", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Le		, "", " <= ", ""	)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Ge		, "", " >= ", ""	)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Eq		, "", " == ", ""	)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Ne		, "", " != ", ""	)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(And		, "", " and ", ""	)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(Or		, "", " or ", ""	)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(NormalCall, "", "", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(CallMember, "", ".", ""		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(CallIndex, "", "[", "]"		)
	SIN_UNPARSE_TREE_VISITOR_TWO_CHILDREN_VISIT_DEFINITION(FuncdefCall, "", "", ""		)


	SIN_UNPARSE_TREE_VISITOR_OBJECT_ACCESS_VISIT_DEFINITION(ObjectMember, ".", "")
	SIN_UNPARSE_TREE_VISITOR_OBJECT_ACCESS_VISIT_DEFINITION(ObjectIndex, "[", "]")




	//SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(FuncdefCall	)
	

	//Auta pote den 8a kalestoun. Ite epidei einai syndactic sugar, ite epidei den brika kanenan kanona :D
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(Not			)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(MethodCall	)	
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(LamdaFunction	)
	SIN_UNPARSE_TREE_VISITOR_DEFAULT_VISIT_DEFINITION(ExpressionList)


} // namespace SIN
