SHELL = /bin/bash

### Required variables
ifndef SIN_BASE_DIR
$(error SIN_BASE_DIR is undefined. Please define it)
endif

PROJECTS = $(addsuffix /../,$(shell find $(SIN_BASE_DIR) -name Projects))
INCLUDE_DIRS = $(addsuffix /Include/,$(PROJECTS))
LIBRARY_DIRS = $(addsuffix /Projects/Linux_GNU/,$(PROJECTS))
SINLIBSNAMES = SINmain SINASTTest SINTest SINAST SINParser SINCommon Common 
LIBSNAMES = $(SINLIBSNAMES)
LIBS = $(addprefix lib,$(addsuffix .a,$(LIBSNAMES)))

CXXFLAGS += -pedantic -Wall -ansi -fno-rtti
CPPFLAGS += $(addprefix -I,$(INCLUDE_DIRS))
LDFLAGS += -static $(addprefix -L,$(LIBRARY_DIRS)) $(addprefix -l,$(LIBSNAMES))
ARFALGS += rv

SRCS = $(wildcard ../../Src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all : lib$(LIBNAME).a

lib$(LIBNAME).a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: clean
clean:
	rm -v $(OBJS) lib$(LIBNAME).a 

