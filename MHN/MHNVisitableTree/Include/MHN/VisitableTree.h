#ifndef __MHN__VisitableTree_h__
#define __MHN__VisitableTree_h__

#include <cstdlib>
#include "MHN/Visitor.h"

namespace MHN {
    /** A minimal tree-like container, which keeps references to all relatives,
      * keeps sorted children and is visitable.
      */
    class VisitableTree {
        VisitableTree const *parent;
    public:
        VisitableTree(
            VisitableTree const *_parent =
                    static_cast<VisitableTree const *>(0x00)
        );
        virtual ~VisitableTree(void);

        /** get parent or 0x00 if this tree has no parent */
        VisitableTree const *getParent(void) const;
        /** get child at index _index_ */
        VisitableTree const &operator[](size_t index) const;
        /** append a child */
        void operator<<(VisitableTree const *_child);

        /** accept a visitor */
        virtual void acceptVisitor(Visitor const &_visitor) const;

    }; // class VisitableTree
} // namespace MHN

#endif /* __MHN__VisitableTree_h__ */
