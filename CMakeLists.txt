cmake_minimum_required(VERSION 3.24)

project(MP3Lint LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.11.1/msvc2022_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

include(FetchContent)
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

get_property(targets DIRECTORY PROPERTY BUILDSYSTEM_TARGETS)
message(STATUS "Targets: ${targets}")

add_executable(MP3Lint
    mp3lint/app/main.cpp
    mp3lint/app/ui/directory_viewer.h
    mp3lint/app/ui/directory_viewer.cpp
    mp3lint/core/linter.h
    mp3lint/core/linter.cpp
    mp3lint/scan/directory_scanner/directory_scanner.h
    mp3lint/model/album.h
    mp3lint/model/song.h
    mp3lint/model/library.h
    mp3lint/app/app.h
    mp3lint/app/app.cpp
    mp3lint/scan/directory_scanner/directory_scanner.cpp
    mp3lint/scan/library_builder.h
    mp3lint/scan/library_builder.cpp
    mp3lint/scan/song_parser/song_parser.h
    mp3lint/scan/song_parser/song_parser.cpp
    mp3lint/core/console.h
    mp3lint/core/console.cpp)

target_link_libraries(MP3Lint PRIVATE Qt6::Widgets nlohmann_json::nlohmann_json)
target_include_directories(MP3Lint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
