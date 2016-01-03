#ifndef SERVSOCKET_H
#define SERVSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMap>

#include "connectionmanager.h"
#include "servermanager.h"


class Controller;
class ModelController;
class ServerController;
class ConnectionManager;
class ServerManager;

/**
 * @brief The ServSocket class represent the server socket
 */
class ServSocket : public QObject
{
    Q_OBJECT
private:
    QTcpServer* m_serv;
    ServerManager* m_servManager;
    ServerController* m_servController;

public:
    explicit ServSocket(ServerController* servController, QObject *parent = 0);
    virtual ~ServSocket();

public slots:
    /**
     * @brief newConnection slot called when a client connect
     */
    void newConnection();
};

#endif // SERVSOCKET_H
