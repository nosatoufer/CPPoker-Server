#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T02:39:12
#
#-------------------------------------------------

QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPPoker-Serveur
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    model/player.cpp \
    network/connectionmanager.cpp \
    network/servsocket.cpp \
    view/pokerservergui.cpp \
    model/room.cpp \
    model/pokerroom.cpp \
    model/pokergame.cpp \
    model/game.cpp \
    model/roomexception.cpp \
    model/deck.cpp \
    model/card.cpp \
    model/gameexception.cpp \
    model/cardplayer.cpp \
    model/pokerplayer.cpp \
    model/playerexception.cpp \
    network/request.cpp \
    network/utils.cpp \
    controller/controller.cpp \
    pattern/observer.cpp \
    pattern/subject.cpp

HEADERS += \
    model/player.h \
    network/connectionmanager.h \
    network/servsocket.h \
    view/pokerservergui.h \
    model/room.h \
    model/pokerroom.h \
    model/card.h \
    model/pokergame.h \
    model/game.h \
    model/roomexception.h \
    model/deck.h \
    model/gameexception.h \
    model/gamestate.h \
    model/cardplayer.h \
    model/pokerplayer.h \
    model/playerexception.h \
    network/request.h \
    network/utils.h \
    network/commands.h \
    network/commands.h \
    network/utils.h \
    controller/controller.h \
    pattern/observer.h \
    pattern/subject.h \
    pattern/test.hpp

FORMS += \
    view/pokerservergui.ui
