#-------------------------------------------------
#
# Project created by QtCreator 2015-02-03T15:43:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fresh
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    board.cpp \
    raindrops.cpp \
    soapbars.cpp \
    counters.cpp \
    instructions.cpp

HEADERS  += mainwindow.h \
    player.h \
    board.h \
    raindrops.h \
    soapbars.h \
    counters.h \
    clock.h \
    instructions.h

FORMS    += mainwindow.ui \
    player.ui \
    board.ui \
    raindrops.ui \
    soapbars.ui \
    quitwidget.ui \
    counters.ui \
    clock.ui \
    youlose.ui \
    youwin.ui \
    instructions.ui

RESOURCES += \
    images.qrc
