# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /s/bach/l/under/alissaam/cs253/HW7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/bach/l/under/alissaam/cs253/HW7

# Include any dependencies generated for this target.
include CMakeFiles/hw7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hw7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hw7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw7.dir/flags.make

CMakeFiles/hw7.dir/CountSort.cc.o: CMakeFiles/hw7.dir/flags.make
CMakeFiles/hw7.dir/CountSort.cc.o: CountSort.cc
CMakeFiles/hw7.dir/CountSort.cc.o: CMakeFiles/hw7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/s/bach/l/under/alissaam/cs253/HW7/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw7.dir/CountSort.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw7.dir/CountSort.cc.o -MF CMakeFiles/hw7.dir/CountSort.cc.o.d -o CMakeFiles/hw7.dir/CountSort.cc.o -c /s/bach/l/under/alissaam/cs253/HW7/CountSort.cc

CMakeFiles/hw7.dir/CountSort.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw7.dir/CountSort.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /s/bach/l/under/alissaam/cs253/HW7/CountSort.cc > CMakeFiles/hw7.dir/CountSort.cc.i

CMakeFiles/hw7.dir/CountSort.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw7.dir/CountSort.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /s/bach/l/under/alissaam/cs253/HW7/CountSort.cc -o CMakeFiles/hw7.dir/CountSort.cc.s

# Object files for target hw7
hw7_OBJECTS = \
"CMakeFiles/hw7.dir/CountSort.cc.o"

# External object files for target hw7
hw7_EXTERNAL_OBJECTS =

libhw7.a: CMakeFiles/hw7.dir/CountSort.cc.o
libhw7.a: CMakeFiles/hw7.dir/build.make
libhw7.a: CMakeFiles/hw7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/s/bach/l/under/alissaam/cs253/HW7/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhw7.a"
	$(CMAKE_COMMAND) -P CMakeFiles/hw7.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw7.dir/build: libhw7.a
.PHONY : CMakeFiles/hw7.dir/build

CMakeFiles/hw7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw7.dir/clean

CMakeFiles/hw7.dir/depend:
	cd /s/bach/l/under/alissaam/cs253/HW7 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/bach/l/under/alissaam/cs253/HW7 /s/bach/l/under/alissaam/cs253/HW7 /s/bach/l/under/alissaam/cs253/HW7 /s/bach/l/under/alissaam/cs253/HW7 /s/bach/l/under/alissaam/cs253/HW7/CMakeFiles/hw7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw7.dir/depend
