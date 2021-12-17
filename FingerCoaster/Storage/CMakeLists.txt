cmake_minimum_required(VERSION 3.16)
project(StorageTests VERSION 1.0.0)

add_library(
    Storage
    Storage.cpp 
    Storage.hpp
)

add_executable(storageTests StorageTests.cpp)

target_link_libraries(storageTests PRIVATE Storage)