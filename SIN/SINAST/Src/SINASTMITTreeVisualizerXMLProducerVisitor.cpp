#include "SINASTMITTreeVisualizerXMLProducerVisitor.h"
#include "SINAssert.h"

#define SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(NODENAME)				\
	void ASTMITTreeVisualizerXMLProducerVisitor::Visit(NODENAME##ASTNode & _node) {	\
		Visit(static_cast<ASTNode &>(_node));											\
	}

namespace SIN {

	ASTMITTreeVisualizerXMLProducerVisitor::ASTMITTreeVisualizerXMLProducerVisitor(OutputStream& _out):
	out(_out),
	users(),
	folder_id_namer("folder_")
	{
		makeUsers();
		writePrelude();
	}

	ASTMITTreeVisualizerXMLProducerVisitor::ASTMITTreeVisualizerXMLProducerVisitor(ASTMITTreeVisualizerXMLProducerVisitor const& _other):
	out(_other.out),
	users(),
	folder_id_namer(_other.folder_id_namer)
	{
		memcpy(users, _other.users, sizeof(users));
	}

	ASTMITTreeVisualizerXMLProducerVisitor::~ASTMITTreeVisualizerXMLProducerVisitor(void) {
		writeOutro();
	}

	void ASTMITTreeVisualizerXMLProducerVisitor::Visit(ASTNode& _node) {
		const size_t numberOfChildren = _node.NumberOfChildren();
		bool const empty =  numberOfChildren == 0;
		writeFolder(folder(_node.Name().c_str()), empty);

		if (!empty) {
			typedef ASTNode::iterator it_t;
			it_t const end = _node.end();
			for (it_t ite = _node.begin(); ite != end; ++ite)
				static_cast<ASTNode&>(*ite).Accept(this);
			writeFolderClosing();
		}
	}

	/////////////// private: write* ///////////////
	// optimisation
	inline void ASTMITTreeVisualizerXMLProducerVisitor::writestr(char const* const _str) {
		out.write(_str, strlen(_str));
	}

	// optimisation
	inline void ASTMITTreeVisualizerXMLProducerVisitor::writehtml(char const* const _str) {
		char const* begin = _str;
		char const* end;
		do {
			for (
				end = begin;
				*end != '"' && *end != '<' && *end != '>' && *end != '&' && *end != '\0';
				++end)
				;
			out.write(begin, end - begin);

			switch (*end) {
				case '\0': break;
				case '"': out.write("&quot;", 6u); break;
				case '<': out.write("&lt;", 4u); break;
				case '>': out.write("&gt;", 4u); break;
				case '&': out.write("&amp;", 5u); break;
				default: SINASSERT(!"Why so serious?");
			}
			
			begin = end + 1;
		} while (*end != '\0');
	}

	inline void ASTMITTreeVisualizerXMLProducerVisitor::writePrelude(void) {
		writestr("<TreevizFileSystem  created=\"2008-07-04 11:34:08\" name=\"SIN AST\">\n<Users>\n");
		size_t const users_len = sizeof(users)/sizeof(users[0]);
		for (size_t i = 0; i < users_len; ++i)
			writeUser(users[i]);
		writestr("</Users>\n<Files>\n");
	}

	inline void ASTMITTreeVisualizerXMLProducerVisitor::writeUser(User const& user) {
		writestr("<User id=\"");
		writestr(user.id);
		writestr("\" name=\"");
		writestr(user.name);
		writestr("\" firstname=\"John\" lastname=\"Doe\" email=\"john.doe@email.com\" created=\"2007-08-27 09:11:54\" used=\"2008-06-23 08:29:15\">\n</User>\n");
	}

	inline void ASTMITTreeVisualizerXMLProducerVisitor::writeFolder(Folder const& folder, bool empty) {
		writestr("<Folder id=\"");
		writestr(folder.id);
		writestr("\" name=\"");
		writehtml(folder.name);
		writestr("\" created=\"2008-06-24 15:15:03\" modified=\"2005-08-04 17:35:06\" ownerRef=\"");
		writestr(users[0].id);
		writestr("\" size=\"2048\"");
		writestr(empty ? "/>\n" : ">\n");
	}

	inline void ASTMITTreeVisualizerXMLProducerVisitor::writeFolderClosing(void) {
		writestr("</Folder>\n");
	}

	inline void ASTMITTreeVisualizerXMLProducerVisitor::writeOutro(void) {
		writestr("</Files>\n</TreevizFileSystem>\n");
	}

	/////////////// private: Users ///////////////
	inline void ASTMITTreeVisualizerXMLProducerVisitor::makeUsers(void) {
		new(&users[0]) User("operator", "Operator");
	}
	/////////////// private: Folder ///////////////
	inline ASTMITTreeVisualizerXMLProducerVisitor::Folder ASTMITTreeVisualizerXMLProducerVisitor::folder(char const* const _name) {
		return Folder(_name, folder_id_namer++);
	}
	///////////////

	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Number			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(String			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Nil				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(True			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(False			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Add				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Sub				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Mul				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Div				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Mod				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Lt				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Gt				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Le				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Ge				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Eq				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Ne				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Or				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Not				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(And				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(For				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(While			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(If				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(IfElse			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Return			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Semicolon		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Break			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Continue		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Block			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Assign			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(NormalCall		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(MethodCall		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(FuncdefCall		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(ActualArguments	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Function		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(LamdaFunction	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(FormalArguments	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(ID				)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(LocalID			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(GlobalID		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(PreIncr			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(PostIncr		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(PreDecr			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(PostDecr		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(UnaryNot		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(UnaryMin		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Object			)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(EmptyObject		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(UnindexedMember	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(IndexedMember	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(ObjectMember	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(ObjectIndex		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(CallMember		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(CallIndex		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(MetaParse		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(MetaPreserve	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(MetaEvaluate	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(MetaUnparse		)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(MetaParseString	)
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(SinCode			)

} // namespace SIN
