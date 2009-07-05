#include "SINTreeNode.h"
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
    TreeNode &TreeNode::operator <<(TreeNode *_kid) {
        _kid->parent = this;
        _kid->next = 0x00u;
        if (NumberOfChildren() > 0) {
            _kid->previous = children.back();
            children.back()->next = _kid;
        }
        else
            _kid->previous = 0x00u;
        children.push_back(_kid);
		UpdateWidthOfDescendantsTree();
        return *this;
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
} // namespace SIN
