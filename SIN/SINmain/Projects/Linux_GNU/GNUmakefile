SIN_BASE_DIR=../../../
include $(SIN_BASE_DIR)/Linux_static_lib_base.mk
export
.PHONY:sin clean_all
SUBPROJECT_RELATIVE_PATH_TO_SIN_BASE_DIR_RUBY_SHELL_ESCAPED_CODE='puts(Pathname('\''$(SIN_BASE_DIR)'\'').relative_path_from(Pathname('\''$(PROJ)/Projects/Linux_GNU/'\'')))'
sin: 
	$(foreach PROJ,$(PROJECTS),(cd '$(PROJ)'/Projects/Linux_GNU/ && printf 'include $$(SIN_BASE_DIR)/Linux_static_lib_base.mk\n' | $(MAKE) -f - SIN_BASE_DIR='$(shell ruby -r pathname -e $(SUBPROJECT_RELATIVE_PATH_TO_SIN_BASE_DIR_RUBY_SHELL_ESCAPED_CODE) )' linux_static_lib_all ) && ) true
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o$@ 

clean_all:
	$(foreach PROJ,$(PROJECTS),(cd '$(PROJ)'/Projects/Linux_GNU/ && printf 'include $$(SIN_BASE_DIR)/Linux_static_lib_base.mk\n' | $(MAKE) -f - SIN_BASE_DIR='$(shell ruby -r pathname -e $(SUBPROJECT_RELATIVE_PATH_TO_SIN_BASE_DIR_RUBY_SHELL_ESCAPED_CODE) )' linux_static_lib_clean ) && )  true 
