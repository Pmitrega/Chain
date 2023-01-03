cmake_minimum_required(VERSION 3.17)
project(Chain)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)
set(SFML_GAME_1_SOURCES
        src/atoms.cpp)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/lib/sfml/lib/cmake/SFML)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(Chain main.cpp ${SFML_GAME_1_SOURCES})
include_directories(include)
include_directories(${PROJECT_SOURCE_DIR}/lib/sfml/include)
target_link_libraries(Chain sfml-system sfml-window sfml-graphics sfml-main)

