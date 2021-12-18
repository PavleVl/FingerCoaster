cmake_minimum_required(VERSION 3.16)
project(ClientTests VERSION 1.0.0)

add_library(
    Client
    Client.cpp 
    Client.hpp
)

add_executable(clientTests ClientTests.cpp)

target_link_libraries(clientTests PRIVATE Client)
