#include "SINASTNode.h"
#include <iostream>
#include <cassert>
#include "SINCommon.h"
#include "SINASTCommon.h"
#include "SINTest.h"
#include "SINTreeNode.h"

#define SINTESTSAST_RUN(NAME)                                                                       \
    NAME##Test __test_##NAME;                                                                       \
    __test_##NAME.Run();                                                                            \
    Out << __test_##NAME.Name() << ":  ";                                                           \
    if (__test_##NAME.Status())                                                                     \
        Out << "ok";                                                                                \
    else                                                                                            \
        Out << "FAIL'D:" <<                                                                         \
        __test_##NAME.GetFailureFile() << ':' << __test_##NAME.GetFailureLine() <<                  \
        ": " << __test_##NAME.FailureMessage() << " [" << __test_##NAME.FailedCondition()           \
        << "]"; \
    Out << std::endl;

#define SINTESTSAST_TESTDEF(NAME,TESTCODE) \
    static void test_##NAME(void) { TESTFOR(NAME, TESTCODE); SINTESTSAST_RUN(NAME); }
#define SINTESTSAST_TESTRUN(NAME)   \
    test_##NAME();

#define SINTESTSAST_TEMPL_HELPER(CLASSNAME,__VA_ARGS__) CLASSNAME<__VA_ARGS__>

namespace SIN {
    namespace Tests {
        namespace AST {
            static std::ostream &Out = std::cout;

            SINTESTSAST_TESTDEF(TreeNode01, {
                // round 1
                TRY(TreeNode().GetParent() == 0x00);
            });
            SINTESTSAST_TESTDEF(TreeNode02,
                // round 2
                SIN::TreeNode parent;
                SIN::TreeNode kid0;
                SIN::TreeNode kid1;
                SIN::TreeNode kid2;
                TRY(parent.GetParent()         ==  0x00u);
                TRY(parent.GetNext()           ==  0x00u);
                TRY(parent.GetPrevious()       ==  0x00u);
                TRY(parent.NumberOfChildren()   ==  0x00u);
                TRY(kid0.GetParent()           ==  0x00u);
                TRY(kid0.GetNext()             ==  0x00u);
                TRY(kid0.GetPrevious()         ==  0x00u);
                TRY(kid0.NumberOfChildren()     ==  0x00u);
                TRY(kid1.GetParent()           ==  0x00u);
                TRY(kid1.GetNext()             ==  0x00u);
                TRY(kid1.GetPrevious()         ==  0x00u);
                TRY(kid1.NumberOfChildren()     ==  0x00u);
                TRY(kid2.GetParent()           ==  0x00u);
                TRY(kid2.GetNext()             ==  0x00u);
                TRY(kid2.GetPrevious()         ==  0x00u);
                TRY(kid2.NumberOfChildren()     ==  0x00u);
            );
            SINTESTSAST_TESTDEF(TreeNode03, {
                // round 3
                SIN::TreeNode parent;
                SIN::TreeNode kid0;
                SIN::TreeNode kid1;
                SIN::TreeNode kid2;
                parent << &kid0 << &kid1 << &kid2;
                TRY(parent[0]               ==  &kid0);
                TRY(parent[1]               ==  &kid1);
                TRY(parent[2]               ==  &kid2);
                TRY(parent[666]             ==  0x00u);
                TRY(parent.GetParent()         ==  0x00u);
                TRY(parent.GetNext()           ==  0x00u);
                TRY(parent.GetPrevious()       ==  0x00u);
                TRY(parent.NumberOfChildren()   ==  0x03u);
                TRY(kid0.GetParent()           ==  &parent);
                TRY(kid0.GetNext()             ==  &kid1);
                TRY(kid0.GetPrevious()         ==  0x00u);
                TRY(kid0.NumberOfChildren()     ==  0x00u);
                TRY(kid0[0]                 ==  0x00u);
                TRY(kid1.GetParent()           ==  &parent);
                TRY(kid1.GetNext()             ==  &kid2);
                TRY(kid1.GetPrevious()         ==  &kid0);
                TRY(kid1.NumberOfChildren()     ==  0x00u);
                TRY(kid1[0]                 ==  0x00u);
                TRY(kid2.GetParent()           ==  &parent);
                TRY(kid2.GetNext()             ==  0x00u);
                TRY(kid2.GetPrevious()         ==  &kid1);
                TRY(kid2.NumberOfChildren()     ==  0x00u);
                TRY(kid2[0]                 ==  0x00u);
            });

            typedef ValueHolder<CONST_NUMBER, int> ValueHolderNum;
            SINTESTSAST_TESTDEF(ValueHolder, 
                ValueHolderNum vh(23);
                TRY(vh.GetType() == CONST_NUMBER);
                TRY(vh.GetValue() == 23);
                TRY(vh.GetValueStr() == "23");
                vh.SetValue(12);
                TRY(vh.GetValue() == 12);
//                TRY(vh == 12);
                TRY(vh.GetValueStr() == "12");
            );

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
            );

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
                OrASTNode  or;
                AndASTNode and;
            );

            void test(void) {
                SINTESTSAST_TESTRUN(TreeNode01);
                SINTESTSAST_TESTRUN(TreeNode02);
                SINTESTSAST_TESTRUN(TreeNode03);
                SINTESTSAST_TESTRUN(ValueHolder);
                SINTESTSAST_TESTRUN(ConstNodes);
                SINTESTSAST_TESTRUN(OpNodes);
            }
        }
    }
}
