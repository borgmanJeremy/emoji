find_package(
        Qt5
        CONFIG
        REQUIRED
        Core
        Gui
        Widgets
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(emoji_selector)
add_subdirectory(emoji)

target_include_directories(emoji_selector
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/emoji)

target_sources(
        emoji_selector
        PRIVATE
        emojiwindow.cpp
        main.cpp)

target_link_libraries(
        emoji_selector
        project_warnings
        project_options
        Qt5::Widgets
)

