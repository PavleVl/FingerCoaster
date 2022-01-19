QT  += core gui
QT  += network
QT  += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Src/game.cpp \
    Src/createroom.cpp \
    Src/gameEngine.cpp \
    Src/joinpopup.cpp \
    Src/main.cpp \
    Src/mainMenu.cpp \
    Src/map.cpp \
    Src/menuBtn.cpp \
    Src/scoreboard.cpp \
    Src/enterusername.cpp \
    #These are backend libs
    Src/ScoreboardBackend.cpp \
    Src/Storage.cpp \
    Server/Server.cpp \
    Server/Thread.cpp   \
    Client/Client.cpp   \
    Src/lobby.cpp \
    Src/gameDialog.cpp
#<<<<<<< HEAD
#=======
#>>>>>>> added game session


HEADERS += \
    Headers/game.h \
    Headers/createroom.h \
    Headers/gameEngine.h \
    Headers/joinpopup.h \
    Headers/mainMenu.h \
    Headers/map.h \
    Headers/menuBtn.h \
    Headers/scoreboard.h \
    Headers/enterusername.h \
    #These are backend libs
    Headers/ScoreboardBackend.hpp \
    Headers/Storage.hpp \
    Server/Server.hpp \
    Server/Thread.h     \
    Client/Client.hpp \
    Headers/lobby.h \
    Headers/gameDialog.h
#>>>>>>> added game session

FORMS += \
    Forms/createroom.ui \
    Forms/enterusername.ui \
    Forms/joinpopup.ui \
    Forms/lobby.ui \
    Forms/scoreboard.ui   \
    Forms/gamedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
