#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QTcpSocket>
#include <QMap>
#include <vector>

#include "../model/player.h"
#include "../network/servsocket.h"
#include "../pattern/netsubject.h"
#include "request.h"

/*
class ServSocket;
*/
class ConnectionManager : public QObject, public NetSubject
{
    Q_OBJECT
private:
    QTcpSocket *m_sock;
    //ServSocket *servSocket;
    std::string nickname;
    std::vector<Request *> m_requests;

public:
    ConnectionManager(QTcpSocket* newClient);
    //ConnectionManager(QTcpSocket* newClient, ServSocket* serv);
    void write(Request req);
    void setNickName(std::string name);
    std::string getNickname();
    bool hasRequests();
    Request *getRequest();

public slots:
    void read();
    void disconnected();
};

#endif // CONNECTIONMANAGER_H
