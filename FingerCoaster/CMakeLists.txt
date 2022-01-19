cmake_minimum_required(VERSION 3.16)

project(FingerCoaster VERSION 1.0.0)



set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6Core REQUIRED)
find_package(Qt6Network REQUIRED)
find_package(Qt6Widgets REQUIRED)

add_subdirectory(Server)
add_subdirectory(Client)


#------------------------------------------------

set(RESOURCES res.qrc)
qt_add_resources(RES_SOURCES ${RESOURCES})

set(SOURCES
    Src/createroom.cpp 
    Src/enterusername.cpp
    Src/game.cpp 
    Src/gameDialog.cpp 
    Src/gameEngine.cpp
    Src/joinpopup.cpp 
    Src/lobby.cpp 
    Src/main.cpp 
    Src/mainMenu.cpp 
    Src/map.cpp 
    Src/menuBtn.cpp 
    Src/scoreboard.cpp 
    Src/ScoreboardBackend.cpp 
    Src/Storage.cpp 
)

set(HEADERS 
    Headers/configuration.h
    Headers/Result.hpp
    Headers/createroom.h
    Headers/enterusername.h
    Headers/game.h
    Headers/gameDialog.h
    Headers/gameEngine.h
    Headers/joinpopup.h 
    Headers/lobby.h 
    Headers/mainMenu.h 
    Headers/map.h 
    Headers/menuBtn.h 
    Headers/scoreboard.h
    Headers/ScoreboardBackend.hpp 
    Headers/Storage.hpp 
)

set(FORMS 
    Forms/createroom.ui 
    Forms/enterusername.ui
    Forms/gamedialog.ui 
    Forms/joinpopup.ui 
    Forms/lobby.ui 
    Forms/scoreboard.ui  
)

set(CMAKE_AUTOUIC_SEARCH_PATHS Forms)
qt6_wrap_ui(FORMS ${FORMS})
#------------------------------------------------

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
    ${RES_SOURCES}
)
#------------------------------------------------



target_link_libraries(FingerCoaster Client Server)
target_link_libraries(FingerCoaster Qt6::Core)
target_link_libraries(FingerCoaster Qt6::Widgets)
target_link_libraries(FingerCoaster Qt6::Network)
target_compile_definitions(FingerCoaster PRIVATE QT_NO_CAST_FROM_ASCII)

set_target_properties(FingerCoaster PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTORCC ON
        EXPORT_NAME FingerCoaster
)

