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
include dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/depend.make

# Include the progress variables for this target.
include dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/progress.make

# Include the compile flags for this target's objects.
include dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj: ../dep/libs/glfw-3.1.2/src/context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\context.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\context.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/context.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\context.c > CMakeFiles\glfw.dir\context.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/context.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\context.c -o CMakeFiles\glfw.dir\context.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj: ../dep/libs/glfw-3.1.2/src/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\init.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\init.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/init.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\init.c > CMakeFiles\glfw.dir\init.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/init.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\init.c -o CMakeFiles\glfw.dir\init.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj: ../dep/libs/glfw-3.1.2/src/input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\input.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\input.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/input.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\input.c > CMakeFiles\glfw.dir\input.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/input.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\input.c -o CMakeFiles\glfw.dir\input.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj: ../dep/libs/glfw-3.1.2/src/monitor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\monitor.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\monitor.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/monitor.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\monitor.c > CMakeFiles\glfw.dir\monitor.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/monitor.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\monitor.c -o CMakeFiles\glfw.dir\monitor.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj: ../dep/libs/glfw-3.1.2/src/window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\window.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\window.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/window.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\window.c > CMakeFiles\glfw.dir\window.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/window.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\window.c -o CMakeFiles\glfw.dir\window.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj: ../dep/libs/glfw-3.1.2/src/win32_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\win32_init.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_init.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/win32_init.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_init.c > CMakeFiles\glfw.dir\win32_init.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/win32_init.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_init.c -o CMakeFiles\glfw.dir\win32_init.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj: ../dep/libs/glfw-3.1.2/src/win32_monitor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\win32_monitor.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_monitor.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/win32_monitor.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_monitor.c > CMakeFiles\glfw.dir\win32_monitor.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/win32_monitor.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_monitor.c -o CMakeFiles\glfw.dir\win32_monitor.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj: ../dep/libs/glfw-3.1.2/src/win32_time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\win32_time.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_time.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/win32_time.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_time.c > CMakeFiles\glfw.dir\win32_time.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/win32_time.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_time.c -o CMakeFiles\glfw.dir\win32_time.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj: ../dep/libs/glfw-3.1.2/src/win32_tls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\win32_tls.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_tls.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/win32_tls.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_tls.c > CMakeFiles\glfw.dir\win32_tls.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/win32_tls.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_tls.c -o CMakeFiles\glfw.dir\win32_tls.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj: ../dep/libs/glfw-3.1.2/src/win32_window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\win32_window.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_window.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/win32_window.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_window.c > CMakeFiles\glfw.dir\win32_window.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/win32_window.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\win32_window.c -o CMakeFiles\glfw.dir\win32_window.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj: ../dep/libs/glfw-3.1.2/src/winmm_joystick.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\winmm_joystick.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\winmm_joystick.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/winmm_joystick.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\winmm_joystick.c > CMakeFiles\glfw.dir\winmm_joystick.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/winmm_joystick.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\winmm_joystick.c -o CMakeFiles\glfw.dir\winmm_joystick.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj


dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/flags.make
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/includes_C.rsp
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj: ../dep/libs/glfw-3.1.2/src/wgl_context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfw.dir\wgl_context.c.obj   -c C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\wgl_context.c

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/wgl_context.c.i"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\wgl_context.c > CMakeFiles\glfw.dir\wgl_context.c.i

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/wgl_context.c.s"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src\wgl_context.c -o CMakeFiles\glfw.dir\wgl_context.c.s

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.requires:

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.provides: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.requires
	$(MAKE) -f dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\build.make dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.provides.build
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.provides

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.provides.build: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj


# Object files for target glfw
glfw_OBJECTS = \
"CMakeFiles/glfw.dir/context.c.obj" \
"CMakeFiles/glfw.dir/init.c.obj" \
"CMakeFiles/glfw.dir/input.c.obj" \
"CMakeFiles/glfw.dir/monitor.c.obj" \
"CMakeFiles/glfw.dir/window.c.obj" \
"CMakeFiles/glfw.dir/win32_init.c.obj" \
"CMakeFiles/glfw.dir/win32_monitor.c.obj" \
"CMakeFiles/glfw.dir/win32_time.c.obj" \
"CMakeFiles/glfw.dir/win32_tls.c.obj" \
"CMakeFiles/glfw.dir/win32_window.c.obj" \
"CMakeFiles/glfw.dir/winmm_joystick.c.obj" \
"CMakeFiles/glfw.dir/wgl_context.c.obj"

# External object files for target glfw
glfw_EXTERNAL_OBJECTS =

dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/build.make
dep/libs/glfw-3.1.2/src/libglfw3.a: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elias\Desktop\GLTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C static library libglfw3.a"
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && $(CMAKE_COMMAND) -P CMakeFiles\glfw.dir\cmake_clean_target.cmake
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glfw.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/build: dep/libs/glfw-3.1.2/src/libglfw3.a

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/build

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/context.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/init.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/input.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/monitor.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/window.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_init.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_monitor.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_time.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_tls.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/win32_window.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/winmm_joystick.c.obj.requires
dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires: dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/wgl_context.c.obj.requires

.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/requires

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/clean:
	cd /d C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src && $(CMAKE_COMMAND) -P CMakeFiles\glfw.dir\cmake_clean.cmake
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/clean

dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elias\Desktop\GLTest C:\Users\Elias\Desktop\GLTest\dep\libs\glfw-3.1.2\src C:\Users\Elias\Desktop\GLTest\cmake-build-debug C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src C:\Users\Elias\Desktop\GLTest\cmake-build-debug\dep\libs\glfw-3.1.2\src\CMakeFiles\glfw.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : dep/libs/glfw-3.1.2/src/CMakeFiles/glfw.dir/depend

