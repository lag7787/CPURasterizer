# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/lucgarabrant/projects/rasterizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucgarabrant/projects/rasterizer/build

# Include any dependencies generated for this target.
include CMakeFiles/rasterizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rasterizer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rasterizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rasterizer.dir/flags.make

CMakeFiles/rasterizer.dir/src/main.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/src/main.cpp.o: /home/lucgarabrant/projects/rasterizer/src/main.cpp
CMakeFiles/rasterizer.dir/src/main.cpp.o: CMakeFiles/rasterizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lucgarabrant/projects/rasterizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rasterizer.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rasterizer.dir/src/main.cpp.o -MF CMakeFiles/rasterizer.dir/src/main.cpp.o.d -o CMakeFiles/rasterizer.dir/src/main.cpp.o -c /home/lucgarabrant/projects/rasterizer/src/main.cpp

CMakeFiles/rasterizer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucgarabrant/projects/rasterizer/src/main.cpp > CMakeFiles/rasterizer.dir/src/main.cpp.i

CMakeFiles/rasterizer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucgarabrant/projects/rasterizer/src/main.cpp -o CMakeFiles/rasterizer.dir/src/main.cpp.s

CMakeFiles/rasterizer.dir/src/geometry.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/src/geometry.cpp.o: /home/lucgarabrant/projects/rasterizer/src/geometry.cpp
CMakeFiles/rasterizer.dir/src/geometry.cpp.o: CMakeFiles/rasterizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lucgarabrant/projects/rasterizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rasterizer.dir/src/geometry.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rasterizer.dir/src/geometry.cpp.o -MF CMakeFiles/rasterizer.dir/src/geometry.cpp.o.d -o CMakeFiles/rasterizer.dir/src/geometry.cpp.o -c /home/lucgarabrant/projects/rasterizer/src/geometry.cpp

CMakeFiles/rasterizer.dir/src/geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/src/geometry.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucgarabrant/projects/rasterizer/src/geometry.cpp > CMakeFiles/rasterizer.dir/src/geometry.cpp.i

CMakeFiles/rasterizer.dir/src/geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/src/geometry.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucgarabrant/projects/rasterizer/src/geometry.cpp -o CMakeFiles/rasterizer.dir/src/geometry.cpp.s

CMakeFiles/rasterizer.dir/src/test.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/src/test.cpp.o: /home/lucgarabrant/projects/rasterizer/src/test.cpp
CMakeFiles/rasterizer.dir/src/test.cpp.o: CMakeFiles/rasterizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lucgarabrant/projects/rasterizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rasterizer.dir/src/test.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rasterizer.dir/src/test.cpp.o -MF CMakeFiles/rasterizer.dir/src/test.cpp.o.d -o CMakeFiles/rasterizer.dir/src/test.cpp.o -c /home/lucgarabrant/projects/rasterizer/src/test.cpp

CMakeFiles/rasterizer.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/src/test.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucgarabrant/projects/rasterizer/src/test.cpp > CMakeFiles/rasterizer.dir/src/test.cpp.i

CMakeFiles/rasterizer.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/src/test.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucgarabrant/projects/rasterizer/src/test.cpp -o CMakeFiles/rasterizer.dir/src/test.cpp.s

# Object files for target rasterizer
rasterizer_OBJECTS = \
"CMakeFiles/rasterizer.dir/src/main.cpp.o" \
"CMakeFiles/rasterizer.dir/src/geometry.cpp.o" \
"CMakeFiles/rasterizer.dir/src/test.cpp.o"

# External object files for target rasterizer
rasterizer_EXTERNAL_OBJECTS =

rasterizer: CMakeFiles/rasterizer.dir/src/main.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/src/geometry.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/src/test.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/build.make
rasterizer: CMakeFiles/rasterizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lucgarabrant/projects/rasterizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable rasterizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rasterizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rasterizer.dir/build: rasterizer
.PHONY : CMakeFiles/rasterizer.dir/build

CMakeFiles/rasterizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rasterizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rasterizer.dir/clean

CMakeFiles/rasterizer.dir/depend:
	cd /home/lucgarabrant/projects/rasterizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucgarabrant/projects/rasterizer /home/lucgarabrant/projects/rasterizer /home/lucgarabrant/projects/rasterizer/build /home/lucgarabrant/projects/rasterizer/build /home/lucgarabrant/projects/rasterizer/build/CMakeFiles/rasterizer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rasterizer.dir/depend

