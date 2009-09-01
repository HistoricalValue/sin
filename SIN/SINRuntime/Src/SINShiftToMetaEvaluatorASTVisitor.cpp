#include "SINShiftToMetaEvaluatorASTVisitor.h"


#include <algorithm>
#include <functional>

#include "SINAlloc.h"
#include "SINAssert.h"
#include "SINMemoryCellAST.h"




//----------------------------------------------------------------------------------------------------------


#define VISIT_NODE_WITH_MANY_CHILDREN()				for(ASTNode::iterator kid = _node.begin();		\
														kid != _node.end();							\
														++kid)										\
													{												\
														parent = newNode;							\
														static_cast<ASTNode&>(*kid).Accept(this);	\
													}


//----------------------------------------------------------------------------------------------------------


#define CONECT_NODE_WITH_ZERO_CHILD(NODE_TYPE)		SINASSERT(_node.NumberOfChildren() == 0);									\
													NODE_TYPE##ASTNode * newNode = SINEWCLASS(NODE_TYPE##ASTNode, (_node));		\
													nodesList.push_back(newNode);												\
													if (parent)																	\
													*parent << newNode


//----------------------------------------------------------------------------------------------------------


#define CONECT_NODE_WITH_ONE_CHILD(NODE_TYPE)		SINASSERT(_node.NumberOfChildren() == 1);									\
													NODE_TYPE##ASTNode * newNode = SINEWCLASS(NODE_TYPE##ASTNode, (_node));		\
													nodesList.push_back(newNode);												\
													if (parent)																	\
														*parent << newNode;														\
													parent = newNode;															\
													static_cast<ASTNode&>(*(_node.begin())).Accept(this)


//----------------------------------------------------------------------------------------------------------


#define CONECT_NODE_WITH_TWO_CHILDREN(NODE_TYPE)	SINASSERT(_node.NumberOfChildren() == 2);									\
													NODE_TYPE##ASTNode * newNode = SINEWCLASS(NODE_TYPE##ASTNode, (_node));		\
													nodesList.push_back(newNode);												\
													if (parent)																	\
														*parent << newNode;														\
													parent = newNode;															\
													ASTNode::iterator kid = _node.begin();										\
													static_cast<ASTNode&>(*kid++).Accept(this);									\
													parent = newNode;															\
													static_cast<ASTNode&>(*kid++).Accept(this)


//----------------------------------------------------------------------------------------------------------


#define CONECT_NODE_WITH_MANY_CHILDREN(NODE_TYPE)	NODE_TYPE##ASTNode * newNode = SINEWCLASS(NODE_TYPE##ASTNode, (_node));		\
													nodesList.push_back(newNode);												\
													if (parent)																	\
														*parent << newNode;														\
													VISIT_NODE_WITH_MANY_CHILDREN()


//----------------------------------------------------------------------------------------------------------

