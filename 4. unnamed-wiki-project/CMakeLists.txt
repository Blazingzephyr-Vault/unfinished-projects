
# CMake setup
cmake_minimum_required(VERSION 3.5)
project(UnnamedWikiProject)

# Add 3rd party libraries
include(cmake/fltk.cmake)
include(cmake/asio.cmake)

# Set CMake options
set(CMAKE_CXX_STANDARD 20)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Get source files
# Add executable
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.*" "include/*.*")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCES})

# Finish adding the libraries
INSTALL_FLTK_FOR(${CMAKE_PROJECT_NAME})
INSTALL_ASIO_FOR(${CMAKE_PROJECT_NAME})
