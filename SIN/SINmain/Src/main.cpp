#include "SINLogger.h"
#include "SINTestCollection.h"
#include "SINTestFactory.h"
#include "SINAllocTester.h"
#include "SIN.h"
#include "SINAssert.h"
#include "SINASTTester.h"
#include "SINCommonTester.h"
#include "SINLoggingTester.h"
#include "SINParserTester.h"
#include "SINSymbolTableTester.h"
#include "SINRunTester.h"
#include "SINLoggerManager.h"
#include "SINObjectTester.h"
#include "SINFunctionLibraryTester.h"
#include "SINLibrary.h"
#include "SINLibraryFunctions.h"
#include "SINVirtualState.h"
#include "SINStandardLibrary.h"
#include "SINAlloc.h"

//////// for quick tests and c++ questions ///////
// (please restore to original before commits)
#include "SINConstants.h"
class out_class {
	SIN::Logger* out_p;
public:
	out_class(SIN::Logger& _out): out_p(&_out) { }
	template <typename _T>
	out_class const& operator <<(_T const& something) const {
		out_p->Notice(SIN::to_string(something));
		return *this;
	}
	SIN::Logger* logger(void) const { return out_p; }
};
// keep the above for convenience. ex:
// out << (SIN::String() << "This is" << " horrible " << (4));
#include "SINASTMITTreeVisualizerXMLProducerVisitor.h"
static InstanceProxy<out_class> g_out;

static void __print_handler(SIN::String const& _msg) {
//	SIN::LoggerManager::StreamLogger oot("STDOUT: ", SIN::Logging::Record::FINEST, SIN::STDOUT, SIN::Logging::RecordPrinter());
//	oot.Notice(_msg);
}

