#ifndef __SIN_SIN_AST_COMMON_H__
#define __SIN_SIN_AST_COMMON_H__

#include <string>
#include "SINASTNode.h"

namespace SIN {
	enum LeafValueType {
		LEAF_NUMBER = 0,
		LEAF_STRING,
		LEAF_NIL,
		LEAF_TRUE,
		LEAF_FALSE,
		LEAF_FUNCTION,
		LEAF_RETURN,
		LEAF_ID
	};

	enum OpValueType {
		OP_ADD = 0,
		OP_SUB,
		OP_MUL,
		OP_DIV,
		OP_MOD,
		OP_LT,
		OP_GT,
		OP_LE,
		OP_GE,
		OP_EQ,
		OP_NE,
		OP_OR,
		OP_END,
	}

	enum ExprValueType {
		EXPR_ASS = 0
	};


	typedef LeafASTNode<0, LeafValueType::LEAF_NUMBER, double>			NumberASTNode;
	typedef LeafASTNode<1, LeafValueType::LEAF_STRING, std::string>		StringASTNode;
	typedef LeafASTNode<2, LeafValueType::LEAF_NIL, void>				NilASTNode;
	typedef LeafASTNode<3, LeafValueType::LEAF_TRUE, bool>				TrueASTNode;
	typedef LeafASTNode<4, LeafValueType::LEAF_FALSE, bool>				FalseASTNode;
	typedef LeafASTNode<5, LeafValueType::LEAF_FUNCTION, void>			FunctionASTNode;
	typedef LeafASTNode<6, LeafValueType::LEAF_RETURN, void>			ReturnASTNode;
	typedef LeafASTNode<7, LeafValueType::LEAF_ID, std::string>			IdASTNode;
	
	//
	typedef OpASTNode<8, OpValueType::OP_ADD, void>						AddASTNode;
	typedef OpASTNode<9, OpValueType::OP_SUB, void>						SubASTNode;	
	typedef OpASTNode<10, OpValueType::OP_MUL, void>					MulASTNode;
	typedef OpASTNode<11, OpValueType::OP_DIV, void>					DivASTNode;
	typedef OpASTNode<12, OpValueType::OP_MOD, void>					ModASTNode;
	typedef OpASTNode<13, OpValueType::OP_LT, void>						LtASTNode;
	typedef OpASTNode<14, opValueType::OP_GT, void>						GtASTNode;
	typedef OpASTNode<15, OpValueType::OP_LE, void>						LeASTNode;
	typedef OpASTNode<16, OpValueType::OP_GE, void>						GeASTNode;
	typedef OpASTNode<17, OpValueType::OP_EQ, void>						EqASTNode;
	typedef OpASTNode<18, OpValueType::OP_NE, void>						NeASTNode;
	typedef OpASTNode<19, OpValueType::OP_OR, void>						OrASTNode;
	typedef OpASTNode<20, OpValueType::OP_END, void>					AndASTNode;

	//
	//typedef ASTNode<21, ExprValueType::EXPR_ASS, void>				AssASTNode;
	

}	//end of namespace SIN


#endif __SIN_SIN_AST_COMMON_H__