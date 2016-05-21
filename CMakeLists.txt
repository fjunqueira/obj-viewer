cmake_minimum_required(VERSION 3.3)
project(obj-viewer)

#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(ExternalProject)

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${PROJECT_SOURCE_DIR}/libs)

ExternalProject_Add(
        lodepng-master
        SOURCE_DIR ${PROJECT_SOURCE_DIR}/libs/lodepng
        DOWNLOAD_DIR ${PROJECT_SOURCE_DIR}/libs/download
        URL https://github.com/lvandeve/lodepng/archive/master.zip
        INSTALL_COMMAND ""
        PATCH_COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/makefiles/lodepng-CMakeLists.txt" ${PROJECT_SOURCE_DIR}/libs/lodepng/CMakeLists.txt
        LOG_DOWNLOAD ON
        LOG_CONFIGURE ON
        LOG_BUILD ON)

set(LODEPNG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/libs/lodepng)
set(LODEPNG_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/libs/lodepng/lib/${CMAKE_FIND_LIBRARY_PREFIXES}lodepng.a)
set(LODEPNG_LIBRARY lodepng)

add_library(${LODEPNG_LIBRARY} UNKNOWN IMPORTED)
set_property(TARGET ${LODEPNG_LIBRARY} PROPERTY IMPORTED_LOCATION ${LODEPNG_LIBRARY_PATH})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${LODEPNG_INCLUDE_DIR})

set(SOURCE_FILES
        source/main.cpp
        source/obj_reader.cpp
        source/obj_reader.h
        source/material.cpp
        source/material.h
        source/mesh.cpp
        source/mesh.h
        source/group.cpp
        source/group.h
        source/face.cpp
        source/face.h
        source/vector3.cpp
        source/vector3.h
        source/mtl_reader.cpp
        source/mtl_reader.h
        source/texture_reader.cpp
        source/texture_reader.h
        source/mesh_loader.cpp
        source/mesh_loader.h .
        source/mesh_drawer.cpp
        source/mesh_drawer.h
        source/picker.h
        source/picker.cpp)

add_executable(obj-viewer ${SOURCE_FILES})

add_dependencies(obj-viewer lodepng-master)

target_link_libraries(obj-viewer ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LODEPNG_LIBRARY})