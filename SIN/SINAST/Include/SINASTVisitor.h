/*
 *	Virtual Class
 */

#ifndef __SIN_SIN_AST_VISITOR_H__
#define __SIN_SIN_AST_VISITOR_H__


#include "SINASTNode.h"
#include "SINASTCommon.h"


#define SINASTVISITOR_VISIT_SIGNATURE(NODENAME) virtual void Visit(NODENAME##ASTNode &) = 0


namespace SIN {
	class ASTVisitor { 
	public :
		virtual ~ASTVisitor() {}

        SINASTVISITOR_VISIT_SIGNATURE(Number );
        SINASTVISITOR_VISIT_SIGNATURE(String );
        SINASTVISITOR_VISIT_SIGNATURE(Nil    );
        SINASTVISITOR_VISIT_SIGNATURE(True   );
        SINASTVISITOR_VISIT_SIGNATURE(False  );
        SINASTVISITOR_VISIT_SIGNATURE(Add    );
        SINASTVISITOR_VISIT_SIGNATURE(Sub    );
        SINASTVISITOR_VISIT_SIGNATURE(Mul    );
        SINASTVISITOR_VISIT_SIGNATURE(Div    );
        SINASTVISITOR_VISIT_SIGNATURE(Mod    );
        SINASTVISITOR_VISIT_SIGNATURE(Lt     );
        SINASTVISITOR_VISIT_SIGNATURE(Gt     );
        SINASTVISITOR_VISIT_SIGNATURE(Le     );
        SINASTVISITOR_VISIT_SIGNATURE(Ge     );
        SINASTVISITOR_VISIT_SIGNATURE(Eq     );
        SINASTVISITOR_VISIT_SIGNATURE(Ne     );
        SINASTVISITOR_VISIT_SIGNATURE(Or     );
        SINASTVISITOR_VISIT_SIGNATURE(And    );

	};
}


#endif //__SIN_AST_VISITOR_H__
