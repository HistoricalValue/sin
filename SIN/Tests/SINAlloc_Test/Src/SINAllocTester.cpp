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
			namespace {
				struct A { int a,b,c; double d,e,f; long double g,h,i,j,k; };
				class B {
					int poo;
					A* as;
				public:
					B(int _poo, A* _as): poo(_poo), as(_as) { }
					int Poo(void) const { return poo; }
					A* As(void) const { return as; }
				};
			}
			static void test_Alloc(void) {
				class AllocTest : public Test {
				public:                                         
					AllocTest(void): Test("Alloc" "Test") { }
				protected:
					virtual void TestLogic(void) {
						int* ip = SINEW(int);
                        *SINPTR(ip) = 5;
						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip));
						ASSERT(SIN::Alloc::TotallyFreed() == 0x00);
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*ip));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*ip));
						ASSERT(SIN::Alloc::IsValid(ip) == true);
						ASSERT(*SINPTR(ip) == 5);

						A* a = SINEW(A);
						SINPTR(a)->a = 12;

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::TotallyFreed() == 0x00);
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::IsValid(ip) == true);
						ASSERT(SIN::Alloc::IsValid(a) == true);
						ASSERT(SINPTR(a)->a == 12);

						SINDELETE(ip);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*ip) + sizeof(*a));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == true);

						double* dp = SINEW(double);
						*SINPTR(dp) = 666.666;
						SINASSERT(sizeof(*dp) < sizeof(*a ));
						SINASSERT(sizeof(*ip) < sizeof(*dp));

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == true);
						ASSERT(SIN::Alloc::IsValid(dp) == true);
						ASSERT(*SINPTR(dp) >= 666.665 && *SINPTR(dp) <= 666.667);

						SINDELETE(dp);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(*dp));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == true);
						ASSERT(SIN::Alloc::IsValid(dp) == false);

						struct A* as = SINEWARRAY(struct A, 12);
						struct A as_size[12] = { A() };
						SINPTR(as)[11] = as_size[0];
						SINASSERT(sizeof(as_size) - sizeof(*a) > sizeof(*dp));

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == true);
						ASSERT(SIN::Alloc::IsValid(dp) == false);
						ASSERT(SIN::Alloc::IsValid(as) == true);

						SINDELETE(a);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(as_size));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == false);
						ASSERT(SIN::Alloc::IsValid(dp) == false);
						ASSERT(SIN::Alloc::IsValid(as) == true);


						class B* bp = SINEWCLASS(class B, (12, as));
						SINASSERT(sizeof(*bp) < sizeof(*a));
						SINASSERT(sizeof(*bp) < sizeof(as_size));

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == false);
						ASSERT(SIN::Alloc::IsValid(dp) == false);
						ASSERT(SIN::Alloc::IsValid(as) == true);
						ASSERT(SIN::Alloc::IsValid(bp) == true);
						ASSERT(SINPTR(bp)->Poo() == 12);
						ASSERT(SINPTR(bp)->As() == as);

						SINDELETE(as);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::MemoryLeak() == true);
						ASSERT(SIN::Alloc::MemoryLeaking() == sizeof(*bp));
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == false);
						ASSERT(SIN::Alloc::IsValid(dp) == false);
						ASSERT(SIN::Alloc::IsValid(as) == false);
						ASSERT(SIN::Alloc::IsValid(bp) == true);

						SINDELETE(bp);

						ASSERT(SIN::Alloc::TotallyAllocated() == sizeof(*ip) + sizeof(*a) + sizeof(*dp) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::TotallyFreed() == sizeof(*ip) + sizeof(*dp) + sizeof(*a) + sizeof(as_size) + sizeof(*bp));
						ASSERT(SIN::Alloc::MemoryLeak() == false);
						ASSERT(SIN::Alloc::MemoryLeaking() == 0);
						ASSERT(SIN::Alloc::MaximumAllocated() == sizeof(*a) + sizeof(as_size));
						ASSERT(SIN::Alloc::IsValid(ip) == false);
						ASSERT(SIN::Alloc::IsValid(a) == false);
						ASSERT(SIN::Alloc::IsValid(dp) == false);
						ASSERT(SIN::Alloc::IsValid(as) == false);
						ASSERT(SIN::Alloc::IsValid(bp) == false);

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
