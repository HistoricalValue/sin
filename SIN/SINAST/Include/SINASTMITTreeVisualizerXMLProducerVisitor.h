#ifndef __SIN__ASTMITTREEVISUALIZERXMLPRODUCERVISITOR_H__
#define __SIN__ASTMITTREEVISUALIZERXMLPRODUCERVISITOR_H__

#include "SINASTVisitor.h"
#include "SINOutputStream.h"
#include <list>

namespace SIN {

	class ASTMITTreeVisualizerXMLProducerVisitor: public ASTVisitor {
		OutputStream& out;

		typedef struct User {
			String const& ID(void) const;
			String const& Name(void) const;
			User(String const& id = "", String const& name = "");
		private:
			String id, name;
		} users_t;
		users_t users[1];
		void makeUsers(void);

		typedef struct Folder {
			String const& Name(void) const;
			String const& ID(void) const;
			Folder(String const& name = "", String const& id = "");
		private:
			String name, id;
		} folders_t;
		Folder folder(String const& name);
		Namer folder_id_namer;

		void writeUser(User const& user);
		void writePrelude(void);
		void writeFolder(Folder const&, bool empty = false);
		void writeFolderClosing(void);
		void writeOutro(void);
	public:
		ASTMITTreeVisualizerXMLProducerVisitor(OutputStream& _out);
		ASTMITTreeVisualizerXMLProducerVisitor(ASTMITTreeVisualizerXMLProducerVisitor const&);
		~ASTMITTreeVisualizerXMLProducerVisitor(void);

		SINASTVISITOR_VISIT_SIGNATURE(       ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Number ) ;
		SINASTVISITOR_VISIT_SIGNATURE(String ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Nil    ) ;
		SINASTVISITOR_VISIT_SIGNATURE(True   ) ;
		SINASTVISITOR_VISIT_SIGNATURE(False  ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Add    ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Sub    ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Mul    ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Div    ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Mod    ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(Incr   ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(Decr   ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Lt     ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Gt     ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Le     ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Ge     ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Eq     ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Ne     ) ;
		SINASTVISITOR_VISIT_SIGNATURE(Or     ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(Not    ) ;
		SINASTVISITOR_VISIT_SIGNATURE(And    ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(For    ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(While  ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(If     ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(IfElse ) ;
//		SINASTVISITOR_VISIT_SIGNATURE(Id	 ) ;
	}; // class ASTMITTreeVisualizerXMLProducerVisitor
} // namespace SIN

#endif // __SIN__ASTMITTREEVISUALIZERXMLPRODUCERVISITOR_H__
