#ifndef CONNEXIONMANAGER_H
#define CONNEXIONMANAGER_H

#include <QTcpSocket>
#include <QMap>

#include "../model/player.h"
#include "../network/servsocket.h"
#include "request.h"

class ServSocket;

class ConnectionManager : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *client;
    ServSocket *servSocket;
    Player *player;
public:
    ConnectionManager(QTcpSocket* newClient, Player* player, ServSocket* serv);
public slots:
    void read();
};

#endif // CONNEXIONMANAGER_H