static void quick_test(void) {
	SIN::LoggerManager::SingletonGetInstance()->MakeStdoutLogger("SIN::main::quick_test");
	out_class out(SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::main::quick_test"));
	g_out = out;
	// keep the above for convenience

	// Example of using "out" and "FOREACH"
//	std::list<int> lis; lis.push_back(9); lis.push_back(8); lis.push_back(7); lis.push_back(6);
//	FOREACH(lis)
//		out << *ITER(lis);
//	out << (SIN::to_string("This is") << " horrible " << (4));

	__print_handler("hi");

	SIN::VM::VirtualState vs;
	vs.PushState();
	vs.Down().Up().Down().Top().RestoreState();

	SIN::Library::StandardLibrary stdlib;
}
////////

class MainTestCollection: public SIN::Tests::TestCollection {
	SIN::Tests::TestFactory test_factory;
	SIN::Tests::Alloc::Status alloc_test_status;
	void emulateAllocTest(void) const;
public:
	MainTestCollection(SIN::Tests::Alloc::Status const& _alloc_test_status): test_factory(), alloc_test_status(_alloc_test_status) { }
	MainTestCollection(SIN::Tests::TestFactory const& tf, SIN::Tests::Alloc::Status const& _alloc_test_status): test_factory(tf), alloc_test_status(_alloc_test_status) { }
	virtual bool RunAll(void);
}; // class MainTestCollection

static int waitToByeBye(void);
static int resolver_main(int, char*[]);
int main(int argc, char *argv[]) {
	// Early testing: LoggerManager taints the memory module.
	SIN::Tests::Alloc::Status s;
	SIN::Tests::Alloc::test(s); // TODO and one day this will be moved in along with the rest of the tests

	if (argc > 1)
		resolver_main(argc, argv);
	else {
		if (SIN::Initialise()) {
			MainTestCollection mtc(s);
			mtc.RunAll();
			quick_test();
		}
		else
			SINASSERT(!"Initialisation failed");

		SIN::CleanUp();
	}
	return waitToByeBye();
}

///// MainTestCollection ////////////////////
bool MainTestCollection::RunAll(void) {
	//emulateAllocTest();
	//SIN::Tests::AST::test(&test_factory);
	//SIN::Tests::Common::test(&test_factory);
	//SIN::Tests::Logging::test(&test_factory);
	//SIN::Tests::Parser::test(&test_factory);
	//SIN::Tests::ST::test(&test_factory);
	SIN::Tests::Run::test(&test_factory);
	//SIN::Tests::OBJ::test(&test_factory);
	//SIN::Tests::FunctionLibrary::test(&test_factory);
	return true;
}

void MainTestCollection::emulateAllocTest(void) const {
	SIN::Logger& logga(SIN::LoggerManager::SingletonGetInstance()->GetLogger("SIN::Tests::Alloc"));
	logga.Notice(alloc_test_status.failed ? SIN::to_string("FAIL'D at line ") << alloc_test_status.at_line : "OK");
	SIN::LoggerManager::SingletonGetInstance()->GetDefaultLoggerFactory()->DestroyLogger(&logga);
}


/// Wait to byebye
static int waitToByeBye(void) {
#ifdef _DEBUG
#ifdef _MSC_VER
	//system("pause");
#elif defined(_LINUX_)
	//getchar();
#endif
#else
#ifdef _MSC_VER
#elif defined(_LINUX_)
	getchar();
#endif
#endif
	return 0;
}


#ifdef _MSC_VER // visual studio compiling
/////////// For the resolver ///////
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <windows.h>
////////////////////////////////////
static int resolver_main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    DWORD dwError;
    int i = 0;

    struct hostent *remoteHost;
    char *host_name;
    struct in_addr addr;

    char **pAlias;

    // Validate the parameters
    if (argc != 2) {
		printf("argc = %d", argc);
		if (argc > 2) {
			puts("wtf");
			return -1;
		}
		printf(", argv[argc - 1] = \"%s\"\n", argc, argc > 0 ? argv[argc - 1] : "(argc is 0)");
        printf("usage: %s ipv4address\n", argv[0]);
        printf(" or\n");
        printf("       %s hostname\n", argv[0]);
        printf("  to return the host\n");
        printf("       %s 127.0.0.1\n", argv[0]);
        printf("  to return the IP addresses for a host\n");
        printf("       %s www.contoso.com\n", argv[0]);
        return 1;
    }
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    host_name = argv[1];

// If the user input is an alpha name for the host, use gethostbyname()
// If not, get host by addr (assume IPv4)
    if (isalpha(host_name[0])) {        /* host address is a name */
        printf("Calling gethostbyname with %s\n", host_name);
        remoteHost = gethostbyname(host_name);
    } else {
        printf("Calling gethostbyaddr with %s\n", host_name);
        addr.s_addr = inet_addr(host_name);
        if (addr.s_addr == INADDR_NONE) {
            printf("The IPv4 address entered must be a legal address\n");
            return 1;
        } else
            remoteHost = gethostbyaddr((char *) &addr, 4, AF_INET);
    }

    if (remoteHost == NULL) {
        dwError = WSAGetLastError();
        if (dwError != 0) {
            if (dwError == WSAHOST_NOT_FOUND) {
                printf("Host not found\n");
                return 1;
            } else if (dwError == WSANO_DATA) {
                printf("No data record found\n");
                return 1;
            } else {
                printf("Function failed with error: %ld\n", dwError);
                return 1;
            }
        }
    } else {
        printf("Function returned:\n");
        printf("\tOfficial name: %s\n", remoteHost->h_name);
        for (pAlias = remoteHost->h_aliases; *pAlias != 0; pAlias++) {
            printf("\tAlternate name #%d: %s\n", ++i, *pAlias);
        }
        printf("\tAddress type: ");
        switch (remoteHost->h_addrtype) {
        case AF_INET:
            printf("AF_INET\n");
            break;
        case AF_INET6:
            printf("AF_INET6\n");
            break;
        case AF_NETBIOS:
            printf("AF_NETBIOS\n");
            break;
        default:
            printf(" %d\n", remoteHost->h_addrtype);
            break;
        }
        printf("\tAddress length: %d\n", remoteHost->h_length);

        i = 0;
        while (remoteHost->h_addr_list[i] != 0) {
            addr.s_addr = *(u_long *) remoteHost->h_addr_list[i++];
            printf("\tIP Address #%d: %s\n", i, inet_ntoa(addr));
        }
    }

    return 0;
}
#else // no visual studio compiling
static int resolver_main(int argc, char *argv[]) {
	puts("Sorry mate, the free resolver has not been implemented in this platform yet.");
	return 1;
}
#endif // _MSC_VER
