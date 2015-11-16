QT       += core gui
QT       += network

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPPoker-Serveur
TEMPLATE = app

SOURCES += main.cpp \
    model/player.cpp \
    network/connectionmanager.cpp \
    network/servsocket.cpp

HEADERS += \
    model/player.h \
    network/connectionmanager.h \
    network/servsocket.h
