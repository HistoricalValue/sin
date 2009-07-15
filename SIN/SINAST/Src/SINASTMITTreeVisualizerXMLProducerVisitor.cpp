#include "SINASTMITTreeVisualizerXMLProducerVisitor.h"
#include "SINAssert.h"

#define SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(NODENAME)				\
	void ASTMITTreeVisualizerXMLProducerVisitor::Visit(NODENAME##ASTNode const& _node) {	\
		Visit(static_cast<ASTNode const&>(_node));											\
	}

namespace {
	static SIN::String const html(SIN::String const& _str) {
		SIN::String result;
		char const* str = _str.c_str();
		const size_t len = _str.Length();
		SINASSERT(strlen(str) == len);
		for (register size_t i = 0; i < len; ++i) {
			register char c = str[i];
			switch (c) {
				case '"': result << "&quot;"; break;
				case '<': result << "&lt;"; break;
				case '>': result << "&gt;"; break;
				case '&': result << "&amp;"; break;
				default : result << c;
			}
		}
		return result;
	}
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

	void ASTMITTreeVisualizerXMLProducerVisitor::Visit(ASTNode const& _node) {
		const size_t numberOfChildren = _node.NumberOfChildren();
		register bool empty =  numberOfChildren == 0;
		writeFolder(folder(_node.Name()), empty);

		if (!empty) {
			for (register size_t i = 0; i < numberOfChildren; ++i)
				static_cast<ASTNode*>(_node[i])->Accept(this);
			writeFolderClosing();
		}
	}

	/////////////// private: write* ///////////////

	void ASTMITTreeVisualizerXMLProducerVisitor::writePrelude(void) {
		out << "<TreevizFileSystem  created=\"2008-07-04 11:34:08\" name=\"SIN AST\">\n<Users>\n";
		FOREACH(array_iterable(users))
			writeUser(*ITER(array_iterable(users)));
		out << "</Users>\n<Files>\n";
	}

	void ASTMITTreeVisualizerXMLProducerVisitor::writeUser(User const& user) {
		out << "<User id=\"" << html(user.ID()) << "\" name=\"" << html(user.Name()) << "\" firstname=\"John\" lastname=\"Doe\" email=\"john.doe@email.com\" created=\"2007-08-27 09:11:54\" used=\"2008-06-23 08:29:15\">\n</User>\n";
	}

	void ASTMITTreeVisualizerXMLProducerVisitor::writeFolder(Folder const& folder, bool empty) {
		out << "<Folder id=\"" << html(folder.ID()) << "\" name=\"" << html(folder.Name()) << "\" created=\"2008-06-24 15:15:03\" modified=\"2005-08-04 17:35:06\" ownerRef=\"" << html(users[0].ID()) << "\" size=\"2048\"" << (empty ? "/" : "") << ">\n";
	}

	void ASTMITTreeVisualizerXMLProducerVisitor::writeFolderClosing(void) {
		out << "</Folder>\n";
	}

	void ASTMITTreeVisualizerXMLProducerVisitor::writeOutro(void) {
		out << "</Files>\n</TreevizFileSystem>\n";
	}

	/////////////// private: Users ///////////////

	void ASTMITTreeVisualizerXMLProducerVisitor::makeUsers(void) {
		users[0] = User("operator", "Operator");
	}

	ASTMITTreeVisualizerXMLProducerVisitor::User::User(String const& _id, String const& _name):
	id(_id),
	name(_name)
	{
	}

	String const& ASTMITTreeVisualizerXMLProducerVisitor::User::ID(void) const {
		return id;
	}

	String const& ASTMITTreeVisualizerXMLProducerVisitor::User::Name(void) const {
		return name;
	}

	/////////////// private: Folder ///////////////
	ASTMITTreeVisualizerXMLProducerVisitor::Folder ASTMITTreeVisualizerXMLProducerVisitor::folder(String const& _name) {
		return Folder(_name, folder_id_namer++);
	}

	ASTMITTreeVisualizerXMLProducerVisitor::Folder::Folder(String const& _name, String const& _id):
	name(_name),
	id(_id)
	{
	}

	String const& ASTMITTreeVisualizerXMLProducerVisitor::Folder::ID(void) const {
		return id;
	}

	String const& ASTMITTreeVisualizerXMLProducerVisitor::Folder::Name(void) const {
		return name;
	}
	///////////////

	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Number )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(String )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Nil    )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(True   )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(False  )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Add    )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Sub    )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Mul    )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Div    )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Mod    )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Incr   )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Decr   )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Lt     )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Gt     )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Le     )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Ge     )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Eq     )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Ne     )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Or     )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Not    )
	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(And    )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(For    )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(While  )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(If     )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(IfElse )
//	SINASTMITTREEVISUALIZERXMLPRODUCER_DEFAULT_VISIT_DEFINITION(Id	   )

} // namespace SIN