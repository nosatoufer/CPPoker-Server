#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QThread>
#include <QVector>
#include "connectionmanager.h"
#include "servsocket.h"
#include "model/roommanager.h"


class RoomManager;
//class ServSocket;

class ServerManager : public QThread
{
private:
    QVector<ConnectionManager *> m_newUsers;
    QVector<RoomManager *> m_rooms;
    //ServSocket * m_servSocket;
public:
    ServerManager();
    void addUser(ConnectionManager * user);
private:
    void run();
    void manageRequest(Request * req);

    bool checkName(std::string name);
};

#endif // SERVERMANAGER_H
