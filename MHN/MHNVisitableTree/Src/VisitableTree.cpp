#include "MHN/VisitableTree.h"
#include <cassert>

namespace MHN {
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
    ////////////////////////////////
    ////////////////////////////////
} // namespace MHN
