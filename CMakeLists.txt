cmake_minimum_required(VERSION 3.7)
project(Vivid)

set (VERSION_MAJOR 0)
set (VERSION_MINOR 0)
set (DEBUG false)

if (WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(PLATFORM WIN64)
    else()
        set(PLATFORM WIN32)
    endif()
endif()

configure_file(
        ${PROJECT_SOURCE_DIR}/config.h.in
        ${PROJECT_SOURCE_DIR}/src/config.h
)

set(CMAKE_CXX_STANDARD 11)

if(DEBUG)
    set(RELEASE_FOLDER bin/debug)
else()
    set(RELEASE_FOLDER bin/release_${PLATFORM}_${VERSION_MAJOR}_${VERSION_MINOR})
endif()

#DELETING BIN FILES IF THEY EXSIST
file(REMOVE_RECURSE ${RELEASE_FOLDER})

if(PLATFORM MATCHES "WIN64")
    #COPYING RES FILES TO BIN
    file(GLOB DEP_FILES dependencies/win64/*)
    file(COPY ${DEP_FILES} DESTINATION "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")
endif()

#COPYING RES FILES TO BIN
file(GLOB RES_FILES res/*)
file(COPY ${RES_FILES} DESTINATION "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")

#SETTING OUTPUT DIRECTORY TO BIN
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/${RELEASE_FOLDER}")

#INCLUDING OpenGL
find_package(OpenGL REQUIRED)

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

# Compile libs dependencies
add_subdirectory (dependencies/libs)

# Including header files
include_directories(dependencies/include)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )



set(SOURCE_FILES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})
