#ifndef __SIN_AST_COMMON_H__
#define __SIN_AST_COMMON_H__

#include <string>
#include "SINASTNode.h"

namespace SIN {
	enum ConstNodeType {
		CONST_NUMBER,
		CONST_STRING,
		CONST_NIL,
		CONST_TRUE,
		CONST_FALSE
    };

	//	LEAF_FUNCTION,
	//	LEAF_RETURN,
	//	LEAF_ID

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
		OP_END
	};

	enum ExprValueType {
		EXPR_ASS = 0
	};

	//typedef LeafASTNode<5, ConstNodeType::LEAF_FUNCTION, void>			FunctionASTNode;
	//typedef LeafASTNode<6, ConstNodeType::LEAF_RETURN, void>			ReturnASTNode;
	//typedef LeafASTNode<7, ConstNodeType::LEAF_ID, std::string>			IdASTNode;
	

	//
	//typedef ASTNode<21, ExprValueType::EXPR_ASS, void>				AssASTNode;
	

} // namespace SIN


#endif //__SIN_AST_COMMON_H__
