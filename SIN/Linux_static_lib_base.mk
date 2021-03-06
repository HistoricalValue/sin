SHELL = /bin/bash

### Required variables
ifndef SIN_BASE_DIR
$(error SIN_BASE_DIR is undefined. It should contain SINmain/ and SIN.sln. Please define it)
endif

PROJECTS = $(addprefix $(SIN_BASE_DIR)/, \
        SINmain \
        $(addsuffix _Test,$(addprefix Tests/SIN,\
                AST \
                Common \
                Logging \
                SymbolTable \
                Alloc \
                Parser \
                Object \
                FunctionLibrary \
                Run )) \
        Tests/SINTest \
        SINParser \
        SINFunctionLibrary \
        SINAST \
        SINRuntime \
        SINLogging \
        SINCommon \
        SINAlloc \
        Common)
INCLUDE_DIRS = $(addsuffix /Include/,$(PROJECTS))
LIBRARY_DIRS = $(addsuffix /Projects/Linux_GNU/,$(PROJECTS))
SINLIBSNAMES = $(foreach PROJ,$(PROJECTS),$(shell basename '$(shell ( cd $(PROJ) && pwd ) )' ) )
LIBSNAMES = $(SINLIBSNAMES)
LIBS = $(addprefix lib,$(addsuffix .a,$(LIBSNAMES)))

CXXFLAGS += -MMD -MP -pedantic -Wall -ansi -g -fno-rtti
CPPFLAGS += $(addprefix -I,$(INCLUDE_DIRS))
LDFLAGS += -static $(addprefix -L,$(LIBRARY_DIRS)) $(addprefix -l,$(LIBSNAMES))
ARFALGS += rv

SRCS = $(wildcard ../../Src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

LIBNAME = $(shell basename '$(shell ( cd '$(shell pwd)'/../../ && pwd ) )' )
TARGET_LIB = lib$(LIBNAME).a
linux_static_lib_all : $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY: linux_static_lib_clean
linux_static_lib_clean:
	rm -v $(OBJS) $(TARGET_LIB)

-include $(DEPS)
