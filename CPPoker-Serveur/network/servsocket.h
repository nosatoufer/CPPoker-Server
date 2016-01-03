#ifndef SERVSOCKET_H
#define SERVSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMap>

#include "../model/player.h"
#include "connectionmanager.h"
#include "controller/controller.h"
#include "servermanager.h"


class Controller;
class ModelController;
class ServerController;
class ConnectionManager;
class ServerManager;


class ServSocket : public QObject
{
    Q_OBJECT
private:
    QTcpServer* m_serv;
    ServerManager * m_servManager;

public:
    explicit ServSocket(QObject *parent = 0);
    ~ServSocket();

public slots:
    void newConnection();
};

#endif // SERVSOCKET_H
