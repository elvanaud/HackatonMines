# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/simoncappe/dev/hackaton/HackatonMines

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simoncappe/dev/hackaton/HackatonMines/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Donjon.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Donjon.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Donjon.dir/flags.make

src/CMakeFiles/Donjon.dir/display.cpp.o: src/CMakeFiles/Donjon.dir/flags.make
src/CMakeFiles/Donjon.dir/display.cpp.o: ../src/display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simoncappe/dev/hackaton/HackatonMines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Donjon.dir/display.cpp.o"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Donjon.dir/display.cpp.o -c /home/simoncappe/dev/hackaton/HackatonMines/src/display.cpp

src/CMakeFiles/Donjon.dir/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Donjon.dir/display.cpp.i"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simoncappe/dev/hackaton/HackatonMines/src/display.cpp > CMakeFiles/Donjon.dir/display.cpp.i

src/CMakeFiles/Donjon.dir/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Donjon.dir/display.cpp.s"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simoncappe/dev/hackaton/HackatonMines/src/display.cpp -o CMakeFiles/Donjon.dir/display.cpp.s

src/CMakeFiles/Donjon.dir/ennemi.cpp.o: src/CMakeFiles/Donjon.dir/flags.make
src/CMakeFiles/Donjon.dir/ennemi.cpp.o: ../src/ennemi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simoncappe/dev/hackaton/HackatonMines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/Donjon.dir/ennemi.cpp.o"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Donjon.dir/ennemi.cpp.o -c /home/simoncappe/dev/hackaton/HackatonMines/src/ennemi.cpp

src/CMakeFiles/Donjon.dir/ennemi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Donjon.dir/ennemi.cpp.i"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simoncappe/dev/hackaton/HackatonMines/src/ennemi.cpp > CMakeFiles/Donjon.dir/ennemi.cpp.i

src/CMakeFiles/Donjon.dir/ennemi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Donjon.dir/ennemi.cpp.s"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simoncappe/dev/hackaton/HackatonMines/src/ennemi.cpp -o CMakeFiles/Donjon.dir/ennemi.cpp.s

src/CMakeFiles/Donjon.dir/internals.cpp.o: src/CMakeFiles/Donjon.dir/flags.make
src/CMakeFiles/Donjon.dir/internals.cpp.o: ../src/internals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simoncappe/dev/hackaton/HackatonMines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/Donjon.dir/internals.cpp.o"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Donjon.dir/internals.cpp.o -c /home/simoncappe/dev/hackaton/HackatonMines/src/internals.cpp

src/CMakeFiles/Donjon.dir/internals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Donjon.dir/internals.cpp.i"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simoncappe/dev/hackaton/HackatonMines/src/internals.cpp > CMakeFiles/Donjon.dir/internals.cpp.i

src/CMakeFiles/Donjon.dir/internals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Donjon.dir/internals.cpp.s"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simoncappe/dev/hackaton/HackatonMines/src/internals.cpp -o CMakeFiles/Donjon.dir/internals.cpp.s

src/CMakeFiles/Donjon.dir/items.cpp.o: src/CMakeFiles/Donjon.dir/flags.make
src/CMakeFiles/Donjon.dir/items.cpp.o: ../src/items.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simoncappe/dev/hackaton/HackatonMines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/Donjon.dir/items.cpp.o"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Donjon.dir/items.cpp.o -c /home/simoncappe/dev/hackaton/HackatonMines/src/items.cpp

src/CMakeFiles/Donjon.dir/items.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Donjon.dir/items.cpp.i"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simoncappe/dev/hackaton/HackatonMines/src/items.cpp > CMakeFiles/Donjon.dir/items.cpp.i

src/CMakeFiles/Donjon.dir/items.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Donjon.dir/items.cpp.s"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simoncappe/dev/hackaton/HackatonMines/src/items.cpp -o CMakeFiles/Donjon.dir/items.cpp.s

# Object files for target Donjon
Donjon_OBJECTS = \
"CMakeFiles/Donjon.dir/display.cpp.o" \
"CMakeFiles/Donjon.dir/ennemi.cpp.o" \
"CMakeFiles/Donjon.dir/internals.cpp.o" \
"CMakeFiles/Donjon.dir/items.cpp.o"

# External object files for target Donjon
Donjon_EXTERNAL_OBJECTS =

src/libDonjon.a: src/CMakeFiles/Donjon.dir/display.cpp.o
src/libDonjon.a: src/CMakeFiles/Donjon.dir/ennemi.cpp.o
src/libDonjon.a: src/CMakeFiles/Donjon.dir/internals.cpp.o
src/libDonjon.a: src/CMakeFiles/Donjon.dir/items.cpp.o
src/libDonjon.a: src/CMakeFiles/Donjon.dir/build.make
src/libDonjon.a: src/CMakeFiles/Donjon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simoncappe/dev/hackaton/HackatonMines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libDonjon.a"
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Donjon.dir/cmake_clean_target.cmake
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Donjon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Donjon.dir/build: src/libDonjon.a

.PHONY : src/CMakeFiles/Donjon.dir/build

src/CMakeFiles/Donjon.dir/clean:
	cd /home/simoncappe/dev/hackaton/HackatonMines/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Donjon.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Donjon.dir/clean

src/CMakeFiles/Donjon.dir/depend:
	cd /home/simoncappe/dev/hackaton/HackatonMines/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simoncappe/dev/hackaton/HackatonMines /home/simoncappe/dev/hackaton/HackatonMines/src /home/simoncappe/dev/hackaton/HackatonMines/build /home/simoncappe/dev/hackaton/HackatonMines/build/src /home/simoncappe/dev/hackaton/HackatonMines/build/src/CMakeFiles/Donjon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Donjon.dir/depend
