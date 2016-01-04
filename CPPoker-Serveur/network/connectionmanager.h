#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QTcpSocket>
#include <QMap>
#include <QVector>

#include "../model/pokermanager.h"
#include "../network/servsocket.h"
#include "request.h"
#include "servermanager.h"
#include <exception>
#include <QMutex>
#include <QMutexLocker>

/**
 * @brief The Client class represent a client, received his requests and emit a signal to call the handler
 */
class ConnectionManager : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *m_sock;
    QVector<Request *> m_requests;
    std::string m_nickname;

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

    /**
     * @brief serverToRoom connect the newRequest signal to a PokerManager
     * @param room
     */
    void serverToRoom(PokerManager* room);

public slots:
    /**
     * @brief read slot called when QTcpSocket received data
     */
    void read();
    /**
     * @brief disconnected slot called when QTcpSocket disconnect
     */
    void disconnected();

signals:
    /**
     * @brief clientDisconnected signal send when QTcpSocket disconnect
     * @param cm pointer to the client
     */
    void clientDisconnected(ConnectionManager* cm);
    /**
     * @brief newRequest signal send when a new request is received
     * @param cm pointer to the client
     */
    void newRequest(ConnectionManager* cm);
};

#endif // CONNECTIONMANAGER_H
