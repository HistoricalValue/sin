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
        TreeNode *operator[](size_t _index);
        
		
		/** append a child (returns self) */
        TreeNode &operator<<(TreeNode *_child);

        
		/** get parent or 0x00 if this tree has no parent */
        TreeNode *GetParent(void) const;
        TreeNode *operator *(void) const { return GetParent(); }
        /** set this node's parent */
		void SetParent(TreeNode * _parent);
        
		
		/** get this node's right (next) sibling or 0x00 if there isn't any */
        TreeNode *GetRightSibling(void) const;
        TreeNode *operator +(void) const { return GetRightSibling(); }
        /** set this node's right (next) sibling */
		void SetRightSibling(TreeNode *_right);
        
		
		/** get this node's left (previous) sibling or 0x00 if there isn't any */
        TreeNode *GetLeftSibling(void) const;
        TreeNode *operator -(void) const { return GetLeftSibling(); }
        /** sets this node's left (previous) sibling */
		void SetLeftSibling(TreeNode *_left);


    private:
		TreeNode *parent, *leftSibling, *rightSibling;
		std::vector<TreeNode *>	children;
	}; // class TreeNode

} // namespace SIN


#endif //__SIN_TREE_NODE_H__