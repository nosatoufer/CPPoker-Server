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
class ModelController;
class ServerController;
class ConnectionManager;

class ServSocket : public QObject
{
    Q_OBJECT
private:
    QTcpServer* m_serv;
    QTcpSocket* m_sock;
    std::vector<ConnectionManager*> m_player;

    Controller* controller;
    ServerController* serverController;
    std::vector<ModelController*> modelController;

public:
    explicit ServSocket(QObject *parent = 0);

    bool nicknameAvailable(std::string nickname);
    void attachController(Controller* controller);
    void attachController(ModelController* controller);
    void attachController(ServerController* controller);

public slots:
    void newConnection();
};

#endif // SERVSOCKET_H
