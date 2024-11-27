cmake_minimum_required(VERSION 3.14)

project(ChessLikeGame)

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)
set(JSON_BuildTests OFF CACHE INTERNAL "")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)

set(IMG_DIR "${CMAKE_SOURCE_DIR}/images")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${INCLUDE_DIR}/*.h"
    "${INCLUDE_DIR}/*.hpp"
    "${INCLUDE_DIR}/*.hxx"
    "${SOURCE_DIR}/*.cpp"
    "${SOURCE_DIR}/*.cxx"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

add_executable(ChessLikeGame ${SOURCES})

target_include_directories(ChessLikeGame PRIVATE ${INCLUDE_DIR})
target_include_directories(ChessLikeGame PRIVATE ${SOURCE_DIR})

add_subdirectory(external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
add_subdirectory(external/nlohmann_json ${CMAKE_CURRENT_BINARY_DIR}/nlohmann_json)
add_subdirectory(external/SFML ${CMAKE_CURRENT_BINARY_DIR}/SFML)

target_link_libraries(ChessLikeGame spdlog nlohmann_json::nlohmann_json sfml-graphics)