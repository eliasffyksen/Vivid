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
include dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/depend.make

# Include the progress variables for this target.
include dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/progress.make

# Include the compile flags for this target's objects.
include dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/flags.make

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/flags.make
dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/includes_C.rsp
dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj: ../dep/libs/glfw-3.1.2/tests/monitors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\monitors.dir\monitors.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\tests\monitors.c

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/monitors.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\tests\monitors.c > CMakeFiles\monitors.dir\monitors.c.i

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/monitors.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\tests\monitors.c -o CMakeFiles\monitors.dir\monitors.c.s

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\tests\CMakeFiles\monitors.dir\build.make dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.provides.build: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj


dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/flags.make
dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/includes_C.rsp
dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj: ../dep/libs/glfw-3.1.2/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\monitors.dir\__\deps\getopt.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\deps\getopt.c

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/__/deps/getopt.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\deps\getopt.c > CMakeFiles\monitors.dir\__\deps\getopt.c.i

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/__/deps/getopt.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\deps\getopt.c -o CMakeFiles\monitors.dir\__\deps\getopt.c.s

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\tests\CMakeFiles\monitors.dir\build.make dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.provides.build: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj


# Object files for target monitors
monitors_OBJECTS = \
"CMakeFiles/monitors.dir/monitors.c.obj" \
"CMakeFiles/monitors.dir/__/deps/getopt.c.obj"

# External object files for target monitors
monitors_EXTERNAL_OBJECTS =

../bin/release_WIN64_0_1/monitors.exe: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj
../bin/release_WIN64_0_1/monitors.exe: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj
../bin/release_WIN64_0_1/monitors.exe: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build.make
../bin/release_WIN64_0_1/monitors.exe: dep/libs/glfw-3.1.2/src/libglfw3.a
../bin/release_WIN64_0_1/monitors.exe: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/linklibs.rsp
../bin/release_WIN64_0_1/monitors.exe: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/objects1.rsp
../bin/release_WIN64_0_1/monitors.exe: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ..\..\..\..\..\bin\release_WIN64_0_1\monitors.exe"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\monitors.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build: ../bin/release_WIN64_0_1/monitors.exe

.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/requires: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/monitors.c.obj.requires
dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/requires: dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.obj.requires

.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/requires

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/clean:
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests && $(CMAKE_COMMAND) -P CMakeFiles\monitors.dir\cmake_clean.cmake
.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/clean

dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elias\Desktop\GLTest C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\tests C:\Users\Elias\Desktop\GLTest\cmake-build-debug C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\tests\CMakeFiles\monitors.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : dep/libs/glfw-3.1.2/tests/CMakeFiles/monitors.dir/depend

