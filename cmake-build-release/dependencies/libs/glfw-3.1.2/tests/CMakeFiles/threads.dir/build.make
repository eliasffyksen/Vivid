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
include dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/depend.make

# Include the progress variables for this target.
include dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/flags.make

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/flags.make
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/includes_C.rsp
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj: ../dependencies/libs/glfw-3.1.2/tests/threads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\threads.dir\threads.c.obj   -c "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests\threads.c"

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/threads.c.i"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests\threads.c" > CMakeFiles\threads.dir\threads.c.i

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/threads.c.s"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests\threads.c" -o CMakeFiles\threads.dir\threads.c.s

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.requires:

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.requires

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.provides: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.requires
	$(MAKE) -f dependencies\libs\glfw-3.1.2\tests\CMakeFiles\threads.dir\build.make dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.provides.build
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.provides

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.provides.build: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj


dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/flags.make
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/includes_C.rsp
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj: ../dependencies/libs/glfw-3.1.2/deps/tinycthread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\threads.dir\__\deps\tinycthread.c.obj   -c "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\deps\tinycthread.c"

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/__/deps/tinycthread.c.i"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\deps\tinycthread.c" > CMakeFiles\threads.dir\__\deps\tinycthread.c.i

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/__/deps/tinycthread.c.s"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && D:\MinGW-64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\deps\tinycthread.c" -o CMakeFiles\threads.dir\__\deps\tinycthread.c.s

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.requires:

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.requires

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.provides: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.requires
	$(MAKE) -f dependencies\libs\glfw-3.1.2\tests\CMakeFiles\threads.dir\build.make dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.provides.build
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.provides

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.provides.build: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj


# Object files for target threads
threads_OBJECTS = \
"CMakeFiles/threads.dir/threads.c.obj" \
"CMakeFiles/threads.dir/__/deps/tinycthread.c.obj"

# External object files for target threads
threads_EXTERNAL_OBJECTS =

../bin/debug/threads.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj
../bin/debug/threads.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj
../bin/debug/threads.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/build.make
../bin/debug/threads.exe: dependencies/libs/glfw-3.1.2/src/libglfw3.a
../bin/debug/threads.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/linklibs.rsp
../bin/debug/threads.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/objects1.rsp
../bin/debug/threads.exe: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ..\..\..\..\..\bin\debug\threads.exe"
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\threads.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/build: ../bin/debug/threads.exe

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/build

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/requires: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/threads.c.obj.requires
dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/requires: dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.obj.requires

.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/requires

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/clean:
	cd /d "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" && $(CMAKE_COMMAND) -P CMakeFiles\threads.dir\cmake_clean.cmake
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/clean

dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\workspace_programming\Workspace C++\CL projects\Vivid" "D:\workspace_programming\Workspace C++\CL projects\Vivid\dependencies\libs\glfw-3.1.2\tests" "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release" "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests" "D:\workspace_programming\Workspace C++\CL projects\Vivid\cmake-build-release\dependencies\libs\glfw-3.1.2\tests\CMakeFiles\threads.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : dependencies/libs/glfw-3.1.2/tests/CMakeFiles/threads.dir/depend

