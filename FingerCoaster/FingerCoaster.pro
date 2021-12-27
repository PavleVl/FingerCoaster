QT  += core gui
QT  += network
QT  += concurrent
QT  += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game/game.cpp \
    Src/createroom.cpp \
    Src/gameEngine.cpp \
    Src/joinpopup.cpp \
    Src/main.cpp \
    Src/mainMenu.cpp \
    Src/mainwindow.cpp \
    Src/map.cpp \
    Src/menuBtn.cpp \
    Src/scoreboard.cpp \
    Src/enterusername.cpp \
    #These are backend libs
    Scoreboard/ScoreboardBackend.cpp \
    Storage/Storage.cpp \
    Server/Server.cpp \
    Server/Thread.cpp   \
    Client/Client.cpp   \
    Src/lobby.cpp \


HEADERS += \
    Game/game.h \
    Headers/createroom.h \
    Headers/gameEngine.h \
    Headers/joinpopup.h \
    Headers/mainMenu.h \
    Headers/mainwindow.h \
    Headers/map.h \
    Headers/menuBtn.h \
    Headers/scoreboard.h \
    Headers/enterusername.h \
    #These are backend libs
    Scoreboard/ScoreboardBackend.hpp \
    Storage/Storage.hpp \
    Server/Server.hpp \
    Server/Thread.h     \
    Client/Client.hpp \
    Headers/lobby.h \

FORMS += \
    createroom.ui \
    enterusername.ui \
    joinpopup.ui \
    lobby.ui \
    mainwindow.ui \
    scoreboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
