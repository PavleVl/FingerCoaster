cmake_minimum_required(VERSION 3.16)

project(Server VERSION 1.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6Core REQUIRED)
find_package(Qt6Network REQUIRED)
find_package(Qt6Widgets REQUIRED)

add_library(Server
    Server.cpp
    Server.hpp 
    Thread.cpp 
    Thread.h
    ../Src/Storage.cpp 
    ../Headers/Storage.hpp
    ../Src/ScoreboardBackend.cpp 
    ../Headers/ScoreboardBackend.hpp
)

target_link_libraries(Server Qt6::Core)
target_link_libraries(Server Qt6::Widgets)
target_link_libraries(Server Qt6::Network)
target_compile_definitions(Server PRIVATE QT_NO_CAST_FROM_ASCII)

set_target_properties(Server PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        EXPORT_NAME Server
)
