# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/matheus/Desktop/Desenvolvimento/clion-2017.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/matheus/Desktop/Desenvolvimento/clion-2017.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/naive.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/naive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/naive.dir/flags.make

CMakeFiles/naive.dir/main.c.o: CMakeFiles/naive.dir/flags.make
CMakeFiles/naive.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/naive.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/naive.dir/main.c.o   -c /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/main.c

CMakeFiles/naive.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/naive.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/main.c > CMakeFiles/naive.dir/main.c.i

CMakeFiles/naive.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/naive.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/main.c -o CMakeFiles/naive.dir/main.c.s

CMakeFiles/naive.dir/main.c.o.requires:

.PHONY : CMakeFiles/naive.dir/main.c.o.requires

CMakeFiles/naive.dir/main.c.o.provides: CMakeFiles/naive.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/naive.dir/build.make CMakeFiles/naive.dir/main.c.o.provides.build
.PHONY : CMakeFiles/naive.dir/main.c.o.provides

CMakeFiles/naive.dir/main.c.o.provides.build: CMakeFiles/naive.dir/main.c.o


CMakeFiles/naive.dir/jsonParser.c.o: CMakeFiles/naive.dir/flags.make
CMakeFiles/naive.dir/jsonParser.c.o: ../jsonParser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/naive.dir/jsonParser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/naive.dir/jsonParser.c.o   -c /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/jsonParser.c

CMakeFiles/naive.dir/jsonParser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/naive.dir/jsonParser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/jsonParser.c > CMakeFiles/naive.dir/jsonParser.c.i

CMakeFiles/naive.dir/jsonParser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/naive.dir/jsonParser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/jsonParser.c -o CMakeFiles/naive.dir/jsonParser.c.s

CMakeFiles/naive.dir/jsonParser.c.o.requires:

.PHONY : CMakeFiles/naive.dir/jsonParser.c.o.requires

CMakeFiles/naive.dir/jsonParser.c.o.provides: CMakeFiles/naive.dir/jsonParser.c.o.requires
	$(MAKE) -f CMakeFiles/naive.dir/build.make CMakeFiles/naive.dir/jsonParser.c.o.provides.build
.PHONY : CMakeFiles/naive.dir/jsonParser.c.o.provides

CMakeFiles/naive.dir/jsonParser.c.o.provides.build: CMakeFiles/naive.dir/jsonParser.c.o


CMakeFiles/naive.dir/cuisine.c.o: CMakeFiles/naive.dir/flags.make
CMakeFiles/naive.dir/cuisine.c.o: ../cuisine.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/naive.dir/cuisine.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/naive.dir/cuisine.c.o   -c /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cuisine.c

CMakeFiles/naive.dir/cuisine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/naive.dir/cuisine.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cuisine.c > CMakeFiles/naive.dir/cuisine.c.i

CMakeFiles/naive.dir/cuisine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/naive.dir/cuisine.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cuisine.c -o CMakeFiles/naive.dir/cuisine.c.s

CMakeFiles/naive.dir/cuisine.c.o.requires:

.PHONY : CMakeFiles/naive.dir/cuisine.c.o.requires

CMakeFiles/naive.dir/cuisine.c.o.provides: CMakeFiles/naive.dir/cuisine.c.o.requires
	$(MAKE) -f CMakeFiles/naive.dir/build.make CMakeFiles/naive.dir/cuisine.c.o.provides.build
.PHONY : CMakeFiles/naive.dir/cuisine.c.o.provides

CMakeFiles/naive.dir/cuisine.c.o.provides.build: CMakeFiles/naive.dir/cuisine.c.o


CMakeFiles/naive.dir/naive_bayes.c.o: CMakeFiles/naive.dir/flags.make
CMakeFiles/naive.dir/naive_bayes.c.o: ../naive_bayes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/naive.dir/naive_bayes.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/naive.dir/naive_bayes.c.o   -c /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/naive_bayes.c

CMakeFiles/naive.dir/naive_bayes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/naive.dir/naive_bayes.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/naive_bayes.c > CMakeFiles/naive.dir/naive_bayes.c.i

