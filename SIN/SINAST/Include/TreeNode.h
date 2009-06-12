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


		/** get child at index _index_ or 0x00 if there is no child for that
          * index */
        TreeNode *operator[](size_t index);
        
		
		/** get number of kids */
        size_t NumberOfKids(void) const;
        
		
		/** append a child (returns self) */
        TreeNode & operator<<(TreeNode *_child);

        
		/** get parent or 0x00 if this tree has no parent */
        TreeNode * GetParent(void);
		void SetParent(const TreeNode * _parent) {parent = _parent};
		TreeNode * operator *(void) { return GetParent(); }


        
		
		/** get the next (right) sibling of this tree or 0x00 if
          * there isn't any */
        TreeNode * GetRightSibling(void);
		void SetNextSilBling(const TreeNode * right) { rightSibling = right; }
		TreeNode * operator +(void) { return GetNextSibling(); }
        
		
		/** get the previous (left) sibling of this tree or 0x00 if
          * there isn't any */
        TreeNode * GetLeftSibling(void);
		void SetPreviousSibling(const TreeNode *prev) { leftSibling = left; }
		TreeNode * operator -(void) { return GetPreviousSibling(); }



		//AcceptBuck(TreeVisitor);
		//AcceptAST(TreeVisitor);






	private:
		TreeNode * parent, *leftSibling, *rightSibling;
		std::vector<TreeNode *>	children;

	};
}	//end of namespace SIN


#endif __SIN_TREE_NODE_H__