cmake_minimum_required (VERSION 2.8)

project(Chess)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -g")

set(CPACK_SOURCE_IGNORE_FILES "bin;.*~;")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src)
