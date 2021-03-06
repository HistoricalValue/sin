#ifndef __SIN_FUNCTION_H__
#define __SIN_FUNCTION_H__

#include "SINString.h"
#include "SINASTNode.h"

namespace SIN {
	namespace Types {
		class Function { 
		public:

			Function(void);
			Function(ASTNode * _node) : node (_node) {}


			~Function(){}


			ASTNode *		GetASTNode(void) const;
			const String &  Name(void) const;
			void			SetASTNode(ASTNode *);

			bool operator== (const Function &) const;
			bool operator!= (const Function &) const;
		private:
			ASTNode	*	node;
			
		};
	}	//namespace Types

	extern String const to_string(Types::Function const & val);
	
}	//namespace SIN



#endif // __SIN_FUNCTION_H__
