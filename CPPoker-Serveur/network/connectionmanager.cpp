#include "connectionmanager.h"
#include <QDebug>

ConnectionManager::ConnectionManager(QTcpSocket *newClient, Player* player, ServSocket *servSocket) :
    m_sock(newClient),
    servSocket(servSocket),
    player(player)
{
    qDebug() << "Test";
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
}

void ConnectionManager::read()
{
    m_requests.insert(m_requests.begin(), new Request(m_sock->readAll().toStdString()));
    notify();
}

void ConnectionManager::disconnected()
{
    qDebug() << "Disconnected";
}

void ConnectionManager::write(Request req)
{
    std::string s = req.toString();
    if(m_sock->isWritable())
        m_sock->write(s.c_str(), s.length());
}

bool ConnectionManager::hasRequests()
{
    return m_requests.size() != 0;
}

Request * ConnectionManager::getRequest()
{
    Request * c = m_requests.back();
    m_requests.pop_back();
    return c;
}
