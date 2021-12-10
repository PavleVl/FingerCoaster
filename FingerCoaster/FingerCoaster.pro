QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/gameEngine.cpp \
    Sources/main.cpp \
    Sources/mainMenu.cpp \
    Sources/mainwindow.cpp \
    Sources/map.cpp \
    Sources/menuBtn.cpp

HEADERS += \
    Headers/configuration.h \
    Headers/gameEngine.h \
    Headers/mainMenu.h \
    Headers/mainwindow.h \
    Headers/map.h \
    Headers/menuBtn.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
