#ifndef __SIN_ASTTREEVISUALISATIONVISITOR_H__
#define __SIN_ASTTREEVISUALISATIONVISITOR_H__

#include "Common.h"
#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"
#include "SINASTVisitor.h"
#include "SINOutputStream.h"

#define SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(NODENAME) virtual void Visit(NODENAME##ASTNode const&)

namespace SIN {
	class ASTTreeVisualisationVisitor: public ASTVisitor {
	public:
		ASTTreeVisualisationVisitor(OutputStream& out);
		virtual ~ASTTreeVisualisationVisitor(void);
		

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(	);
		//////////////////////////////////////////////////
		//Const value nodes
		//virtual void	Visit (IdASTNode const &		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Number	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(String	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Nil		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(True		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(False	);
		
		
		//////////////////////////////////////////////////
		//arithmetic operators nodes
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Add	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Sub	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Mul	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Div	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Mod	);
		//virtual void	Visit (IncrASTNode const &	);
		//virtual void	Visit (DecrASTNode const &	);
		

		//////////////////////////////////////////////////
		//compare nodes
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Lt);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Gt);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Le);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Ge);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Eq);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Ne);


		//////////////////////////////////////////////////
		//logic nodes
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Or	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Not	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(And	);

		//////////////////////////////////////////////////
		//stmt nodes
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(For			);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(While		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(If			);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(IfElse		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Return		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Semicolon	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Break		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Continue		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Block		);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Assign	);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Arguments	);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(NormalCall	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(MethodCall	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(FuncdefCall	);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Function		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(LamdaFunction);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(ID		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(LocalID	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(GlobalID	);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(PreIncr	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(PostIncr	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(PreDecr	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(PostDecr	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(UnaryNot	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(UnaryMin	);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(Object			);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(EmptyObject		);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(UnindexedMember	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(IndexedMember	);

		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(ObjectMember	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(ObjectIndex	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(CallMember	);
		SINASTTREEVISUALIZATIONVISITOR_VISIT_SIGNATURE(CallIndex	);

		// "Indentation" levels
		void			IncreaseIndentationLevel(void);
		void			DecreaseIndentationLevel(void);
		unsigned int	IndentationLevel(void) const;


	private:
		String tabs;
		OutputStream &out;
		InstanceProxy<Logger> logger_p;
		unsigned int indentation_level;
	}; // class ASTTreeVisualisationVisitor


} // namespace SIN




#endif // __SIN_ASTTREEVISUALISATIONVISITOR_H__

