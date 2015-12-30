#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QTcpSocket>
#include <QMap>
#include <vector>

#include "../model/player.h"
#include "../network/servsocket.h"
#include "../pattern/subject.h"
#include "request.h"

class ServSocket;

class ConnectionManager : public QObject//, public Subject
{
    Q_OBJECT
private:
    QTcpSocket *m_sock;
    ServSocket *servSocket;
    std::string nickname;
    //std::vector<Request *> m_requests;

public:
    ConnectionManager(QTcpSocket* newClient, std::string player, ServSocket* serv);
    void write(Request req);
    std::string getNickname();
    //bool hasRequests();
    //Request *getRequest();

public slots:
    void read();
    void disconnected();
};

#endif // CONNECTIONMANAGER_H
