#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QThread>
#include <QVector>
#include "connectionmanager.h"
#include "servsocket.h"
#include "../model/pokermanager.h"

class ConnectionManager;
class Request;
class ServerController;
class PokerManager;

class ServerManager : public QObject
{
    Q_OBJECT
protected:
    QVector<ConnectionManager*> m_users;
    QVector<PokerManager*> m_rooms;
    ServerController* m_servController;
    ConnectionManager* m_disc;

public:
    ServerManager(ServerController* servController);
    virtual ~ServerManager();
    virtual void addUser(ConnectionManager* user);

protected:
    /**
     * @brief manageRequest reads the request command and dispatch to the appropriate function
     * @param user the user who sent the request
     */
    virtual void manageRequest(ConnectionManager* user) throw();

    /**
     * @brief roomList returns a list containing the rooms name
     * @return a list containing the rooms name
     */
    virtual std::map<std::string, std::string> roomList();

    /**
     * @brief createRoom tries to create a room of the given name
     * @param name the room's name
     * @return true if the room has been created
     */
    virtual bool createRoom(std::string name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);

    /**
     * @brief checkRoomName checks if a room of the given name already exists.
     * @param name the name to find
     * @return true if the room exists
     */
    virtual bool checkRoomName(std::string name);

    /**
     * @brief joinRoom tries to add a player to the room of the given name
     * @param user the user to add
     * @param name the room's name
     * @return true if the player succesfully joined the room
     */
    virtual bool joinRoom(ConnectionManager* user, std::string name);

    /**
     * @brief checkPlayerName checks if there is already a player with the given name
     * @param name the name to check
     * @return true if the player exists.
     */
    virtual bool isNicknameAvailable(std::string name);

    void sendRoomList(ConnectionManager* user, Request* req);

public slots:
    void clientDisconnected(ConnectionManager* cm);
    void readRequest(ConnectionManager* cm);
};

#endif // SERVERMANAGER_H
