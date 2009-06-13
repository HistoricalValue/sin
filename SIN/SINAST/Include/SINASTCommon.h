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


	typedef ASTNode<0, LeafValueType::LEAF_NUMBER, double>			NumberASTNode;
	typedef ASTNode<1, LeafValueType::LEAF_STRING, std::string>		StringASTNode;
	typedef ASTNode<2, LeafValueType::LEAF_NIL, void>				NilASTNode;
	typedef ASTNode<3, LeafValueType::LEAF_TRUE, bool>				TrueASTNode;
	typedef ASTNode<4, LeafValueType::LEAF_FALSE, bool>				FalseASTNode;
	typedef ASTNode<5, LeafValueType::LEAF_FUNCTION, void>			FunctionASTNode;
	typedef ASTNode<6, LeafValueType::LEAF_RETURN, void>			ReturnASTNode;
	typedef ASTNode<7, LeafValueType::LEAF_ID, std::string>			IdASTNode;
	
	//
	typedef ASTNode<8, OpValueType::OP_ADD, void>					AddASTNode;
	typedef ASTNode<9, OpValueType::OP_SUB, void>					SubASTNode;	
	typedef ASTNode<10, OpValueType::OP_MUL, void>					MulASTNode;
	typedef ASTNode<11, OpValueType::OP_DIV, void>					DivASTNode;
	typedef ASTNode<12, OpValueType::OP_MOD, void>					ModASTNode;
	typedef ASTNode<13, OpValueType::OP_LT, void>					LtASTNode;
	typedef ASTNode<14, opValueType::OP_GT, void>					GtASTNode;
	typedef ASTNode<15, OpValueType::OP_LE, void>					LeASTNode;
	typedef ASTNode<16, OpValueType::OP_GE, void>					GeASTNode;
	typedef ASTNode<17, OpValueType::OP_EQ, void>					EqASTNode;
	typedef ASTNode<18, OpValueType::OP_NE, void>					NeASTNode;
	typedef ASTNode<19, OpValueType::OP_OR, void>					OrASTNode;
	typedef ASTNode<20, OpValueType::OP_END, void>					AndASTNode;
	

}	//end of namespace SIN


#endif __SIN_SIN_AST_COMMON_H__