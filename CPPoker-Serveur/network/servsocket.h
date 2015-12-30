#ifndef SERVSOCKET_H
#define SERVSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMap>

#include "../model/player.h"
#include "connectionmanager.h"
#include "controller/controller.h"

class Controller;
class ConnectionManager;

class ServSocket : public QObject
{
    Q_OBJECT
private:
    QTcpServer* m_serv;
    QTcpSocket* m_sock;
    QMap<Player*, ConnectionManager*> m_player;
    Controller* controller;

public:
    explicit ServSocket(QObject *parent = 0);

    bool nicknameAvailable(std::string nickname);
    void attachController(Controller* controller);

public slots:
    void newConnection();
};

#endif // SERVSOCKET_H
