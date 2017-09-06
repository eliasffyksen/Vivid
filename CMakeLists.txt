cmake_minimum_required(VERSION 3.7)

#----PROJECT VARIABLES----#
project(Vivid)

set(DEBUG true)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
#-------------------------#

# Find the platform of the compiling system
if (WIN32)
	if(NOT DEBUG)
		SET(EXE_ARGUMENT ${EXE_ARGUMENT} WIN32)
	endif()

	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(PLATFORM WIN64)
	else ()
		set(PLATFORM WIN32)
	endif ()
endif (WIN32)

# Create the configuration file for the C++ code
configure_file(
		${PROJECT_SOURCE_DIR}/config.h.in
		${PROJECT_SOURCE_DIR}/src/config.h
)

set(CMAKE_CXX_STANDARD 11)

# Set the correct output folder
if (DEBUG)
	set(RELEASE_FOLDER bin/debug)
else (DEBUG)
	set(RELEASE_FOLDER bin/release_${PLATFORM}/${VERSION_MAJOR}.${VERSION_MINOR})
endif (DEBUG)

# Delete any existing bin files
file(REMOVE_RECURSE ${RELEASE_FOLDER})

# Copy the platform-dependent dlls and libraries
if (PLATFORM MATCHES "WIN64")
	file(GLOB DEP_FILES dependencies/win64/*)
	file(COPY ${DEP_FILES} DESTINATION "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")
endif ()

# Copying resource files to the correct bin folder
file(GLOB RES_FILES res/*)
file(COPY ${RES_FILES} DESTINATION "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")

# Setting output folder to the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")

# Adds a copy of the source code for reference in release builds
if (NOT DEBUG)
	file(COPY src DESTINATION "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")
endif (NOT DEBUG)

# Include OpenGL (Would be a shame to forget doing this...)
find_package(OpenGL REQUIRED)

# Adds a few definitions because the libraries need it
add_definitions(
		-DTW_STATIC
		-DTW_NO_LIB_PRAGMA
		-DTW_NO_DIRECT3D
		-DGLEW_STATIC
		-D_CRT_SECURE_NO_WARNINGS
)

# Compile library dependencies
add_subdirectory(dependencies/libs)

# Include header files
include_directories(dependencies/include)

# Pack all the necessary libraries in one convenient variable
set(ALL_LIBS
		${OPENGL_LIBRARY}
		glfw
		GLEW_1130
)

# Adds all the source files (CLion automatically does this when creating a file)
set(SOURCE_FILES src/config.h src/main.cpp src/vivid/graphics/shader.h src/vivid/graphics/shader.cpp src/vivid/graphics/window.h src/vivid/graphics/window.cpp src/vivid/vivid.h src/vivid/util/timer.h src/vivid/input/input.cpp src/vivid/input/input.h)

add_executable(${PROJECT_NAME} ${EXE_ARGUMENT} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})
