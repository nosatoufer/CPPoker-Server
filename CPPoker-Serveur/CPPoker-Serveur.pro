#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T02:39:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPPoker-Serveur
TEMPLATE = app


SOURCES += main.cpp\
    model/player.cpp \
    network/connectionmanager.cpp \
    network/servsocket.cpp \
    view/pokerserveurgui.cpp

HEADERS += \
    model/player.h \
    network/connectionmanager.h \
    network/servsocket.h \
    view/pokerserveurgui.h

FORMS += \
    view/pokerserveurgui.ui
