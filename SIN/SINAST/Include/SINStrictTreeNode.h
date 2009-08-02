#ifndef __SIN__STRICT_TREE_NODE_H__
#define __SIN__STRICT_TREE_NODE_H__

#include "SINAssert.h"

#define SIN_STRICTTREE_ASSERTS
#define SIN_STRICTTREE_ASSERTS_INVARIANTS

namespace SIN {

	/** A strict Tree Node structure.
	  *
	  * Keeps strict and up to date family information
	  * (no double fathers, etc).
	  *
	  * When a family bond is updated for a node, all related and concerned
	  * nodes and their bonds are updated as well.
	  *
	  * At the aame time, this node allows for convenient and
	  * flexible reparenting and constructing or reconstructing
	  * a family tree from scattered nodes.
	  */
	class StrictTreeNode {
	public:
		StrictTreeNode(void): prev_bro(0x00), parent(0x00), next_bro(0x00), first_child(0x00), last_child(0x00), number_of_children(0u) { }
		~StrictTreeNode(void) { }

		inline StrictTreeNode& operator >>(StrictTreeNode& _parent) { _parent.l1InheritFirst(this); return _parent; }
		inline StrictTreeNode& operator <<(StrictTreeNode* _child) { l1InheritLast(_child); return *this; }
		inline StrictTreeNode& operator  ,(StrictTreeNode* _next_bro) { l1BondNextBro(_next_bro); return *_next_bro; }
		inline StrictTreeNode& operator  +(StrictTreeNode* _first_of_orphan_chain) { l1AdoptOrphans(_first_of_orphan_chain); return *this; }

		// Emulation API -- DEPRECATED
		inline StrictTreeNode* GetParent(void) const { return l2Parent(); } // DEPRECATED
		inline size_t NumberOfChildren(void) const { return l2NumberOfChildren(); } // DEPRECATED
		inline StrictTreeNode* GetNext(void) const { return l2NextBro(); } // DEPRECATED
		inline StrictTreeNode* operator +(void) const { return GetNext(); } // DEPRECATED
		inline StrictTreeNode* GetPrevious(void) const { return l2PreviousBro(); } // DEPRECATED
		inline StrictTreeNode& ConnectChild(StrictTreeNode* _ch) { if (_ch != 0x00) return *this + _ch; else return *this; } // DEPRECATED
		inline void SetRightSibling(StrictTreeNode* _next_bro) { *this , _next_bro; } // DEPRECATED
		// end Emulation API


		template <typename _T> struct iterator_base {
			typedef _T type;
			typedef _T* ptr;
			typedef _T& rfr;
			explicit iterator_base(ptr _p): p(_p) { }
			iterator_base(iterator_base<type> const& _o): p(_o.p) { }
			rfr operator *(void) const { return *p; }
			ptr operator ->(void) const { return p; }
			iterator_base<type> const operator ++(void) { p = p->next_bro; return *this; }
			iterator_base<type> const operator --(void) { p = p->prev_bro; return *this; }
			iterator_base<type> const operator ++(int)  { ptr const _p = p; ++*this; return iterator_base<type>(_p); }
			iterator_base<type> const operator --(int)  { ptr const _p = p; --*this; return iterator_base<type>(_p); }
			bool operator ==(iterator_base<type> const& _o) const { return p == _o.p; }
			bool operator !=(iterator_base<type> const& _o) const { return p != _o.p; }
		private:
			ptr p;
		};
		typedef iterator_base<StrictTreeNode> iterator;
		typedef iterator_base<StrictTreeNode const> const_iterator;
		
		inline iterator const begin(void) { return iterator(first_child); }
		inline iterator const end(void) { return iterator(0x00); }
		inline iterator const rbegin(void) { return iterator(last_child); }
		inline iterator const rend(void) { return iterator(0x00); }
		inline const_iterator const begin(void) const { return const_iterator(first_child); }
		inline const_iterator const end(void) const { return const_iterator(0x00); }
		inline const_iterator const rbegin(void) const { return const_iterator(last_child); }
		inline const_iterator const rend(void) const { return const_iterator(0x00); }


