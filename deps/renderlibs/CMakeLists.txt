#
# This file is part of the WarheadCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# User has manually chosen to ignore the git-tests, so throw them a warning.
# This is done EACH compile so they can be alerted about the consequences.
#

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Freetype REQUIRED)

# Find include files
find_path(
        GLFW_INCLUDE_DIR
        NAMES GLFW/glfw3.h
        PATHS
        /usr/include
        /usr/local/include
        /sw/include
        /opt/local/include
        DOC "The directory where GL/glfw.h resides")

# Find library files
# Try to use static libraries
find_library(
        GLFW_LIBRARY
        NAMES glfw
        PATHS
        /usr/lib64
        /usr/lib
        /usr/local/lib64
        /usr/local/lib
        /sw/lib
        /opt/local/lib
        ${GLFW_ROOT_DIR}/lib
        DOC "The GLFW library")

add_library(sdl2 INTERFACE)
add_library(glfw INTERFACE)
add_library(opengl INTERFACE)
add_library(freetype INTERFACE)

target_include_directories(sdl2 INTERFACE ${SDL2_INCLUDE_DIRS})
target_link_libraries(sdl2 INTERFACE ${SDL2_LIBRARIES})

target_include_directories(glfw INTERFACE ${GLFW_INCLUDE_DIR})
target_link_libraries(glfw INTERFACE ${GLFW_LIBRARY})

target_link_libraries(freetype
  INTERFACE
    Freetype::Freetype)

target_link_libraries(opengl
  INTERFACE
    OpenGL::OpenGL)