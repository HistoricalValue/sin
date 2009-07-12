#ifndef __SIN_ASTTREEVISUALISATIONVISITOR_H__
#define __SIN_ASTTREEVISUALISATIONVISITOR_H__

#include "Common.h"
#include "SINLogger.h"
#include "SINString.h"
#include "SINASTNode.h"
#include "SINASTVisitor.h"
#include "SINOutputStream.h"


namespace SIN {
	class ASTTreeVisualisationVisitor: public ASTVisitor {
	public:
		ASTTreeVisualisationVisitor(OutputStream& out);
		virtual ~ASTTreeVisualisationVisitor(void);
		

		virtual void	Visit (ASTNode const &);
		//////////////////////////////////////////////////
		//Const value nodes
		//virtual void	Visit (IdASTNode const &		);
		virtual void	Visit (NumberASTNode const &	);
		virtual void	Visit (StringASTNode const &	);
		virtual void	Visit (NilASTNode const &	);
		virtual void	Visit (TrueASTNode const &	);
		virtual void	Visit (FalseASTNode const &	);
		
		
		//////////////////////////////////////////////////
		//arithmetic operators nodes
		virtual void	Visit (AddASTNode const &	);
		virtual void	Visit (SubASTNode const &	);
		virtual void	Visit (MulASTNode const &	);
		virtual void	Visit (DivASTNode const &	);
		virtual void	Visit (ModASTNode const &	);
		//virtual void	Visit (IncrASTNode const &	);
		//virtual void	Visit (DecrASTNode const &	);
		

		//////////////////////////////////////////////////
		//compare nodes
		virtual void	Visit (LtASTNode const &		);
		virtual void	Visit (GtASTNode const &		);
		virtual void	Visit (LeASTNode const &		);
		virtual void	Visit (GeASTNode const &		);
		virtual void	Visit (EqASTNode const &		);
		virtual void	Visit (NeASTNode const &		);


		//////////////////////////////////////////////////
		//logic nodes
		virtual void	Visit (OrASTNode const &		);
		//virtual void	Visit (NotASTNode const &	);
		virtual void	Visit (AndASTNode const &	);

		//////////////////////////////////////////////////
		//stmt nodes
		//virtual void	Visit (ForASTNode const &	);
		//virtual void	Visit (WhileASTNode const &	);
		//virtual void	Visit (IfASTNode const &		);
		//virtual void	Visit (IfElseASTNode const &	);

		void	AddTab(void);
		void	RemoveTab(void);


	private:
		String tabs;
		OutputStream &out;
		InstanceProxy<Logger> logger_p;
	}; // class ASTTreeVisualisationVisitor


} // namespace SIN




#endif // __SIN_ASTTREEVISUALISATIONVISITOR_H__

