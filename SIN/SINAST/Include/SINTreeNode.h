#ifndef __SIN_TREE_NODE_H__
#define __SIN_TREE_NODE_H__

#include <vector>

namespace SIN {

    /** A minimal tree-like container, which keeps references to all relatives,
      * keeps sorted children and is visitable.
      */
	class TreeNode {
	public:
		TreeNode(void);
		virtual ~TreeNode();


        /** get number of children */
        size_t NumberOfChildren(void) const;
		/** get child at index _index_ or 0x00 if there is no child for that
          * index */
        TreeNode *operator[](size_t _index) const;
        
		
		/** append a child (returns self) */
        TreeNode &operator<<(TreeNode *_child);

        
		/** get parent or 0x00 if this tree has no parent */
        TreeNode *GetParent(void) const;
        TreeNode *operator *(void) const { return GetParent(); }
        /** set this node's parent */
		void SetParent(TreeNode * _parent);
        
		
		/** get this node's next (right) sibling or 0x00 if there isn't any */
        TreeNode *GetNext(void) const;
        TreeNode *operator +(void) const { return GetNext(); }
        TreeNode *GetRightSibling(void) const { return GetNext(); } // for santa
        /** set this node's next (right) sibling */
		void SetNext(TreeNode *_next);
        void SetRightSibling(TreeNode *_right) { SetNext(_right); } // for santa
        
		
		/** get this node's previous (left) sibling or 0x00 if there isn't any */
        TreeNode *GetPrevious(void) const;
        TreeNode *operator -(void) const { return GetPrevious(); }
        TreeNode *GetLeftSibling(void) const { return GetPrevious(); } // for santa
        /** sets this node's previous (left) sibling */
		void SetPrevious(TreeNode *_previous);
        void SetLeftSibling(TreeNode *_left) { SetPrevious(_left); } // for santa


    private:
		TreeNode *parent, *previous, *next;
		std::vector<TreeNode *>	children;
	}; // class TreeNode

} // namespace SIN


#endif //__SIN_TREE_NODE_H__