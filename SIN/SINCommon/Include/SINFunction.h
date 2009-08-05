#ifndef __SIN_FUNCTION_H__
#define __SIN_FUNCTION_H__

#include "SINString.h"
#include "SINASTNode.h"

namespace SIN {
	class SINFunction { 
	public:

		SINFunction(void);
		SINFunction(ASTNode * _node) : node (_node) {}


		~SINFunction();


		const ASTNode *	GetASTNode(void) const;
		const String &  Name(void) const;
		void			SetASTNode(const ASTNode *);


	private:
		ASTNode	*	node;
		
	};

	extern String const to_string(SIN::SINFunction const * val);
	extern String const to_string(SIN::SINFunction const & val);
}



#endif