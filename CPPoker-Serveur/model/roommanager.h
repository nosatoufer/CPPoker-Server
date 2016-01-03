#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <QThread>
#include <QVector>

#include "controller/pokercontroller.h"
#include "network/connectionmanager.h"
#include "network/utils.h"
#include "pattern/netobserver.h"
#include "pattern/observer.h"
#include "network/request.h"
#include "network/commands.h"
#include "roommanagerexception.h"

class ConnectionManager;
class PokerController;

class RoomManager : public QThread, public Observer, public NetObserver
{
private:
    PokerController * m_mController;
    QVector<ConnectionManager *> m_players;
    QString m_name;

public:
    RoomManager(QString name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);
    ~RoomManager();

    void addPlayer(ConnectionManager * player);
    bool remPlayer(ConnectionManager * player);

    QString name() const;
    int nbPlayer() const;
    bool isNicknameAvailable(std::string pName) const;
    QVector<std::string> playerName() const;
    std::string toString();

    void update();
    void netUpdate();

private:
    void run();
    void manageRequest(ConnectionManager * player);
    void sendToAll(Request * req);
};

#endif // ROOMMANAGER_H
