cmake_minimum_required(VERSION 3.16)
project(ScoreboardTests VERSION 1.0.0)

add_library(
    Scoreboard
    Scoreboard.cpp
    Scoreboard.hpp
)

add_executable(scoreboardTest ScoreboardTests.cpp)

target_link_libraries(scoreboardTest PRIVATE Scoreboard)