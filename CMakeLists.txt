cmake_minimum_required(VERSION 3.15)
project(WebREST-test C CXX)
add_definitions(-std=c++17)

include_directories(${PROJECT_SOURCE_DIR}/third/WebREST/include)

add_executable(http_test http_test.cc)

target_link_libraries(http_test ${PROJECT_SOURCE_DIR}/third/WebREST/lib/libWebREST-static.a -lpthread)
