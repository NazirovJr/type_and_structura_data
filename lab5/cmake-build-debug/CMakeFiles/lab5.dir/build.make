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
CMAKE_COMMAND = /home/nazirov/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nazirov/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab5.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab5.dir/flags.make

CMakeFiles/lab5.dir/src/main.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab5.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/main.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/main.c

CMakeFiles/lab5.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/main.c > CMakeFiles/lab5.dir/src/main.c.i

CMakeFiles/lab5.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/main.c -o CMakeFiles/lab5.dir/src/main.c.s

CMakeFiles/lab5.dir/src/list_que_operation.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/list_que_operation.c.o: ../src/list_que_operation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab5.dir/src/list_que_operation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/list_que_operation.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/list_que_operation.c

CMakeFiles/lab5.dir/src/list_que_operation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/list_que_operation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/list_que_operation.c > CMakeFiles/lab5.dir/src/list_que_operation.c.i

CMakeFiles/lab5.dir/src/list_que_operation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/list_que_operation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/list_que_operation.c -o CMakeFiles/lab5.dir/src/list_que_operation.c.s

CMakeFiles/lab5.dir/src/arr_que_operation.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/arr_que_operation.c.o: ../src/arr_que_operation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab5.dir/src/arr_que_operation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/arr_que_operation.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/arr_que_operation.c

CMakeFiles/lab5.dir/src/arr_que_operation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/arr_que_operation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/arr_que_operation.c > CMakeFiles/lab5.dir/src/arr_que_operation.c.i

CMakeFiles/lab5.dir/src/arr_que_operation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/arr_que_operation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/arr_que_operation.c -o CMakeFiles/lab5.dir/src/arr_que_operation.c.s

CMakeFiles/lab5.dir/src/timer.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/timer.c.o: ../src/timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lab5.dir/src/timer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/timer.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/timer.c

CMakeFiles/lab5.dir/src/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/timer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/timer.c > CMakeFiles/lab5.dir/src/timer.c.i

CMakeFiles/lab5.dir/src/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/timer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/timer.c -o CMakeFiles/lab5.dir/src/timer.c.s

CMakeFiles/lab5.dir/src/menu.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/menu.c.o: ../src/menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lab5.dir/src/menu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/menu.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/menu.c

CMakeFiles/lab5.dir/src/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/menu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/menu.c > CMakeFiles/lab5.dir/src/menu.c.i

CMakeFiles/lab5.dir/src/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/menu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/menu.c -o CMakeFiles/lab5.dir/src/menu.c.s

CMakeFiles/lab5.dir/src/utils.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/utils.c.o: ../src/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lab5.dir/src/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/utils.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/utils.c

CMakeFiles/lab5.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/utils.c > CMakeFiles/lab5.dir/src/utils.c.i

CMakeFiles/lab5.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/utils.c -o CMakeFiles/lab5.dir/src/utils.c.s

CMakeFiles/lab5.dir/src/process.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/process.c.o: ../src/process.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/lab5.dir/src/process.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/process.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/process.c

CMakeFiles/lab5.dir/src/process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/process.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/process.c > CMakeFiles/lab5.dir/src/process.c.i

CMakeFiles/lab5.dir/src/process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/process.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/process.c -o CMakeFiles/lab5.dir/src/process.c.s

CMakeFiles/lab5.dir/src/print.c.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/src/print.c.o: ../src/print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/lab5.dir/src/print.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5.dir/src/print.c.o -c /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/print.c

CMakeFiles/lab5.dir/src/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5.dir/src/print.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/print.c > CMakeFiles/lab5.dir/src/print.c.i

CMakeFiles/lab5.dir/src/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5.dir/src/print.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/src/print.c -o CMakeFiles/lab5.dir/src/print.c.s

# Object files for target lab5
lab5_OBJECTS = \
"CMakeFiles/lab5.dir/src/main.c.o" \
"CMakeFiles/lab5.dir/src/list_que_operation.c.o" \
"CMakeFiles/lab5.dir/src/arr_que_operation.c.o" \
"CMakeFiles/lab5.dir/src/timer.c.o" \
"CMakeFiles/lab5.dir/src/menu.c.o" \
"CMakeFiles/lab5.dir/src/utils.c.o" \
"CMakeFiles/lab5.dir/src/process.c.o" \
"CMakeFiles/lab5.dir/src/print.c.o"

# External object files for target lab5
lab5_EXTERNAL_OBJECTS =

lab5: CMakeFiles/lab5.dir/src/main.c.o
lab5: CMakeFiles/lab5.dir/src/list_que_operation.c.o
lab5: CMakeFiles/lab5.dir/src/arr_que_operation.c.o
lab5: CMakeFiles/lab5.dir/src/timer.c.o
lab5: CMakeFiles/lab5.dir/src/menu.c.o
lab5: CMakeFiles/lab5.dir/src/utils.c.o
lab5: CMakeFiles/lab5.dir/src/process.c.o
lab5: CMakeFiles/lab5.dir/src/print.c.o
lab5: CMakeFiles/lab5.dir/build.make
lab5: CMakeFiles/lab5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable lab5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab5.dir/build: lab5
.PHONY : CMakeFiles/lab5.dir/build

CMakeFiles/lab5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab5.dir/clean

CMakeFiles/lab5.dir/depend:
	cd /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5 /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5 /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug /home/nazirov/projects/C++/C/TYPEANDSTRUCTDATA/lab5/cmake-build-debug/CMakeFiles/lab5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab5.dir/depend

