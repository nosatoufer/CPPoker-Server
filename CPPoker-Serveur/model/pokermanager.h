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

/**
 * @brief The PokerManager class manage the request from player who enter a PokerGame
 */
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
    /**
     * @brief addPlayer add a player to the game id the game is not running
     * @param player pointer to add to the game
     */
    void addPlayer(ConnectionManager * player);
    /**
     * @brief remPlayer remove a player from the game, if the game is running it cancel the game
     * @param player pointer to delete from the game
     * @return true if player was in the game and have been deleted, false otherwise
     */
    bool remPlayer(ConnectionManager * player);
    /**
     * @brief name return the name of the manager who represent the name of the game to the client
     * @return
     */
    QString name() const;
    /**
     * @brief nbPlayer return the number of player in the game
     * @return number of player in the game
     */
    int nbPlayer() const;
    /**
     * @brief isNicknameAvailable check if the given nickname is used by a player of the game
     * @param pName is the nickname to check
     * @return true if nickname is available, false otherwise
     */
    bool isNicknameAvailable(std::string pName) const;
    /**
     * @brief playerName return a QVector of the name of the players in the game
     * @return QVector of the name of the players in the game
     */
    QVector<std::string> playerName() const;
    /**
     * @brief toString return a string representation of the game
     * @return string representation of the game
     */
    std::string toString();

public slots:
    /**
     * @brief readRequest read the request of cm when called
     * @param cm pointer to the request handler
     */
    void readRequest(ConnectionManager *cm);
    /**
     * @brief clientDisconnected is the slot to call if a client disconnect
     * @param cm pointer to the request handler
     */
    void clientDisconnected(ConnectionManager *cm);

protected:
    /**
     * @brief sendCurrentPlayer send to the players the current player who has to play
     */
    void sendCurrentPlayer();
    /**
     * @brief sendCardsToPlayers send their cards to the players of the game
     */
    void sendCardsToPlayers();
    /**
     * @brief manageRequest manage the request of client
     * @param player
     */
    void manageRequest(ConnectionManager * player);
    /**
     * @brief sendToAll send a req to all the players
     * @param req pointer to send
     */
    void sendToAll(Request * req);
};

#endif // ROOMMANAGER_H
