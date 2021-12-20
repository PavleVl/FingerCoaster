cmake_minimum_required(VERSION 3.16)
project(ServerTests VERSION 1.0.0)

add_library(
    Server
    Server.cpp 
    Server.hpp
)

add_executable(ServerTests ServerTests.cpp)

target_link_libraries(ServerTests PRIVATE Server)
