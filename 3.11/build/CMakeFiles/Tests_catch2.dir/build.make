# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/shenmaa/CP2024_code/3.11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shenmaa/CP2024_code/3.11/build

# Include any dependencies generated for this target.
include CMakeFiles/Tests_catch2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tests_catch2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tests_catch2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tests_catch2.dir/flags.make

CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o: CMakeFiles/Tests_catch2.dir/flags.make
CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o: /home/shenmaa/CP2024_code/3.11/Test_IsingSpin.cpp
CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o: CMakeFiles/Tests_catch2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shenmaa/CP2024_code/3.11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o -MF CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o.d -o CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o -c /home/shenmaa/CP2024_code/3.11/Test_IsingSpin.cpp

CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shenmaa/CP2024_code/3.11/Test_IsingSpin.cpp > CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.i

CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shenmaa/CP2024_code/3.11/Test_IsingSpin.cpp -o CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.s

# Object files for target Tests_catch2
Tests_catch2_OBJECTS = \
"CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o"

# External object files for target Tests_catch2
Tests_catch2_EXTERNAL_OBJECTS =

Tests_catch2: CMakeFiles/Tests_catch2.dir/Test_IsingSpin.cpp.o
Tests_catch2: CMakeFiles/Tests_catch2.dir/build.make
Tests_catch2: _deps/catch2-build/src/libCatch2Main.a
Tests_catch2: _deps/catch2-build/src/libCatch2.a
Tests_catch2: CMakeFiles/Tests_catch2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/shenmaa/CP2024_code/3.11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tests_catch2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests_catch2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tests_catch2.dir/build: Tests_catch2
.PHONY : CMakeFiles/Tests_catch2.dir/build

CMakeFiles/Tests_catch2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tests_catch2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tests_catch2.dir/clean

CMakeFiles/Tests_catch2.dir/depend:
	cd /home/shenmaa/CP2024_code/3.11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shenmaa/CP2024_code/3.11 /home/shenmaa/CP2024_code/3.11 /home/shenmaa/CP2024_code/3.11/build /home/shenmaa/CP2024_code/3.11/build /home/shenmaa/CP2024_code/3.11/build/CMakeFiles/Tests_catch2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Tests_catch2.dir/depend

