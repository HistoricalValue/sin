#include "SINTest.h"
#include "SINStrictTreeNode.h"
#include "SINTestingCommon.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINAlloc.h"

namespace SIN {
	namespace Tests {
		namespace AST {
			InstanceProxy<Logger> logger;

			class StrictTreeNodeTest: public Test {
			public:
				StrictTreeNodeTest(void): Test("StrictTreeNode" "Test") { }
			protected:
				virtual void TestLogic(void) {
					StrictTreeNode parent, kid1, kid2, kid3;
					kid3 >> (kid2 >> (kid1 >> parent));
					TIME(MakeABigFakeTree());
				}
			private:
				typedef StrictTreeNode* const node;
				typedef StrictTreeNode nodeinst;
				node newnode(void) const { return SINEW(nodeinst); }
				void MakeABigFakeTree(void) {
					node statements = newnode();
					// Make about 1000 statements, each of each has about 10 nodes
					for (size_t i = 0; i < 1000; ++i) {
						// make a function call, more or less
						node func = newnode();
						node funcname = newnode();
						*func << funcname;
						node funcargs = newnode();
						for (size_t  i = 0 ; i < 5; ++i)
							*funcargs << newnode();

						// result being plused with a number and a string
						node string = newnode();
						node number = newnode();
						node plus1 = newnode();
						node plus2 = newnode();
						*plus1 << number << func;
						*plus2 << plus1 << string;

						*statements << plus2;
					}
				}
			};
			
			void test_StrictTreeNode(void) {
				logger = SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::AST");
				SINTESTS_RUNTEST(StrictTreeNode);
			}

		} // namespace AST
	} // namespace Tests
} // namespace SIN

