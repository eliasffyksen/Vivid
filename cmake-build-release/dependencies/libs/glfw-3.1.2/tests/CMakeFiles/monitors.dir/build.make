# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\programs\CLion\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\programs\CLion\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\workspace_programming\Workspace C++\CL projects\Vivid"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release"

# Include any dependencies generated for this target.
include dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/depend.make

# Include the progress variables for this target.
include dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/flags.make

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/flags.make
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/includes_C.rsp
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj: ../dependencies/libs/glfw-3.1.2/tests/monitors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\monitors.dir\monitors.c.obj   -c "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests\monitors.c"

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/monitors.c.i"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests\monitors.c" > CMakeFiles\monitors.dir\monitors.c.i

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/monitors.c.s"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests\monitors.c" -o CMakeFiles\monitors.dir\monitors.c.s

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires:

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires
	$(MAKE) -f dependencies\libs\glfw-3.1.2\tests\CMakeFiles\monitors.dir\build.make dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides.build
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides.build: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj


dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/flags.make
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/includes_C.rsp
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: ../dependencies/libs/glfw-3.1.2/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\monitors.dir\__\deps\getopt.c.obj   -c "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\deps\getopt.c"

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/__/deps/getopt.c.i"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\deps\getopt.c" > CMakeFiles\monitors.dir\__\deps\getopt.c.i

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/__/deps/getopt.c.s"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\deps\getopt.c" -o CMakeFiles\monitors.dir\__\deps\getopt.c.s

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires:

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f dependencies\libs\glfw-3.1.2\tests\CMakeFiles\monitors.dir\build.make dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides.build
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides.build: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj


# Object files for target monitors
monitors_OBJECTS = \
"CMakeFiles/monitors.dir/monitors.c.obj" \
"CMakeFiles/monitors.dir/__/deps/getopt.c.obj"

# External object files for target monitors
monitors_EXTERNAL_OBJECTS =

../bin/debug/monitors.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj
../bin/debug/monitors.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj
../bin/debug/monitors.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build.make
../bin/debug/monitors.exe: dependencies/libs/glfw-3.1.2/src/libglfw3.a
../bin/debug/monitors.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/linklibs.rsp
../bin/debug/monitors.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/objects1.rsp
../bin/debug/monitors.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ..\..\..\..\..\bin\debug\monitors.exe"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\monitors.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build: ../bin/debug/monitors.exe

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/requires: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/requires: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/requires

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/clean:
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && $(CMAKE_COMMAND) -P CMakeFiles\monitors.dir\cmake_clean.cmake
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/clean

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\workspace_programming\Workspace C++\CL projects\Vivid" "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests" "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release" "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests\CMakeFiles\monitors.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/depend

