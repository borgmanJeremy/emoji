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

add_executable(emoji emoji.h)

target_sources(
        emoji
        PRIVATE
        window.cpp
        main.cpp)

target_link_libraries(
        emoji
        project_warnings
        project_options
        Qt5::Widgets
)

