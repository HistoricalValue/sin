#include "SIN/VisitableTree.h"
#include <cassert>

namespace SIN {
    ////////////////////////////////
    VisitableTree::~VisitableTree(void) { }
    ////////////////////////////////
    VisitableTree::VisitableTree(VisitableTree const *_parent):
    parent(_parent)
    { }
    ////////////////////////////////
    void VisitableTree::acceptVisitor(Visitor const &_visitor) const {
        // nothing happens
    }
    ////////////////////////////////
    VisitableTree const *VisitableTree::getParent(void) const {
        return parent;
    }
    ////////////////////////////////
    VisitableTree const &VisitableTree::operator [](size_t _index) const {
        return *kids[_index];
    }
    ////////////////////////////////
    VisitableTree &VisitableTree::operator <<(VisitableTree const *_kid) {
        kids.push_back(_kid);
        return *this;
    }
    ////////////////////////////////
    size_t VisitableTree::numberOfKids(void) const { 
        return kids.size();
    }
    ////////////////////////////////
} // namespace SIN
