cmake_minimum_required(VERSION 3.26)
project(UlrParser)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)
add_executable(UrlParser_run ${SOURCE_FILES})

include_directories(UrlParser_lib)
add_subdirectory(UrlParser_lib)

target_link_libraries(UrlParser_run UrlParser_lib)

add_subdirectory(Google_tests)