		// functor returns false to stop iterating
		template <typename _FunctorType> inline _FunctorType for_each(_FunctorType _f) {
			const_iterator const end_ = end();
			bool keep_iterating = true;
			for (const_iterator ite = begin(); keep_iterating && ite != end; ++ite)
				done = _f(*ite);
			return _f;
		}

	protected:
		typedef StrictTreeNode my_t;
		typedef my_t* my_p;
		typedef my_t& my_r;
		typedef my_t const* my_cp;
		typedef my_t const& my_cr;
	private:
		my_p first_child;
		my_p last_child;
		size_t number_of_children;
		my_p parent;
		my_p prev_bro;
		my_p next_bro;

		#define FOREACH_CHILD(ID)	for (my_p ID = first_child; ID != 0x00; ID = ID->next_bro)
		#define RFOREACH_CHILD(ID)	for (my_p ID = last_child; ID != 0x00; ID = ID->prev_bro)

		// Invariants
		// * FC->prev == NULL
		// * LC->next == NULL
		// ASSERT_INVARIANTS should always be safe for level1 and above
		#ifdef SIN_STRICTTREE_ASSERTS
		#define STRICT_TREE_ASSERT SINASSERT
		#else
		#define STRICT_TREE_ASSERT(C)
		#endif // SIN_STRICTTREE_ASSERTS
		inline bool __assert_from_first_child_to_last_child(void) const {
			my_p last_ch = 0x00;
			size_t children_counter = 0;
			for (my_p ch = first_child; ch != 0x00; ch = ch->next_bro) {
				STRICT_TREE_ASSERT(ch->parent == this);
				STRICT_TREE_ASSERT(ch->first_child != 0x00 ? ch->first_child->prev_bro == 0x00 : true);
				STRICT_TREE_ASSERT(ch->last_child != 0x00 ? ch->last_child->next_bro == 0x00 : true);
				STRICT_TREE_ASSERT(ch->prev_bro != 0x00 ? ch->prev_bro->next_bro == ch : true);
				STRICT_TREE_ASSERT(ch->next_bro != 0x00 ? ch->next_bro->prev_bro == ch : true);
				STRICT_TREE_ASSERT(ch->__assert_from_first_child_to_last_child());
				STRICT_TREE_ASSERT(ch->__assert_from_last_child_to_first_child());
				last_ch = ch;
				++children_counter;
			}
			STRICT_TREE_ASSERT(last_ch == last_child);
			STRICT_TREE_ASSERT(children_counter == number_of_children);
			return true;
		}
		inline bool __assert_from_last_child_to_first_child(void) const {
			my_p first_ch = 0x00;
			size_t children_counter = 0;
			for (my_p ch = last_child; ch != 0x00; ch = ch->prev_bro) {
				STRICT_TREE_ASSERT(ch->parent == this);
				STRICT_TREE_ASSERT(ch->first_child != 0x00 ? ch->first_child->prev_bro == 0x00 : true);
				STRICT_TREE_ASSERT(ch->last_child != 0x00 ? ch->last_child->next_bro == 0x00 : true);
				STRICT_TREE_ASSERT(ch->prev_bro != 0x00 ? ch->prev_bro->next_bro == ch : true);
				STRICT_TREE_ASSERT(ch->next_bro != 0x00 ? ch->next_bro->prev_bro == ch : true);
				STRICT_TREE_ASSERT(ch->__assert_from_first_child_to_last_child());
				STRICT_TREE_ASSERT(ch->__assert_from_last_child_to_first_child());
				first_ch = ch;
				++children_counter;
			}
			STRICT_TREE_ASSERT(first_ch == first_child);
			STRICT_TREE_ASSERT(children_counter == number_of_children);
			return true;
		}
		#ifdef SIN_STRICTTREE_ASSERTS_INVARIANTS
		#define SIN_STRICTTREEE_ASSERT_INVARIANTS													\
			STRICT_TREE_ASSERT(first_child != 0x00 ? first_child->prev_bro == 0x00 : true);	\
			STRICT_TREE_ASSERT(last_child != 0x00 ? last_child->next_bro == 0x00 : true);	\
			STRICT_TREE_ASSERT(prev_bro != 0x00 ? prev_bro->next_bro == this : true);		\
			STRICT_TREE_ASSERT(next_bro != 0x00 ? next_bro->prev_bro == this : true); 		\
			STRICT_TREE_ASSERT(__assert_from_first_child_to_last_child());					\
			STRICT_TREE_ASSERT(__assert_from_last_child_to_first_child());
		#else
		#define SIN_STRICTTREEE_ASSERT_INVARIANTS
		#endif // SIN_STRICTTREE_ASSERTS_INVARIANTS
		
