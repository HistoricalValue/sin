#include "SINASTNode.h"
#include <iostream>
#include <cassert>
#include "SINConstants.h"
#include "SINASTCommon.h"
#include "SINTest.h"
#include "SINTreeNode.h"
#include "SINOutputStream.h"
#include "SINTestingCommon.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "Common.h"

#define SINTESTSAST_RUN(NAME)               SINTESTS_RUNTEST(NAME)
#define SINTESTSAST_TESTDEF(NAME,TESTCODE)  SINTESTS_TESTDEF(NAME,TESTCODE)
#define SINTESTSAST_TESTRUN(NAME)           SINTESTS_CALLTEST(NAME)

#define SINTESTSAST_TREENODE_SUPERTEST(CLASSNAME) { \
    TRY(CLASSNAME().GetParent() == 0x00);           \
    CLASSNAME parent;                               \
    CLASSNAME kid0;                                 \
    CLASSNAME kid1;                                 \
    CLASSNAME kid2;                                 \
    TRY(parent.GetParent()         ==  0x00u);      \
    TRY(parent.GetNext()           ==  0x00u);      \
    TRY(parent.GetPrevious()       ==  0x00u);      \
    TRY(parent.NumberOfChildren()   ==  0x00u);     \
    TRY(kid0.GetParent()           ==  0x00u);      \
    TRY(kid0.GetNext()             ==  0x00u);      \
    TRY(kid0.GetPrevious()         ==  0x00u);      \
    TRY(kid0.NumberOfChildren()     ==  0x00u);     \
    TRY(kid1.GetParent()           ==  0x00u);      \
    TRY(kid1.GetNext()             ==  0x00u);      \
    TRY(kid1.GetPrevious()         ==  0x00u);      \
    TRY(kid1.NumberOfChildren()     ==  0x00u);     \
    TRY(kid2.GetParent()           ==  0x00u);      \
    TRY(kid2.GetNext()             ==  0x00u);      \
    TRY(kid2.GetPrevious()         ==  0x00u);      \
    TRY(kid2.NumberOfChildren()     ==  0x00u);     \
    parent << &kid0 << &kid1 << &kid2;              \
    TRY(parent[0]               ==  &kid0);         \
    TRY(parent[1]               ==  &kid1);         \
    TRY(parent[2]               ==  &kid2);         \
    TRY(parent[666]             ==  0x00u);         \
    TRY(parent.GetParent()         ==  0x00u);      \
    TRY(parent.GetNext()           ==  0x00u);      \
    TRY(parent.GetPrevious()       ==  0x00u);      \
    TRY(parent.NumberOfChildren()   ==  0x03u);     \
    TRY(kid0.GetParent()           ==  &parent);    \
    TRY(kid0.GetNext()             ==  &kid1);      \
    TRY(kid0.GetPrevious()         ==  0x00u);      \
    TRY(kid0.NumberOfChildren()     ==  0x00u);     \
    TRY(kid0[0]                 ==  0x00u);         \
    TRY(kid1.GetParent()           ==  &parent);    \
    TRY(kid1.GetNext()             ==  &kid2);      \
    TRY(kid1.GetPrevious()         ==  &kid0);      \
    TRY(kid1.NumberOfChildren()     ==  0x00u);     \
    TRY(kid1[0]                 ==  0x00u);         \
    TRY(kid2.GetParent()           ==  &parent);    \
    TRY(kid2.GetNext()             ==  0x00u);      \
    TRY(kid2.GetPrevious()         ==  &kid1);      \
    TRY(kid2.NumberOfChildren()     ==  0x00u);     \
    TRY(kid2[0]                 ==  0x00u);       } \
    TRY(true)

namespace SIN {
    namespace Tests {
        namespace AST {
            static InstanceProxy<Logger> logger;

            SINTESTSAST_TESTDEF(TreeNode,
                SINTESTSAST_TREENODE_SUPERTEST(TreeNode);
            )

            typedef ValueHolder<CONST_NUMBER, int> ValueHolderNum;
            SINTESTSAST_TESTDEF(ValueHolder, 
                ValueHolderNum vh(23);
                TRY(vh.GetType() == CONST_NUMBER);
                TRY(vh.GetValue() == 23);
                TRY(vh.GetValueStr() == "23");
                vh.SetValue(12);
                TRY(vh.GetValue() == 12);
                //TRY(vh == 12);
                TRY(vh.GetValueStr() == "12");
            )

            SINTESTSAST_TESTDEF(ConstNodes,
                Number_t num_val = 0xfaceful;
                String_t str_val = "Ludvich Rudolf Santa Bach";

                NumberASTNode num(num_val);
                StringASTNode str(str_val);
                NilASTNode nil;
                TrueASTNode tru;
                FalseASTNode fls;

                TRY(num.GetValue() == num_val);
                TRY(str.GetValue() == str_val);
                TRY(nil.GetValue() == NIL);
                TRY(tru.GetValue() == TRUE);
                TRY(fls.GetValue() == FALSE);
            )

            SINTESTSAST_TESTDEF(OpNodes,
                AddASTNode add;
                SubASTNode sub;
                MulASTNode mul;
                DivASTNode siv;
                ModASTNode mod;
                LtASTNode  lt;
                GtASTNode  gt;
                LeASTNode  le;
                GeASTNode  ge;
                EqASTNode  eq;
                NeASTNode  ne;
                OrASTNode  or_;
                AndASTNode and_;
            )

            SINTESTSAST_TESTDEF(AllNodes,
                SINTESTSAST_TREENODE_SUPERTEST(TreeNode);
                SINTESTSAST_TREENODE_SUPERTEST(NumberASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(StringASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(NilASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(TrueASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(FalseASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(AddASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(SubASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(MulASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(DivASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(ModASTNode);
                SINTESTSAST_TREENODE_SUPERTEST(LtASTNode );
                SINTESTSAST_TREENODE_SUPERTEST(GtASTNode );
                SINTESTSAST_TREENODE_SUPERTEST(LeASTNode );
                SINTESTSAST_TREENODE_SUPERTEST(GeASTNode );
                SINTESTSAST_TREENODE_SUPERTEST(EqASTNode );
                SINTESTSAST_TREENODE_SUPERTEST(NeASTNode );
                SINTESTSAST_TREENODE_SUPERTEST(OrASTNode );
                SINTESTSAST_TREENODE_SUPERTEST(AndASTNode);
            )

            void test(void) {
                logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::AST");
                SINTESTSAST_TESTRUN(TreeNode);
                SINTESTSAST_TESTRUN(ValueHolder);
                SINTESTSAST_TESTRUN(ConstNodes);
                SINTESTSAST_TESTRUN(OpNodes);
                SINTESTSAST_TESTRUN(AllNodes);
            }
        }
    }
}
