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
CMAKE_SOURCE_DIR = /home/vany/Desktop/work/myproject/training_assign

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vany/Desktop/work/myproject/training_assign/build

# Include any dependencies generated for this target.
include CMakeFiles/training_exam_app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/training_exam_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/training_exam_app.dir/flags.make

CMakeFiles/training_exam_app.dir/src/main.c.o: CMakeFiles/training_exam_app.dir/flags.make
CMakeFiles/training_exam_app.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vany/Desktop/work/myproject/training_assign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/training_exam_app.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/training_exam_app.dir/src/main.c.o   -c /home/vany/Desktop/work/myproject/training_assign/src/main.c

CMakeFiles/training_exam_app.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/training_exam_app.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vany/Desktop/work/myproject/training_assign/src/main.c > CMakeFiles/training_exam_app.dir/src/main.c.i

CMakeFiles/training_exam_app.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/training_exam_app.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vany/Desktop/work/myproject/training_assign/src/main.c -o CMakeFiles/training_exam_app.dir/src/main.c.s

CMakeFiles/training_exam_app.dir/src/execute_command.c.o: CMakeFiles/training_exam_app.dir/flags.make
CMakeFiles/training_exam_app.dir/src/execute_command.c.o: ../src/execute_command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vany/Desktop/work/myproject/training_assign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/training_exam_app.dir/src/execute_command.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/training_exam_app.dir/src/execute_command.c.o   -c /home/vany/Desktop/work/myproject/training_assign/src/execute_command.c

CMakeFiles/training_exam_app.dir/src/execute_command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/training_exam_app.dir/src/execute_command.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vany/Desktop/work/myproject/training_assign/src/execute_command.c > CMakeFiles/training_exam_app.dir/src/execute_command.c.i

CMakeFiles/training_exam_app.dir/src/execute_command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/training_exam_app.dir/src/execute_command.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vany/Desktop/work/myproject/training_assign/src/execute_command.c -o CMakeFiles/training_exam_app.dir/src/execute_command.c.s

CMakeFiles/training_exam_app.dir/src/read_write.c.o: CMakeFiles/training_exam_app.dir/flags.make
CMakeFiles/training_exam_app.dir/src/read_write.c.o: ../src/read_write.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vany/Desktop/work/myproject/training_assign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/training_exam_app.dir/src/read_write.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/training_exam_app.dir/src/read_write.c.o   -c /home/vany/Desktop/work/myproject/training_assign/src/read_write.c

CMakeFiles/training_exam_app.dir/src/read_write.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/training_exam_app.dir/src/read_write.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vany/Desktop/work/myproject/training_assign/src/read_write.c > CMakeFiles/training_exam_app.dir/src/read_write.c.i

CMakeFiles/training_exam_app.dir/src/read_write.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/training_exam_app.dir/src/read_write.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vany/Desktop/work/myproject/training_assign/src/read_write.c -o CMakeFiles/training_exam_app.dir/src/read_write.c.s

CMakeFiles/training_exam_app.dir/src/signal_handler.c.o: CMakeFiles/training_exam_app.dir/flags.make
CMakeFiles/training_exam_app.dir/src/signal_handler.c.o: ../src/signal_handler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vany/Desktop/work/myproject/training_assign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/training_exam_app.dir/src/signal_handler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/training_exam_app.dir/src/signal_handler.c.o   -c /home/vany/Desktop/work/myproject/training_assign/src/signal_handler.c

CMakeFiles/training_exam_app.dir/src/signal_handler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/training_exam_app.dir/src/signal_handler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vany/Desktop/work/myproject/training_assign/src/signal_handler.c > CMakeFiles/training_exam_app.dir/src/signal_handler.c.i

CMakeFiles/training_exam_app.dir/src/signal_handler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/training_exam_app.dir/src/signal_handler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vany/Desktop/work/myproject/training_assign/src/signal_handler.c -o CMakeFiles/training_exam_app.dir/src/signal_handler.c.s

# Object files for target training_exam_app
training_exam_app_OBJECTS = \
"CMakeFiles/training_exam_app.dir/src/main.c.o" \
"CMakeFiles/training_exam_app.dir/src/execute_command.c.o" \
"CMakeFiles/training_exam_app.dir/src/read_write.c.o" \
"CMakeFiles/training_exam_app.dir/src/signal_handler.c.o"

# External object files for target training_exam_app
training_exam_app_EXTERNAL_OBJECTS =

training_exam_app: CMakeFiles/training_exam_app.dir/src/main.c.o
training_exam_app: CMakeFiles/training_exam_app.dir/src/execute_command.c.o
training_exam_app: CMakeFiles/training_exam_app.dir/src/read_write.c.o
training_exam_app: CMakeFiles/training_exam_app.dir/src/signal_handler.c.o
training_exam_app: CMakeFiles/training_exam_app.dir/build.make
training_exam_app: CMakeFiles/training_exam_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vany/Desktop/work/myproject/training_assign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable training_exam_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/training_exam_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/training_exam_app.dir/build: training_exam_app

.PHONY : CMakeFiles/training_exam_app.dir/build

CMakeFiles/training_exam_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/training_exam_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/training_exam_app.dir/clean

CMakeFiles/training_exam_app.dir/depend:
	cd /home/vany/Desktop/work/myproject/training_assign/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vany/Desktop/work/myproject/training_assign /home/vany/Desktop/work/myproject/training_assign /home/vany/Desktop/work/myproject/training_assign/build /home/vany/Desktop/work/myproject/training_assign/build /home/vany/Desktop/work/myproject/training_assign/build/CMakeFiles/training_exam_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/training_exam_app.dir/depend

