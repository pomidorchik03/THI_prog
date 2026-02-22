cmake_minimum_required(VERSION 3.10.0)
project(Main VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Transport SHARED lib/Plane.cpp lib/Train.cpp)
set_target_properties(Transport PROPERTIES PREFIX "")
target_compile_definitions(Transport PRIVATE MY_LIB_EXPORTS)

add_executable(Main main.cpp)
target_link_libraries(Main ${CMAKE_CURRENT_SOURCE_DIR}/build/libTransport.dll.a)