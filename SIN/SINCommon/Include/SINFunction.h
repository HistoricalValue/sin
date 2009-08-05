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


			~Function();


			ASTNode *		GetASTNode(void);
			const String &  Name(void) const;
			void			SetASTNode(const ASTNode *);


		private:
			ASTNode	*	node;
			
		};
	}	//namespace Types

	extern String const to_string(SIN::Types::Function const * val);
	extern String const to_string(SIN::Types::Function const & val);
	
}	//namespace SIN



#endif