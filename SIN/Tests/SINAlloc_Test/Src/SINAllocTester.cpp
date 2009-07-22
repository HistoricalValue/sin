#include "SINAllocTester.h"
#include "SINTest.h"
#include "SINTestingCommon.h"
#include "SINLogger.h"
#include "SINLoggerManager.h"
#include "SINAlloc.h"
#include "SINAssert.h"

namespace SIN {
	namespace Tests {
		namespace Alloc {
			static InstanceProxy<Logger> logger;
			static InstanceProxy<TestFactory> test_factory;

			//SINTESTS_TESTDEF(Alloc,
			//);
			static void test_Alloc(void) {
				class AllocTest : public Test {
				public:                                         
					AllocTest(void): Test("Alloc" "Test") { }   
				protected:                                      
					virtual void TestLogic(void) {
						int* ip = SINEW(int);
                        *ip = 5;
						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip));
						ASSERT(SIN::Alloc::TotallyFreed() == 0x00);
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*ip));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*ip));
						ASSERT(*ip == 5);
						
						struct A { int a,b,c; double d,e,f; long double g,h,i,j,k; };
						A* a = SINEW(A);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::TotallyFreed() == 0x00);
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*ip) + sizeof(*a));

						SINDELETE(ip);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*ip) + sizeof(*a));

						double* dp = SINEW(double);
						*dp = 666.666;
						SINASSERT(sizeof(*dp) < sizeof(*a ));
						SINASSERT(sizeof(*ip) < sizeof(*dp));

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(*dp));

						SINDELETE(dp);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(*dp));

						struct A* as = SINEWARRAY(struct A, 12);
						struct A as_size[12] = { A() };
						as[11] = as_size[0];
						SINASSERT(sizeof(as_size) - sizeof(*a) > sizeof(*dp));

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));

						SINDELETE(a);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(as_size));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));

						class B {
							int poo;
							A* as;
						public:
							B(int _poo, A* _as): poo(_poo), as(_as) { }
						};
						class B* bp = SINEWCLASS(class B, (12, as));
						SINASSERT(sizeof(*bp) < sizeof(*a));
						SINASSERT(sizeof(*bp) < sizeof(as_size));

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));

						SINDELETE(as);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*bp));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));

						SINDELETE(bp);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::MemoryLeak() == false);
						ASSERT(SIN::Alloc::MemoryLeaking() == 0);
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));
						// TODO add more testing
					}
				};
				SINTESTS_RUNTEST(Alloc);
			}

			void test(InstanceProxy<TestFactory> const& tf) {
                logger = LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Alloc");
				test_factory = tf;
				SINTESTS_CALLTEST(Alloc);
			}
        }
    }
}
