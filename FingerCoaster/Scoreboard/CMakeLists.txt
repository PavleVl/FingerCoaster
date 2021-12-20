cmake_minimum_required(VERSION 3.16)
project(ScoreboardBackendTests VERSION 1.0.0)

add_library(
    ScoreboardBackend
    ScoreboardBackend.cpp
    ScoreboardBackend.hpp
)

add_executable(scoreboardBackendTest ScoreboardBackendTests.cpp)

target_link_libraries(scoreboardBackendTest PRIVATE ScoreboardBackend)
