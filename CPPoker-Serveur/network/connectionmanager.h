#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QTcpSocket>
#include <QMap>
#include <vector>

#include "../model/pokermanager.h"
#include "../network/servsocket.h"
#include "request.h"
#include "servermanager.h"
#include <exception>
#include <QMutex>
#include <QMutexLocker>

/*
class ServSocket;
*/
class ConnectionManager : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *m_sock;
    std::vector<Request *> m_requests;
    std::string nickname;

public:
    ConnectionManager(QTcpSocket* newClient, ServerManager* sm);
    ~ConnectionManager();
    /**
     * @brief write writes a request to the socket
     * @param req the request to send
     */
    void write(Request *req);

    /**
     * @brief setNickName set the player nickname
     * @param name the new player's name
     */
    void setNickName(std::string name);

    /**
     * @brief getNickname returns the player's nickname
     * @return the player's nickname
     */
    std::string getNickname();

    /**
     * @brief hasRequests returns true if there is request to read
     * @return true if there is request to read
     */
    bool hasRequests();

    /**
     * @brief getRequest remove a request from the stack and returns it
     * @return a request
     */
    Request *getRequest();

    /**
     * @brief close closes the socket
     */
    void close();

    void serverToRoom(PokerManager* room);
public slots:
    void read();
    void disconnected();

signals:
    void clientDisconnected(ConnectionManager* cm);
    void newRequest(ConnectionManager* cm);
};

#endif // CONNECTIONMANAGER_H
