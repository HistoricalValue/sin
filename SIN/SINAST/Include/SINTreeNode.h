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
		/** returns tha width of this node's tree of descendats.
		  * (In other words, the number of columns required to represent
		  *  the tree which has this node as root, in a tree-like
		  *  representation). */
		size_t WidthOfDescendantsTree(void) const;

		
		/** append a child (returns self). Returns this. */
		TreeNode &operator<<(TreeNode *_child);
		/** prepends this node as a child to the given parent. Returns the parent. */
                TreeNode &operator>>(TreeNode *_parent);


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

		/** Deletes the whole subtree under root including root */
		static void DeleteTree(TreeNode *_root);

	protected:
		void UpdateWidthOfDescendantsTree(void);

		private:
		TreeNode *parent, *previous, *next;
		std::vector<TreeNode *>	children;
		typedef std::vector<TreeNode *> children_type;
		typedef children_type::iterator children_iterator;
		typedef children_type::const_iterator children_const_iterator;
		size_t width_of_descendants_tree;
	}; // class TreeNode

} // namespace SIN


#endif //__SIN_TREE_NODE_H__
