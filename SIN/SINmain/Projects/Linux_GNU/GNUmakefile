LIBNAME = SINmain

ifndef LIBNAME
$(error Set LIBNAME in your GNUmakefile)
endif

SIN_BASE_DIR=../../../
include $(SIN_BASE_DIR)/Linux_static_lib_base.mk

sin: $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o$@ 

lib%Test.a:
	cd $(SIN_BASE_DIR)/Tests/$*/Projects/Linux_GNU/ && $(MAKE) $@
lib%.a:
	cd $(SIN_BASE_DIR)/$*/Projects/Linux_GNU/ && $(MAKE) $@
libSINTest.a:
	cd $(SIN_BASE_DIR)/Tests/SINTest/Projects/Linux_GNU/ && $(MAKE) $@

.PHONY:clean
clean_all:
	$(foreach PRJ,$(PROJECTS), pushd $(PRJ)/Projects/Linux_GNU/ && $(MAKE) clean && popd &&)  true 
