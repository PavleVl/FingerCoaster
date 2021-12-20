QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createroom.cpp \
    gameEngine.cpp \
    joinpopup.cpp \
    main.cpp \
    mainMenu.cpp \
    mainwindow.cpp \
    map.cpp \
    menuBtn.cpp \
    scoreboard.cpp \
    storage.cpp

HEADERS += \
    createroom.h \
    gameEngine.h \
    joinpopup.h \
    mainMenu.h \
    mainwindow.h \
    map.h \
    menuBtn.h \
    scoreboard.h \
    storage.h

FORMS += \
    createroom.ui \
    joinpopup.ui \
    mainwindow.ui \
    scoreboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
