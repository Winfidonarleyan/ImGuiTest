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

find_package(Vulkan REQUIRED)
find_package(SDL2 REQUIRED)

# Find include files
find_path(
        GLFW_INCLUDE_DIR
        NAMES GLFW/glfw.h
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
        NAMES glfw3
        PATHS
        /usr/lib64
        /usr/lib
        /usr/local/lib64
        /usr/local/lib
        /sw/lib
        /opt/local/lib
        ${GLFW_ROOT_DIR}/lib
        DOC "The GLFW library")

add_library(vulkan SHARED IMPORTED GLOBAL)
add_library(sdl2 STATIC IMPORTED GLOBAL)
add_library(glfw SHARED IMPORTED GLOBAL)

set_target_properties(vulkan
  PROPERTIES
    IMPORTED_LOCATION
      "${Vulkan_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES
      "${Vulkan_INCLUDE_DIRS}")

set_target_properties(sdl2
  PROPERTIES
    IMPORTED_LOCATION
      "${SDL2_LIBRARIES}"
    INTERFACE_INCLUDE_DIRECTORIES
      "${SDL2_INCLUDE_DIRS}")

set_target_properties(glfw
  PROPERTIES
    IMPORTED_LOCATION
      "${GLFW_INCLUDE_DIR}"
    INTERFACE_INCLUDE_DIRECTORIES
      "${GLFW_LIBRARY}")