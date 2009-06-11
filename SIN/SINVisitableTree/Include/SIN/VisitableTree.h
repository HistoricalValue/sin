#ifndef __SIN__VisitableTree_h__
#define __SIN__VisitableTree_h__

#include <cstdlib>
#include "SIN/Visitor.h"
#include <vector>

namespace SIN {
    /** A minimal tree-like container, which keeps references to all relatives,
      * keeps sorted children and is visitable.
      */
    class VisitableTree {
        VisitableTree const *parent;
        std::vector<VisitableTree const *> kids;
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
        /** get number of kids */
        size_t numberOfKids(void) const;
        /** append a child */
        VisitableTree &operator<<(VisitableTree const *_child);

        /** accept a visitor */
        virtual void acceptVisitor(Visitor const &_visitor) const;

    }; // class VisitableTree
} // namespace SIN

#endif /* __SIN__VisitableTree_h__ */
