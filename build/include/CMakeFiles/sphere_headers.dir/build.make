# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xottab/cg-course/sphere_intersections

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xottab/cg-course/sphere_intersections/build

# Utility rule file for sphere_headers.

# Include the progress variables for this target.
include include/CMakeFiles/sphere_headers.dir/progress.make

include/CMakeFiles/sphere_headers:
	cd /home/xottab/cg-course/sphere_intersections/build/include && ./has_intersection.cpp /home/xottab/cg-course/sphere_intersections/include/common.h /home/xottab/cg-course/sphere_intersections/include/has_intersection.h /home/xottab/cg-course/sphere_intersections/include/point.h /home/xottab/cg-course/sphere_intersections/include/segment.h

sphere_headers: include/CMakeFiles/sphere_headers
sphere_headers: include/CMakeFiles/sphere_headers.dir/build.make
.PHONY : sphere_headers

# Rule to build all files generated by this target.
include/CMakeFiles/sphere_headers.dir/build: sphere_headers
.PHONY : include/CMakeFiles/sphere_headers.dir/build

include/CMakeFiles/sphere_headers.dir/clean:
	cd /home/xottab/cg-course/sphere_intersections/build/include && $(CMAKE_COMMAND) -P CMakeFiles/sphere_headers.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/sphere_headers.dir/clean

include/CMakeFiles/sphere_headers.dir/depend:
	cd /home/xottab/cg-course/sphere_intersections/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xottab/cg-course/sphere_intersections /home/xottab/cg-course/sphere_intersections/include /home/xottab/cg-course/sphere_intersections/build /home/xottab/cg-course/sphere_intersections/build/include /home/xottab/cg-course/sphere_intersections/build/include/CMakeFiles/sphere_headers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/sphere_headers.dir/depend