#define SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(NODE_TYPE)				\
		void ShiftToMetaEvaluatorASTVisitor::Visit(NODE_TYPE##ASTNode& _node)	\
			{	CONECT_NODE_WITH_ZERO_CHILD(NODE_TYPE);	}

//----------------------------------------------------------------------------------------------------------

#define SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(NODE_TYPE)					\
		void ShiftToMetaEvaluatorASTVisitor::Visit(NODE_TYPE##ASTNode& _node)	\
			{	CONECT_NODE_WITH_ONE_CHILD(NODE_TYPE);	}

//----------------------------------------------------------------------------------------------------------

#define SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(NODE_TYPE)				\
		void ShiftToMetaEvaluatorASTVisitor::Visit(NODE_TYPE##ASTNode& _node)	\
			{	CONECT_NODE_WITH_TWO_CHILDREN(NODE_TYPE);	}

//----------------------------------------------------------------------------------------------------------

#define SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(NODE_TYPE)				\
		void ShiftToMetaEvaluatorASTVisitor::Visit(NODE_TYPE##ASTNode& _node)	\
			{	CONECT_NODE_WITH_MANY_CHILDREN(NODE_TYPE)	}




namespace SIN {

	namespace {
		template<class C>
		struct CleanListFunctor : public std::unary_function<C *&, void> {
			void operator() (C *& node) { 
				if (node != static_cast<C *>(0)) {
					SINDELETE(node); 
					node = static_cast<C *>(0);
				}
			}
		};
	}


	//-----------------------------------------------------------------

	ShiftToMetaEvaluatorASTVisitor::ShiftToMetaEvaluatorASTVisitor(TreeEvaluationVisitor & visitor):
		metaParseCounter(0),
		meta(0x00), 
		parent(0x00),
		treeEvalVisitor(visitor)
	{ }

	//-----------------------------------------------------------------

	ShiftToMetaEvaluatorASTVisitor::ShiftToMetaEvaluatorASTVisitor(ShiftToMetaEvaluatorASTVisitor const& _o):
		metaParseCounter(_o.metaParseCounter),
		meta(_o.meta), 
		parent(_o.parent),
		treeEvalVisitor(_o.treeEvalVisitor)	
	{ }

	//-----------------------------------------------------------------

	ShiftToMetaEvaluatorASTVisitor::~ShiftToMetaEvaluatorASTVisitor(void) { 
		/*
		if (nodesList.size() > 0)
			DeleteAST();
		*/
	}


	//-----------------------------------------------------------------

	ASTNode * ShiftToMetaEvaluatorASTVisitor::Root(void)
		{	return parent;	}


	//-----------------------------------------------------------------

	void ShiftToMetaEvaluatorASTVisitor::DeleteAST(void){ 
		std::for_each(nodesList.begin(), nodesList.end(), CleanListFunctor<ASTNode>()); 
		nodesList.clear();
	}


	//-----------------------------------------------------------------

	void ShiftToMetaEvaluatorASTVisitor::Visit(SinCodeASTNode& _node)	{ 
		SinCodeASTNode * newNode = SINEWCLASS(SinCodeASTNode, (_node));
		nodesList.push_back(newNode);		
		
		VISIT_NODE_WITH_MANY_CHILDREN()
		parent	= newNode;
	}
	
	
	//-----------------------------------------------------------------

	void ShiftToMetaEvaluatorASTVisitor::Visit(ReturnASTNode& _node)	{
		SINASSERT(_node.NumberOfChildren() == 1 || _node.NumberOfChildren() == 0);									
		
		ReturnASTNode * newNode = SINEWCLASS(ReturnASTNode, (_node));		
		nodesList.push_back(newNode);												
		*parent << newNode;													
		
		if (_node.NumberOfChildren() == 1) {
			parent = newNode;															
			static_cast<ASTNode&>(*(_node.begin())).Accept(this);
		}
	}


	//-----------------------------------------------------------------
	
	void ShiftToMetaEvaluatorASTVisitor::Visit(MetaParseASTNode& _node) {
		SINASSERT( _node.NumberOfChildren() == 1);
		++metaParseCounter;
		static_cast<ASTNode&>(*(_node.begin())).Accept(this);
		--metaParseCounter;
	}
	
	
	//-----------------------------------------------------------------

	void ShiftToMetaEvaluatorASTVisitor::Visit(MetaPreserveASTNode& _node)	{ 

		if ( metaParseCounter != 0){
			CONECT_NODE_WITH_MANY_CHILDREN(MetaPreserve)
		}

		else {
			static_cast<ASTNode&>(*_node.begin()).Accept(&treeEvalVisitor);

			MemoryCell * astmc = treeEvalVisitor.Memory();
			SINASSERT(astmc && astmc->Type() == MemoryCell::AST_MCT);

			*parent << static_cast<MemoryCellAST *>(astmc)->GetValue();
		}
	}


	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(Number				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(String				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(Nil					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(True					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(False					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(ID					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(Break					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(Continue				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(Semicolon				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(EmptyObject			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(LocalID				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ZERO_CHILD(GlobalID				)
	

	//SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(Return				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(PreIncr				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(PostIncr				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(PreDecr				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(PostDecr				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(UnaryMin				)
	//SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(MetaParse			)
	//SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(MetaPreserve			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(MetaEvaluate			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(MetaUnparse			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_ONE_CHILD(MetaParseString		)


	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(If					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Add					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Sub					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Mul					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Div					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Mod					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Lt					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Gt					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Le					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Ge					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Eq					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Ne					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Or					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(And					)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Assign				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(While				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(FuncdefCall			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(Function			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(LamdaFunction		)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(IndexedMember		)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(ObjectIndex			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(CallMember			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_TWO_CHILDREN(CallIndex			)


	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(ObjectMember		)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(NormalCall			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(UnaryNot			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(Not				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(UnindexedMember	)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(MethodCall			)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(ActualArguments	)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(ExpressionList		)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(FormalArguments	)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(IfElse				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(Object				)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(For				)	
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(ForPreamble		)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(ForAddendum		)
	SIN_VISIT_DEFINITION_FOR_NODE_WITH_MENY_CHILDREN(Block				)
} // namespace SIN