CMakeFiles/naive.dir/naive_bayes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/naive.dir/naive_bayes.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/naive_bayes.c -o CMakeFiles/naive.dir/naive_bayes.c.s

CMakeFiles/naive.dir/naive_bayes.c.o.requires:

.PHONY : CMakeFiles/naive.dir/naive_bayes.c.o.requires

CMakeFiles/naive.dir/naive_bayes.c.o.provides: CMakeFiles/naive.dir/naive_bayes.c.o.requires
	$(MAKE) -f CMakeFiles/naive.dir/build.make CMakeFiles/naive.dir/naive_bayes.c.o.provides.build
.PHONY : CMakeFiles/naive.dir/naive_bayes.c.o.provides

CMakeFiles/naive.dir/naive_bayes.c.o.provides.build: CMakeFiles/naive.dir/naive_bayes.c.o


CMakeFiles/naive.dir/cronometro.c.o: CMakeFiles/naive.dir/flags.make
CMakeFiles/naive.dir/cronometro.c.o: ../cronometro.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/naive.dir/cronometro.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/naive.dir/cronometro.c.o   -c /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cronometro.c

CMakeFiles/naive.dir/cronometro.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/naive.dir/cronometro.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cronometro.c > CMakeFiles/naive.dir/cronometro.c.i

CMakeFiles/naive.dir/cronometro.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/naive.dir/cronometro.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cronometro.c -o CMakeFiles/naive.dir/cronometro.c.s

CMakeFiles/naive.dir/cronometro.c.o.requires:

.PHONY : CMakeFiles/naive.dir/cronometro.c.o.requires

CMakeFiles/naive.dir/cronometro.c.o.provides: CMakeFiles/naive.dir/cronometro.c.o.requires
	$(MAKE) -f CMakeFiles/naive.dir/build.make CMakeFiles/naive.dir/cronometro.c.o.provides.build
.PHONY : CMakeFiles/naive.dir/cronometro.c.o.provides

CMakeFiles/naive.dir/cronometro.c.o.provides.build: CMakeFiles/naive.dir/cronometro.c.o


# Object files for target naive
naive_OBJECTS = \
"CMakeFiles/naive.dir/main.c.o" \
"CMakeFiles/naive.dir/jsonParser.c.o" \
"CMakeFiles/naive.dir/cuisine.c.o" \
"CMakeFiles/naive.dir/naive_bayes.c.o" \
"CMakeFiles/naive.dir/cronometro.c.o"

# External object files for target naive
naive_EXTERNAL_OBJECTS =

../naive: CMakeFiles/naive.dir/main.c.o
../naive: CMakeFiles/naive.dir/jsonParser.c.o
../naive: CMakeFiles/naive.dir/cuisine.c.o
../naive: CMakeFiles/naive.dir/naive_bayes.c.o
../naive: CMakeFiles/naive.dir/cronometro.c.o
../naive: CMakeFiles/naive.dir/build.make
../naive: /lib/x86_64-linux-gnu/libjson.so.0
../naive: CMakeFiles/naive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ../naive"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/naive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/naive.dir/build: ../naive

.PHONY : CMakeFiles/naive.dir/build

CMakeFiles/naive.dir/requires: CMakeFiles/naive.dir/main.c.o.requires
CMakeFiles/naive.dir/requires: CMakeFiles/naive.dir/jsonParser.c.o.requires
CMakeFiles/naive.dir/requires: CMakeFiles/naive.dir/cuisine.c.o.requires
CMakeFiles/naive.dir/requires: CMakeFiles/naive.dir/naive_bayes.c.o.requires
CMakeFiles/naive.dir/requires: CMakeFiles/naive.dir/cronometro.c.o.requires

.PHONY : CMakeFiles/naive.dir/requires

CMakeFiles/naive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/naive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/naive.dir/clean

CMakeFiles/naive.dir/depend:
	cd /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug /home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel/cmake-build-debug/CMakeFiles/naive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/naive.dir/depend

