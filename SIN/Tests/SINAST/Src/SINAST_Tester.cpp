#include "SINASTNode.h"
#include <iostream>
#include <cassert>
#include "SINCommon.h"
#include "SINASTCommon.h"

namespace SIN {
    namespace Tests {
        namespace AST {
            static void test_valueHolder(void) {
                ValueHolder<CONST_NUMBER,int> vh(23);
                assert(vh.GetType() == CONST_NUMBER);
                assert(vh.GetValue() == 23);
                assert(vh.GetValueStr() == "23");
                vh.SetValue(12);
                assert(vh.GetValue() == 12);
//                assert(vh == 12);
                assert(vh.GetValueStr() == "12");
            }
            static void test_constNodes() {
                Number_t num_val = 0xfaceful;
                String_t str_val = "Ludvich Rudolf Santa Bach";

                NumberASTNode num(num_val);
                StringASTNode str(str_val);
                NilASTNode nil;
                TrueASTNode tru;
                FalseASTNode fls;

                assert(num.GetValue() == num_val);
                assert(str.GetValue() == str_val);
                assert(nil.GetValue() == NIL);
                assert(tru.GetValue() == TRUE);
                assert(fls.GetValue() == FALSE);
            }
            static void test_opNodes(void) {
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
            }
            void test(void) {
                test_valueHolder();
                test_constNodes();
                test_opNodes();
            }
        }
    }
}
