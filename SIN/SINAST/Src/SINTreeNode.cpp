#include "SINTreeNode.h"
#include "SINAssert.h"
#include "SINAlloc.h"
#include <cassert>
#include <stdexcept>

namespace SIN {
	//-----------------------------------------------------------------------	
	TreeNode::TreeNode(void):
	parent(0x00u), previous(0x00u), next(0x00u), width_of_descendants_tree(1u)
	{ }



   	//-----------------------------------------------------------------------	
	TreeNode::~TreeNode(void) { }



	//-----------------------------------------------------------------------
	TreeNode *TreeNode::operator [](size_t _index) const {
		TreeNode *result = 0x00;
		try {
			result = children.at(_index);
		}
		catch(std::out_of_range e) { }
		return result;
	}



	//-----------------------------------------------------------------------
	size_t TreeNode::WidthOfDescendantsTree(void) const {
		return width_of_descendants_tree;
	}



   	//-----------------------------------------------------------------------	
		size_t TreeNode::NumberOfChildren(void) const {
				return children.size();
		}

	
	
	//-----------------------------------------------------------------------
	TreeNode &TreeNode::operator <<(TreeNode *const _new_kid) {
		TreeNode *const parent_I = this;
		_new_kid->parent = parent_I;
		_new_kid->next = 0x00u;
		if (parent_I->NumberOfChildren() > 0) {
			_new_kid->previous = parent_I->children.back();
			parent_I->children.back()->next = _new_kid;
		}
		else
			_new_kid->previous = 0x00u;
		parent_I->children.push_back(_new_kid);
		parent_I->UpdateWidthOfDescendantsTree();
		return *this;
	}

	//-----------------------------------------------------------------------
	TreeNode &TreeNode::operator >>(TreeNode *const _parent) {
		TreeNode *const new_kid_I = this;
		new_kid_I->parent = _parent;
		new_kid_I->previous = 0x00u;
		if (_parent->NumberOfChildren() > 0) {
			new_kid_I->next = _parent->children.front();
			_parent->children.front()->previous = new_kid_I;
		}
		else
			new_kid_I->next = 0x00u;
		_parent->children.insert(_parent->children.begin(), new_kid_I);
		_parent->UpdateWidthOfDescendantsTree();
		return *_parent;
	}

	//-----------------------------------------------------------------------
	TreeNode *TreeNode::GetParent(void) const {
		return parent;
	}


	
	//-----------------------------------------------------------------------
	void TreeNode::SetParent(TreeNode *_parent) {
		parent = _parent;
	}

	
	
	//-----------------------------------------------------------------------
	TreeNode *TreeNode::GetNext(void) const {
		return next;
	}
   
	
	
	//-----------------------------------------------------------------------
	void TreeNode::SetNext(TreeNode *_next) {
		next = _next;
	}

	
	
	//-----------------------------------------------------------------------	
	TreeNode *TreeNode::GetPrevious(void) const {
		return previous;
	}

	
	
	//-----------------------------------------------------------------------	
	void TreeNode::SetPrevious(TreeNode *_previous) {
		previous = _previous;
	}

	
	
	//-----------------------------------------------------------------------
	void TreeNode::UpdateWidthOfDescendantsTree(void) {
		width_of_descendants_tree = 0;
		for (children_const_iterator i = children.begin(); i != children.end(); ++i)
			width_of_descendants_tree += (*i)->WidthOfDescendantsTree();
		if (parent)
			parent->UpdateWidthOfDescendantsTree();
	}



	//-----------------------------------------------------------------------
	void TreeNode::DeleteTree(TreeNode *_root){
		SINASSERT(_root);

		for(TreeNode *child = (*SINPTR(_root))[0], *nxtChild; child != NULL; child = nxtChild){
			nxtChild = +(*SINPTR(child));
			DeleteTree(child);
		}
		SINDELETE(_root);
	}

} // namespace SIN
