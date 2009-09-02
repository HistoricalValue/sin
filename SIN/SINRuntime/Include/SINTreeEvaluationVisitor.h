#ifndef __SIN_TREE_EVALUATION_VISITOR_H__
#define __SIN_TREE_EVALUATION_VISITOR_H__

#include <stack>

#include "SINASTVisitor.h"
#include "SINMemoryCell.h"
#include "SINLibrary.h"
#include "SINVirtualState.h"
#include "SINNamer.h"

namespace SIN{

	class TreeEvaluationVisitor : public ASTVisitor {
	
	public:
		MetaPreserveASTNode * PreserveASTNode() { return preserveNode; };

		SINASTVISITOR_VISIT_SIGNATURE(Number			) ;
		SINASTVISITOR_VISIT_SIGNATURE(String			) ;
		SINASTVISITOR_VISIT_SIGNATURE(Nil				) ;
		SINASTVISITOR_VISIT_SIGNATURE(True				) ;
		SINASTVISITOR_VISIT_SIGNATURE(False				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Add				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Sub				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Mul				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Div				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Mod				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Lt				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Gt				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Le				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Not				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Ge				) ;	
		SINASTVISITOR_VISIT_SIGNATURE(Eq				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Ne				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Or				) ;
		SINASTVISITOR_VISIT_SIGNATURE(And				) ;
		SINASTVISITOR_VISIT_SIGNATURE(For				) ;
		SINASTVISITOR_VISIT_SIGNATURE(ForPreamble		) ;
		SINASTVISITOR_VISIT_SIGNATURE(ForAddendum		) ;
		SINASTVISITOR_VISIT_SIGNATURE(While				) ;
		SINASTVISITOR_VISIT_SIGNATURE(If				) ;
		SINASTVISITOR_VISIT_SIGNATURE(IfElse			) ;
		SINASTVISITOR_VISIT_SIGNATURE(Return			) ;
		SINASTVISITOR_VISIT_SIGNATURE(Semicolon			) ;	
		SINASTVISITOR_VISIT_SIGNATURE(Break				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Continue			) ;
		SINASTVISITOR_VISIT_SIGNATURE(Block				) ;
		SINASTVISITOR_VISIT_SIGNATURE(Assign			) ;
		SINASTVISITOR_VISIT_SIGNATURE(NormalCall		) ;
		SINASTVISITOR_VISIT_SIGNATURE(MethodCall		) ;
		SINASTVISITOR_VISIT_SIGNATURE(FuncdefCall		) ;
		SINASTVISITOR_VISIT_SIGNATURE(ActualArguments	) ;
		SINASTVISITOR_VISIT_SIGNATURE(ExpressionList	) ;
		SINASTVISITOR_VISIT_SIGNATURE(Function			) ;
		SINASTVISITOR_VISIT_SIGNATURE(LamdaFunction		) ;
		SINASTVISITOR_VISIT_SIGNATURE(FormalArguments	) ;
		SINASTVISITOR_VISIT_SIGNATURE(ID				) ;
		SINASTVISITOR_VISIT_SIGNATURE(LocalID			) ;
		SINASTVISITOR_VISIT_SIGNATURE(GlobalID			) ;
		SINASTVISITOR_VISIT_SIGNATURE(PreIncr			) ;
		SINASTVISITOR_VISIT_SIGNATURE(PostIncr			) ;
		SINASTVISITOR_VISIT_SIGNATURE(PreDecr			) ;
		SINASTVISITOR_VISIT_SIGNATURE(PostDecr			) ;
		SINASTVISITOR_VISIT_SIGNATURE(UnaryNot			) ;
		SINASTVISITOR_VISIT_SIGNATURE(UnaryMin			) ;
		SINASTVISITOR_VISIT_SIGNATURE(Object			) ;
		SINASTVISITOR_VISIT_SIGNATURE(EmptyObject		) ;
		SINASTVISITOR_VISIT_SIGNATURE(UnindexedMember	) ;
		SINASTVISITOR_VISIT_SIGNATURE(IndexedMember		) ;
		SINASTVISITOR_VISIT_SIGNATURE(ObjectMember		) ;
		SINASTVISITOR_VISIT_SIGNATURE(ObjectIndex		) ;
		SINASTVISITOR_VISIT_SIGNATURE(CallMember		) ;
		SINASTVISITOR_VISIT_SIGNATURE(CallIndex			) ;
		SINASTVISITOR_VISIT_SIGNATURE(ObjectKeys		) ;
		SINASTVISITOR_VISIT_SIGNATURE(ObjectSize		) ;
		SINASTVISITOR_VISIT_SIGNATURE(MetaParse			) ;
		SINASTVISITOR_VISIT_SIGNATURE(MetaPreserve		) ;
		SINASTVISITOR_VISIT_SIGNATURE(MetaEvaluate		) ;
		SINASTVISITOR_VISIT_SIGNATURE(MetaUnparse		) ;
		SINASTVISITOR_VISIT_SIGNATURE(MetaParseString	) ;
		SINASTVISITOR_VISIT_SIGNATURE(SinCode			) ;

		MemoryCell * Memory(void) const { return memory; }

		TreeEvaluationVisitor (void);
		TreeEvaluationVisitor (Library::Library *lib, VM::VirtualState *vs);
		virtual ~TreeEvaluationVisitor (void);
	private:
		MemoryCell *			memory;
		InstanceProxy<MemoryCell>*	lookuped;
		MetaPreserveASTNode	*	preserveNode;
		Library::Library *		lib;
		VM::VirtualState *		vs;
		Types::Object_t			obj_imp; // as in "object-imp", not "object implementation"
		bool					triggeredBreak;
		bool					triggeredContinue;

		typedef Environment::argument_list_t argument_list_t;
		typedef std::stack<argument_list_t> argument_lists_t;
		argument_lists_t argument_lists;
		void resetObjectImp(void);
		void assignObjectImpToMemory(void);
		// temporaries
		void insertTemporary(InstanceProxy<MemoryCell> const&);
		// lookups
		void lookup(String const&);
		void lookup(String const&, SymbolTable::scope_id);
		void lookup_local(String const&);
		void lookup_global(String const&);
		bool lookup_failed(void) const;
		void insert(String const&, MemoryCell*);
		void insert(String const&, MemoryCell*, SymbolTable::scope_id);
		void insert_global(String const&, MemoryCell*);
		// function stuff
		void performCall(MemoryCell* funcmemcell, String const& func_desc, String const& file_name, unsigned int file_line, ASTNode& actual_args_astnode);
		void triggerReturn(MemoryCell* returnValue);
		bool returnTriggered(void) const;
		
		// Unusable
		TreeEvaluationVisitor(const TreeEvaluationVisitor&);
	};

} // namespace SIN

#endif //__SIN_AST_TREE_EVALUATION_VISITOR_H__
