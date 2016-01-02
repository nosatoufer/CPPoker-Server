#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <QThread>
#include <QVector>

#include "controller/modelcontroller.h"
#include "network/connectionmanager.h"
#include "pattern/netobserver.h"
#include "pattern/observer.h"
#include "network/request.h"
#include "network/commands.h"

class ConnectionManager;
class ModelController;

class RoomManager : public QThread, public Observer, public NetObserver
{
private:
    ModelController * m_mController;
    QVector<ConnectionManager *> m_players;
    QString m_name;

public:
    RoomManager(QString name);
    ~RoomManager();



    void addPlayer(ConnectionManager * player);
    bool remPlayer(ConnectionManager * player);

    QString name() const;
    int nbPlayer() const;
    bool checkName(std::string pName) const;
    QVector<std::string> playerName() const;

    void update();
    void netUpdate();

private:
    void run();
    void readRequest(std::string pName, Request * req);
};

#endif // ROOMMANAGER_H
