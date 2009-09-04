#include <assert.h>
#include "SINConstants.h"
#include "SINASTNode.h"
#include "SINASTVisitor.h"
#include "SINASTUnparseTreeVisitor.h"
#include "SINASTTreeVisualisationVisitor.h"
#include "SINAssert.h"
#include "SINAlloc.h"
#include "SINASTCloneVisitor.h"

namespace SIN {

    ///--------- SIN AST ---------
	
	//---------------------------------------------------
	
	ASTNode::ASTNode(void):
		leftParenthesis(false),
		rightParenthesis(false),
		name(ASTNodeFactory::NextName()),
		associatedFileName(""),
		associatedFileLine(0),
		id(ASTNodeFactory::NextID())
	{}


	//---------------------------------------------------

    ASTNode::ASTNode(String const &_name, String const & fileName, const unsigned int line):
		leftParenthesis(false),
		rightParenthesis(false),
		name(_name),
		associatedFileName(fileName),
		associatedFileLine(line),
		id(ASTNodeFactory::NextID())
	{}


	//---------------------------------------------------

	ASTNode::ASTNode(ASTNode const&_other):
		leftParenthesis(_other.leftParenthesis),
		rightParenthesis(_other.rightParenthesis),
		name(_other.name),
		associatedFileName(_other.associatedFileName),
		associatedFileLine(_other.associatedFileLine),
		id(_other.id)
	{}

	//---------------------------------------------------


    ASTNode::~ASTNode(void) {}


	//---------------------------------------------------

    String const &ASTNode::Name(void) const 
		{	return name;	}


	//---------------------------------------------------

	ASTNode::ID_t const& ASTNode::ID(void) const 
		{	return id;	}
	

	//---------------------------------------------------

	void ASTNode::Accept(ASTTreeVisualisationVisitor *_v) {
		SINASSERT(_v);
		_v->Visit(*this);
		_v->IncreaseIndentationLevel();
		iterator const end_ = end();
		for (iterator ite = begin(); ite != end_; ++ite)
			static_cast<ASTNode&>(*ite).Accept(_v);
		_v->DecreaseIndentationLevel();
	}
	

	//---------------------------------------------------

	ASTNode *ASTNode::Clone(void) const { SINASSERT(!"Not cloning generally"); return 0x00;}
	

	//---------------------------------------------------

	String const to_string(ASTNode const &_node) 
		{	return to_string(_node.Name());	}

	//---------------------------------------------------

	void DeleteAST(ASTNode* const _root_p) {
		ASTNode::iterator ite(_root_p->begin());
		ASTNode::iterator const end(_root_p->end());
		for (; ite != end; ++ite)
			DeleteAST(static_cast<ASTNode*>(&*ite));
		SINDELETE(_root_p);
	}

	//---------------------------------------------------

	ASTNode* CopyAST(ASTNode* const _root) {
		ASTCloneVisitor cloner;
		_root->Accept(&cloner);
		SINDELETE(cloner.TakeNodesList());
		return cloner.Root();
	}

	//---------------------------------------------------

	bool ASTNode::operator ==(const ASTNode & _other) const {
		return id == _other.id;
	}

	//---------------------------------------------------

	bool ASTNode::operator !=(const ASTNode & _other) const {
		return id != _other.id;
	}

	//---------------------------------------------------

	bool ASTNode::HasLeftParenthesis(void) const
		{	return leftParenthesis;	}
	
	//---------------------------------------------------	
	
	bool ASTNode::HasRightParenthesis(void)const
		{	return rightParenthesis;	}

	//---------------------------------------------------	

	void ASTNode::AddLeftParenthesis(void)
		{	leftParenthesis = true;	}

	//---------------------------------------------------	

	void ASTNode::AddRightParenthesis(void)
		{	rightParenthesis = true;	}

	//---------------------------------------------------	

	void ASTNode::RemoveLeftParenthesis(void)
		{	leftParenthesis = false;	}

	//---------------------------------------------------	

	void ASTNode::RemoveRightParenthesis(void)
		{	rightParenthesis = false;	}

	///--------- AST Node Factory ----------
	ASTNodeFactory::ASTNodeFactory(void): namer("ASTNode-"), next_id(0x00ul) {}

	//---------------------------------------------------

	ASTNodeFactory::ASTNodeFactory(ASTNodeFactory const& _other): namer(""), next_id(0xbee1cebul) {
		SINASSERT(!"Copy constructor called for singleton class SIN::ASTNodeFactory");
		throw String("Copy constructor called for singleton class SIN::ASTNodeFactory");
	}
	
	
	//---------------------------------------------------
	ASTNodeFactory::~ASTNodeFactory(void) {}
	
	
	//---------------------------------------------------
	// singleton related
	ASTNodeFactory* ASTNodeFactory::singleton = 0x00;
	
	
	//---------------------------------------------------
	
	bool ASTNodeFactory::singleton_created = false;
	
	
	//---------------------------------------------------
	
	void ASTNodeFactory::SingletonCreate(void) {
		SINASSERT(!singleton_created);
		if ((singleton = SINEW(ASTNodeFactory)) != 0x00)
			singleton_created = true;
	}
	
	
	//---------------------------------------------------
	
	bool ASTNodeFactory::SingletonCreated(void) 
		{	return singleton_created;	}
	
	
	//---------------------------------------------------

	void ASTNodeFactory::SingletonDestroy(void) {
		SINASSERT(singleton_created);
		SINDELETE(singleton);
		singleton_created = false;
	}
	
	
	//---------------------------------------------------

	ASTNodeFactory& ASTNodeFactory::SingletonInstance(void) {
		SINASSERT(singleton_created);
		return *(singleton_created ? singleton : 0x00);
	}
	
	
	//---------------------------------------------------
	// convenience methods
	String const ASTNodeFactory::NextName(void) 
		{	return SingletonInstance().iNextName();	}
	
	
	//---------------------------------------------------
	
	ASTNode::ID_t const ASTNodeFactory::NextID(void) 
		{	return SingletonInstance().iNextID();	}
	
	
	//---------------------------------------------------
	// instance factory methods
	String const ASTNodeFactory::iNextName(void) 
		{	return namer++;	}


	//---------------------------------------------------

	ASTNode::ID_t const ASTNodeFactory::iNextID(void) 
		{	return next_id++;	}

} // namespace SIN
