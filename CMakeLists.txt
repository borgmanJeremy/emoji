cmake_minimum_required(VERSION 3.13)

set(EMOJI_VERSION 0.10.1)

project(
        emoji_selector
        VERSION ${EMOJI_VERSION}
        LANGUAGES CXX)

include(cmake/StandardProjectSettings.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

add_library(project_warnings INTERFACE)

# enable cache system
include(cmake/Cache.cmake)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
# set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

add_subdirectory(src)

