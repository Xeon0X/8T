# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/alex/Bureau/8T

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/Bureau/8T/build

# Include any dependencies generated for this target.
include _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/flags.make

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/flags.make
_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o: _deps/ftxui-src/examples/dom/color_truecolor_RGB.cpp
_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Bureau/8T/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o"
	cd /home/alex/Bureau/8T/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o -MF CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o.d -o CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o -c /home/alex/Bureau/8T/build/_deps/ftxui-src/examples/dom/color_truecolor_RGB.cpp

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.i"
	cd /home/alex/Bureau/8T/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Bureau/8T/build/_deps/ftxui-src/examples/dom/color_truecolor_RGB.cpp > CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.i

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.s"
	cd /home/alex/Bureau/8T/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Bureau/8T/build/_deps/ftxui-src/examples/dom/color_truecolor_RGB.cpp -o CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.s

# Object files for target ftxui_example_color_truecolor_RGB
ftxui_example_color_truecolor_RGB_OBJECTS = \
"CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o"

# External object files for target ftxui_example_color_truecolor_RGB
ftxui_example_color_truecolor_RGB_EXTERNAL_OBJECTS =

_deps/ftxui-build/examples/dom/ftxui_example_color_truecolor_RGB: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/color_truecolor_RGB.cpp.o
_deps/ftxui-build/examples/dom/ftxui_example_color_truecolor_RGB: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/build.make
_deps/ftxui-build/examples/dom/ftxui_example_color_truecolor_RGB: _deps/ftxui-build/libftxui-dom.a
_deps/ftxui-build/examples/dom/ftxui_example_color_truecolor_RGB: _deps/ftxui-build/libftxui-screen.a
_deps/ftxui-build/examples/dom/ftxui_example_color_truecolor_RGB: _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/Bureau/8T/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ftxui_example_color_truecolor_RGB"
	cd /home/alex/Bureau/8T/build/_deps/ftxui-build/examples/dom && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ftxui_example_color_truecolor_RGB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/build: _deps/ftxui-build/examples/dom/ftxui_example_color_truecolor_RGB
.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/build

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/clean:
	cd /home/alex/Bureau/8T/build/_deps/ftxui-build/examples/dom && $(CMAKE_COMMAND) -P CMakeFiles/ftxui_example_color_truecolor_RGB.dir/cmake_clean.cmake
.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/clean

_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/depend:
	cd /home/alex/Bureau/8T/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/Bureau/8T /home/alex/Bureau/8T/build/_deps/ftxui-src/examples/dom /home/alex/Bureau/8T/build /home/alex/Bureau/8T/build/_deps/ftxui-build/examples/dom /home/alex/Bureau/8T/build/_deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/ftxui_example_color_truecolor_RGB.dir/depend

