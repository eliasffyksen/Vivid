# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Elias\Desktop\GLTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Elias\Desktop\GLTest\cmake-build-debug

# Include any dependencies generated for this target.
include external/glfw-3.1.2/tests/CMakeFiles/events.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/tests/CMakeFiles/events.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/tests/CMakeFiles/events.dir/flags.make

external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj: external/glfw-3.1.2/tests/CMakeFiles/events.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj: external/glfw-3.1.2/tests/CMakeFiles/events.dir/includes_C.rsp
external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj: ../external/glfw-3.1.2/tests/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\events.dir\events.c.obj   -c C:\Users\Elias\Desktop\GLTest\external\glfw-3.1.2\tests\events.c

external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/events.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\external\glfw-3.1.2\tests\events.c > CMakeFiles\events.dir\events.c.i

external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/events.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\external\glfw-3.1.2\tests\events.c -o CMakeFiles\events.dir\events.c.s

external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.requires:

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.requires

external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.provides: external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.requires
	$(MAKE) -f external\glfw-3.1.2\tests\CMakeFiles\events.dir\build.make external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.provides.build
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.provides

external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.provides.build: external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj


external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: external/glfw-3.1.2/tests/CMakeFiles/events.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: external/glfw-3.1.2/tests/CMakeFiles/events.dir/includes_C.rsp
external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: ../external/glfw-3.1.2/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\events.dir\__\deps\getopt.c.obj   -c C:\Users\Elias\Desktop\GLTest\external\glfw-3.1.2\deps\getopt.c

external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/getopt.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\external\glfw-3.1.2\deps\getopt.c > CMakeFiles\events.dir\__\deps\getopt.c.i

external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/getopt.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\external\glfw-3.1.2\deps\getopt.c -o CMakeFiles\events.dir\__\deps\getopt.c.s

external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires:

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires

external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides: external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f external\glfw-3.1.2\tests\CMakeFiles\events.dir\build.make external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides.build
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides

external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides.build: external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj


# Object files for target events
events_OBJECTS = \
"CMakeFiles/events.dir/events.c.obj" \
"CMakeFiles/events.dir/__/deps/getopt.c.obj"

# External object files for target events
events_EXTERNAL_OBJECTS =

external/glfw-3.1.2/tests/events.exe: external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj
external/glfw-3.1.2/tests/events.exe: external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj
external/glfw-3.1.2/tests/events.exe: external/glfw-3.1.2/tests/CMakeFiles/events.dir/build.make
external/glfw-3.1.2/tests/events.exe: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/tests/events.exe: external/glfw-3.1.2/tests/CMakeFiles/events.dir/linklibs.rsp
external/glfw-3.1.2/tests/events.exe: external/glfw-3.1.2/tests/CMakeFiles/events.dir/objects1.rsp
external/glfw-3.1.2/tests/events.exe: external/glfw-3.1.2/tests/CMakeFiles/events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable events.exe"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\events.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/tests/CMakeFiles/events.dir/build: external/glfw-3.1.2/tests/events.exe

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/build

external/glfw-3.1.2/tests/CMakeFiles/events.dir/requires: external/glfw-3.1.2/tests/CMakeFiles/events.dir/events.c.obj.requires
external/glfw-3.1.2/tests/CMakeFiles/events.dir/requires: external/glfw-3.1.2/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/requires

external/glfw-3.1.2/tests/CMakeFiles/events.dir/clean:
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests && $(CMAKE_COMMAND) -P CMakeFiles\events.dir\cmake_clean.cmake
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/clean

external/glfw-3.1.2/tests/CMakeFiles/events.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elias\Desktop\GLTest C:\Users\Elias\Desktop\GLTest\external\glfw-3.1.2\tests C:\Users\Elias\Desktop\GLTest\cmake-build-debug C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests C:\Users\Elias\Desktop\GLTest\cmake-build-debug\external\glfw-3.1.2\tests\CMakeFiles\events.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/events.dir/depend

