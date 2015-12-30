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

class ConnectionManager : public QObject, public Subject
{
    Q_OBJECT
private:
    QTcpSocket *m_sock;
    ServSocket *servSocket;
    Player *player;
    std::vector<Request *> m_requests;

public:
    ConnectionManager(QTcpSocket* newClient, Player* player, ServSocket* serv);
    void write(Request req);
    bool hasRequests();
    Request *getRequest();
public slots:
    void read();
    void disconnected();
};

#endif // CONNECTIONMANAGER_H
