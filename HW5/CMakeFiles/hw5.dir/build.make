# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /s/bach/l/under/alissaam/cs253/HW5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/bach/l/under/alissaam/cs253/HW5

# Include any dependencies generated for this target.
include CMakeFiles/hw5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw5.dir/flags.make

CMakeFiles/hw5.dir/main.cc.o: CMakeFiles/hw5.dir/flags.make
CMakeFiles/hw5.dir/main.cc.o: main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/s/bach/l/under/alissaam/cs253/HW5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw5.dir/main.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw5.dir/main.cc.o -c /s/bach/l/under/alissaam/cs253/HW5/main.cc

CMakeFiles/hw5.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw5.dir/main.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /s/bach/l/under/alissaam/cs253/HW5/main.cc > CMakeFiles/hw5.dir/main.cc.i

CMakeFiles/hw5.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw5.dir/main.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /s/bach/l/under/alissaam/cs253/HW5/main.cc -o CMakeFiles/hw5.dir/main.cc.s

# Object files for target hw5
hw5_OBJECTS = \
"CMakeFiles/hw5.dir/main.cc.o"

# External object files for target hw5
hw5_EXTERNAL_OBJECTS =

hw5: CMakeFiles/hw5.dir/main.cc.o
hw5: CMakeFiles/hw5.dir/build.make
hw5: CMakeFiles/hw5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/s/bach/l/under/alissaam/cs253/HW5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw5.dir/build: hw5

.PHONY : CMakeFiles/hw5.dir/build

CMakeFiles/hw5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw5.dir/clean

CMakeFiles/hw5.dir/depend:
	cd /s/bach/l/under/alissaam/cs253/HW5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/bach/l/under/alissaam/cs253/HW5 /s/bach/l/under/alissaam/cs253/HW5 /s/bach/l/under/alissaam/cs253/HW5 /s/bach/l/under/alissaam/cs253/HW5 /s/bach/l/under/alissaam/cs253/HW5/CMakeFiles/hw5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw5.dir/depend

