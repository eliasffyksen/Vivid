cmake_minimum_required(VERSION 3.7)

#----PROJECT VARIABLES----#
project(Vivid)

set(CMAKE_CXX_STANDARD 17)

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(DEBUG true)
else ()
	set(DEBUG false)
endif ()
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
#-------------------------#

# Find the platform of the compiling system
if (WIN32)
	if (NOT DEBUG)
		SET(EXE_ARGUMENT ${EXE_ARGUMENT} WIN32)
	endif ()

	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(PLATFORM WIN64)
	else ()
		set(PLATFORM WIN32)
	endif ()
endif (WIN32)

# Create the configuration file for the C++ code
configure_file(
		${PROJECT_SOURCE_DIR}/config.h.in
		${PROJECT_SOURCE_DIR}/src/vivid/util/config.h
)

# Set the correct output folder
if (DEBUG)
	set(RELEASE_FOLDER bin/debug)
else (DEBUG)
	set(RELEASE_FOLDER bin/release_${PLATFORM}/${VERSION_MAJOR}.${VERSION_MINOR})
endif (DEBUG)

# Delete any existing bin files
file(REMOVE_RECURSE ${RELEASE_FOLDER})

# Setting output folder to the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")

# Copy the platform-dependent dlls and libraries
if (PLATFORM MATCHES "WIN64")
	file(GLOB DEP_FILES dependencies/win64/*)
	file(COPY ${DEP_FILES} DESTINATION "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")
endif ()

# Copying resource files to the correct bin folder
file(GLOB RES_FILES res/*)
file(COPY ${RES_FILES} DESTINATION "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")

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
set(
		ALL_LIBS

		${OPENGL_LIBRARY}
		glfw
		GLEW_1130
		VividImage
)

# Adds all the source files (CLion automatically does this when creating a file)
set(
		SOURCE_FILES

		src/vivid/util/config.h
		src/main.cpp
		src/vivid/graphics/shader.h
		src/vivid/graphics/shader.cpp
		src/vivid/graphics/window.h
		src/vivid/graphics/window.cpp
		src/vivid/vivid.h
		src/vivid/util/timer.h
		src/vivid/input/input.cpp
		src/vivid/input/input.h
		src/vivid/graphics/renderer2D.h
		src/vivid/graphics/renderable2D.h
		src/vivid/graphics/batchrenderer2D.cpp
		src/vivid/graphics/batchrenderer2D.h
		src/vivid/graphics/buffers/buffer.cpp
		src/vivid/graphics/buffers/buffer.h
		src/vivid/graphics/buffers/indexbuffer.cpp
		src/vivid/graphics/buffers/indexbuffer.h
		src/vivid/graphics/buffers/vertexarray.cpp
		src/vivid/graphics/buffers/vertexarray.h
		src/vivid/graphics/buffers/buffers.h
		src/vivid/scenegraph/sprite.h
		src/vivid/scenegraph/sprite.cpp
		src/vivid/graphics/texture.cpp
		src/vivid/graphics/texture.h
		src/vivid/scenegraph/gameobject.cpp
		src/vivid/scenegraph/gameobject.h
		src/vivid/scenegraph/camera.cpp
		src/vivid/scenegraph/camera.h
		src/vivid/scenegraph/layer.cpp
		src/vivid/scenegraph/layer.h
		src/vivid/scenegraph/transform.cpp
		src/vivid/scenegraph/transform.h
		src/vivid/util/maths/maths.h src/vivid/util/resource.cpp src/vivid/util/resource.h)

add_executable(${PROJECT_NAME} ${EXE_ARGUMENT} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})
