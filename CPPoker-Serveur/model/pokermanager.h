#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <QThread>
#include <QVector>

#include "controller/pokercontroller.h"
#include "network/connectionmanager.h"
#include "network/utils.h"
#include "network/request.h"
#include "network/commands.h"
#include "pokermanagerexception.h"

class ConnectionManager;
class PokerController;

class PokerManager : public QObject
{
Q_OBJECT
private:
    PokerController * m_mController;
    QVector<ConnectionManager *> m_players;
    ConnectionManager* m_disc;
    QString m_name;

public:
    PokerManager(QString name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);
    ~PokerManager();

    void addPlayer(ConnectionManager * player);
    bool remPlayer(ConnectionManager * player);

    QString name() const;
    int nbPlayer() const;
    bool isNicknameAvailable(std::string pName) const;
    QVector<std::string> playerName() const;
    std::string toString();

public slots:
    void readRequest(ConnectionManager *cm);
    void clientDisconnected(ConnectionManager *cm);

protected:
    void sendCurrentPlayer();
    void sendCardsToPlayers();
    void manageRequest(ConnectionManager * player);
    void sendToAll(Request * req);
};

#endif // ROOMMANAGER_H
