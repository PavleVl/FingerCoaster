cmake_minimum_required(VERSION 3.16)

project(Client VERSION 1.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6Core REQUIRED)
find_package(Qt6Network REQUIRED)
find_package(Qt6Widgets REQUIRED)
add_library(Client
    Client.cpp 
    Client.hpp
)

target_link_libraries(Client Qt6::Core)
target_link_libraries(Client Qt6::Widgets)
target_link_libraries(Client Qt6::Network)
target_compile_definitions(Client PRIVATE QT_NO_CAST_FROM_ASCII)

set_target_properties(Client PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        EXPORT_NAME Client
)
