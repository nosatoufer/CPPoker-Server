#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T02:39:12
#
#-------------------------------------------------

QT += core gui
QT += network

QT_VERSION = 5

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPPoker-Serveur
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    network/connectionmanager.cpp \
    network/servsocket.cpp \
    view/pokerservergui.cpp \
    model/pokergame.cpp \
    model/deck.cpp \
    model/card.cpp \
    model/gameexception.cpp \
    model/pokerplayer.cpp \
    model/playerexception.cpp \
    network/request.cpp \
    network/utils.cpp \
    controller/servercontroller.cpp \
    network/servermanager.cpp \
    controller/pokercontroller.cpp \
    model/pokermanagerexception.cpp \
    model/pokermanager.cpp \
    pattern/observer.cpp \
    pattern/subject.cpp

HEADERS += \
    network/connectionmanager.h \
    network/servsocket.h \
    view/pokerservergui.h \
    model/card.h \
    model/pokergame.h \
    model/deck.h \
    model/gameexception.h \
    model/gamestate.h \
    model/pokerplayer.h \
    model/playerexception.h \
    network/request.h \
    network/utils.h \
    network/commands.h \
    network/commands.h \
    network/utils.h \
    controller/servercontroller.h \
    network/servermanager.h \
    controller/pokercontroller.h \
    model/pokermanager.h \
    model/pokermanagerexception.h \
    pattern/observer.h \
    pattern/subject.h

FORMS += \
    view/pokerservergui.ui
