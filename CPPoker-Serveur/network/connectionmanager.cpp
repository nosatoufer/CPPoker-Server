#include "connectionmanager.h"
#include <QDebug>

ConnectionManager::ConnectionManager(QTcpSocket *newClient, ServerManager* sm) :
    m_sock(newClient),
    m_requests(),
    nickname("guest")
{
    qDebug() << "Client connected";
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    connect(this, SIGNAL(clientDisconnected(ConnectionManager*)), sm, SLOT(clientDisconnected(ConnectionManager*)));
    connect(this, SIGNAL(newRequest(ConnectionManager*)), sm, SLOT(readRequest(ConnectionManager*)));
    qDebug() << "Client connect connected";
    Request * req = new Request();
    req->setCommand(LOGIN);
    this->write(req);
    delete req;
}

ConnectionManager::~ConnectionManager()
{
    qDebug() << "~ConnectionManager()";
    this->disconnect();
    //disconnect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    //disconnect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    //m_sock->readAll();
    //m_sock->close();
    delete m_sock;
    for(Request * req : m_requests)
        delete req;
    qDebug() << "~ConnectionManager 2";

}

void ConnectionManager::read()
{
    //mutex.lock();
    QString req(m_sock->readAll());
    qDebug() << "Request received : " << req;
    m_requests.insert(m_requests.begin(), new Request(req.toStdString()));
    emit newRequest(this);
    //mutex.unlock();
}

void ConnectionManager::disconnected()
{
    qDebug() << "Client disconnected";
    emit clientDisconnected(this);
}

void ConnectionManager::write(Request * req)
{
    if(m_sock->isOpen() && m_sock->isWritable())
    {
        std::string s = req->toString();
        qDebug() << "SEND : " << QString::fromStdString(s);
        m_sock->write(s.c_str(), s.length());
        //qDebug() << "SENT" << QString::fromStdString(s);
    }
}

void ConnectionManager::setNickName(std::string name)
{
    this->nickname = name;
}

std::string ConnectionManager::getNickname()
{
    qDebug() << "getNickname()";
    return this->nickname;
}

bool ConnectionManager::hasRequests()
{
    //qDebug() << "Enter hasRequests";
    //mutex.lock();
    //qDebug() << "Middle hasRequests";
    bool returnValue = (m_requests.size() != 0);
    //qDebug() << "Exiting hasRequests";
    //mutex.unlock();
    return returnValue;
}

Request * ConnectionManager::getRequest()
{
    //mutex.lock();
    qDebug() << "Entering getRequests";
    Request * req = m_requests.back();
    m_requests.pop_back();
    //qDebug() << "Exiting getRequests";
    //mutex.unlock();
    return req;
}

void ConnectionManager::close()
{
    m_sock->close();
}

void ConnectionManager::serverToRoom(RoomManager *room)
{

    disconnect(this, SIGNAL(clientDisconnected(ConnectionManager*)));
    disconnect(this, SIGNAL(newRequest(ConnectionManager*)));


    connect(this, SIGNAL(clientDisconnected(ConnectionManager*)), room, SLOT(clientDisconnected(ConnectionManager*)));
    connect(this, SIGNAL(newRequest(ConnectionManager*)), room, SLOT(readRequest(ConnectionManager*)));
}