		// --- Level 0 ---
		// Self setting relatives. No assertions, no checks, no updates, no anything.
		inline void l0NB(my_p _nb) { next_bro = _nb; }
		inline void l0PB(my_p _pb) { prev_bro = _pb; }
		inline void l0PR(my_p _pr) { parent = _pr; }
		inline void l0FC(my_p _ch) { first_child = _ch; }
		inline void l0LC(my_p _ch) { last_child = _ch; }
		// Nullifiers
		inline void l0NBNULL(void) { l0NB(0x00); }
		inline void l0PBNULL(void) { l0PB(0x00); }
		inline void l0PRNULL(void) { l0PR(0x00); }
		inline void l0FCNULL(void) { l0FC(0x00); }
		inline void l0LCNULL(void) { l0LC(0x00); }
		inline void l0ALONEISE(void) { l0NBNULL(); l0PBNULL(); l0PRNULL(); l0FCNULL(); l0LCNULL(); }
		inline void l0ORPHANISE(void) { l0NBNULL(); l0PBNULL(); l0PRNULL(); }
		// Convenience to avoid checking if == NULL for relatives.
		// Otherwise it's pretty low level. No assertions and anything.
		// Naming is "Whose"2chars-(set)0chars-"what"2chars, so for example:
		// l0NBNB is read like "level 0 -- NextBro set NextBro -- so it sets
		// the next bro of our next bro, if we have one.
		// PB: Previous Bro    PR: Parent    NB: Next Bro
		inline void l0PBPB(my_p _pb) { if (prev_bro) prev_bro->prev_bro = _pb; }
		inline void l0PBPR(my_p _pr) { if (prev_bro) prev_bro->parent = _pr; }
		inline void l0PBNB(my_p _nb) { if (prev_bro) prev_bro->next_bro = _nb; }
		inline void l0NBPB(my_p _pb) { if (next_bro) next_bro->prev_bro = _pb; }
		inline void l0NBPR(my_p _pr) { if (next_bro) next_bro->parent = _pr; }
		inline void l0NBNB(my_p _nb) { if (next_bro) next_bro->next_bro = _nb; }
		// FC: First Child     LC: Last Child
		inline void l0FCPB(my_p _pb) { if (first_child) first_child->prev_bro = _pb; }
		inline void l0FCPR(my_p _pr) { if (first_child) first_child->parent = _pr; }
		inline void l0FCNB(my_p _nb) { if (first_child) first_child->next_bro = _nb; }
		inline void l0LCPB(my_p _pb) { if (last_child) last_child->prev_bro = _pb; }
		inline void l0LCPR(my_p _pr) { if (last_child) last_child->parent = _pr; }
		inline void l0LCNB(my_p _nb) { if (last_child) last_child->next_bro = _nb; }
		// Same stuff but as readers
		// PB: Previous Bro    PR: Parent    NB: Next Bro
		inline my_p l0PBPB(void) const { return prev_bro != 0x00 ? prev_bro->prev_bro : 0x00; }
		inline my_p l0PBPR(void) const { return prev_bro != 0x00 ? prev_bro->parent : 0x00; }
		inline my_p l0PBNB(void) const { return prev_bro != 0x00 ? prev_bro->next_bro : 0x00; }
		inline my_p l0NBPB(void) const { return next_bro != 0x00 ? next_bro->prev_bro : 0x00; }
		inline my_p l0NBPR(void) const { return next_bro != 0x00 ? next_bro->parent : 0x00; }
		inline my_p l0NBNB(void) const { return next_bro != 0x00 ? next_bro->next_bro : 0x00; }
		// FC: First Child     LC: Last Child
		inline my_p l0FCPB(void) const { return first_child != 0x00 ? first_child->prev_bro : 0x00; }
		inline my_p l0FCPR(void) const { return first_child != 0x00 ? first_child->parent : 0x00; }
		inline my_p l0FCNB(void) const { return first_child != 0x00 ? first_child->next_bro : 0x00; }
		inline my_p l0LCPB(void) const { return last_child != 0x00 ? last_child->prev_bro : 0x00; }
		inline my_p l0LCPR(void) const { return last_child != 0x00 ? last_child->parent : 0x00; }
		inline my_p l0LCNB(void) const { return last_child != 0x00 ? last_child->next_bro : 0x00; }
		// Some more elaborate tests, but still no checks, updates and assertions.
		inline bool l0IsMyChild(my_p _ch) const {
			bool ismychild = false;
			for (my_p ch = first_child; !ismychild && ch != 0x00; ch = ch->next_bro)
				ismychild = ch == _ch;
			return ismychild;
		}
		inline bool l0IsMyPreviousBro(my_p _br) const { return prev_bro == _br; }
		inline bool l0IsMyParent(my_p _pr) const { return parent == _pr; }
		inline bool l0IsMyNextBro(my_p _br) const { return next_bro == _br; }
		inline bool l0IsMyFirstChild(my_p _ch) const { return first_child == _ch; }
		inline bool l0IsMyLastChild(my_p _ch) const { return last_child == _ch; }
		inline bool l0HasPreviousBro(void) const { return prev_bro != 0x00; }
		inline bool l0HasParent(void) const { return parent != 0x00; }
		inline bool l0HasNextBro(void) const { return next_bro != 0x00; }
		inline bool l0HasFirstChild(void) const { return first_child != 0x00; }
		inline bool l0HasLastChild(void) const { return last_child != 0x00; }
		// most mundane: number of kids tracking
		inline void l0PlusKid(void) { ++number_of_children; }
		inline void l0MinusKid(void) { --number_of_children; }
		inline size_t l0NOC/* Number Of Children */(void) const { return number_of_children; }

