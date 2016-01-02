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
    QString m_logs;
    //ServSocket * m_servSocket;
public:
    ServerManager();
    ~ServerManager();
    void addUser(ConnectionManager * user);
private:
    void run();
    /**
     * @brief manageRequest reads the request command and dispatch to the appropriate function
     * @param user the user who sent the request
     */
    void manageRequest(ConnectionManager * user);

    /**
     * @brief roomList returns a list containing the rooms name
     * @return a list containing the rooms name
     */
    QString roomList();

    /**
     * @brief createRoom tries to create a room of the given name
     * @param name the room's name
     * @return true if the room has been created
     */
    bool createRoom(ConnectionManager *user, std::string name);

    /**
     * @brief checkRoomName checks if a room of the given name already exists.
     * @param name the name to find
     * @return true if the room exists
     */
    bool checkRoomName(std::string name);

    /**
     * @brief joinRoom tries to add a player to the room of the given name
     * @param user the user to add
     * @param name the room's name
     * @return true if the player succesfully joined the room
     */
    bool joinRoom(ConnectionManager * user, std::string name);

    /**
     * @brief checkPlayerName checks if there is already a player with the given name
     * @param name the name to check
     * @return true if the player exists.
     */
    bool checkPlayerName(std::string name);
};

#endif // SERVERMANAGER_H