		// Level 1
		// Breaking and making one way links. Notifies both parties. Also notified old relatives -- only 1 step away.
		// Making many level0 checks and assertions.
		// ---
		// Cuts this child off the children chain. Makes it an orphan
		// (cuts of the parent and sibling links).
		inline void l1AbandonChild(my_p _ch) { SIN_STRICTTREEE_ASSERT_INVARIANTS
			STRICT_TREE_ASSERT(_ch != 0x00); // have this too ...
			STRICT_TREE_ASSERT(this != 0x00);
			STRICT_TREE_ASSERT(_ch->l0IsMyParent(this) && _ch->l0HasParent());
			STRICT_TREE_ASSERT(l0IsMyChild(_ch));
			STRICT_TREE_ASSERT(_ch->l0HasPreviousBro() && l0IsMyChild(_ch->prev_bro) && _ch->l0PBNB() == _ch && _ch->prev_bro->l0IsMyParent(this) || !_ch->l0HasPreviousBro() && l0IsMyFirstChild(_ch));
			STRICT_TREE_ASSERT(_ch->l0HasNextBro() && l0IsMyChild(_ch->next_bro) && _ch->l0NBPB() == _ch && _ch->next_bro->l0IsMyParent(this) || !_ch->l0HasNextBro() && l0IsMyLastChild(_ch));
			_ch->l0PBNB(_ch->next_bro);
			_ch->l0NBPB(_ch->prev_bro);
			if (l0IsMyFirstChild(_ch))
				l0FC(_ch->next_bro);
			if (l0IsMyLastChild(_ch))
				l0LC(_ch->prev_bro);
			_ch->l0ORPHANISE();
			l0MinusKid();
			SIN_STRICTTREEE_ASSERT_INVARIANTS
		}
		inline void l1LeaveParent(void) { if (l0HasParent()) parent->l1AbandonChild(this); }
		inline void l1Inherit(
				my_p const _ch,
				void (StrictTreeNode::*const _end_nullifier)(void),
				void (StrictTreeNode::*const _end_connector_to)(my_p),
				my_p const _end_connect_node,
				void (StrictTreeNode::*const _old_end_connector_to)(my_p), /*  _ch is given as an argument to this one */
				void (StrictTreeNode::*const _end_setter)(my_p), /* _ch is given as an argumen to this one */
				bool (StrictTreeNode::*const _other_end_missing_too_predicate)(void) const,
				void (StrictTreeNode::*const _other_end_setter)(my_p), /* _ch is given as an argument to this one */
				void (StrictTreeNode::*const _kid_adjuster)(void)
		) { SIN_STRICTTREEE_ASSERT_INVARIANTS
			STRICT_TREE_ASSERT(_ch != 0x00);
			STRICT_TREE_ASSERT(_end_nullifier != 0x00);
			STRICT_TREE_ASSERT(_end_connector_to != 0x00);
			STRICT_TREE_ASSERT(_old_end_connector_to != 0x00);
			STRICT_TREE_ASSERT(_end_setter != 0x00);
			STRICT_TREE_ASSERT(_other_end_missing_too_predicate != 0x00);
			STRICT_TREE_ASSERT(_other_end_setter != 0x00);
			STRICT_TREE_ASSERT(_kid_adjuster != 0x00);
			STRICT_TREE_ASSERT(!_ch->l0IsMyParent(this));
			STRICT_TREE_ASSERT(!l0IsMyChild(_ch));
			STRICT_TREE_ASSERT(_ch->l0HasPreviousBro() && !l0IsMyChild(_ch->prev_bro) && _ch->l0PBNB() == _ch && !_ch->prev_bro->l0IsMyParent(this) || !_ch->l0HasPreviousBro());
			STRICT_TREE_ASSERT(_ch->l0HasNextBro() && !l0IsMyChild(_ch->next_bro) && _ch->l0NBPB() == _ch && !_ch->next_bro->l0IsMyParent(this) || !_ch->l0HasNextBro());
			_ch->l1LeaveParent();
			STRICT_TREE_ASSERT(!_ch->l0HasNextBro());
			STRICT_TREE_ASSERT(!_ch->l0HasPreviousBro());
			STRICT_TREE_ASSERT(!_ch->l0HasParent());
			// nulify the appropriate end (inherit-first: _ch->l0PBNULL())
			(_ch->*_end_nullifier)();
			// connect the other end to the appropriate node (inherit-first: _ch->l0NB(first_child))
			(_ch->*_end_connector_to)(_end_connect_node);
			// connect our old appropriate end to the new node (inherit-first: l0FCPB(_ch))
			(this->*_old_end_connector_to)(_ch);
			// set the appropriate end to the new node (inherit-first: l0FC(_ch))
			(this->*_end_setter)(_ch);
			// set the new kid's parent (us)
			_ch->l0PR(this);
			// conditional to check if the other end needs setting too (inherit-first: l0HasLastChild())
			if (!(this->*_other_end_missing_too_predicate)())
				// set the other end too (inherit-first: l0LC(_ch))
				(this->*_other_end_setter)(_ch);
			// adjust the number of kids (inherit-first: l0PlusKid())
			(this->*_kid_adjuster)();
			SIN_STRICTTREEE_ASSERT_INVARIANTS
		}
		inline void l1InheritFirst(my_p _ch) { l1Inherit(_ch, &StrictTreeNode::l0PBNULL, &StrictTreeNode::l0NB, first_child, &StrictTreeNode::l0FCPB, &StrictTreeNode::l0FC, &StrictTreeNode::l0HasLastChild, &StrictTreeNode::l0LC, &StrictTreeNode::l0PlusKid); }
		inline void l1InheritLast(my_p _ch) { l1Inherit(_ch, &StrictTreeNode::l0NBNULL, &StrictTreeNode::l0PB, last_child, &StrictTreeNode::l0LCNB, &StrictTreeNode::l0LC, &StrictTreeNode::l0HasFirstChild, &StrictTreeNode::l0FC, &StrictTreeNode::l0PlusKid); }
		// Orphan siblings: playing with those is allowed only for orphans. No middle linking, only first or last in the chain.
		static void l1BondBro(my_p const _prev, my_p const _next) {
			STRICT_TREE_ASSERT(_prev != 0x00);
			STRICT_TREE_ASSERT(_next != 0x00);
			STRICT_TREE_ASSERT(!_prev->l0HasParent());
			STRICT_TREE_ASSERT(!_next->l0HasParent());
			STRICT_TREE_ASSERT(!_prev->l0HasNextBro());
			STRICT_TREE_ASSERT(!_next->l0HasPreviousBro());
			_prev->l0NB(_next);
			_next->l0PB(_prev);
		}
		void l1BondNextBro(my_p const _nb) {SIN_STRICTTREEE_ASSERT_INVARIANTS
			l1BondBro(this, _nb);
			SIN_STRICTTREEE_ASSERT_INVARIANTS
		}
		void l1BondPreviousBro(my_p const _pb) {SIN_STRICTTREEE_ASSERT_INVARIANTS
			l1BondBro(_pb, this);
			SIN_STRICTTREEE_ASSERT_INVARIANTS
		}
		// Adopting a chain of orphans. Parent must have no kids.
		void l1AdoptOrphans(my_p const _first) {SIN_STRICTTREEE_ASSERT_INVARIANTS
			STRICT_TREE_ASSERT(_first != 0x00);
			STRICT_TREE_ASSERT(!l0HasFirstChild());
			STRICT_TREE_ASSERT(!l0HasLastChild());
			STRICT_TREE_ASSERT(l0NOC() == 0u);
			// find last and assert that they are all orphans at the same time
			// ... at the same time as reparenting them
			my_p last;
			for (my_p imp = _first; imp != 0x00; imp = imp->next_bro) {
				last = imp;
				STRICT_TREE_ASSERT(!imp->l0HasParent());
				imp->l0PR(this);
				l0PlusKid();
			}		
			STRICT_TREE_ASSERT(!_first->l0HasPreviousBro());
			STRICT_TREE_ASSERT(!last->l0HasNextBro());
			l0FC(_first);
			l0LC(last);
			SIN_STRICTTREEE_ASSERT_INVARIANTS
		}

		// Level 2
		// super hight api, asserts all 
		inline my_p l2Parent(void) const {
			SIN_STRICTTREEE_ASSERT_INVARIANTS 
			return parent;
		}
		inline size_t l2NumberOfChildren(void) const {
			SIN_STRICTTREEE_ASSERT_INVARIANTS 
			return l0NOC();
		}
		inline StrictTreeNode* l2NextBro(void) const {
			SIN_STRICTTREEE_ASSERT_INVARIANTS
			return next_bro;
		}
		inline StrictTreeNode* l2PreviousBro(void) const {
			SIN_STRICTTREEE_ASSERT_INVARIANTS
			return prev_bro;
		}

		// Unused and private-protected
		StrictTreeNode(StrictTreeNode const&) { SINASSERT(!"No"); }
	}; // class StrictTreeNode

} // namespace SIN

#endif // __SIN__STRICT_TREE_NODE_H__
